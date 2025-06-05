class Solution(object):
    def applyOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        for i in range(n - 1):
            if nums[i] == nums[i + 1]:
                nums[i] *= 2
                nums[i + 1] = 0

        res = []
        num_zeros = 0
        for num in nums:
            if num == 0:
                num_zeros += 1
            else:
                res.append(num)
        for i in range(num_zeros):
            res.append(0)
        return res