class Solution {
public:
    long long createPalindrome(long long num, bool odd) {
        long long x = num;
        if (odd) x /= 10;
        while (x > 0) {
            num = num * 10 + x % 10;
            x /= 10;
        }
        return num;
    }

    bool isPalindrome(long long num, int base) {
        vector<int> digits;
        while (num > 0) {
            digits.push_back(num % base);
            num /= base;
        }
        int i = 0, j = digits.size() - 1;
        while (i < j) {
            if (digits[i++] != digits[j--]) return false;
        }
        return true;
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        for (long long len = 1; n > 0; len *= 10) {
            for (long long i = len; n > 0 && i < len * 10; i++) {
                long long p = createPalindrome(i, true);
                if (isPalindrome(p, k)) {
                    sum += p;
                    n--;
                }
            }
            for (long long i = len; n > 0 && i < len * 10; i++) {
                long long p = createPalindrome(i, false);
                if (isPalindrome(p, k)) {
                    sum += p;
                    n--;
                }
            }
        }
        return sum;
    }
};

// class Solution {
// private:
//     bool isPalindrome(string s){
//         int l =0;
//         int r = s.size()-1;
//         while(l<=r){
//             if(s[l] != s[r]){
//                 return false;
//             }
//             l++;
//             r--;
//         }
//         return true;
//     }
//     bool convert(int i, int n){
//         string s;
//         int a = i;
//         while(i>0){
//             char c = (i%n) + '0';
//             s  = c + s;
//             i = i/n;
//         }

//         if(isPalindrome(s)){
//             cout<<"number = "<<a<<" string = "<<s<<endl;
//             return true;
//         }
//         return false;
//     }
// public:
//     long long kMirror(int k, int n) {
//         int i=1;
//         vector<int> v;
//         while(v.size() != n){
//             if(isPalindrome(to_string(i)) && convert(i,k)){
//                 v.push_back(i);
//             }
//             i++;
//         }

//         long long sum =0;
//         for(int j=0;j<v.size();j++){
//             sum += v[j];
//             cout<<sum<<endl;
//         }

//         return sum;
//     }
// };
