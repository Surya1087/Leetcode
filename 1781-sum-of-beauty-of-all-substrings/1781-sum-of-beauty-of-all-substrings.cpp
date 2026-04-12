class Solution {
public:
    int beautySum(string s) {
        int ans =0;
        for(int i=0; i<s.size(); i++){
            vector<int> freq(26, 0); 
            for(int k=0; k<2; k++) if(k+i<s.size()) freq[s[k+i]-'a']++;
            for(int j=i+2; j<s.size(); j++){
                freq[s[j]-'a']++;
                int mx=0, mn=501;
                for(auto i: freq){
                    if(i!=0){
                        mx = max(mx, i);
                        mn = min(mn, i);
                    }
                }
                ans += mx-mn;
            }
        }
        return ans;
    }
};