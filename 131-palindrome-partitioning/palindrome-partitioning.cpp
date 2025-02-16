class Solution {
    vector<vector<string>> ans;
    vector<string> tmp;
    bool isPalindrome(string &s, int i, int j) {
        while (i < j && s[i] == s[j]) ++i, --j;
        return i >= j;
    }
    void dfs(string &s, int start) {
        if (start == s.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (!isPalindrome(s, start, i)) continue;
            tmp.push_back(s.substr(start, i - start + 1));
            dfs(s, i + 1);
            tmp.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return ans;
    }
};