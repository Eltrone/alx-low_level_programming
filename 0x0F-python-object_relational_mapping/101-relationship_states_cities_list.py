#!/usr/bin/python3
"""
List all State objects, and corresponding City objects, contained in the database hbtn_0e_101_usa
"""

import sys
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker
from relationship_state import Base, State  # Assurez-vous que ces modules sont correctement définis

if __name__ == "__main__":
    username = sys.argv[1]
    password = sys.argv[2]
    db_name = sys.argv[3]

    # Créer la connexion à la base de données
    engine = create_engine(f'mysql+mysqldb://{username}:{password}@localhost:3306/{db_name}')

    # Créer une session
    Session = sessionmaker(bind=engine)
    session = Session()

    # Requête pour récupérer tous les objets State avec leurs villes correspondantes
    # en utilisant la relation 'cities' définie dans le modèle State
    states = session.query(State).order_by(State.id, State.cities.any().id).all()

    for state in states:
        print(f"{state.id}: {state.name}")
        for city in state.cities:
            print(f"\t{city.id}: {city.name}")

    session.close()
