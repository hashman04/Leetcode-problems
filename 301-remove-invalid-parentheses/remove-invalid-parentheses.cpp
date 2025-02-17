class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int N = s.size();
        vector<int> right(N + 1);
        for (int i = N - 1; i >= 0; --i) right[i] = max(0, right[i + 1] + (s[i] == '(' || s[i] == ')' ? (s[i] == ')' ? 1 : -1) : 0));
        unordered_set<string> ans;
        string tmp;
        function<void(int, int)> dfs = [&](int i, int left) {
            if (i == N) {
                if (left == 0) ans.insert(tmp);
                return;
            }
            if (s[i] == '(') {
                if (left + 1 > right[i + 1]) { // we can remove this '('
                    dfs(i + 1, left);
                }
                ++left;
            } else if (s[i] == ')') {
                if (right[i] > left) { // we can remove this ')'
                    dfs(i + 1, left);
                }
                if (left > 0) {
                    --left;
                } else return;
            } 
            tmp.push_back(s[i]);
            dfs(i + 1, left);
            tmp.pop_back();
        };
        dfs(0, 0);
        return vector<string>(begin(ans), end(ans));
    }
};