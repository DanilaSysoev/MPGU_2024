import requests
from bs4 import BeautifulSoup

# sber3
# url = 'https://megamarket.ru/catalog/?q=macbook%20air&suggestionType=constructor'
# dns Unauthorized
# url = 'https://www.dns-shop.ru/search/?q=macbook+air&category=17a892f816404e77'
# wb
# url = 'https://www.wildberries.ru/catalog/0/search.aspx?search=macbook%20air'
# techno park Unauthorized
# url = 'https://www.technopark.ru/search/?q=macbook&withContent=true&strategy=vectors_extended,zero_queries'
# citilink
# url = 'https://www.citilink.ru/catalog/noutbuki/APPLE/'
# m video
url = 'https://www.auchan.ru/product/desert-biskvitnyy-akkond-lomtishka-s-nachinkoy-moloko-160-g'

headers = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/81.0.4044.122 Safari/537.36',
    'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
    'accept-language': 'ru-RU, ru;q=0.9',
}

response = requests.get(url, headers=headers)
response.raise_for_status()

soup = BeautifulSoup(response.content, 'html.parser')

if soup is None:
    print("empty")
else:
    print("norm")

print(soup.prettify())

products = soup.find_all('div', class_='product-card')

product_list = []

for product in products:
    title = product.find('div', class_='product-card__title')
    if title:
        product_name = title.text.strip()
    else:
        product_name = "Unknown"

    price = product.find('div', class_='product-card__price-new')
    if price:
        product_price = price.text.strip()
    else:
        product_price = "Unknown"

    product_list.append((product_name, product_price))

for item in product_list:
    print(f"Название: {item[0]}, Цена: {item[1]}")
