#!/usr/bin/python3
"""Fetch cities by state"""

import sys
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from model_state import Base, State
from model_city import City


if __name__ == "__main__":
    username = sys.argv[1]
    password = sys.argv[2]
    db_name = sys.argv[3]

    # Create the connection to the database
    engine = create_engine('mysql+mysqldb://{}:{}@localhost/{}'
                           .format(username, password, db_name),
                           pool_pre_ping=True)

    # Create the session
    Session = sessionmaker(bind=engine)
    session = Session()

    # Query to fetch cities by state
    cities = session.query(State.name, City.id, City.name)\
                    .join(City, State.id == City.state_id)\
                    .order_by(City.id)\
                    .all()

    # Display the results
    for city in cities:
        print("{}: ({}) {}".format(city[0], city[1], city[2]))
