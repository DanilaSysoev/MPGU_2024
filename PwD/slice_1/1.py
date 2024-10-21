data = list(map(int, input().split()))

even_cnt = 0
odd_cnt = 0

for i in range(len(data)):
    if data[i] > 0 and data[i] % 2 == 0:
        even_cnt += 1
    if data[i] > 0 and data[i] % 2 == 1:
        odd_cnt += 1

print(even_cnt)
print(odd_cnt)
