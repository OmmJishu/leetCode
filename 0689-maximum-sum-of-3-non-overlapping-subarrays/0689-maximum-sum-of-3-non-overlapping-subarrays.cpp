class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        this->k = k;
        vector<int> pref;
        int sum = 0;

        // Construct prefix sums
        int n = nums.size();
        this->n = n;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        pref.push_back(sum);

        for (int i = k; i < n; i++) {
            sum += nums[i] - nums[i - k];
            pref.push_back(sum);
        }

        vector<vector<long long>> dp(pref.size(), vector<long long>(3, -1));
        int i = 0;
        vector<int> index;

        // Greedily collect indices
        while (i <= n - k && index.size() < 3) {
            long long take = pref[i] + getMaxSum(i + k, index.size() + 1, pref, dp);
            long long notTake = getMaxSum(i + 1, index.size(), pref, dp);

            if (take >= notTake) {
                index.push_back(i);
                i += k;
            } 
            else {
                i += 1;
            }
        }

        return index;
    }

    int k,n;
    long long getMaxSum(int idx, int cnt, vector<int>& pref, vector<vector<long long>>& dp) {
        if (cnt == 3 || idx > n-k) {
            return 0;
        }

        if (dp[idx][cnt] != -1) return dp[idx][cnt];

        long long take = pref[idx] + getMaxSum(idx + k, cnt + 1, pref, dp);
        long long notTake = getMaxSum(idx + 1, cnt, pref, dp);

        return dp[idx][cnt] = max(take, notTake);
    }
};