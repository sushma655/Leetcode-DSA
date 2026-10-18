class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0, current, ans);

        return ans;
    }

    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& current, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicate combinations
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Since sorted, no need to check larger numbers
            if (candidates[i] > target) {
                break;
            }

            current.push_back(candidates[i]);

            // i + 1: each number can be used only once
            backtrack(candidates, target - candidates[i],
                      i + 1, current, ans);

            // Backtrack
            current.pop_back();
        }
    }
};