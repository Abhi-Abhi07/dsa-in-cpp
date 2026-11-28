// Problem link: https://leetcode.com/problems/stone-removal-game/

class Solution {
public:
    bool canAliceWin(int n) {
        int x = 10;
        bool alice_win = false;
        while(x <= n){
            alice_win = !alice_win;
            n -= x--;
        }
        return alice_win;
    }
};