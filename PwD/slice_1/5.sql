CREATE TABLE T1 (
    id INT PRIMARY KEY,
    name TEXT NOT NULL
);

CREATE TABLE T2 (
    title CHAR(32) PRIMARY KEY,
    t1_id INT NOT NULL,
    FOREIGN KEY (t1_id) REFERENCES T1(id) ON DELETE CASCADE
);
