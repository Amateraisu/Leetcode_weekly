class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int cur = 0;
        int t = x;
        while (t > 0) {
            cur += t % 10;
            t /= 10;
        }
        if (x % cur == 0) {
            return cur;
        }
        return -1;
    }
};
