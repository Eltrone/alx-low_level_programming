#!/usr/bin/node

function addMeMaybe(number, theFunction) {
  number++;
  theFunction(number);
}

addMeMaybe(4, (nb) => console.log('New value : ' + nb));
