// 026 Remove Duplicates From Sorted Array
//
//


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int flag = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i-1]) {
                nums[++flag] == nums[i];
            }
        }
        return flag;
    }
};

class Solution {
public:
    int simpleOne(int *A, int n) {
        int count = 0;
        for (int i = 1; i < n; i++) {
            if (A[i] == A[i-1]) count++;
            else A[i-count] = A[i];
        }
        return n - count;
    }
};
