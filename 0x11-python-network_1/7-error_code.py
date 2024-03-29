#!/usr/bin/python3
"""
Takes in URL, sends request to URL, and displays the body of the response.
Displays an error code for HTTP status codes >= 400.
"""
import requests
import sys

if __name__ == "__main__":
    url = sys.argv[1]
    response = requests.get(url)
    if response.status_code >= 400:
        print(f"Error code: {response.status_code}")
    else:
        print(response.text)
