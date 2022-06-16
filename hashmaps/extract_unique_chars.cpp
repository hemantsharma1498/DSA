#include<unordered_map>
#include<string>
#include<bits/stdc++.h>
string uniqueChar(string str) {
    string ans="";
    unordered_map<char, int> map;
    
	for(int i=0;i<str.size();i++){
        map[str[i]]++;
        if (map[str[i]]==1)
            ans+=str[i];
    }

    return ans;
}
