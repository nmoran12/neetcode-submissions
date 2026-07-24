class Solution {
public:

    vector<vector<int>> builtGraph;
    // 0 = unvisited, 1 = currently visiting, 2 = fully checked and is safe
    vector<int> nodeState;

    bool dfs(int course, vector<vector<int>>& builtGraph, vector<int>& state){
        // Base Cases:
        if (state[course] == 1){ // cycle has been found
            return false;
        }

        if (state[course] == 2){
            return true; // already checked, is safe
        }

        // Mark as visited:
        state[course] = 1;

        for (int prereq : graph[course]){
            if (!dfs(prereq, graph, state)){
                return false;
            }
        }

        state[course] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for (auto p : prerequisites){
            int course = p[0];
            int prereq = p[1];

            graph[course].push_back(prereq);
        }

        vector<int> state(numCourses, 0);




        for (int course = 0; course < numCourses; course++) {
            if (!dfs(course, graph, state)) {
                return false;
            }
        }

        return true;
    }
};
