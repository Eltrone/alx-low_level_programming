#!/usr/bin/python3
"""Module containing the State class definition"""

from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import Column, Integer, String

# Create an instance of declarative base
Base = declarative_base()


class State(Base):
    """State class that represent the states table in the database"""

    __tablename__ = 'states'

    id = Column(Integer, primary_key=True, nullable=False, autoincrement=True)
    name = Column(String(128), nullable=False)
