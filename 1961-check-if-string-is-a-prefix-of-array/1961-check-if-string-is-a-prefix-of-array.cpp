class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string parr{};
        for(string word : words)
        {
            while(parr.length() <= s.length())
            {
                parr += word;
                if(parr.length() == s.length() && parr == s)
                    return true;
                else
                    break;
            }
            if(parr.length() > s.length())
                break;
        }
        return false;
    }
};