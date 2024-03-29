#!/usr/bin/python3
"""
Sends request to given URL and displays body of the response. Manages
urllib.error.HTTPError exceptions to print the HTTP status code.
"""
import urllib.request
import urllib.error
import sys

if __name__ == "__main__":
    url = sys.argv[1]
    try:
        with urllib.request.urlopen(url) as response:
            content = response.read()
            print(content.decode('utf-8'))
    except urllib.error.HTTPError as e:
        print(f"Error code: {e.code}")
