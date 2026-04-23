class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int maxLen = 0;
        unordered_set<char> us;

        while (j < s.length()) {
            if (us.find(s[j]) == us.end()) {
                us.insert(s[j]);
                maxLen = max(maxLen, j - i + 1);
                j++;
            } else {
                us.erase(s[i]);
                i++;
            }
        }
        return maxLen;
    }
};