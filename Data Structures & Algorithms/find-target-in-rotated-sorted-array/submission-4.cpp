class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;


        while (left <= right){

            int mid = left + (right - left) / 2;

            // check if left side of array is sorted
            if (nums[left] <= nums[mid]){
                // basically check if target is on left side,
                // so if target is greater than or equal to left value, and smaller than mid value, its on the left
                if (nums[left] <= target && target <= nums[mid]){
                    right = mid;
                } else {
                    left = mid + 1;
                };
            };

            // check if right side of array is sorted
            if (nums[right] >= nums[mid]){
                // basically check if target is on right side,
                // so if target is less than or equal to right value, and larger than mid value, its on the right
                if (nums[right] >= target && target > nums[mid]){
                    left = mid + 1;
                } else {
                    right = mid;
                }
            };


            // check if current number is equal to target
            if (nums[mid] == target){
                return mid;
            }

        }


        return -1;
    }
};
