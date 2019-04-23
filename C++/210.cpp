// 210 Course Schedule II
//
// 之前那个题目的升级版，就是问你在所给定的这些数组里，哪些是需要你先修的，给出其中一个正确的组合。
//
// Input: 2, [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished
//              course 0. So the correct course order is [0,1] .
//
// Input: 4, [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,1,2,3] or [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both
//              courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
//                           So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
//
// 还是有向图和拓扑排序求解，利用 DFS 或者 BFS。https://leetcode.com/problems/course-schedule-ii/discuss/59316/C%2B%2B-BFS-and-DF://leetcode.com/problems/course-schedule-ii/discuss/59316/C%2B%2B-BFS-and-DFS
//


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computerIndgrees(g);
        vector<int> order;
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (!degrees[j]) {
                    order.push_back(j);
                    break;
                }
            }
            if (j == numCourses) return {};
            degrees[j]--;
            for (int v : g[j]) degrees[v]--;
        }
        return order;
    }

private:
    typedef vector<vector<int>> graph;
    graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites)
            g[p.second].push_back(p.first);
        return g;
    }
    vector<int> computeIndegrees(graph& g) {
        vector<int> degrees(g.size(), 0);
        for (auto adj : g)
            for (int v : adj)
                degrees[v]++;
        return degrees;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        for (auto p : prerequisites)
            adj[p.second].push_back(p.first); // u->p
        ans = vector<int>(numCourses, 0);
        t = numCourses;
        visited = vector<int>(numCourses, false);
        for (int u = 0; u < numCourses; u++)
            if (visited[u] == 0)
                if (dfs(u) == false)
                    return {};
        return ans;
    }
private:
    unordered_map<int, vector<int>> adj;
    vector<int> visited;
    vector<int> ans;
    int t;

    bool dfs(int u) {
        visited[u] = -1 // visiting node
        for (int v : adj[u]) {
            if (visited[v] == -1) return false;
            if (visited[v] == 0 && dfs(v) == false) return false;
        }
        visited[u] = 1; // visited
        ans[--t] = u;
        return true;
    }
};
