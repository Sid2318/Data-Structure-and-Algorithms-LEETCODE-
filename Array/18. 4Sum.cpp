class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        vector<int> mini(4);

        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k = j+1;k<nums.size();k++){
                    for(int l = k+1;l<nums.size();l++){
                        long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                        if(sum == (long long)target ){
                            mini[0] = nums[i];
                            mini[1] = nums[j];
                            mini[2] = nums[k];
                            mini[3] = nums[l];
                            if(find(ans.begin(),ans.end(),mini) == ans.end()){
                                ans.push_back(mini);
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};
