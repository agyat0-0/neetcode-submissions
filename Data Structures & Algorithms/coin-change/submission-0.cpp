class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount +1, amount +1);
        dp[0] = 0;
        for (int am = 1; am < amount + 1; am++)
        {
            for (int& coin: coins)
            {
                if (am - coin >= 0 )
                {
                    dp[am] = min(dp[am-coin]+1, dp[am]);
                }
            }
        }
        if (dp[amount]>amount) return -1;
        return dp[amount];
    }
};
