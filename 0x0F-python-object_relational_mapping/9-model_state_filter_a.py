#!/usr/bin/python3
"""
Lists all State objects that contain the letter a from
the database hbtn_0e_6_usa.
"""

import sys
from model_state import Base, State
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker

if __name__ == "__main__":
    # Create a connection to the database
    engine = create_engine('mysql+mysqldb://{}:{}@localhost/{}'
                           .format(sys.argv[1], sys.argv[2], sys.argv[3]))

    # Bind the engine to the metadata of the Base class
    Base.metadata.bind = engine

    # Create a configured "Session" class
    Session = sessionmaker(bind=engine)

    # Create a Session
    session = Session()

    # Query all State objects that contain the letter 'a' in their name
    states = session.query(State).\
        filter(State.name.like('%a%')).\
        order_by(State.id).\
        all()

    # Print the results
    for state in states:
        print("{}: {}".format(state.id, state.name))

    # Close the session
    session.close()
