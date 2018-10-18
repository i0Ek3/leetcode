# 001思路

该题解使用了C++中的STL模版，利用unordered_map的桶排序特性来存储nums中的数字，定义为unordered_map<int, int> m。

将target和nums[i]作差，结果保存到vector中去。

然后判断上述中的差值是否在m中，并push_back()到vector中。


