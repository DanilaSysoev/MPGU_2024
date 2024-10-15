import notes_models as models
import json


class NotesController:
    def __init__(self, configs):
        self.connection_provider = models.MySqlConnectionProvider(configs)
        self.note_repository = models.NoteRepository(self.connection_provider)
        self.note_repository.create()
        notes = self.note_repository.get_all_notes()
        max_id = max(notes, key=lambda note: note.id).get_id() if notes else 1
        self.note_builder = models.NoteBuilder(models.IdProvider(max_id + 1))
    
    def get_all_notes(self):
        res = []
        for note in self.note_repository.get_all_notes():
            res.append(
                {
                    'id': note.get_id(),
                    'title': note.get_title(),
                    'body': note.get_body()
                }
            )
        return json.dumps(res)
    
    def get_note(self, data):
        note = self.note_repository.get_note(data['id'])
        return json.dumps(
            {
                'id': note.get_id(),
                'title': note.get_title(),
                'body': note.get_body()
            }
        )
    
    def add_note(self, data):
        if 'body' not in data:
            data['body'] = ''
        note = self.note_builder.build(data['title'], data['body'])
        self.note_repository.add_note(note)
    
    def update_note(self, data):
        note = self.note_repository.get_note(data['id'])
        if 'title' in data:
            note.title = data['title']
        if 'body' in data:
            note.body = data['body']
        self.note_repository.update_note(note)
    
    def delete_note(self, data):
        self.note_repository.delete_note(data['id'])
