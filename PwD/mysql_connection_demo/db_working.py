import mysql.connector as m_conn
from os import path


def init_db(config):
    global _config
    _config = config.copy()


def create_widget_table():
    global _config
    cnx = _create_connection()
    cursor = cnx.cursor()
    cursor.execute(_get_sql('create_widget_table.sql'))
    cursor.close()
    cnx.close()
    
    
def create_one_to_one_tables():
    global _config
    cnx = _create_connection()
    cursor = cnx.cursor()
    cursor.execute(_get_sql('create_one_to_one_tables.sql'))
    cursor.close()
    cnx.close()


def add_widget(data):
    global _config
    cnx = _create_connection()
    cursor = cnx.cursor()
    cursor.execute(
        _get_sql('insert_widget.sql'),
        (data,)
    )
    cnx.commit()
    cursor.close()
    cnx.close()


def get_all_widgets():
    global _config
    cnx = _create_connection()
    cursor = cnx.cursor()
    cursor.execute(_get_sql('select_all_widgets.sql'))
    result = cursor.fetchall()
    cursor.close()
    cnx.close()
    return result


def delete_widget(id):
    global _config
    cnx = _create_connection()
    cursor = cnx.cursor()
    cursor.execute(
        _get_sql('delete_widget.sql'),
        (id,)
    )
    cnx.commit()
    cursor.close()
    cnx.close()


def _get_sql(name):
    with open(path.join(_config['sql_dir'], name), 'r') as f:
        return f.read()
    
    
def _create_connection():
    global _config
    return m_conn.connect(
        user=_config["user"],
        password=_config["password"],
        host=_config["host"],
        database=_config["database"]
    )
    

def create_library_tables():
    global _config
    cnx = _create_connection()
    cursor = cnx.cursor()
    cursor.execute(_get_sql('create_library_tables.sql'))
    cursor.close()
    cnx.close()
    
    
def insert_library(name, address):
    global _config
    cnx = _create_connection()
    cursor = cnx.cursor()
    cursor.execute(_get_sql('insert_library.sql'), (name, address))
    cnx.commit()
    cursor.close()
    cnx.close()


def insert_book(name, author, year):
    global _config
    cnx = _create_connection()
    cursor = cnx.cursor()
    cursor.execute(_get_sql('insert_book.sql'), (name, author, year))
    cnx.commit()
    cursor.close()
    cnx.close()


def get_all_libraries():
    global _config
    cnx = _create_connection()
    cursor = cnx.cursor()
    cursor.execute(_get_sql('get_all_libraries.sql'))
    result = cursor.fetchall()
    cursor.close()
    cnx.close()
    return result


def get_all_books():
    global _config
    cnx = _create_connection()
    cursor = cnx.cursor()
    cursor.execute(_get_sql('get_all_books.sql'))
    result = cursor.fetchall()
    cursor.close()
    cnx.close()
    return result


def add_book_to_library(book_id, library_id):
    global _config
    cnx = _create_connection()
    cursor = cnx.cursor()
    cursor.execute(_get_sql('add_book_to_library.sql'), (book_id, library_id))
    cnx.commit()
    cursor.close()
    cnx.close()


def drop_library_tables():
    global _config
    cnx = _create_connection()
    cursor = cnx.cursor()
    cursor.execute(_get_sql('drop_library_tables.sql'))
    cursor.close()
    cnx.close()
    
    
def get_books_from_library(library_id):
    global _config
    cnx = _create_connection()
    cursor = cnx.cursor()
    cursor.execute(_get_sql('get_books_from_library.sql'), (library_id,))
    result = cursor.fetchall()
    cursor.close()
    cnx.close()
    return result
    

_config = {
    'user': 'root',
    'password': '',
    'host': 'localhost',
    'sql_dir': 'sql'
}
