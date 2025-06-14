class Solution {
private:
    int number(string s,int idxRep,char ch){
        char change = s[idxRep];
        for(int i=0;i<s.size();i++){
            if(change == s[i]){
                s[i] = ch;
            }
        }

        //convert to int
        int num =0;
        for(int i=0;i<s.size();i++){
            num = num*10 + (s[i]-'0');
        }
        cout<<num<<endl;
        return num;
    }
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int idxRep;
        for(int i=0;i<s.size();i++){
            if(s[i] != '9'){
                idxRep = i;
                break;
            }
        }
        cout<<idxRep<<endl;
        int max = number(s,idxRep,'9');
        int min = number(s,0,'0');
        return max-min;
    }
};
