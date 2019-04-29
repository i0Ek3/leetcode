// 454 4Sum II
//
// 印象中的做法是一层一层的用分治法，不知道对不对？但又感觉像排列的问题。
//
// 题目的意思是给定四个整数列表A，B，C，D，找出这么一个元组(i, j, k, l) 使得 A[i] + B[j] + C[k] + D[l] = 0.
//
// 其中题目已经将难度降低，给定了数的取值范围等。具体例子如下：
//
// Input:
// A = [ 1, 2 ]
// B = [-2,-1]
// C = [-1, 2]
// D = [ 0, 2 ]
//
// Output:
// 2
//
// Explanation:
// The two tuples are:
// 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
// 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
//
// 输出满足条件的元素的个数。
//


class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> sum;
        for (auto a : A) {
            for (auto b : B) {
                ++sum[a+b];
            }
        }
        
        int cnt = 0;
        for (auto c : C) {
            for (auto d : D) {
                auto it = sum.find(0 - c - d);
                if (it != sum.end()) cnt += it->second;
            }
        }
        return cnt;
    }
};
