class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        vector<int> freq;
        for (auto& p : freqMap) {
            freq.push_back(p.second);
        }

        sort(freq.begin(), freq.end(), greater<int>());

        int deletions = 0;
        for (int i = 1; i < freq.size(); ++i) {
            if (freq[i] >= freq[i - 1]) {
                int del = max(0, freq[i - 1] - 1);
                deletions += freq[i] - del;
                freq[i] = del;
            }
        }

        return deletions;
    }
};

// class Solution {
// public:
//     int minDeletions(string s) {
//         unordered_map<char,int> mpp;
//         for(int i=0;i<s.size();i++){
//             mpp[s[i]]++;
//         }

//         vector<int> v;
//         for(auto& m: mpp){
//             v.push_back(m.second);
//         }

//         sort(v.begin(),v.end());

//         int cnt =0;
//         for(int i=v.size()-1;i>=0;i--){
//             cout<<v[i]<<endl;
//             if(i>0 && v[i] == v[i-1]){
//                 v[i-1]--;
//                 cnt++;
//             }
//             else if(i>0 && v[i-1] > v[i]){
//                 cout<<"fege  "<<(v[i-1]-v[i])<<endl;
//                 v[i-1] = v[i-1] - (v[i-1]-v[i]+1);
//                 cnt += (v[i-1]-v[i]+1);
//             }
//         }

//         return cnt;
//     }
// };
