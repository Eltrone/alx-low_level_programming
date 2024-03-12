#!/usr/bin/node
const { dict } = require('./101-data.js');

const sortedDict = {};

Object.entries(dict).forEach(([key, value]) => {
  if (!sortedDict[value]) {
    sortedDict[value] = [];
  }
  sortedDict[value].push(key);
});

console.log(sortedDict);
