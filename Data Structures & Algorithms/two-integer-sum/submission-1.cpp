class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> hash;
        vector <int> answer; 
        for (int i = 0; i<nums.size(); i++)
        {
            hash[nums[i]] = i;
        }

        for (int i = 0; i<nums.size(); i++)
        {
            int j = hash[target - nums[i]];
            if (j && i != j)
            {
                answer.push_back(i);
                answer.push_back(j);
                return answer;
            }
        }
    }
};
