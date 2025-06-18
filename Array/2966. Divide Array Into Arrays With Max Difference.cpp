class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());

        vector<int> mini(3);
        int j =0;

        for(int i=0;i<nums.size();i++){
            mini[j] = nums[i];
            j++;
            if((i+1)%3 == 0){
                j =0;
                v.push_back(mini);
            }
        }

        //The difference between any two elements in one array is less than or equal to k
        for(int i=0;i<v.size();i++){
            if((v[i][0] - v[i][1] > k) || (v[i][0] - v[i][2] > k) || (v[i][1] - v[i][2] > k) ||
               (v[i][1] - v[i][0] > k) || (v[i][2] - v[i][0] > k) || (v[i][2] - v[i][1] > k) ){
                    return {};
               }
        }

        return v;
    }
};
