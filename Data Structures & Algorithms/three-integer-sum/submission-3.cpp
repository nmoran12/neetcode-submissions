class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> validTriplets;


        for (int onePointer = 0; onePointer < nums.size(); onePointer++){


            for (int twoPointer = 1; twoPointer < nums.size(); twoPointer++){

                for (int threePointer = 2; threePointer < nums.size(); threePointer++){

                    // If the three pointers values add up to 0, and this triplet does not already exist in results vector, add it to results vector
                    if ((nums[onePointer] + nums[twoPointer] + nums[threePointer]) == 0 && !validTriplets({nums[onePointer], nums[twoPointer], nums[threePointer]})){
                        validTriplets.push_back({nums[onePointer], nums[twoPointer], nums[threePointer]});
                    }

                }
            }
        }
        

        return validTriplets;
    }
};
