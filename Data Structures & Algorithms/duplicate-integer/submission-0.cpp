class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int i=0; i<size(nums); ++i)
        {
            if (hash[nums[i]])
            {
                return true;
            }
            hash[nums[i]] = 1;
        };
        return false;
    }
};