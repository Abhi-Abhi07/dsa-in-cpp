// Problem link: https://leetcode.com/problems/calculate-digit-sum-of-a-string/

class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length() > k){
            string next = "";
            int i=0;
            while(i<s.length()){
                int digit_sum = 0;
                int x = k;
                while(x-- && i < s.length())
                    digit_sum += (s[i++]-'0');
                
                next += to_string(digit_sum);
            }
            s = next;
        }
        return s;
    }
};