from bs4 import BeautifulSoup

with open('demo.html', 'r') as f:
    doc_html = f.read()
    
bs = BeautifulSoup(doc_html, 'html.parser')

print(bs.title)
print(bs.p)
print(bs.find_all('p'))

print(bs.title.string)
print(bs.p.contents)
print(bs.title.parent.name)

print(bs.meta['charset'])
print(bs.find('p', id='contacts'))
print(bs.find('p', {'class': 'body'}))
