



def binary_search_iterative(num, nums_array)->bool:
    l=0
    r=len(nums_array)

    while l<r:
        m=(l+r)//2
        if num==nums_array[m]:
            return True
        elif num>nums_array[m]:
            l=m
        else:
            r=m

    return False

def binary_search_recursive(num, nums_array, l, r)->bool:
    if l>r:
        return False
    
    m=(l+r)//2
    if num==nums_array[m]:
        return True
    elif num > nums_array[m]:
        return binary_search_recursive(num, nums_array, m+1, r)
    else: return binary_search_recursive(num, nums_array, l, m-1)


iter=binary_search_iterative(8, [1,2,3,4,5,6,7,8])
rec=binary_search_recursive(8, [1,2,3,4,5,6,7,8], 0, len([1,2,3,4,5,6,7,8]))
print(rec)
