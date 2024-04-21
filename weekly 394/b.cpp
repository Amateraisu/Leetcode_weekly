class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>lowercase(26, -1);
        vector<int> uppercase(26, -1);
        int n = word.size();
        for (int i = 0; i  < n; ++i) {
            char c = word[i];
            if (std::islower(c)) {
                lowercase[c - 'a'] = i;
            }
        }
        for (int i = n; i >= 0; --i) {
            char c = word[i];
            if (std::isupper(c)) {
                uppercase[c - 'A'] = i;
            }
        }


        int res = 0;

        // Check if any letter appears in both forms
        for (int i = 0; i < 26; i++) {
            if (lowercase[i] != -1 && uppercase[i] != -1 && lowercase[i] < uppercase[i]) {
                // cout << i << ' ' << lowercase[i] << ' ' << uppercase[i] << '\n';
                ++res;
            }
        }
        return res;
    }
};
