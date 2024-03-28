#!/usr/bin/python3
"""
Sends request to a given URL and displays value of the X-Request-Id
variable found in the header of the response.
"""
import urllib.request
import sys

if __name__ == "__main__":
    url = sys.argv[1]
    with urllib.request.urlopen(url) as response:
        # Retrieve the value of the 'X-Request-Id' header
        request_id = response.getheader('X-Request-Id')
        print(request_id)

