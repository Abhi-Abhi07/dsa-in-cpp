/*
https://leetcode.com/problems/maximize-sum-of-squares-of-digits/
*/
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string str = "";
        while(num && sum >= 0){
            if(sum >= 9)
                str.push_back('9');
            else
                str.push_back(sum + '0');
            
            sum -= 9;
            num--;
        }

        if(sum > 0) return "";

        while(num){
            str.push_back('0');
            num--;
        }
        return str;
    }
};