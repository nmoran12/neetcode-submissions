class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int newArray[0];
        int k = 0;
        int readPos = 0;
        int writePos = 1;

        for (int readPos = 0; readPos < nums.size(); readPos++){
            if (nums[readPos] != nums[writePos-1]){
                nums[writePos] = nums[readPos];
                writePos++;

                cout << "Nums: " << nums[readPos] << endl;
            };
        }

        return writePos;
    }
};