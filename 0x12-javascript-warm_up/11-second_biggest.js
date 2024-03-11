#!/usr/bin/node

const args = process.argv.slice(2);
const numArgs = args.length;

if (numArgs === 0) {
  console.log(0);
} else if (numArgs === 1) {
  console.log(0);
} else {
  const numbers = args.map(num => parseInt(num));
  let firstBiggest = -Infinity;
  let secondBiggest = -Infinity;

  for (const num of numbers) {
    if (num > firstBiggest) {
      secondBiggest = firstBiggest;
      firstBiggest = num;
    } else if (num > secondBiggest && num !== firstBiggest) {
      secondBiggest = num;
    }
  }

  console.log(secondBiggest);
}
