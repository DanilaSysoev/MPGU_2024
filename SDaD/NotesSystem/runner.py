import json
import notes_view as view
import notes_controller as controller


def run():
    with open('config.json') as f:
        config = json.load(f)
    notes_view = view.NotesView(
        controller.NotesController(config)
    )
    command = -1
    while command != '0':
        notes_view.print_menu()
        command = input('Enter command: ')
        if command == '1':
            notes_view.show_notes()
        if command == '2':
            notes_view.show_note()
        if command == '3':
            notes_view.add_note()
        if command == '4':
            notes_view.delete_note()
        if command == '5':
            notes_view.update_note()


if __name__ == '__main__':
    run()
