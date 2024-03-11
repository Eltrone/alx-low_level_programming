#!/usr/bin/node

const myObject = {
  type: "objet",
  valeur: 12,
  incr() {
    this.valeur++;
  },
};

myObject.incr();
console.log(myObject);
myObject.incr();
console.log(myObject);
myObject.incr();
console.log(myObject);
