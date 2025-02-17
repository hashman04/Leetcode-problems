class Solution {
    vector<int> id, tmp, ans;
    void solve(vector<int> &A, int begin, int end) {
        if (begin + 1 >= end) return;
        int mid = (begin + end) / 2, i = begin, j = mid, k = begin;
        solve(A, begin, mid);
        solve(A, mid, end);
        for (; i < mid; ++i) {
            while (j < end && A[id[j]] < A[id[i]]) {
                tmp[k++] = id[j++];
            }
            ans[id[i]] += j - mid;
            tmp[k++] = id[i];
        }
        for (; j < end; ++j) tmp[k++] = id[j];
        for (int i = begin; i < end; ++i) id[i] = tmp[i];
    }
public:
    vector<int> countSmaller(vector<int>& A) {
        int N = A.size();
        id.assign(N, 0);
        tmp.assign(N, 0);
        ans.assign(N, 0);
        iota(begin(id), end(id), 0);
        solve(A, 0, N);
        return ans;
    }
};