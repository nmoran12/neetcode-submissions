class Solution {
public:
    int jump(vector<int>& nums) {

        int start = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size(); i++){
            farthest = max(farthest, i + nums[i]);

            if (i == currentEnd){
                jumps++;
                currentEnd = farthest;
            }
        }
        
    }
};
