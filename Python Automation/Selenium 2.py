import time

from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
driver = webdriver.Chrome()
driver.get("https://www.youtube.com/")
search = driver.find_element(By.ID,'search-container')
search.send_keys("Hackathon")
search.send_keys(Keys.RETURN)
time.sleep(100)