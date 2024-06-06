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

def lengthOfLongestSubstringWithoutArray(s):
    substr=""
    max_len=0
    for i, l in enumerate(s):
        if l in substr:
            w=0
            while w<i and l in substr:
                substr=substr[1:]
                w+=1
        substr+=l
        max_len=max(max_len, len(substr))
    return max_len   



lengthOfLongestSubstring("1a2b3c4d5e6f7g8h9i0j1k2l3m4n5o6p7q8r9s0t1u2v3w4x5y6z7A8B9C0D1E2F3G4H5I6J7K8L9M0N1O2P3Q4R5S6T7U8V9W0X1Y2Z3")
