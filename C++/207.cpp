// 207 Course Schedule
//
// 有0~n-1共n门课程，选择有些可能有先决条件，比如选课程0需要先选课程1，表示为[0, 1]。现在给定总课程数和先决条件列表，问你是否可以完成全部的课程，大致意思应该就是这样了！
//
// Input: 2, [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take.
//              To take course 1 you should have finished course 0. So it is possible.
//
// 也就是说，如果两个数组是相反的，则不能完成。也就是构成一个环的时候，为死锁。大神们用拓扑排序来解决该问题的，和图联系在一起的，说实话，我想不到。
//
// ref：https://leetcode.com/problems/course-schedule/discuss/58709/BFS(Topological-Sort)-and-DFS(Finding-cycle)-by-C%2B%2B
//      https://leetcode.com/problems/course-schedule/discuss/58509/C%2B%2B-BFSDFS
//

class DFS {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int n = prerequisites.size();
        vector<unordered_set<int>> matrix(numCourses);
        for (int i = 0; i < n; ++i) {
            matrix[prerequisites[i][1]].insert(prerequisites[i][0]); // record directed graph
        }
        unordered_set<int> visited;
        vector<bool> flag(numCourses, false);
        for (int i = 0; i < numCourses; ++i) {
            if (!flag[i]) {
                if (dfs(matrix, visited, i, flag)) return false;
            }
        }
        return true;
    }

    bool dfs(vector<unordered_set<int>> &matrix, unordered_set<int> &visited, int b, vector<bool> &flag) {
        flag[b] = true;
        visited.insert(b);
        for (auto it = matrix[b].begin(); it != matrix[b].end(); ++i) {
            if (visited.find(*it) != visited.end() || dfs(matrix, visited, *it, flag)) return true;
        }
        visited.erase(b);
        return false;
    }
};

class BFS {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> matrix(numCourses, unordered_set<int>());
        int n = prerequisites.size();
        for (int i = 0; i < n; i++) { // construct directed graph, [1, 0] -> edge: 0->1
            matrix[prerequisites[i].second].insert(prerequisites[i].first);
        }
        vector<int> d(numCourses, 0); // count indegree
        for (int i = 0; i < numCourses; i++) {
            for (auto it = matrix[i].begin(); it != matrix[i].end(); it++) {
                d[*it]++;
            }
        }

        // topological sort
        for (int j = 0; j < numCourses; ++j) {
            for (i = 0; i < numCourses && d[i] != 0; i++); // find the node which indegree is 0.
            if (i == numCourses) return false;
            d[i] = -1; // delete this node.
            for (auto it = matrix[i].begin(); it != matrix[i].end(); it++) {
                d[*it]--;
            }
        }
        return true;
    }
};
