class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }

        int maxodd =0;
        int mineven = INT_MAX;
        for(auto& m : mpp){
            if(m.second%2 == 0){
                mineven = min(mineven,m.second);
            }
            else{
                maxodd = max(maxodd,m.second);
            }
        }

        return maxodd - mineven;
    }
};
