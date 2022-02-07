#4chan parser

import os, bs4, requests

print('Enter thread URL')
url = input()
os.makedirs('4chan Downloads', exist_ok=True)
res = requests.get(url)
res.raise_for_status()

soup = bs4.BeautifulSoup(res.text)

imgList = []

for link in soup.find_all("a", class_="fileThumb"):
    #print(link)
    i = 0
    imgList.insert(i, 'http:' + link.get('href'))
    i += 1

print(str(len(imgList)) + ' Images selected for download.')


for i in imgList:
    res = requests.get(i)
    res.raise_for_status
    imgFile = open(os.path.join('4chan Downloads', os.path.basename(i)), 'wb')
    for chunk in res.iter_content(100000):
        imgFile.write(chunk)
    imgFile.close()

print('Done')
