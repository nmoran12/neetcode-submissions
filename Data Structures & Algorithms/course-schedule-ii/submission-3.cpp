class Solution {
public:

    bool dfs(int course, vector<vector<int>>& graph, vector<int>& state, vector<int>& validPaths){
        // Base Cases:
        // if state is 1, i.e. currently visiting, we have found a cycle, return false
        if (state[course] == 1){
            return false;
        }

        // if state is 2 i.e. already visited and is safe, just return true.
        if (state[course] == 2){
            return true;
        }

        // Now mark it as 1, as we are currently visiting it now
        state[course] = 1;

        for (auto prereq : graph[course]){
            if (!dfs(prereq, graph, state, validPaths)){
                return false;
            }
        }

        state[course] = 2;

        validPaths.push_back(course);

        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> validPaths;

        vector<int> state(numCourses, 0);

        for (auto p : prerequisites){
            int course = p[0];
            int prereq = p[1];

            graph[course].push_back(prereq);
        }

        for (int i = 0; i < numCourses; i++){
            if (!dfs(numCourses, prerequisites, state, validPaths)){
                validPaths.push_back(course);
                return false;
            }
        }


        return validPaths;
    }
};
