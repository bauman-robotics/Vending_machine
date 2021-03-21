import requests

session = requests.Session()
response = session.post('http://178.140.18.140:3141/led', data={'led':'true'})
print(response.text)

