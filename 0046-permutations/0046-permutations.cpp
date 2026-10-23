class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        backtrack(nums, used, current, ans);

        return ans;
    }

    void backtrack(vector<int>& nums, vector<bool>& used,
                   vector<int>& current, vector<vector<int>>& ans) {

        // If permutation contains all numbers
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }

            // Choose number
            current.push_back(nums[i]);
            used[i] = true;

            // Explore next position
            backtrack(nums, used, current, ans);

            // Backtrack
            current.pop_back();
            used[i] = false;
        }
    }
};