class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Sort in ascending order based on start time
        sort(intervals.begin(), intervals.end(), [](const vector<int> a, const vector<int> b){
            return a[0] < b[0];
        });

        vector<vector<int>> results;

        int i = 0;
        int n = intervals.size();
        // Push first interval vector in
        results.push_back(intervals[0]);

        // For length of intervals
        for (int i = 1; i < n; i++){

            // If last vector added to results >= start time of current interval
            if (results.back()[1] >= intervals[i][0]){
                // last vector added to results end time changed to maximum of last vector's end time and current vector's end time
                results.back()[1] = max(results.back()[1], intervals[i][1]);
            } else {
            // If not overlapping, just push current vector.
            results.push_back(intervals[i]);
            }
        }
        

        return results;
    }
};
