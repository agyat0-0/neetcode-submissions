class Solution {
public:
    bool isAnagram(string s, string t) {
    unordered_map <char, int> hash_s; 
    unordered_map <char, int> hash_t; 
    for (auto ch : s)
    {
        hash_s[ch]++;
    }
    for (auto ch : t)
    {
        hash_t[ch]++;
    }
    return hash_s == hash_t;
    }
};
