class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0){
            return 0;
        }

        // Pair the cars {position, time_to_target}
        vector<pair<int, int>> pair;

        for (int i = 0; i < n; i++){
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());

        int carFleets = 1;
        double prevTime = (double)(target - pair[0].first) / pair[0].second;
        for (int i = 1; i < n; i++){
            double currTime = (double)(target - pair[i].first) / pair[i].second;
            if (currTime > prevTime){
                carFleets++;
                prevTime = currTime;
            }
        }

        return carFleets;
    }
};
