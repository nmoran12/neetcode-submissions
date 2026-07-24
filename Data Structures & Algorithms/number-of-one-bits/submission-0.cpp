class Solution {
public:
    int hammingWeight(uint32_t n) {

        int nCount = 0;

        for (int i = 0; i < n; i++){
            if (n[i] == '1'){
                nCount++;
            }
        }


        return nCount;
    }
};
