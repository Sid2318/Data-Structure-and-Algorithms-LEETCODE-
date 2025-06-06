class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int max_sum =0;
        int sum =nums[0];
        max_sum = max(max_sum, sum);
        for(int i=1;i<nums.size();i++){
            if(nums[i] <= nums[i-1]){
                sum = 0;
            }
            sum += nums[i];
            max_sum = max(max_sum, sum);
            cout<<nums[i]<<" "<<max_sum<<endl;
        }

        return max_sum;
    }
};
