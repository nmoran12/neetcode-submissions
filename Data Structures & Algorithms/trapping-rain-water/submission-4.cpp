class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int left = 0;
        int right = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int result = 0;

        while (left < right) {
            // Compare current actual heights to pick the smaller bottleneck
            if (height[left] < height[right]) {
                leftMax = max(leftMax, height[left]);
                result += leftMax - height[left];
                left++; // Advance AFTER calculating for current left
            } else {
                rightMax = max(rightMax, height[right]);
                result += rightMax - height[right];
                right--; // Advance AFTER calculating for current right
            }
        }

        return result;
    }
};