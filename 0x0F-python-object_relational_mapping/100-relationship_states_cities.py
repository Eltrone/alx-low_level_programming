#!/usr/bin/python3
"""Create a state with a city"""

import sys
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from relationship_state import Base, State
from relationship_city import City


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

    # Create the State "California" with the City "San Francisco"
    new_state = State(name="California", cities=[City(name="San Francisco")])
    session.add(new_state)
    session.commit()
