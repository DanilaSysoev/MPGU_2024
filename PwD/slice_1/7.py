from mysql import connector
import json

with open('config.json', 'r') as f:
    config = json.load(f)

cnx = connector.connect(
    user=config['user'], password=config['password'], host=config['host'], database='Students'
)
cursor = cnx.cursor()

cursor.execute('select * from Student;')
students = cursor.fetchall()

cursor.execute('select * from StudentsGroup;')
groups = cursor.fetchall()

mean_pts = 0
for st in students:
    mean_pts += st[3]
mean_pts /= len(students)

print(mean_pts)
print(len(students) / len(groups))

cursor.close()
cnx.close()
