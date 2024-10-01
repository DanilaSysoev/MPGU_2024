from os import listdir, path
from os import remove
import re
import subprocess


def file_not_processed(directory, full_path_file):
    return (path.isfile(full_path_file) and
            not full_path_file.endswith(f'_{directory}.mp4'))


def process_file(prefix, directory, file, command):
    full_path_file = path.join(prefix, directory, file)
    match = re.match(
        r'(?P<year>\d+)-(?P<month>\d+)-(?P<day>\d+).*.mp4', file
    )
    if match and len(match.groups()) == 3:
        year = match.group('year')[2:]
        month = match.group('month')
        day = match.group('day')
        out_file = path.join(
            prefix, directory, f'{year}{month}{day}_{directory}.mp4'
        )
        subprocess.run(
            command.replace('<in_file>', full_path_file)
                   .replace('<out_file>', out_file).split()
        )
        remove(full_path_file)



def process_files(dirs, prefix, command):
    for directory in dirs:
        full_path = path.join(prefix, directory)
        for file in listdir(full_path):
            full_path_file = path.join(full_path, file)
            if file_not_processed(directory, full_path_file):
                print('Processing... ', full_path_file)
                process_file(prefix, directory, file, command)
                print('OK!')

            
if __name__ == '__main__':
    dirs = ['OOP', 'PwD', 'SDaD']
    prefix = '.'
    command = 'ffmpeg -i <in_file> -vcodec libx265 -crf 28 <out_file>'
    process_files(dirs, prefix, command)
