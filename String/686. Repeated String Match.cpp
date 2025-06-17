class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = a;
        int count = 1;

        // Repeat 'a' until it's length is at least that of 'b'
        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }

        // Check if b is a substring of current repeated string
        if (repeated.find(b) != string::npos) return count;

        // Try one more repetition to handle edge case (wrap-around)
        repeated += a;
        if (repeated.find(b) != string::npos) return count + 1;

        // If not found even after that, it's impossible
        return -1;
    }
};




// class Solution {
// public:
//     int repeatedStringMatch(string a, string b) {
//         int cnt = 0;
        
//         //remove the complete substrings;
//         while(b.size()>0){
//             int n = b.find(a);
//             cout<<n<<endl;
//             cout<<"Before = "<<b<<endl;
//             if(n>b.size() || n < 0){
//                 break;
//             }
//             b.erase(n,a.size());
//             cout<<"After = "<<b<<endl<<endl;
//             cnt++;
//         }

//         if(b.size() == 0){
//             return cnt;
//         }

//         //if remaining break the remaining into 2 parts and see whether it is present in a
//         vector<int> posof1;
//         char start = a[0];
//         for(int i=0;i<b.size();i++){
//             if(start == b[i]){
//                 posof1.push_back(i);
//             }
//         }

//         bool rem = false;
//         for(int i=0;i<posof1.size();i++){
//             int s = posof1[i];
//             string s1 = b.substr(s);
//             string s2 = b.substr(0,s);
//             cout<<s1<<endl;
//             cout<<s2<<endl;
//             cout<<endl;

//             int c1 =0;
//             int c2 =0;
//             cout<<"C1"<<endl;
//             for(int i=0;i<s1.size();i++){
//                 if(a[i] != s1[i]){
//                     break;
//                 }
//                 c1++;
//                 cout<<c1<<endl;
//             }
//             cout<<"C2"<<endl;
//             for(int i=s2.size()-1;i>=0;i--){
//                 cout<<a[a.size()-1-i]<<endl;
//                 cout<<s2[s2.size()-1-i]<<endl;
//                 if(a[a.size()-1+i] != s2[s2.size()-1-i]){
//                     cout<<c2<<"dfergef"<<endl;
//                     break;
//                 }
//                 c2++;
//                 cout<<c2<<endl;
//             }

//             if(c1 == s1.size() && c2 == s2.size()){
//                 cnt +=2;
//                 rem = true;
//                 break;
//             }
//         }

//         if(rem){
//             return cnt;
//         }
//         return -1;
//     }
// };
