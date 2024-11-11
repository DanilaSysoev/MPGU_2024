import requests
from bs4 import BeautifulSoup

url_path = 'https://beautiful-soup.readthedocs.io/en/latest/'

r = requests.get(url_path)

if r.status_code != 200:
    print('Error: ', r.status_code)
    exit()

bs = BeautifulSoup(r.text, 'html.parser')

side_menu = bs.find('div', {'class': 'local-toc'}).find_all('li')

headers = []

for li in side_menu:
    if li.parent.parent.name == 'div':
        headers.append(li.a.text)


sub_headers = {}
for h in headers:
    id = '-'.join(h.split()).lower()
    if not bs.find('div', id=id):        
        print(id)
        continue

    sections = bs.find('div', id=id).find_all('div', {'class': 'section'})
    sub_headers[h] = []
    for s in sections:
        if s.h2:
            if isinstance(s.h2.contents[0], str):
                sub_headers[h].append(s.h2.contents[0])
            elif s.h2.contents[0].name == 'code':
                sub_headers[h].append(s.h2.contents[0].span.string)


for h, sh in sub_headers.items():
    print(h)
    for s in sh:
        print('\t', s)
