class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        int now = gain[0];
        maxi = max(now,maxi);
        for (int i = 0; i < gain.size() - 1; i++) {
            maxi = max(maxi, gain[i + 1] + now);
            now = gain[i + 1] + now;
            cout<<now<<endl;
        }
        return maxi;
    }
};
