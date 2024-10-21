CREATE TABLE T1 (
    id INT PRIMARY KEY,
    name TEXT NOT NULL
);

CREATE TABLE T2 (
    title CHAR(32) PRIMARY KEY
);

CREATE TABLE T1_T2 (
    t1_id INT NOT NULL,
    t2_title CHAR(32) NOT NULL,
    PRIMARY KEY (t1_id, t2_title),
    FOREIGN KEY (t1_id) REFERENCES T1(id),
    FOREIGN KEY (t2_title) REFERENCES T2(title)
);
