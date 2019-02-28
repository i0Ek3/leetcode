// 31 Next Permutation
//
// 刚开始看不懂题意，下一个排列？反正看来看去还是不太懂啥意思，看了大神们的代码，才有所悟。
//
// Solution1 中的代码是评论区中的网友在 Wiki 上找到的，我用来理解并添加注释，虽然还是没太明白，看来需要我继续探索。Solution2 的代码是最简单的一种方式，直接使用了自带的库函数解决了这个排列问题。
//
// 但 Solution3 的代码相对来说才是最好理解的，我还得继续研究。
//


class Solution1 {
public:
    void nextPermutation(vector<int>& nums) {
    	int n = nums.size();
        int k, l;
    	for (k = n - 2; k >= 0; k--) { // 从倒数第三个数开始向前遍历
            if (nums[k] < nums[k + 1]) { // 如果相邻的两个数，前者小于后者，则停止遍历
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) { // 从倒数第二个数开始向前遍历
                if (nums[l] > nums[k]) { // 如果某个数大于另一个数，则停止遍历
                    break;
                }
            }
    	    swap(nums[k], nums[l]); // 交换这两个数
    	    reverse(nums.begin() + k + 1, nums.end()); // 倒置这个位置上的数和数组中最后一个数
        }
    }
};

class Solution2 {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(begin(nums), end(nums)); // 重点是这个函数是如何实现的
    }
};

class Solution3 {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1, k = i; // 我们假设 nums 中有 4 个数，则 i=3，此时的 k=3；
        while (i > 0 && nums[i-1] >= nums[i]) i--; // 条件：3 > 0 && nums[2] >= nums[3] 如果成立的话，继续向前移动 i；
        for (int j=i; j<k; j++, k--) swap(nums[j], nums[k]); //
        if (i > 0) {
            k = i--;
            while (nums[k] <= nums[i]) k++;
            swap(nums[i], nums[k]); // 交换这两个数
        }
    }
};
