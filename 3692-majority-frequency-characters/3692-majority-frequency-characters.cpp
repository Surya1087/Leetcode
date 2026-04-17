class Solution {
public:
    string majorityFrequencyGroup(string s) {
        
        int freq[26] = {0};
        for (char& c : s) 
            freq[c - 'a']++;

        unordered_map<int, int> count;
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) 
                count[freq[i]]++;  
        }

        int bestFreq = 0;   
        int maxCount = 0;   
        for (auto &[f, c] : count) {
            
            if (c > maxCount || (c == maxCount && f > bestFreq)) {
                bestFreq = f;
                maxCount = c;
            }
        }

        string res;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == bestFreq)
                res += char(i + 'a');
        }

        return res;
    }
};