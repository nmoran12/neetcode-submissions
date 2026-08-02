class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) return 0; // Edge case: no cars present

        // 1. Combine position and speed into pairs so they stay linked when sorted
        vector<pair<int, int>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        // 2. Sort cars by starting position descending (closest to target first)
        sort(cars.rbegin(), cars.rend());

        // 3. Start with the front-most car as the leader of the 1st fleet
        int carFleets = 1;
        
        // prevTime = arrival time of the current fleet leader directly ahead
        double prevTime = (double)(target - cars[0].first) / cars[0].second;

        // 4. Process all remaining cars from front to back
        for (int i = 1; i < n; i++) {
            // Time this car needs to reach the target on an empty road
            double currTime = (double)(target - cars[i].first) / cars[i].second;

            // If this car takes MORE time than the fleet ahead:
            // It can NEVER catch up -> starts a brand new fleet!
            if (currTime > prevTime) {
                carFleets++;
                prevTime = currTime; // This car becomes the new fleet leader/bottleneck
            }
            // Note: If currTime <= prevTime, it catches up and merges into the ahead fleet,
            // so we do nothing and keep prevTime as the bottleneck.
        }

        return carFleets;
    }
};