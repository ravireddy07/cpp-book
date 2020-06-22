'use strict';

const fs = require('fs');

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', function (inputStdin) {
  inputString += inputStdin;
});

process.stdin.on('end', function () {
  inputString = inputString.split('\n');

  main();
});

function readLine() {
  return inputString[currentLine++];
}

/*
 * Complete the 'longestSubarray' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

function longestSubarray(arr) {
  // Write your code here
  if (arr.length < 2) return arr.length;

  let best = 1;
  let bestLower = 1;
  let bestHigher = 1;

  for (let i = 1; i < arr.length; i++) {
    if (arr[i] == arr[i - 1]) {
      bestLower = bestLower + 1;
      bestHigher = bestHigher + 1;
    } else if (arr[i] - 1 == arr[i - 1]) {
      bestLower = 1 + bestHigher;
      bestHigher = 1;
    } else if (arr[i] + 1 == arr[i - 1]) {
      bestHigher = 1 + bestLower;
      bestLower = 1;
    } else {
      bestLower = 1;
      bestHigher = 1;
    }

    best = Math.max(best, bestLower, bestHigher);
  }

  return best;
}
function main() {
  const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

  const arrCount = parseInt(readLine().trim(), 10);

  let arr = [];

  for (let i = 0; i < arrCount; i++) {
    const arrItem = parseInt(readLine().trim(), 10);
    arr.push(arrItem);
  }

  const result = longestSubarray(arr);

  ws.write(result + '\n');

  ws.end();
}
