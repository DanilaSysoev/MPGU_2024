import json

class NotesView:
    def __init__(self, controller):
        self.controller = controller
        
    def print_menu(self):
        print('1. Show all notes')
        print('2. Show note')
        print('3. Add note')
        print('4. Delete note')
        print('5. Update note')
        print('0. Exit')

    def show_notes(self):
        notes = json.loads(self.controller.get_all_notes())
        for note in notes:
            print(f'{note["id"]}. {note["title"]}: {note["body"]}')
        print()

    def show_note(self):
        note_id = int(input('Enter id: '))
        note = json.loads(self.controller.get_note({ 'id': note_id }))
        print(f'{note["id"]}. {note["title"]}: {note["body"]}')
        print()

    def add_note(self):
        note_title = input("Enter note title:\n")
        note_body = input("Enter note body:\n")
        self.controller.add_note(
            {'title': note_title, 'body' : note_body}
        )
        print("Note added")
    
    def delete_note(self):
        note_id = input("Enter note id:\n")
        self.controller.delete_note(
            {'id': note_id}
        )
        print("Note deleted")

    def update_note(self):
        note_id = input("Enter note id:\n")
        note_title = input("Enter note title:\n")
        note_body = input("Enter note body:\n")
        self.controller.update_note(
            {'id': note_id, 'title': note_title, 'body': note_body}
        )
        print("Note updated")
