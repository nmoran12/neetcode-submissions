class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        int n = intervals.size();

        // Sort by ascending order
       // sort(intervals.begin(), intervals.end(), [](const vector<int>& interval1, const vector<int>& interval2){
       //     return interval1[0] < interval2[0];
       // });

        vector<vector<int>> results;

        // Phase 1: Push intervals from left side into results vector
            // If newInterval's start time is greater than an intervals end time, they don't overlap at all, so we are good to just push to results
        while (i < n && intervals[i][1] < newInterval[0]){
            results.push_back(intervals[i]);
            i++;
        }

        // Phase 2: Merge intervals that overlap with newInterval, THEN push them.
            // If newInterval's end time is greater than or equal to intervals start time (i.e. they do overlap), we merge them
        while (i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(newInterval[0], intervals[i][0]); // Get minimum start time of both merging intervals, make that the start time
            newInterval[1] = max(newInterval[1], intervals[i][1]); // Get maximum end time of both merging intervals, make that the end time
            i++;
        }

        // CRUCIAL: Once you have finished merging the intervals, we push that big merged interval into the results.
        results.push_back(newInterval);

        // Phase 3: Push the rest of the intervals that are in interval into the results vector, you don't have to do anything with them.
        while (i < n){
            results.push_back(intervals[i]);
            i++;
        }

        return results;
    }
};
