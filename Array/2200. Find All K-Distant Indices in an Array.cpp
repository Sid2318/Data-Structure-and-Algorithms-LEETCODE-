class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> ans;
        vector<int> v;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == key){
                v.push_back(i);
                // cout<<i<<endl;
            }
        }


        vector<int> s;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<v.size();j++){
                if(abs(i-v[j])<= k){
                    ans.insert(i);
                    cout<<i<<endl;
                    break;
                }
            }
        }

        for(auto& i : ans){
            s.push_back(i);
        }

        sort(s.begin(),s.end());

        return s;
    }
};
