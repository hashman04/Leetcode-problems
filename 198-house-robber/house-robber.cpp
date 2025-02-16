// rob[i + 1] = nums[i] + skip[i] // If we rob at house[i], we must skip house[i-1]
// skip[i + 1] = max(rob[i - 1], skip[i - 1]) // If we skip house[i], we can pick the maximum from robbing or skipping house[i-1]

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int a = 0, b = nums[0];
        for (int i = 1; i < n; ++i) {
            int c = max(nums[i] + a, b);
            a = b;
            b = c;
        }
        return b;
    }
};