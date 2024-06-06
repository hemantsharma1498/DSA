

def hasDuplicate(nums:List[int])->bool:
    dictionary={}
        for num in nums:
            if num in dictionary:
                dictionary[num]+=1
            else:
                dictionary[num]=1
        print(dictionary)
        for k, v in dictionary.items():
            if v>1:
                return False
        return True

hasDuplicate([1,2,3,4,5])
