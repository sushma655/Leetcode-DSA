class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& candidates, int target,
               int index, vector<int>& current) {

        // Target complete ho gaya
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Target se chhota ho gaya
        if (target < 0) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Agar number target se bada hai
            if (candidates[i] > target)
                break;

            // Current number choose karo
            current.push_back(candidates[i]);

            // Same number dobara use kar sakte hain,
            // isliye i hi pass karenge
            solve(candidates, target - candidates[i], i, current);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        sort(candidates.begin(), candidates.end());

        vector<int> current;

        solve(candidates, target, 0, current);

        return result;
    }
};