class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        unordered_map <char, char> br = {
            {'}', '{'},
            {')', '('},
            {']', '['}
        };
        for (auto ch : s)
        {
            if (br.count(ch))
            {
                if (st.empty() || st.top()!= br[ch])return false;
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
        return st.empty();
    }
};
