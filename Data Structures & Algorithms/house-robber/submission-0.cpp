class Solution {
public:
    int rob(vector<int>& nums) {
        int numHouses = nums.size();
        if (numHouses == 0) return 0;
        else if(numHouses == 1)return nums[0];
        vector<int> moneyrobbed(numHouses, 0);
        moneyrobbed[0] = nums[0];
        moneyrobbed[1] = max(nums[0], nums[1]);
        for(int house = 2; house<numHouses; house++)
        {
            moneyrobbed[house] = max(moneyrobbed[house-2]+nums[house], moneyrobbed[house-1]);
        }
        return moneyrobbed[numHouses-1];
    }
};
