// Problem link: https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/

class Solution {
public:
    bool checkString(string s) {
        int len = s.length();
        if(len == 1)    return true;
        
        for(int i=1; i<len; i++)
            if(s[i-1] > s[i])   
                return false;
        
        return true;
    }
};