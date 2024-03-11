#!/usr/bin/node

function callMeMoby(times, theFunction) {
  for (let i = 0; i < times; i++) {
    theFunction();
  }
}

callMeMoby(3, () => console.log('C is fun'));
