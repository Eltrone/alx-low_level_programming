function add(a, b) {
  const numA = parseInt(a);
  const numB = parseInt(b);
  if (isNaN(numA) || isNaN(numB)) {
    return NaN;
  }
  return numA + numB;
}

// This line makes the function visible from outside the file (module.exports)
module.exports = { add };
