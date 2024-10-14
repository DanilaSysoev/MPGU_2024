SELECT * FROM Library_Book
LEFT JOIN Book ON Book.id = Library_Book.book_id
WHERE library_id = %s;
