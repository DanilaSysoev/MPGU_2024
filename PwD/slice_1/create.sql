CREATE DATABASE IF NOT EXISTS Students;

CONNECT Students;

CREATE TABLE IF NOT EXISTS StudentsGroup  (
    id INTEGER PRIMARY KEY,
    name TEXT NOT NULL,
    study_year INTEGER NOT NULL
);

CREATE TABLE IF NOT EXISTS Student (
    id INTEGER PRIMARY KEY,
    name TEXT NOT NULL,
    StudentsGroup_id INTEGER NOT NULL,
    mean_points REAL NOT NULL,
    FOREIGN KEY (StudentsGroup_id) REFERENCES StudentsGroup(id)
);

INSERT INTO StudentsGroup (id, name, study_year)
           VALUES (1, 'StudentsGroup 1', 2018);
INSERT INTO StudentsGroup (id, name, study_year)
           VALUES (2, 'StudentsGroup 2', 2020);
INSERT INTO StudentsGroup (id, name, study_year)
           VALUES (3, 'StudentsGroup 3', 2024);

INSERT INTO Student (id, name, StudentsGroup_id, mean_points)
             VALUES (11, 'Student 11', 1, 10);
INSERT INTO Student (id, name, StudentsGroup_id, mean_points)
             VALUES (12, 'Student 12', 1, 20);
INSERT INTO Student (id, name, StudentsGroup_id, mean_points)
             VALUES (13, 'Student 13', 1, 15);

INSERT INTO Student (id, name, StudentsGroup_id, mean_points)
             VALUES (21, 'Student 21', 2, 12);
INSERT INTO Student (id, name, StudentsGroup_id, mean_points)
             VALUES (22, 'Student 22', 2, 16);

INSERT INTO Student (id, name, StudentsGroup_id, mean_points)
             VALUES (31, 'Student 31', 3, 22);
INSERT INTO Student (id, name, StudentsGroup_id, mean_points)
             VALUES (32, 'Student 32', 3, 12);
INSERT INTO Student (id, name, StudentsGroup_id, mean_points)
             VALUES (33, 'Student 33', 3, 10);
INSERT INTO Student (id, name, StudentsGroup_id, mean_points)
             VALUES (34, 'Student 34', 3, 14);
