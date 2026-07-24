class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        int answer = 0;


        while (left < right){

            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]){
                left = mid + 1;
            } else {
                answer = nums[mid];
                right = mid;
            }
        }
        
        return answer;
    }
};
