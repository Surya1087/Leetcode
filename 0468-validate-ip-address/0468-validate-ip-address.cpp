class Solution {
public:
    string validIPAddress(string queryIP) {
        int n = queryIP.size();

        bool dot = false, colan = false;
        for(auto i : queryIP) {
            if(i == '.') dot = true;
            else if(i == ':') colan = true;
        }

        if(dot && colan) return "Neither";

        if(dot) {
            if(queryIP[0] == '.' || queryIP.back() == '.') return "Neither";
            int i=0, cnt = 0;
            while(i < n) {
                string s = "";
                while(i < n && queryIP[i] != '.') {
                    s += queryIP[i++];
                }
                i++;
                cnt++;
                bool ok = false, zz = false;
                for(auto j : s) {
                    if(j < '0' || j > '9') {
                        ok = true; break; 
                    }
                }
                int x = 266;
                if(s.size() && s.size() < 4 && !ok) x = stoi(s);
                if(s.size() > 1 && s[0] == '0') zz = true;
                if(s.empty() || zz || x>255 || x<0 || ok) return "Neither";
            }
            if(cnt != 4) return "Neither";
            return "IPv4";
        }

        if(colan) {
            if(queryIP[0] == ':' || queryIP.back() == ':') return "Neither";
            int i=0, cnt = 0;
            while(i < n) {
                string s = "";
                while(i < n && queryIP[i] != ':') {
                    s += queryIP[i++];
                }
                i++;
                cnt++;
                bool ok = false;
                for(auto j : s) {
                    if((j<'0' || j>'9') && (j<'a' || j>'f') && (j<'A' || j>'F')) {
                        ok = true; break; 
                    }
                }
                if(s.empty() || s.size() > 4 || ok ) return "Neither";
            }
            if(cnt != 8) return "Neither";
            return "IPv6";
        }

        return "Neither";
    }
};