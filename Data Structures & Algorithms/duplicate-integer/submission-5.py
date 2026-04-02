class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        mySet = defaultdict(int)
        for i in range(len(nums)):
            mySet[nums[i]] = mySet[nums[i]]+1
        
        for i in range(len(nums)):
            if(mySet[nums[i]]>1):
                return True
        return False
        