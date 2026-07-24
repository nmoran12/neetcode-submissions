class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

       // int left = 0;

        //int right = 1;
        vector<int> results;

        for (int left = 0; left < numbers.size(); left++){
            for (int right = 1; right < numbers.size(); right++){
                if (numbers[left] + numbers[right] == target && numbers[right] > numbers[left]){
                    results.push_back(left + 1, right + 1);
                }
            }
        }
        

        return results;
    }
};
