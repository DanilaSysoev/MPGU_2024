CREATE TABLE IF NOT EXISTS Table_1_Indexed (
    id INT PRIMARY KEY,
    data INT NOT NULL
);

CREATE TABLE IF NOT EXISTS Table_1 (
    id INT PRIMARY KEY,
    data INT NOT NULL
);

CREATE INDEX Table_1_name_index ON Table_1_Indexed(data);
