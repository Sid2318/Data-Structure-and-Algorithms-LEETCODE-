class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum =0;
        for(int i=0;i<nums.size();i++){
            totalSum += nums[i];
        }

        int leftsum =0;
        if(leftsum == (totalSum - nums[0] - leftsum)){
            return 0;
        }
        for(int i=0;i<nums.size()-1;i++){
            leftsum += nums[i];
            if(leftsum == (totalSum - nums[i+1] - leftsum)){
                return i+1;
            }
        }

        return -1;
    }
};
