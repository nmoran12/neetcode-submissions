class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

       int left = 0;
       int right = numbers.size() - 1;
       int middle = left + (right - left) / 2;

        vector<int> results;

        while (right > left){
            if (numbers[mid] > target){
                right = mid;
            } else if (numbers[mid] < target){
                left = mid + 1;
            } else{
                results.push_back(left + 1);
                results.push_back(right + 1);
            }
        }
        

        return results;
    }
};
