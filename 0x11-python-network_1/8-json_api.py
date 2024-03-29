#!/usr/bin/python3
"""
Takes in letter and sends POST request to http://0.0.0.0:5000/search_user
with the letter as a parameter.
"""
import requests
import sys

if __name__ == "__main__":
    q = ""
    if len(sys.argv) > 1:
        q = sys.argv[1]

    url = 'http://0.0.0.0:5000/search_user'
    data = {'q': q}

    try:
        response = requests.post(url, data=data)
        json_response = response.json()
        if json_response:
            id = json_response.get('id')
            name = json_response.get('name')
            print(f"[{id}] {name}")
        else:
            print("No result")
    except ValueError:
        print("Not a valid JSON")
