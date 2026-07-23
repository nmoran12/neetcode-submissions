class Solution {
public:
    int hammingWeight(uint32_t n) {

        int nCount = 0;

        while (n != 0){

            nCount += n & 1;
            n >>= 1;
        }


        return nCount;
    }
};
