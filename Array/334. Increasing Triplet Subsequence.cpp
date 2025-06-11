class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first=INT_MAX,second=INT_MAX;
        for(int n:nums){
            if(n<=first) first=n;
            else if(n<=second) second=n;
            else return true;
        }return false;
    }
};


// class Solution {
// public:
//     bool increasingTriplet(vector<int>& nums) {
//         int next;
//         int prev = nums[i];
//         int cnt = 1;
//         for(int i=1;i<nums.size();i++){
//             next = nums[i];
//             if(prev<next){
//                 cnt++;
//             }
//             else{
//                 cnt = 1;
//             }
//         }
//         return false;
//     }
// };
