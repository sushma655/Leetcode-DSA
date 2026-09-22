class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;       // nums1 ke actual elements ka last index
        int j = n - 1;       // nums2 ka last index
        int k = m + n - 1;   // nums1 mein last position

        // Jab tak nums2 mein elements hain
        while (j >= 0) {

            // nums1 ka element bada hai
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }
    }
};