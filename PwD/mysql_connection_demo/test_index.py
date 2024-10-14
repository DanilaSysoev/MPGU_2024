import mysql.connector as m_conn
import json
import orm_model as orm
import db_working as db
from os import path
import random
from datetime import datetime as dt
import tqdm


data_size = 10**4
search_cnt = 10000
min_rande = -2 * 10**8
max_rande = 2 * 10**8
exists_data = []


def init():
    global config
    with open('config.json', 'r') as f:
        config = json.load(f)


def create_connection():
    global config
    return m_conn.connect(
        user=config["user"],
        password=config["password"],
        host=config["host"],
        database=config["database"],
    )


def get_sql(name):
    global config
    with open(path.join(config['sql_dir'], name), 'r') as f:
        return f.read()

        
def create_and_connect():
    global config
    cnx = create_connection()
    cursor = cnx.cursor()
    cursor.execute(get_sql('create_table_with_index.sql'))
    cursor.close()
    cnx.close()
    
    
def fill_data():
    global config, \
           data_size, \
           min_rande, \
           max_rande, \
           exists_data

    print("Заполнение таблиц...")
    cnx = create_connection()
    cursor = cnx.cursor()
    insert_t1 = get_sql('insert_into_t1.sql')
    insert_t1_in = get_sql('insert_into_t1_indexed.sql')
    for i in tqdm.tqdm(range(data_size)):
        data = random.randint(min_rande, max_rande)
        exists_data.append(data)
        cursor.execute(insert_t1, (i, data))
        cnx.commit()
        cursor.execute(insert_t1_in, (i, data))
        cnx.commit()
    cursor.close()
    cnx.close()
    print("Заполнение завершено.")


def selection():
    global config, \
           search_cnt, \
           exists_data
           
    select_from_table('Table_1')
    select_from_table('Table_1_Indexed')


def select_from_table(tab_name):
    start = dt.now()
    print(f"Начало запросов в {tab_name}: ", start)
    
    cnx = create_connection()
    cursor = cnx.cursor()
    for _ in tqdm.tqdm(range(search_cnt)):
        data = random.choice(exists_data)
        cursor.execute(
            f"SELECT * FROM {tab_name} WHERE data = %s;",
            (data,)
        )
        result = cursor.fetchall()
        if len(result) == 0:
            print("Ошибка! Не найдено значение: ", data)
        # else:
        #     print("Значение: ", data)
    cursor.close()
    cnx.close()    
    end = dt.now()
    print("Конец запроса: ", end)
    print("Время: ", end - start)
    
    
def drop_data():
    global config
    cnx = create_connection()
    cursor = cnx.cursor()
    cursor.execute(get_sql('drop_indexed.sql'))
    cursor.close()
    cnx.close()


def main():
    init()
    create_and_connect()
    fill_data()
    selection()
    drop_data()


if __name__ == '__main__':
    main()    
