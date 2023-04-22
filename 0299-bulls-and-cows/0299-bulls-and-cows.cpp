class Solution {
public:
    string getHint(string secret, string guess) {
       unordered_map<char, int> freq;
        int cows = 0, bulls = 0;
        
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
                secret.erase(secret.begin()+i);
                guess.erase(guess.begin()+i);
                i--;
            }
            else {
                freq[secret[i]]++;
            }
        }
    
        for (int i = 0; i < guess.size(); i++) {
            if (freq[guess[i]] > 0) {
                cows++;
                freq[guess[i]]--;
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};