#!/usr/bin/node
const fs = require('fs');

const [,, fileA, fileB, fileC] = process.argv;

const contentA = fs.readFileSync(fileA, { encoding: 'utf8', flag: 'r' });
const contentB = fs.readFileSync(fileB, { encoding: 'utf8', flag: 'r' });

fs.writeFileSync(fileC, contentA + contentB);
