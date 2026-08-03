class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        for (auto ch: s)
        {
            if (ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
                continue;
            }
            if (st.empty())return false;
            else {char last = st.top();
            st.pop();
            if (ch == ')' &&  last!= '(')
            {
                return false;
            }
            else if (ch == ']' &&  last!= '[')
            {
                return false;
            }
            else if (ch == '}' &&  last!= '{')
            {
                return false;
            }}
        }
        if (!st.empty())return false;
        return true;
    }
};
