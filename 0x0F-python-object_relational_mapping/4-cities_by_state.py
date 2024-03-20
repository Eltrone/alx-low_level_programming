#!/usr/bin/python3
"""
Script that lists all cities from the database hbtn_0e_4_usa
takes 3 arguments: mysql username, mysql password, database name.
"""

import MySQLdb
import sys

if __name__ == "__main__":
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

    # Execute the SQL query
    cur.execute("""
        SELECT cities.id, cities.name, states.name
        FROM cities
        JOIN states ON cities.state_id = states.id
        ORDER BY cities.id ASC
    """)

    # Fetch all the rows in a list of lists.
    query_rows = cur.fetchall()
    for row in query_rows:
        print(row)

    # Close cursor and connection
    cur.close()
    db.close()
