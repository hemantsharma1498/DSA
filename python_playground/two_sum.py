from typing import List

def two_sum(nums: List[int], target: int) -> List[int]:
    iterated_nums={}
    for i in range(0, len(nums)):
        diff=target-nums[i];
        if diff in iterated_nums:
            return [iterated_nums[diff],i]
        iterated_nums[nums[i]]=i
    
    return []

print(two_sum([1,2,3,4,5,6], 10))


    
