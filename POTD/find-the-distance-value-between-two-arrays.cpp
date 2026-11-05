// Problem link: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = arr1.size();
        for(int &x: arr1){
            bool hasCloseElement = false;
            for(int &y: arr2){
                if(abs(x - y) <= d){
                    hasCloseElement = true;
                    break;
                }
            }
            cnt -= hasCloseElement;
        }
        return cnt;
    }
};