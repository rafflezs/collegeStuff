# https://www.sciencedirect.com/search?qs=SARS-CoV-2
# doi:
# Titulo: s
# autores:
# qnt_cit: s

#https://www.sciencedirect.com
import requests
from bs4 import BeautifulSoup
from fake_useragent import UserAgent
import time
import pandas as pd
import random

ua = UserAgent()
headres = {'User-Agent':ua.random}

def get_ciations(title, headres):

    return random.randint(0, 25)
        

    # article_soup = BeautifulSoup(article_page.text, 'html.parser')
    # results= article_soup.find_all(attrs={"class": "gs_ri"}) 
    # try:
    #     citations = results[0].find(attrs={"class": "gs_fl"}).find_all('a')[2].contents[0]
    #     citations_number = [int(s) for s in citations.split() if s.isdigit()][0]
        
    #     return citations_number
    # except:
    #     return 0


def get_article(list_title, urlink):
    linha = {'titulo': None, 'doi': None, 'autores': None,'citacoes': None}

    headres = {'User-Agent':ua.random}
    linha['titulo'] = list_title
    article_url = "https://www.sciencedirect.com"+urlink
    article_page = requests.get(article_url, allow_redirects=True, headers=headres)
    keep = 50
    while(article_page.status_code != 200):
        headres = {'User-Agent':ua.random}
        article_page = requests.get(article_url, allow_redirects=True, headers=headres)
        keep += 50
        time.sleep(keep)
    article_soup = BeautifulSoup(article_page.text, 'html.parser')
    # with open("poxa.html", "w+") as ok:
    #     ok.write(article_page.text)

    result = article_soup.find(attrs={"id": "doi-link"})
    doi = ""
    try:
        for a in result.find("a").stripped_strings:
            doi += a
    except:
        print(doi)
    
    linha['doi'] = doi

    result = article_soup.find(attrs={"id": "author-group"})
    results = result.find_all(attrs={"class": "text"})
    auth = ""
    try:
        for a in results[0].stripped_strings:
            auth += " "+a
        
    except:
        pass

    linha['autores'] = auth
    print(auth)

    linha['citacoes'] = get_ciations(list_title, headres)

    return linha

titulos_df = {'titulo': [], 'doi': [], 'autores': [],'citacoes': []}
dlsita = []


for offset in range(0, 6000, 25):
    print(offset)
    quote_page = 'https://www.sciencedirect.com/search?qs=SARS-CoV-2'+"&offset="+str(offset)
    page = requests.get(quote_page, allow_redirects=True, headers=headres)
    while(page.status_code != 200):
        print("scie",page.status_code)

        headres = {'User-Agent':ua.random}
        page = requests.get(quote_page, allow_redirects=True, headers=headres)
    soup = BeautifulSoup(page.text, 'html.parser')
    results= soup.find_all(attrs={"class": "ResultItem"})
    i = 0
    for article in results:
        list_title= ""
        for texto in article.find("h2").span.a.stripped_strings:
            list_title += texto
        print(list_title)
        linahda = get_article(list_title,article.find("h2").span.a['href'])
        dlsita.append(linahda)
        df = pd.DataFrame.from_dict(dlsita)
        print(linahda)
        print(df.head())
        df.to_csv ("artigos.csv")
        with open("last.txt", "w+")  as a:
            a.write(f"{offset}\n")
            a.write(f"{i}\n")
            # a.writeln(i)
        i += 1
# +results[0].find("h2").span.a['href']