class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;

        if (words.empty() || s.empty()) {
            return ans;
        }

        int n = s.size();
        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (n < totalLen) return ans;

        unordered_map<string, int> wordFreq;

        for (const string& word : words) {
            wordFreq[word]++;
        }

        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int count = 0;
            unordered_map<string, int> seen;

            for (int right = i; right + wordLen <= n;
                 right += wordLen) {

                string word = s.substr(right, wordLen);

                if (wordFreq.find(word) == wordFreq.end()) {
                    seen.clear();
                    count = 0;
                    left = right + wordLen;
                    continue;
                }

                seen[word]++;
                count++;

                while (seen[word] > wordFreq[word]) {
                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    count--;
                    left += wordLen;
                }

                if (count == wordCount) {
                    ans.push_back(left);

                    string leftWord = s.substr(left, wordLen);
                    seen[leftWord]--;
                    count--;
                    left += wordLen;
                }
            }
        }

        return ans;
    }
};