class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> c;
        int ans = 0;

        for (char x : s) {
            if (x == '(') {
                c.push(x);
            }
            else {
                if (!c.empty() && c.top() == '(') {
                    c.pop();
                }
                else {
                    ans++;  
                }
            }
        }
        ans += c.size();

        return ans;
    }
};