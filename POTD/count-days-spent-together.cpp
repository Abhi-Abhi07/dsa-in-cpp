// problem link : https://leetcode.com/problems/count-days-spent-together/description/


class Solution {
public:

    int dayOfYear(int m, int d, vector<int>&daysInMonths) {
        int totalDays = d;
        for (int i = 1; i < m; ++i) {
            totalDays += daysInMonths[i];
        }
        return totalDays;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string x = max(arriveAlice, arriveBob);
        string y = min(leaveAlice, leaveBob);

        if(x > y)   return 0;

        int m1 = stoi(x.substr(0, 2));
        int d1 = stoi(x.substr(3, 2));
        
        int m2 = stoi(y.substr(0, 2));
        int d2 = stoi(y.substr(3, 2));

        vector<int>daysInMonths = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int totalDays1 = dayOfYear(m1, d1, daysInMonths);
        int totalDays2 = dayOfYear(m2, d2, daysInMonths);

        return abs(totalDays2 - totalDays1) + 1;
    }
};