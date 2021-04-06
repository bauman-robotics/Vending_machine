import requests
import configparser

config = configparser.ConfigParser()
config.read('config.ini')

id = config['va_config']['id']
port = config['va_config']['port']
vs_prod = config['va_config']['vs_prod']
vs_dev = config['va_config']['vs_dev']
mode = config['va_config']['mode']
auth_key = config['va_config']['auth_key']
br_server = config['va_config']['br_server']

print('config.ini configuration:')

print 'id:', 
print 'port:', port
print 'vs_prod:', vs_prod
print 'vs_dev:', vs_dev
print 'mode:', mode
print 'auth_key:', auth_key
print 'br_server:', br_server

ip = br_server + 'api/v1/' + auth_key + '/apparat-on'

print ip
payload = {'id': id, 'port': port}  
response = requests.get(ip, params = payload)
print(response.url) 

print(response.text)

