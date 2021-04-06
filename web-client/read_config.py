import configparser

config = configparser.ConfigParser()
config.read('config.ini')

id = config['va_config']['id']
port = config['va_config']['port']
vs_prod = config['va_config']['vs_prod']
vs_dev = config['va_config']['vs_dev']
mode = config['va_config']['mode']
auth_key = config['va_config']['auth_key']

print('config.ini configuration:')

#print(id)
#print(port)
#print(vs_prod)
#print(vs_dev)
#print(mode)
#print(auth_key)

print 'id:', id
print 'port:', port
print 'vs_prod:', vs_prod
print 'vs_dev:', vs_dev
print 'mode:', mode
print 'auth_key:', auth_key
