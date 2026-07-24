class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = nums.size() / 2;
        int left = 0;
        int right = nums.size();
        

        while (left < right){
            int mid = (right + left) / 2;

            if (nums[mid] > target){
                right = mid - 1;
            }

            if (nums[mid] < target){
                left = mid + 1;
            }


            if (nums[mid] == target){
                return mid;
            }



        }



        return -1;
    }
};
