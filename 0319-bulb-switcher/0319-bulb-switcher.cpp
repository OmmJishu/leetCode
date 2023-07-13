class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

// Explanation below



// This works for n <= 10^7 otherwise  TLE


// class Solution {
// public:
//     int bulbSwitch(int n) {
//         vector<bool> arr(n,false);

//         for(int i = 1; i<= n; i++){
//             for(int j = i-1; j<n; j = j+i){

//                 if(arr[j] == false)
//                     arr[j] = true;
//                 else if(arr[j] == true)
//                     arr[j] = false;
//             }
//         }

//         int count = 0;
//         for(int i = 0; i<n; i++)
//             if(arr[i] == true)
//                 count++;
        
//         return count;
//     }
// };


// Just focus on a bulb and see how many times its state gets toggled. If a bulb gets toggled even number of times its state is the same as initial state (which is OFF), and if the bulb is toggled odd number of times its state is ON.

// Notice that each bulb gets toggled only in those rounds that are its divisors.

// Bulb 1 -> Gets toggled 1 time. (in round 1) -> Final State ON
// Bulb 2 -> Gets toggled 2 times. (in round 1 and 2) -> Final State OFF
// ...
// Bulb 6 -> Gets toggled 4 times (in round 1, 2, 3 and 6) -> Final State OFF
// Bulb 9 -> Gets toggled 3 times (in round 1, 3 and 9) -> Final State ON
// ...
// Bulb 25 -> Gets toggled 3 times (in round 1, 5 and 25) -> Final State ON

// Once you start writing the state of each bulb after n rounds you will notice that only the bulbs that are perfect square numbered are in ON state, rest are in OFF (or initial) state
// .
// This is because the divisors of every integer that is NOT a perfect square comes as a pair.
// For example, in case of 6 its divisors are (1,6) and (2,3). In case of 12 the divisors are (1,12), (2,6), (3,4).
// Each member of the pair cancels out the toggle made by the other member.

// But in case of perfect-square number one of its divisor does not come as a pair. That divisor is the square root of that perfect square number. Thats why a perfect-square number has odd number of divisors. That is why there is no round that can cancel out the toggle made by the "square-root" round. Thats why all the perfect square numbers are in ON state.

// So, the answer is: the number of perfect square numbers less than or equal to n