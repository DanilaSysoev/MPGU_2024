CREATE TABLE IF NOT EXISTS `Library` (
    `id` INTEGER PRIMARY KEY NOT NULL AUTO_INCREMENT,
    `name` TEXT NOT NULL,
    `address` TEXT NOT NULL
);

CREATE TABLE IF NOT EXISTS `Book` (
    `id` INTEGER PRIMARY KEY NOT NULL AUTO_INCREMENT,
    `name` TEXT NOT NULL,
    `author` TEXT NOT NULL,
    `year` INTEGER NOT NULL
);

CREATE TABLE IF NOT EXISTS `Library_Book` (
    `book_id` INTEGER NOT NULL,
    `library_id` INTEGER NOT NULL,
    FOREIGN KEY (book_id) REFERENCES Book(id),
    FOREIGN KEY (library_id) REFERENCES Library(id),
    PRIMARY KEY (book_id, library_id)
);
