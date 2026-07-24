class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> results;

        while (left < right){
            int currentSum = numbers[left] + numbers[right];

            if (currentSum == target){
                return results.push_back(left + 1) && results.push_back(right + 1);
            } else if (currentSum > target){
                right--;
            } else if (currentSum < target){
                left++;
            }
        }
        

        return results;
    }
};
