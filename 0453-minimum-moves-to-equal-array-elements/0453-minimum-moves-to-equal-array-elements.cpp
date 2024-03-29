class Solution {
public:
    int minMoves(vector<int>& nums) {
        return accumulate(nums.begin(),nums.end(),0) - *min_element(nums.begin(),nums.begin()+nums.size())*nums.size();
    }
};

//let's define sum as the sum of all the numbers, before any moves; minNum as the min number int the list; n is the length of the list;

// After, say m moves, we get all the numbers as x , and we will get the following equation

//  sum + m * (n - 1) = x * n
// and actually,

//   x = minNum + m

// the minum number will always be minum until it reachs the final number, because every move, other numbers (besides the max) will be increamented too;
// from above, we can get, the minum number will be incremented in every move. So, if the final number is x, it would be minNum + moves;
// and finally, we will get

//   sum - minNum * n = m