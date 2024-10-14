import db_working as db
import json


def add_books():
    db.insert_book('Book 1', 'Author 1', 2000)
    db.insert_book('Book 2', 'Author 2', 2024)
    db.insert_book('Book 3', 'Author 3', 2022)
    db.insert_book('Book 4', 'Author 4', 2015)
    db.insert_book('Book 2', 'Author 2', 2020)
    
    
def add_libraries():
    db.insert_library('Library 1', 'Address 1')
    db.insert_library('Library 2', 'Address 2')
    db.insert_library('Library 3', 'Address 3')
    db.insert_library('Library 4', 'Address 4')
    db.insert_library('Library 5', 'Address 5')
    
    
def add_books_to_libraries():
    db.add_book_to_library(1, 1)
    db.add_book_to_library(2, 1)
    db.add_book_to_library(3, 1)
    db.add_book_to_library(4, 1)
    db.add_book_to_library(1, 2)
    db.add_book_to_library(2, 2)
    db.add_book_to_library(5, 3)
    db.add_book_to_library(1, 4)
    db.add_book_to_library(2, 4)
    db.add_book_to_library(4, 4)
    db.add_book_to_library(5, 4)
    db.add_book_to_library(3, 5)
    db.add_book_to_library(2, 5)
    
    
def init():
    with open('config.json', 'r') as f:
        config = json.load(f)
    db.init_db(config)


def print_all():
    for library in db.get_all_libraries():
        print(f'{library[1]} ({library[2]})')
        for book in db.get_books_from_library(library[0]):
            print(f'\t{book[4]}. "{book[3]}" ({book[5]})')


def run():
    init()
    db.create_library_tables()
    add_books()
    add_libraries()
    add_books_to_libraries()
    print_all()
    command = input('введите delete для удаления\n')
    if command == 'delete':
        db.drop_library_tables()


if __name__ == '__main__':
    run()
