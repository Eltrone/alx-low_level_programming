#!/usr/bin/node

function add (a, b) {
  const numA = parseInt(a);
  const numB = parseInt(b);
  if (isNaN(numA) || isNaN(numB)) {
    return NaN;
  }
  return numA + numB;
}

module.exports = { add };
