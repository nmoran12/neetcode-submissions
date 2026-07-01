class Solution {
public:
    bool dfs(int course, vector<vector<int>>& graph, vector<int>& state) {
        // cycle found
        if (state[course] == 1) {
            return false;
        }

        // already checked and safe
        if (state[course] == 2) {
            return true;
        }

        // mark as currently visiting
        state[course] = 1;

        // check all prerequisites for this course
        for (int prereq : graph[course]) {
            if (!dfs(prereq, graph, state)) {
                return false;
            }
        }

        // finished checking this course
        state[course] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        // [course, prereq] means course depends on prereq
        for (auto& p : prerequisites) {
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