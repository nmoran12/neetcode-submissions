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

        // Loop through entire intervals list, starting from 2nd index (since you push first by default)
        for (int i = 1; i < n; i++){
            int previousEnd = intervals[0][1];

            // If last valid vector's end time is greater than the current interval's start time
            if (prevEnd > intervals[i][0]){
                // They are overlapping, so we increment overlapCount
                overlapCount++;
            } else {
                // If anything else is true, then we just add the interval vector to the results vector, because its valid.
                prevEnd = intervals[i][1];
            }
        }
        

        return overlapCount;
    }
};
