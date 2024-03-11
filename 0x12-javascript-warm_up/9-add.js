#!/usr/bin/node

function add (a, b) {
  const numA = parseInt(a);
  const numB = parseInt(b);
  if (isNaN(numA) || isNaN(numB)) {
    return NaN;
  }
  return numA + numB;
}

const firstNum = process.argv[2];
const secondNum = process.argv[3];

console.log(add(firstNum, secondNum));
