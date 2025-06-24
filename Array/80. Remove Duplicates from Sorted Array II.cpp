class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; // Already valid if size is <= 2

        int index = 2; // Start from third position

        for (int i = 2; i < n; ++i) {
            // If current number is not equal to the number two places before, it's allowed
            if (nums[i] != nums[index - 2]) {
                nums[index] = nums[i];
                index++;
            }
        }

        return index;
    }
};




// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int curr =0;
//         int cnt =0;
//         int prev = 0;
//         int a =0;

//         for(int i=0;i<nums.size();i++){
//             if((nums[prev] != nums[curr])){
//                 if(cnt<2){
//                     a = 2;
//                 }
//                 else{
//                     a = cnt;
//                 }
//                 int b = nums[curr];
//                 cout<<b<<" Cur = "<<curr<<endl;
//                 for(int j=0;j<a;j++){
//                     nums[curr+j] = b;
//                 }
//                 curr = prev;
//                 cnt = 0;
//             }
//             cnt++;
//             prev++;
//         } 

//         return curr;
//     }
// };
