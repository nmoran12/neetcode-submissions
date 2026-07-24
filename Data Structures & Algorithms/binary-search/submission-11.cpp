class Solution {
public:
    int search(vector<int>& nums, int target) {


        while (left <= right){
            int right = nums.size();
            int left = 0;
            int mid = left + (right - left) / 2;

            if (nums[mid] < target){
                left = mid + 1;
            }

            if (nums[mid] > target){
                right = mid - 1;
            }

            if (nums[mid] == target){
                return mid;
            }

            return -1;
        }
        

        return -1;
    }
};
