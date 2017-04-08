module.exports.calculate = function calculate(n) {
    let i;
    let f = 0;

    for (i = 1; i <= n; ++i) {
        if (checkIsPrime(i)) {
            f += (i - f) / i;
        }
    }
    return f;
}


function checkIsPrime(n) {
    let j;
    let isPrime = true;

    if (n == 1) {
        return false;
    }
    let nSqrt = Math.sqrt(n)
    for(j = 2; j <= nSqrt; ++j)
    {
         if(n % j == 0)
         {
              isPrime = false;
              break;
         }
    }
    return isPrime;
}
