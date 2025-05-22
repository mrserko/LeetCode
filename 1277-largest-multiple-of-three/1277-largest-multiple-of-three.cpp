class Solution {
public:
    string makeNum(std::vector<int>freq) {
        std::string res;
        for (int i = 9; i >= 0; --i) {
        for (int j = 0; j != freq[i]; ++j) {
                    res.push_back('0' + i);
            }
        }
        if (res.empty()) {
            return res;
        }
        return res[0] == '0' ? "0" : res;
    }

    string largestMultipleOfThree(vector<int>& digits) {
        std::vector<int> freq(10, 0);
        int sum = 0;
        for (auto digit: digits) {
            freq[digit]++;
            sum += digit;
        }
        if (sum % 3 == 1) {
            if (freq[1] > 0) {
                --freq[1];
            } else if (freq[4] > 0) {
                --freq[4];
            } else if (freq[7] > 0) {
                --freq[7];
            } else if (freq[2] > 1) {
                freq[2] -= 2;
            } else if (freq[2] > 0 and freq[5] > 0) {
                --freq[2];
                --freq[5];
            } else if (freq[5] > 1) {
                freq[5] -= 2;
            } else if (freq[2] > 0 and freq[8] > 0) {
                --freq[2];
                --freq[8];
            } else if (freq[5] > 0 and freq[8] > 0) {
                --freq[5];
                --freq[8];
            } else {
                freq[8] -= 2;
            }
        }
        if (sum % 3 == 2) {
            if (freq[2] > 0) {
                --freq[2];
            } else if (freq[5] > 0) {
                --freq[5];
            } else if (freq[8] > 0) {
                --freq[8];
            } else if (freq[1] > 1) {
                freq[1] -= 2;
            } else if (freq[1] > 0 and freq[4] > 0) {
                --freq[1];
                --freq[4];
            } else if (freq[4] > 1) {
                freq[4] -= 2;
            } else if (freq[1] > 0 and freq[7] > 0) {
                --freq[1];
                --freq[7];
            } else if (freq[4] > 0 and freq[7] > 0) {
                --freq[4];
                --freq[7];
            } else {
                freq[7] -= 2;
            }
        }

        return makeNum(freq);
    }
};