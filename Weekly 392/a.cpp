class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1;
        int dec = 1;
        int n = nums.size();
        int res = 1;
        for (int i = 1 ; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++inc;
            } else {
                inc = 1;
            }

            if (nums[i] < nums[i - 1]) {
                ++dec;
            } else {
                dec = 1;
            }

            res = max(res, dec);
            res = max(res, inc);
        }
        return res;
    }
};
