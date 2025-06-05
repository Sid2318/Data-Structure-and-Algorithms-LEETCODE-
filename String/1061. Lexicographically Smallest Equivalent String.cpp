// class Solution {
// public:
//     string smallestEquivalentString(string s1, string s2, string baseStr) {
//         unordered_map<char,char> mpp;
//         for(char ch = 'a';ch<='z';ch++){
//             mpp[ch] = ' ';
//         }

//         //map for smallest allocation
//         for(int i=0;i<s1.size();i++){
//             if(mpp[s1[i]] == ' '){
//                 mpp[s1[i]] = s2[i];
//             }
//             if(mpp[s2[i]] == ' '){
//                 mpp[s2[i]] = s2[i];
//             }
//             if((mpp[s1[i]] != ' ')){
//                 char ch = mpp[s1[i]];
//                 if(s2[i] < ch){
//                     mpp[s1[i]] = s2[i];
//                     mpp[s2[i]] = s2[i];
//                 }
//             }
//             if((mpp[s2[i]] != ' ')){
//                 char ch = mpp[s1[i]];
//                 if(s2[i] < ch){
//                     mpp[s1[i]] = s2[i];
//                     mpp[s2[i]] = s2[i];
//                 }
//             }

//             if(mpp[s2[i]] == ' '){
//                 mpp[s2[i]] = s1[i];
//             }
//             if(mpp[s1[i]] == ' '){
//                 mpp[s1[i]] = s1[i];
//             }
//             if((mpp[s1[i]] != ' ')){
//                 char ch = mpp[s2[i]];
//                 if(s1[i] < ch){
//                     mpp[s1[i]] = s1[i];
//                     mpp[s2[i]] = s1[i];
//                 }
//             }
//             if((mpp[s2[i]] != ' ')){
//                 char ch = mpp[s2[i]];
//                 if(s1[i] < ch){
//                     mpp[s1[i]] = s1[i];
//                     mpp[s2[i]] = s1[i];
//                 }
//             }
//         }

//         //final answer
//         for(int i=0;i<baseStr.size();i++){
//             char ch = baseStr[i];
//             if(mpp[ch] != ' '){
//                 baseStr[i] = mpp[ch];
//             }
//         }

//         return baseStr;
//     }
// };

class Solution {
public:
    char find(unordered_map<char, char>& parent, char ch) {
        if (parent[ch] != ch) {
            parent[ch] = find(parent, parent[ch]);
        }
        return parent[ch];
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, char> parent;

        // Initialize each character as its own parent
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            parent[ch] = ch;
        }

        // Merge equivalence groups
        for (int i = 0; i < s1.size(); ++i) {
            char a = find(parent, s1[i]);
            char b = find(parent, s2[i]);

            // Always point to the lexicographically smaller one
            if (a < b) parent[b] = a;
            else if (a > b) parent[a] = b;
        }

        // Build the result
        for (int i = 0; i < baseStr.size(); ++i) {
            baseStr[i] = find(parent, baseStr[i]);
        }

        return baseStr;
    }
};
