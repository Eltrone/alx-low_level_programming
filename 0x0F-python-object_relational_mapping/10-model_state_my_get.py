#!/usr/bin/python3
"""
Prints the State object with the name passed as argument
from the database hbtn_0e_6_usa.
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

    # Query the State object with the specified name
    state = session.query(State).filter(State.name == sys.argv[4]).first()

    # Print the result
    if state:
        print(state.id)
    else:
        print("Not found")

    # Close the session
    session.close()
