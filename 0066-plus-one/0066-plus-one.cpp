class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        // Last digit se start karo
        for (int i = digits.size() - 1; i >= 0; i--) {

            // Agar digit 9 nahi hai
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // Agar digit 9 hai, to 0 kar do
            digits[i] = 0;
        }

        // Agar sabhi digits 9 the
        digits.insert(digits.begin(), 1);

        return digits;
    }
};