class Solution {
private:
    void insert(int n, vector<char>& ans) {
        vector<char> a;
        while (n > 0) {
            a.push_back((n % 10) + '0');
            n = n / 10;
        }

        for (int i = a.size() - 1; i >= 0; i--) {
            ans.push_back(a[i]);
        }
        return;
    }

public:
    int compress(vector<char>& chars) {
        vector<char> ans;
        int cnt = 1;
        char ch = chars[0];
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == ch) {
                cnt++;
            } else {
                ans.push_back(ch);
                if (cnt != 1) {
                    insert(cnt, ans);
                }
                cout << ch << " = " << cnt << endl;
                cnt = 1;
                ch = chars[i];
            }
        }
        ans.push_back(ch);
        if (cnt != 1) {
            insert(cnt, ans);
        }

        chars.resize(ans.size());
        for (int i = 0; i < ans.size(); i++) {
            chars[i] = ans[i];
        }

        return ans.size();
    }
};
