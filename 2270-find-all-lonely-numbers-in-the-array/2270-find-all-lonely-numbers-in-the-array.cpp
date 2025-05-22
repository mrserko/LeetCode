class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        // std::set<int> seen(nums.begin, nums.end());
        // nums.clear();
        // nums = std::vector<int>(seen.begin(), seen.end());
        nums.push_back(-2);
        nums.push_back(10000000);
        std::sort(nums.begin(), nums.end());
        std::vector<int> res;
        for (int i = 1; i != nums.size() - 1; ++i) {
            if (nums[i] == nums[i - 1] or nums[i] == nums[i + 1]) {
                continue;
            }
            if (nums[i] != nums[i - 1] + 1 and nums[i] != nums[i + 1] - 1) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};