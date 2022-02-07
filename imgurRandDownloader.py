#downloads random imgur image from a search

import random, os, bs4, requests, re
os.makedirs('imgurImages', exist_ok=True)

# Enter search term

print('Enter what kind of image you want: ')
search = input()
print('How many imagaes do you want?')
iterations = input()
url = 'http://imgur.com/search/score?q=' + search
print(url)
# Find random image on page
res = requests.get(url)
res.raise_for_status()

soup = bs4.BeautifulSoup(res.text)
imgGallery = []
imgList = []
# finding galleries
for link in soup.find_all('', class_="image-list-link"):
    i = 1
    print(link)
    imgGallery.insert(i, 'http://imgur.com' + link.get('href'))
    i += 1
print(imgGallery)

for link in imgGallery:
    i = 0
    resGal = requests.get(link)
    res.raise_for_status()
    soupGal = bs4.BeautifulSoup(resGal.text)
    for imgLink in soupGal.find_all('div', class_="image post-image"):
        p = 0
        imgList.insert(p, imgLink.get('src'))
        p += 1
    i += 1
        
print(imgList)


print(str(len(imgList)) + ' images found.')
####print(imgList)
##while i < int(iterations):
##    print('Random image selected: ')
##    randImg = imgList[random.randint(0, len(imgList)-1)]
##    print(randImg)
##    imgUrl = 'http:' + randImg
##    # Download Image
##    res = requests.get(imgUrl)
##    res.raise_for_status()
##    imgFile = open(os.path.join('imgurImages', os.path.basename(imgUrl)), 'wb')
##    for chunk in res.iter_content(10000000):
##        imgFile.write(chunk)
##    imgFile.close()
##    print(imgUrl)
##    i += 1
print('Done.')
