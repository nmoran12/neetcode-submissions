class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

       // int left = 0;

        //int right = 1;
        vector<int> results;
        int newLength = numbers.size();

        for (int left = 0; left < newLength; left++){
            for (int right = 1; right < newLength; right++){

                if (numbers[left] + numbers[right] == target && numbers[right] > numbers[left]){
                    results.push_back(left + 1);
                    results.push_back(right + 1);
                }

                if (numbers[right] >= target){
                    newLength = right;
                }
            }
        }
        

        return results;
    }
};
