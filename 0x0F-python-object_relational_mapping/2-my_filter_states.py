#!/usr/bin/python3
"""
takes an argument and displays all values in the states table
of hbtn_0e_0_usa where name matches the argument.
takes 4 arguments: mysql username, mysql password,
database name, state name searched.
"""

import MySQLdb
import sys

if __name__ == "__main__":
    mysql_username = sys.argv[1]
    mysql_password = sys.argv[2]
    database_name = sys.argv[3]
    state_name_searched = sys.argv[4]

    # Connect to the MySQL database
    db = MySQLdb.connect(host="localhost",
                         user=mysql_username,
                         passwd=mysql_password,
                         db=database_name,
                         port=3306)

    # Create a cursor object
    cur = db.cursor()

    # Using format to insert the user input into the query
    # Note: This is not safe against SQL injection attacks.
    query = ("SELECT * FROM states WHERE name = '{}'"
             "ORDER BY id ASC").format(state_name_searched)

    cur.execute(query)

    # Fetch all the rows in a list of lists.
    query_rows = cur.fetchall()
    for row in query_rows:
        if row[1] == state_name_searched:
            print(row)

    # Close cursor and connection
    cur.close()
    db.close()
