class Solution {
private:
    int convert(string s, int idx,char ch){
        char c = s[idx];
        for(int i=0;i<s.size();i++){
            if(s[i] == c){
                s[i] = ch;
            }
        }

        //convert to number
        int num  = 0;
        for(int i=0;i<s.size();i++){
            num = num*10 + (s[i] - '0');
        }

        cout<<num<<endl;
        return num;
    }
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int indexh = 0;
        bool ih = false;
        int indexl = 0;
        char lowchar = '1';
        bool il = false;

        for(int i=0;i<s.size();i++){
            if(s[i] != '9' && !ih){
                indexh = i;
                ih = true;
            }
            if(s[0] != '1' && !il){
                indexl = i;
                il = true;
            }
            if(s[i] != '1'&& s[i] != '0' && !il){
                indexl = i;
                il = true;
                lowchar = '0';
            }

            if(ih && il){
                break;
            }
        }

        int max = convert(s,indexh,'9');
        int min = convert(s,indexl,lowchar);

        return max-min;
    }
};
