class Solution {
public:
    int numberOfSpecialChars(string str) {
        bool lowercase[26] = {false};
        bool uppercase[26] = {false};

        for (char c : str) {
            if (std::islower(c)) {
                lowercase[c - 'a'] = true;
            } else if (std::isupper(c)) {
                uppercase[c - 'A'] = true;
            }
        }

        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (lowercase[i] && uppercase[i]) {
                ++res;
            }
        }
        return res;

    }
};
