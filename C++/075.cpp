// Sort Colors
//
// 给定一个数组，包含 n 个对象，分别是红色、白色和蓝色的。通过排序将颜色相同的彼此相邻，0 表示红色，1 表示白色，2 表示蓝色。不可以使用库函数中的 sort 函数。
//
// 问你有没有一步就可以解决的算法，空间复杂度为常数级的。说实话没啥思路，文中提示用迭代，但是我依旧土包子。看了 pezy 的分析，感觉好多了～
//
// 他的第一次提交用的是两个迭代，显然不符合文中的要求；第二次的提交用了一个迭代和一个交换；第三次提交设置两个 flag，并只用一次迭代就解决了，完美～ 我们常有的思维定势啊，这样只需要解决一首一尾，便都解决了。
//
//

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0, j = 0; i < n; ++i) {
            if (nums[i] == 0) swap(nums[i], nums[j++]);
            else if (nums[i] == 2) swap(nums[i--], nums[--n]);
        }
    }
};
