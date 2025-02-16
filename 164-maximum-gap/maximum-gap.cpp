class Solution {
public:
    int maximumGap(vector<int>& A) {
        if (A.size() == 1) return 0;
        int minVal = *min_element(begin(A), end(A));
        int maxVal = *max_element(begin(A), end(A));
        int N = A.size(), gap = (maxVal - minVal + N - 2) / (N - 1);
        vector<int> mn(N - 1, INT_MAX), mx(N - 1, INT_MIN);
        for (int n : A) {
            if (n == minVal || n == maxVal) continue;
            int i = (n - minVal) / gap;
            mn[i] = min(mn[i], n);
            mx[i] = max(mx[i], n);
        }
        int ans = gap, prev = minVal;
        for (int i = 0; i < N - 1; ++i) {
            if (mn[i] == INT_MAX) continue;
            ans = max(ans, mn[i] - prev);
            prev = mx[i];
        }
        return max(ans, maxVal - prev);
    }
};