class Solution {
public:
    bool canBeFormed(std::string& s, string chars) {
        std::unordered_map<char, int> freq;
        for (auto c: chars) {
            freq[c]++;
        }
        for (char c: s) {
            if (freq.find(c) == freq.end() or freq[c] == 0) {
                return false;
            }
            --freq[c];
        }
        return true;
    }

    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        for (auto& word: words) {
            if (canBeFormed(word, chars)) {
                res += word.size();
            }
        }
        return res;
    }
};