class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int min = nums[0];
        vector<vector<int>> ans;
        vector<int> v;

        for(int i=0;i<nums.size();i++){
            if(nums[i] - min > k){
                ans.push_back(v);
                v.erase(v.begin(),v.end());
                min = nums[i];
            }
            v.push_back(nums[i]);
        }

        if(v.size()>0){
           ans.push_back(v); 
        }
        
        return ans.size();
    }
};
