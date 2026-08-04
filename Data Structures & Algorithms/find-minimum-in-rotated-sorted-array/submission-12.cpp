class Solution {
public:
    int findMin(vector<int> &nums) {

        int left = 0;
        int right = nums.size() - 1;

        // We use left < right not left <= right, so that when left and right converge on the same element,
        // the while loop stops and we just return nums[left].
        while (left < right){
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]){
                left = mid + 1;
            } else if (nums[mid] < nums[right]){
                // We want to stay inside our search range, so we do right = mid, not right = mid - 1.
                right = mid;
            }
        }
        
        // You can return left or right, it doesn't matter.
        return nums[left];
    }
};
