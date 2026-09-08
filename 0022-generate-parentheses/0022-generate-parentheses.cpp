class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;

        backtrack(result, current, 0, 0, n);

        return result;
    }

private:
    void backtrack(vector<string>& result, string& current,
                   int open, int close, int n) {

        // If the string has 2*n characters, it's complete
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '(' if we still have opening brackets available
        if (open < n) {
            current.push_back('(');
            backtrack(result, current, open + 1, close, n);
            current.pop_back();
        }

        // Add ')' only if it won't make the sequence invalid
        if (close < open) {
            current.push_back(')');
            backtrack(result, current, open, close + 1, n);
            current.pop_back();
        }
    }
};