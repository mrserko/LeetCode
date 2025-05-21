class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        std::set<int> seen;
        int sub = 0;
        for (int num: nums) {
            if (num < k) {
                return -1;
            }
            if (num == k) {
                sub = -1;
            }
            seen.emplace(num);
        }
        return seen.size() + sub;
    }
};