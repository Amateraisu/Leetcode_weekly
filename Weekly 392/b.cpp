class Solution {
public:
    string getSmallestString(string s, int k) {
        int n = s.size();
        string res =s;
        auto g = [](char a , char b) {
            int a2 = a - 'a';
            int b2 = b - 'a';

            return min(abs(a2 - b2), 25 - abs(a2 - b2 ) + 1);
        };
        // cout << g('z', 'e');
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (s[i] - 'a'); ++j) {
                if (g('a' + j, s[i]) <= k) {
                    res[i] = 'a' + j;
                    k-= g('a' + j, s[i]);
                    break;
                }
            }

        }
        return res;
    }
};
