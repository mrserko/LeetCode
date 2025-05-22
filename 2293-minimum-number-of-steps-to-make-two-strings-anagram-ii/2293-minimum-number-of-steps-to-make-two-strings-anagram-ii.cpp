class Solution {
public:
    int minSteps(string s, string t) {
        std::vector<int> letters1(26, 0);
        std::vector<int> letters2(26, 0);
        for (auto letter: s) {
            letters1[letter - 'a']++;
        }
        for (auto letter: t) {
            letters2[letter - 'a']++;
        }
        int res = 0;
        for (int i = 0; i != 26; ++i) {
            res += std::abs(letters1[i] - letters2[i]);
        }
        return res;
    }
};