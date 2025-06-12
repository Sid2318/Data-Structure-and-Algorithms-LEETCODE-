class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi = abs(nums[nums.size()-1] - nums[0]);
        for(int i=0;i<nums.size()-1;i++){
            maxi = max(abs(nums[i+1]-nums[i]),maxi);
        }
        return maxi;
    }
};
