def valid_paranthesis(s: str)->bool:
    if len(s)%2!=0:
        return False
    bracket_map={"}":"{", "]":"[", ")":"("}
    stack=[]
    for c in s:
        if c not in bracket_map:
            stack.append(c)
            continue
        if len(stack)==0 or stack[-1]!=bracket_map[c]:
            return False
        stack.pop()
    return not stack
