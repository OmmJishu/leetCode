class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<int> st;
        
        // For first window
        for (int i = 0; i < k; i++) 
            st.insert(nums[i]);
        
        auto middleIter = next(st.begin(), (k-1)/2);
        
        if(k%2 != 0){
            res.push_back(double(*middleIter));
        }
        else{
            auto next = middleIter;
            ++next;
            // long double median = (*middleIter + *next) / 2.0;
            long double median = (static_cast<long double>(*middleIter) + static_cast<long double>(*next)) / 2.0;
            res.push_back(median);
        }

        
        // For rest of windows
        for (int i = 1; i + k <= nums.size(); i++) {
            st.insert(nums[i+k-1]);
            
            if (nums[i+k-1] < *middleIter) 
                middleIter--;
            
            if (nums[i-1] <= *middleIter) 
                middleIter++;
            
            st.erase(st.lower_bound(nums[i-1]));
            
            if(k%2 != 0){
                res.push_back(double(*middleIter));
            }
            else{
                auto next = middleIter;
                ++next;
                long double median = (static_cast<long double>(*middleIter) + static_cast<long double>(*next)) / 2.0;
                res.push_back(median);
            }
        }

        return res;
    }
};