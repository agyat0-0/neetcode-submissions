class Solution {
public:
    bool isPalindrome(string s) {
        string newstring = "";
        for (auto c : s)
        {
            if (isalnum(c))
            {
                newstring += tolower(c);
            }
        }
        return newstring == string(newstring.rbegin(), newstring.rend());
    }
};
