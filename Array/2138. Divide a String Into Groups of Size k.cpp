class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string a;
        for(int i=0;i<s.size();i++){
            a += s[i];
            if((i+1)%k == 0){
                ans.push_back(a);
                a.erase(a.begin(),a.end());
            }
        }

        if(a.size()>0){
            int size = a.size();
            while(size != k){
                a += fill;
                size++;
            }
            ans.push_back(a);
        }

        return ans;
    }
};
