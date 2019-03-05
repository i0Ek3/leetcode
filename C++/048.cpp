// 048 Rotate Image
//
// 给定一个 n x n 的二维像素，然后顺时针 90 度旋转。
//
// 我能想到的就是最普通的方法，这里一定还有更好的解法，为啥不画个图去找一下规律呢？
//
// 先按顺序置换所有列，将后面的列往前移，然后以左斜对角线为基准调换左上角的数和右下角的数。这样不就得到了想要的结果吗？
//
// 发现个问题，用 decltype 比用 int 快 4 ms。难道是因为一个是直接提取类型，而另一个要定义分配内存的吗？
//
// 另外，solution2 也很简洁，我更喜欢这样的感觉，solution2 来自评论区，solution1 来自 pezy。

class Solution1 {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 使用了 C++ 中的相关函数
        reverse(matrix.begin(), matrix.end());
        int n = matrix.size();
        for (decltype(n) i = 0; i < n; i++) { // decltype 为自动类型推导，即它会去提取括号内表达式的类型
            for (decltype(n) j = i; j < matrix[i].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

class Solution2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int a = 0;
        int b = n-1;
        while(a<b){
            for(int i=0;i<(b-a);++i){
                swap(matrix[a][a+i], matrix[a+i][b]);
                swap(matrix[a][a+i], matrix[b][b-i]);
                swap(matrix[a][a+i], matrix[b-i][a]);
            }
            ++a;
            --b;
        }
    }
};
