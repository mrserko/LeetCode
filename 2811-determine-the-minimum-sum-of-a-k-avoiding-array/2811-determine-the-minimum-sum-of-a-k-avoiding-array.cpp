class Solution {
public:
    int minimumSum(int n, int k) {
        int res = 0;
        int i = 1;
        int left = n;
        while (i <= k / 2 and i <= n) {
            res += i;
            ++i;
            --left;
        }
        for (int i = k; i < k + left; ++i) {
            res += i;
        }
        return res;

    }
};