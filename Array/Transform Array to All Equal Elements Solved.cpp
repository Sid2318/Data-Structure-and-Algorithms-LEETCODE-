class Solution {
public:
    int countFlips(vector<int> nums, int target) {
        int flips = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] != target) {
                // Flip nums[i] and nums[i+1]
                nums[i] *= -1;
                nums[i + 1] *= -1;
                flips++;
            }
        }
        // Check if all are equal to target
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != target) return INT_MAX; // Not achievable
        }
        return flips;
    }

    bool canMakeEqual(vector<int>& nums, int k) {
        int toAll1 = countFlips(nums, 1);
        int toAllMinus1 = countFlips(nums, -1);
        return min(toAll1, toAllMinus1) <= k;
    }
};

// class Solution {
// public:
//     bool canMakeEqual(vector<int>& nums, int k) {
//         int i = 0;
//         int j = k;
//         int cnt1 = 0;
//         int cnt2 = 0;
//         vector<int> dum = nums;

//         // Try to make all 1
//         while ((k != 0 && i < nums.size() - 1) ||
//                (j != 0 && i < dum.size() - 1)) {
//             if (k != 0 && i < nums.size() - 1) {
//                 if (nums[i] == -1) {
//                     // cout << i << "= " << nums[i]<<endl;
//                     if (i + 1 < nums.size()) { // 🛠️ Check bound
//                         // cout << "  " << i + 1 << " = " << nums[i + 1] << endl;
//                         nums[i] *= -1;
//                         nums[i + 1] *= -1;
//                         // cout << i << "= " << nums[i] << "  " << i + 1 << " = "
//                         //      << nums[i + 1] << endl;
//                         k--;
//                     }
//                 }
//             }
//             if (j != 0 && i < dum.size() - 1) {
//                 if (dum[i] == 1) {
//                     cout << i << "=  " << dum[i]<<" dum"<<endl;
//                     if (i + 1 < dum.size()) { // 🛠️ Check bound
//                         cout << "  " << i + 1 << " = " << dum[i + 1] << endl;
//                         dum[i] *= -1;
//                         dum[i + 1] *= -1;
//                         cout << i << "= " << dum[i] << "  " << i + 1 << " = "
//                              << dum[i + 1] << endl;
//                         j--;
//                     }
//                 }
//             }
//             i++;
//         }

//         for (i = 0; i < nums.size(); i++) {
//             if (nums[i] == 1) {
//                 cnt1++;
// // };©leetcode
