class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output(n + 1, 0);

        for (int i = 0; i <= n; i++){
            int temp = i;
            int count = 0;
            while (temp > 0){
                temp = temp & (temp - 1);
                count++;
            }
            output[i] = count;
        }

        return output;
    }
};
