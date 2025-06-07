class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int,vector<int>> mpp;
        for(int i = 0;i<x.size();i++){
            mpp[x[i]].push_back(y[i]);
        }

        vector<int> largest;
        for(auto& m : mpp){
            vector<int> v = m.second;
            sort(v.begin(),v.end());
            largest.push_back(v[v.size()-1]);
        }

        if(largest.size()<3){
            return -1;
        }
        sort(largest.begin(),largest.end());
        int n = largest.size();
        return largest[n-1] + largest[n-2] + largest[n-3];
    }
}
