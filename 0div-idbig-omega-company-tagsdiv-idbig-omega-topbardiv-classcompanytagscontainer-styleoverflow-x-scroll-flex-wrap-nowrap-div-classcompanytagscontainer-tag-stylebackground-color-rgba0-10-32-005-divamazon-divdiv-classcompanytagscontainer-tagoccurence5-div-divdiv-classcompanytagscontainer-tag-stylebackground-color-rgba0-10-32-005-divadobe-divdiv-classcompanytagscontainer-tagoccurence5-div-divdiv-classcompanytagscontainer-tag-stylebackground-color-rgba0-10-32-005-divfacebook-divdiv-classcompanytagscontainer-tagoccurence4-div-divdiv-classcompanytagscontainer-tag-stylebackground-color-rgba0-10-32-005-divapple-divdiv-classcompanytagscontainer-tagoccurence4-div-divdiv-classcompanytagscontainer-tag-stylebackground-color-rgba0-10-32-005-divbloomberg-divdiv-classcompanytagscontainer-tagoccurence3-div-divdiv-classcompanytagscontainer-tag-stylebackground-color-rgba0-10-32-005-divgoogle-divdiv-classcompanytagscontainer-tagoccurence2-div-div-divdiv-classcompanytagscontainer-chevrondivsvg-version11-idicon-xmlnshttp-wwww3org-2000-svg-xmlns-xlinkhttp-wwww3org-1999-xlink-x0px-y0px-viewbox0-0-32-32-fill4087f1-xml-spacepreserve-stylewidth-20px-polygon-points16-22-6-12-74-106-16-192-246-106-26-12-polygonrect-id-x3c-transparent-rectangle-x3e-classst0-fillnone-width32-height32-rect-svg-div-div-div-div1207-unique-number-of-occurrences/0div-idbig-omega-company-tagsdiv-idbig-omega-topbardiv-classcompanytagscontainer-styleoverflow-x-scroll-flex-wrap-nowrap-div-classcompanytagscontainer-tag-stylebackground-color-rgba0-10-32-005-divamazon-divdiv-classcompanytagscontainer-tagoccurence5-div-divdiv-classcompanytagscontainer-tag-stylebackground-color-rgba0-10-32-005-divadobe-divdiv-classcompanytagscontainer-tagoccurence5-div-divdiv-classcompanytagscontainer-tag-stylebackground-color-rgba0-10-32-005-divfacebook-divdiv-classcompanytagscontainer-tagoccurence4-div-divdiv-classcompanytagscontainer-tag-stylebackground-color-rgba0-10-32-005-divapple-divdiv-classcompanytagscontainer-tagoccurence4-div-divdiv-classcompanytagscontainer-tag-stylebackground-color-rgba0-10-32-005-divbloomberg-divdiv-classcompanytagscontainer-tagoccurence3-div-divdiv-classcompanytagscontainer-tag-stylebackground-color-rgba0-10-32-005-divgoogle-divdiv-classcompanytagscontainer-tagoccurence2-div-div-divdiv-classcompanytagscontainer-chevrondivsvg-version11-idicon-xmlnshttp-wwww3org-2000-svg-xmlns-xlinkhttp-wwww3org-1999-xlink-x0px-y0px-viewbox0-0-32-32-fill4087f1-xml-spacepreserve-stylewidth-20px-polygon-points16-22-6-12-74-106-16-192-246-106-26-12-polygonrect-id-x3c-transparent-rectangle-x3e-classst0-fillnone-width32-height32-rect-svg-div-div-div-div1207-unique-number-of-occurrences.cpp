class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> iteration;
        int k = 0;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < n;)
        {
            int count = 1;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    count = count + 1;
                }
                else
                {
                    break;
                }
            }
            
            i = count + i;
            iteration.push_back(count);
        }
        
        k = iteration.size();
        sort(iteration.begin(), iteration.end());
        for (int i = 0; i < k - 1; i++)
        {
            if (iteration[i] == iteration[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};