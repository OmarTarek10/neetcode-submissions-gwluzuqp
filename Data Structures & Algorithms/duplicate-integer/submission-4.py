class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        mySet = set()
        for i in range(len(nums)):
            cond = nums[i] not in mySet
            print(f"{cond}\n")
            if cond:
                mySet.add(nums[i])
            else:
                return True
        return False