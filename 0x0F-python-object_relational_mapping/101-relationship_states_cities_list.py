#!/usr/bin/python3
"""List all State objects, and corresponding City objects from the database"""

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
    Base.metadata.create_all(engine)

    # Create the session
    Session = sessionmaker(bind=engine)
    session = Session()

    # One query to the database using the cities relationship for all State objects
    states = session.query(State).order_by(State.id, City.id).all()

    # Display results sorted by states.id and cities.id
    for state in states:
        print("{}: {}".format(state.id, state.name))
        for city in state.cities:
            print("\t{}: {}".format(city.id, city.name))
