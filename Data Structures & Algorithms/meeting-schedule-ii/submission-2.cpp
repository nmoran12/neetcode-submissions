/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        // Sort by start times
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval&b){
            return a.start < b.start;
        });

        // Min heap stores by end times
        priority_queue<int, vector<int>, greater<int>> minHeap;

        minHeap.push(intervals[0].end);

        for (int i = 1; i < intervals.size(); i++){

            // If current meeting starts AT or AFTER the current end time
            // i.e. if current meeting starts at 11:00, and current end time is 10:30
            if (minHeap.top() <= intervals[i].start){
                minHeap.pop();
            }


            minHeap.push(intervals[i].end);
        }
        

        return minHeap.size();
    }
};
