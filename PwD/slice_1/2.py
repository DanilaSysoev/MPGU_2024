import pandas as pd

df = pd.read_csv("data.csv", sep=';')

print(df['A'].mean())
print(df['A'].median())
print(df['A'].max())
print(df['A'].min())
print(df['A'].std())
