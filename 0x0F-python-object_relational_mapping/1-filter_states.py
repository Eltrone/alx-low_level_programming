#!/usr/bin/python3
"""
lists all states with a name starting with 'N' from database hbtn_0e_0_usa.
This script takes 3 arguments: mysql username, mysql password, database name.
"""

import MySQLdb
import sys

if __name__ == "__main__":
    # Get user input
    mysql_username = sys.argv[1]
    mysql_password = sys.argv[2]
    database_name = sys.argv[3]

    # Connect to the MySQL database
    db = MySQLdb.connect(host="localhost",
                         user=mysql_username,
                         passwd=mysql_password,
                         db=database_name,
                         port=3306)

    # Create a cursor object
    cur = db.cursor()

    # Execute the SQL query with a filter for names starting with 'N'
    cur.execute("SELECT * FROM states WHERE name LIKE 'N%' ORDER BY id ASC")

    # Fetch all the rows in a list of lists.
    query_rows = cur.fetchall()
    for row in query_rows:
        if row[1][0] == 'N':  # Additional check to avoid potential issues with case sensitivity
            print(row)

    # Close cursor and connection
    cur.close()
    db.close()
