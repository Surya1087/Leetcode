class Solution {
public:
    string removeOuterParentheses(string S) {
//         string result = "";
//         stack<char> st;
//         for(char ch: S) {
//             if(ch == '('){
//                 if(!st.empty()) result += ch;
//                 st.push(ch);
//             }
//             else{
//                 st.pop();
//                 if(!st.empty())result += ch;
//             }
//         }
//         return result;
//     }
// };

        string res;
        int opened = 0;
        for (char c : S) {
            if (c == '(' && opened++ > 0) res += c;
            if (c == ')' && opened-- > 1) res += c;
        }
        return res;
    }
};