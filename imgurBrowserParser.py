#selenium browser

from selenium import webdriver

browser = webdriver.Firefox()
browser.get('https://imgur.com/signin?redirect=%2F')

password = '2HFZyP5dwVTGZnh'
gusername = 'roberto.eligio.69@gmail.com'
iusername = 'robertoeligio69'

try:
    usrElem = browser.find_element_by_id("username")
    usrElem.send_keys(iusername)
    pssElem = browser.find_element_by_id("password")
    pssElem.send_keys(password)
    pssElem.submit()
    print('Sign In Successful')
    print('What would you like to search?')
    
    
    
except:
    print('No sign in button found')
