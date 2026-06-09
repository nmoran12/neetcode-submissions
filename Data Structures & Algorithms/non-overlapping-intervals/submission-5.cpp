class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        vector<vector<int>> results;
        results.push_back(intervals[0]);
        int i = 0;
        int n = intervals.size();
        int overlapCount = 0;

        for (int i = 1; i < n; i++){

            if (results.back()[1] > intervals[i][0]){
                overlapCount++;
            } else {
                results.push_back(intervals[i]);
            }
        }
        

        return overlapCount;
    }
};
