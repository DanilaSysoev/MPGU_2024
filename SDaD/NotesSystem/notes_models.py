import mysql
from mysql.connector import connect


class Note:
    def __init__(self, id, title, body):
        self.id = id
        self.title = title
        self.body = body

    def get_id(self):
        return self.id

    def get_title(self):
        return self.title

    def get_body(self):
        return self.body

    def set_title(self, title):
        self.title = title

    def set_body(self, body):
        self.body = body

    def __str__(self):
        return "Title: " + self.title + "\nBody: " + self.body


class NoteBuilder:
    def __init__(self, id_provider):
        self.id_provider = id_provider

    def build(self, title, body):
        return Note(self.id_provider.get_id(), title, body)


class IdProvider:
    def __init__(self, start_id):
        self.next_id = start_id

    def get_id(self):
        self.next_id += 1
        return self.next_id - 1


class NoteRepository:
    def __init__(self, connection_provider):
        self.connection_provider = connection_provider
    
    def create(self):
        with self.connection_provider.get_connection() as connection:
            cursor = connection.cursor()
            cursor.execute(
                "CREATE TABLE IF NOT EXISTS Note"
                "(id INT PRIMARY KEY,"
                " title TEXT NOT NULL,"
                " body TEXT);"
            )
        
    def add_note(self, note):
        with self.connection_provider.get_connection() as connection:
            cursor = connection.cursor()
            cursor.execute("INSERT INTO Note (id, title, body) VALUES (%s, %s, %s);",
                           (note.get_id(), note.get_title(), note.get_body()))
            connection.commit()

    def get_note(self, id):
        with self.connection_provider.get_connection() as connection:
            cursor = connection.cursor()
            cursor.execute("SELECT * FROM Note WHERE id = %s;", (id,))
            result = cursor.fetchone()
            if result:
                return Note(result[0], result[1], result[2])
            return None

    def get_all_notes(self):
        with self.connection_provider.get_connection() as connection:
            cursor = connection.cursor()
            cursor.execute("SELECT * FROM Note;")
            return [Note(line[0], line[1], line[2])
                    for line in cursor.fetchall()]
            
    def update_note(self, note):
        with self.connection_provider.get_connection() as connection:
            cursor = connection.cursor()
            cursor.execute("UPDATE Note SET title = %s, body = %s WHERE id = %s;",
                           (note.get_title(), note.get_body(), note.get_id()))
            connection.commit()

    def delete_note(self, id):
        with self.connection_provider.get_connection() as connection:
            cursor = connection.cursor()
            cursor.execute("DELETE FROM Note WHERE id = %s;", (id,))
            connection.commit()


class MySqlConnectionProvider:
    def __init__(self, config):
        self.host = config["host"]
        self.username = config["username"]
        self.password = config["password"] if "password" in config else ""
        self.database = config["database"]

    def get_connection(self):
        return connect(
            host=self.host,
            user=self.username,
            password=self.password,
            database=self.database
        )
