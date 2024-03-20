#!/usr/bin/python3
"""
lists all cities of a given state from the database hbtn_0e_4_usa.
takes 4 args: mysql username, mysql password, database name, state name.
"""

import MySQLdb
import sys

if __name__ == "__main__":
    mysql_username = sys.argv[1]
    mysql_password = sys.argv[2]
    database_name = sys.argv[3]
    state_name = sys.argv[4]

    # Connect to the MySQL database
    db = MySQLdb.connect(host="localhost",
                         user=mysql_username,
                         passwd=mysql_password,
                         db=database_name,
                         port=3306)

    # Create a cursor object
    cur = db.cursor()

    # Execute the SQL query with a placeholder
    cur.execute("""
        SELECT cities.name
        FROM cities
        JOIN states ON cities.state_id = states.id
        WHERE states.name = %s
        ORDER BY cities.id ASC
    """, (state_name,))

    # Fetch all the rows in a list of tuples.
    query_rows = cur.fetchall()
    cities = [row[0] for row in query_rows]

    # Display the results as comma-separated string
    print(", ".join(cities))

    # Close cursor and connection
    cur.close()
    db.close()
