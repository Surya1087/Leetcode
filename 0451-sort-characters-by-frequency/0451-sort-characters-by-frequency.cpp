class Solution {
public:
    string frequencySort(string s) {
    unordered_map<char, int> freq;

    
    for (char c : s) {
        freq[c]++;
    }

    int n = s.size();

   
    vector<vector<char>> bucket(n + 1);

    
    for (const auto &p : freq) {
        bucket[p.second].push_back(p.first);
    }

    
    string ans;
    ans.reserve(s.size());

    for (int i = n; i >= 1; --i) {
        for (char c : bucket[i]) {
            ans += string(i, c);
        }
    }

    return ans;
}
};