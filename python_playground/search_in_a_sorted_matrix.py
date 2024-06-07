def searchMatrix( matrix: List[List[int]], target: int) -> bool:
    l=0
    r=len(matrix)-1
    while l<=r:
        mid=(l+r)//2
        if matrix[mid]==target:
            return True
        elif matrix[mid][0]>target:
            found=binary_search(matrix[mid], target)
            if found:
                return found
            else:
                r=mid-1
                continue
        else:
            found=binary_search(matrix[mid], target)
            if found:
                return found
            else:
                l=mid+1
                continue
    return False



def binary_search(array: List[int], target: int)->bool:
    l=0
    r=len(array)-1

    while l<=r:
        mid=(l+r)//2
        if array[mid]==target:
            return True
        elif array[mid]>target:
            r=mid-1
        else:
            l=mid+1
    return False
