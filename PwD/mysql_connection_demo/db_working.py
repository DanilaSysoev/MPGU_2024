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
    
_config = {
    'user': 'root',
    'password': '',
    'host': 'localhost',
    'sql_dir': 'sql'
}
