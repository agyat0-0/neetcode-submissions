class Solution {
public:
    int rob(vector<int>& nums) {
        int numHouses = nums.size();
        if (numHouses == 0) return 0;
        else if(numHouses == 1)return nums[0];
        nums[1] = max(nums[0], nums[1]);
        for(int house = 2; house<numHouses; house++)
        {
            nums[house] = max(nums[house-2]+nums[house], nums[house-1]);
        }
        return nums[numHouses-1];
    }
};
