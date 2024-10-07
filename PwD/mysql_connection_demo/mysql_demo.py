import mysql.connector as m_conn
import json
import orm_model as orm
import db_working as db


def init():
    with open('config.json', 'r') as f:
        config = json.load(f)

    orm.init(config)


def create_tables():
    db.create_widget_table()
    db.create_one_to_one_tables()


def add_widgets():
    orm.add_new_widget("widget_1")
    orm.add_new_widget("widget_2")
    orm.add_new_widget("widget_3")


def print_widgets():
    for widget in orm.get_widgets():
        print(f'Id: {widget.get_id()}, Data: {widget.get_data()}')
    


def run():
    init()
    create_tables()
    
    print_widgets()
    id_for_removing = int(input('Введите id для удаления:\n'))
    db.delete_widget(id_for_removing)
    print_widgets()


if __name__ == '__main__':
    run()
