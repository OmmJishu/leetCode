/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    if(nums.length == 0)
        return init;
    var sum = 0;
    
    for(var i = 0; i<nums.length; i++){
        sum += init;
        sum = fn(init,nums[i]);
        init = sum;
    }
    
    return sum;
};