class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int mini = INT_MAX;

        for (int i = 0; i < arr.size() - 1; i++) {
            mini = min(mini, arr[i + 1] - arr[i]);
        }

        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i + 1] - arr[i] == mini) {
                ans.push_back({arr[i], arr[i + 1]});
            }
        }
        
        return ans;
    }
};
