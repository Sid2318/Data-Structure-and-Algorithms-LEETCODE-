// // class Solution {
// // public:
// //     string clearStars(string s) {
// //         int stars =0;
// //         for(int i=0;i<s.size();i++){
// //             if(s[i] == '*'){
// //                 stars++;
// //             }
// //         }

// //         // map<char,int> mpp;
// //         // for(int i=0;i<s.size();i++){
// //         //     if(s[i] != '*'){
// //         //         mpp[s[i]]++;
// //         //     }
// //         // }

// //         int i = 0;
// //         while(stars != 0){
// //             cout<<s<<endl;
// //             if(s[i] == '*'){
// //                 // map<char,int> mpp;
// //                 // for(int k=0;k<i;k++){
// //                 //     if(s[k] != '*'){
// //                 //         mpp[s[k]]++;
// //                 //     }
// //                 // }
// //                 char smallest = 'z';
// //                 // for(auto& m:mpp){
// //                 //     smallest = m.first;
// //                 //     break;
// //                 // }
// //                 for(int k=0;k<i;k++){
// //                     if(s[k] != '*'){
// //                         smallest = min(smallest , s[k]);
// //                     }
// //                 }
// //                 // mpp[smallest]--;?
// //                 int j = i;
// //                 while(j >= 0 && s[j] != smallest){
// //                     j--;
// //                 }
// //                 s.erase(i,1);
// //                 s.erase(j,1);
// //                 stars--;
// //             }
// //             else{
// //                 i++;
// //             }
// //         }

// //         return s;
// //     }
// // };


// class Solution {
// public:
//     string clearStars(string s) {
//         int stars = 0;
//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == '*') stars++;
//         }

//         int i = 0;
//         while (stars != 0) {
//             if (s[i] == '*') {
//                 char smallest = 'z';
//                 for (int k = 0; k < i; k++) {
//                     if (s[k] != '*') {
//                         smallest = min(smallest, s[k]);
//                     }
//                 }

//                 int j = i;
//                 while (j >= 0 && s[j] != smallest) {
//                     j--;
//                 }

//                 if (j >= 0) {
//                     s.erase(i, 1);  // Remove '*'
//                     s.erase(j, 1);  // Remove smallest before it
//                     stars--;
//                     i--; // adjust index after erasure
//                 } else {
//                     i++;
//                 }
//             } else {
//                 i++;
//             }
//         }

//         return s;
//     }
// };


class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> um(26);
        vector<int> rem(s.size(), 0);   // take all index in start

        int i=0;
        while(i<s.size()){
            char ch = s[i]-'a';
            um[ch].push(i);
            i++;

            int cnt=0;
            while(i<s.size() and s[i] == '*'){
                cnt++;
                i++;
            }

            if(cnt>0){
                for(char c=0;c<=25;c++){
                    while(!um[c].empty()){
                        int ind = um[c].top();
                        um[c].pop();

                        rem[ind] = 1;

                        cnt--;
                        if(cnt==0){break;}
                    }
                    if(cnt==0){break;}
                }
            }
        }

        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i]!='*' and rem[i]==0){
                ans += s[i];
            }
        }
        return ans;
    }
};
