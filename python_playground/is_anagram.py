def isAnagram(s: str, t: str)->bool:
    if len(s) != len(t):
        return False
    letters_histogram={}
    s_sorted=''.join(sorted(s))
    t_sorted=''.join(sorted(t))

    x=s_sorted.replace(t_sorted, "")
    if len(x)>1:
        return False
    return True

    

print(isAnagram("jam", "majj"))

