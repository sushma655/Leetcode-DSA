class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();

        // 32-bit integer range
        int INT_MAX_VAL = INT_MAX;
        int INT_MIN_VAL = INT_MIN;

        // Step 1: Ignore leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check sign
        int sign = 1;

        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        } 
        else if (i < n && s[i] == '+') {
            i++;
        }

        // Step 3: Convert digits
        long result = 0;

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Step 4: Handle overflow
            if (result > (INT_MAX_VAL - digit) / 10) {
                return sign == 1 ? INT_MAX_VAL : INT_MIN_VAL;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};