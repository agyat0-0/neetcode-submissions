class Solution {
private:
    bool canEat(vector<int> piles, int h, int k)
    {
        int pile = 0;
        long long time = 0;
        while (pile < piles.size())
        {
            time += (piles[pile] + k - 1 )/ k;
            pile ++;
        }
        return time <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBananas = 0;
        if (piles.size() > h)return -1;
        for (int bananas: piles)
        {
            if (bananas > maxBananas)
            {
                maxBananas = bananas;
            }
        }
        int minRate = 1;
        int maxRate = maxBananas;
        int rate = minRate + ((maxRate - minRate)/ 2);
        int result = maxRate;
        while (minRate <= maxRate)
        {
            rate = minRate + ((maxRate - minRate)/ 2); 
            if(canEat(piles, h, rate))
            {
                result = rate;
                maxRate = rate - 1;
            }
            else
            {
                minRate = rate + 1;
            }
        }
        return result;
    }
};
