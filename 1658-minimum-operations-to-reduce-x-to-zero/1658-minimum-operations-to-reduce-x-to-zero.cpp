class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        long long total = 0;

        for (int num : nums) {
            total += num;
        }

        long long target = total - x;

        // Agar target negative hai
        if (target < 0)
            return -1;

        // target = 0 => poora array remove karna hoga
        if (target == 0)
            return n;

        int left = 0;
        long long sum = 0;
        int maxLen = -1;

        // Sliding Window
        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum > target && left <= right) {
                sum -= nums[left];
                left++;
            }

            if (sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        if (maxLen == -1)
            return -1;

        return n - maxLen;
    }
};