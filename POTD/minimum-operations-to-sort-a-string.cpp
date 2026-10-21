/*
Problem link: https://leetcode.com/problems/minimum-operations-to-sort-a-string/
*/

class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        string x = s;

        sort(x.begin(),x.end());
        if(x == s)  return 0;
        if(n == 2)  return -1;

        x = s;
        string y = s;

        sort(x.begin(),x.end()-1);
        if(x[n-2] <= x[n-1]) return 1;

        sort(y.begin()+1,y.end());
        if(y[0] <= y[1]) return 1;

        sort(x.begin()+1,x.end());
        if(x[0] <= x[1]) return 2;

        sort(y.begin(),y.end()-1);
        if(y[n-2] <= y[n-1]) return 2;

        return 3; 
    }
};