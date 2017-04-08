const primeAverageNode = require('./prime-average');
const primeAverageC = require('./build/Release/prime-average');
const n = 1000000; // 100 k

console.time('Prime Average Node');
console.log(primeAverageNode.calculate(n));
console.timeEnd('Prime Average Node');

console.time('Prime Average C');
console.log(primeAverageC.calculate(n));
console.timeEnd('Prime Average C');
