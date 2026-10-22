class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp = {}
        for num in nums:
            mp[num] = mp.get(num, 0) +  1
        answer = sorted(list(mp.keys()), key = lambda x : mp[x], reverse = True)[:k]
        return answer