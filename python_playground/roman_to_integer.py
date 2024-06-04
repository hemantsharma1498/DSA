def romanToInt(s):
        key_mapper={
            "I":1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M":1000
        }
        special_cases={
            "IV": 4,
            "IX": 9,
            "XL": 40,
            "XC": 90,
            "CD": 400,
            "CM": 900
        }
        num=0
        i=len(s)-1
        while i>=0:
            substr=""
            if i-1>=0:
                substr=s[i-1]+s[i]
            if substr in special_cases:
                num+=special_cases[substr]
                i-=2
            else: 
                num+=key_mapper[s[i]]
                i-=1
        print(num)
        return num


romanToInt("MMMXLV")