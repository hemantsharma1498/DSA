def lengthOfLongestSubstring(s):
    l=0
    array=[]
    max_length=0
    
    for r in range(len(s)):
        if s[r] in array:
            while l<r and s[r] in array:
                array.remove(s[l])
                l+=1
        array.append(s[r])
        max_length=max(max_length, r-l+1)


    print(max_length)
    return max_length

lengthOfLongestSubstring("bbbbb")
