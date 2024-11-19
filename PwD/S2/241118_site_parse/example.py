import scrapy


class QuotesSpider(scrapy.Spider):
    name = "quotes"
    start_urls = [
        "https://www.dns-shop.ru/catalog/17a9fce216404e77/varochnye-paneli-gazovye/",
    ]

    def parse(self, response):
        for quote in response.css("span.text"):
            yield {
                "text": quote.css("span.text::text").get(),
            }

        next_page = response.css('li.next a::attr("href")').get()
        if next_page is not None:
            yield response.follow(next_page, self.parse)