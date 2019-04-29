// 384 Shuffle an Array
//
//
//
//

class Solution {
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
        
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
        
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res(nums);
        int n = res.size();
        for (int i = 0; i < n; i++) {
            int pos = rand() % (n - i);
            swap(res[pos+i], res[i]);
        }
        return res;
    }
private:
    vector<int> nums;
};
