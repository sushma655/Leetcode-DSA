class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {

            // Push opening brackets
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {

                // If stack is empty
                if (st.empty())
                    return false;

                char top = st.top();
                st.pop();

                // Check matching brackets
                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // Valid if stack becomes empty
        return st.empty();
    }
};