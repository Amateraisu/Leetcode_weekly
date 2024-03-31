class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        using ll = long long;
        ll res = 0;
        int l = 0;
        int f = -1; // when f is 1,
        for (int r = 0; r < nums.size(); ++r) {
            if (f == 1 && nums[r] != 0) {
                l = r;
            }  else if (f == 0 && nums[r] != 1) {
                l = r;
            }
            f = nums[r];

            res += (r - l + 1);
            // cout << "lr " << l << ' ' << r << '\n';
        }





        return res;
    }
};
