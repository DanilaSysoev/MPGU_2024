import db_working as db


class Widget:
    def __init__(self, id, data):
        self._id = id
        self._data = data

    def get_id(self):
        return self._id

    def get_data(self):
        return self._data


def init(config):
    db.init_db(config)
    
    
def get_widgets():
    return [Widget(widget[0], widget[1]) for widget in db.get_all_widgets()]


def add_new_widget(data):
    db.add_widget(data)
