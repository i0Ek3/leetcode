// 041 First Missing Positive
//
// 给定一个未排序的整数数组，找出最小缺失的正整数。这是啥意思？说实话前几遍真是没看明白，最后看了以下例子，明白了。
//
// 就是说，给定一个序列，没有排序的，正整数，所以不存在负数，那么 1，2，0 从 0 开始，1 和 2 都出现了，那么在正整数的序列中，只有 3 满足最小的情况。
//
// 同理 3，4，-1，1 中只有 2 满足情况。但是第三个例子什么鬼？不懂！
//
// 代码来自评论区，还是没看懂，谁来解释一下？


class Solution
{
public:
    int firstMissingPositive(int A[], int n)
    {
        for(int i = 0; i < n; ++ i)
            while(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
                swap(A[i], A[A[i] - 1]);

        for(int i = 0; i < n; ++ i)
            if(A[i] != i + 1)
                return i + 1;

        return n + 1;
    }
};
