/**
 * @param {number} n
 * @return {Function} counter
 */
let val;
var createCounter = function(n) {
    val = n;
    return function() {
        let curr = val;
        val = val + 1;
        return curr;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */