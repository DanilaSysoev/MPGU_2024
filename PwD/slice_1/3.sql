CREATE TABLE T1 (
    id INT PRIMARY KEY,
    name TEXT NOT NULL,
    descr TEXT
);

INSERT INTO T1 (id, name, descr)
          VALUES (1, 'name1', 'descr1');

INSERT INTO T1 (id, name)
          VALUES (10, 'name2');

INSERT INTO T1 (id, name, descr)
          VALUES (2, 'name2', 'descr2');
