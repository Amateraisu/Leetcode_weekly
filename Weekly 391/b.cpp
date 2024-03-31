class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = 0;
        int empty = 0;
        while (numBottles >= numExchange) {
            numBottles -= numExchange;
            res += numExchange;
            ++numExchange;
            ++numBottles;

        }
        if (numBottles) res += numBottles;
        return res;
    }
};
