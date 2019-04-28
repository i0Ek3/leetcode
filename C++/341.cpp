// 341 Flatten Nested List Iterator
// 
// 给定一个嵌套的整数列表，实现一个迭代器来展开它。每个元素都是整数或列表，其元素也可以是整数或其他列表。
// 
// Input: [[1,1],2,[1,1]]
// Output: [1,1,2,1,1]
// Explanation: By calling next repeatedly until hasNext returns false, 
//              the order of elements returned by next should be: [1,1,2,1,1].
//
// Input: [1,[4,[6]]]
// Output: [1,4,6]
// Explanation: By calling next repeatedly until hasNext returns false, 
//                           the order of elements returned by next should be: [1,4,6].
//
//

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next() {
        hasNext();
        return (begins.top()++)->getInteger();
    }

    bool hasNext() {
        while (begins.size()) {
            if (begins.top() == ends.top()) {
                begins.pop();
                ends.pop();
            } else {
                auto x = begins.top();
                if (x->isInteger()) return true;
                begins.top()++;
                begins.push(x->getList().begin());
                ends.push(x->getList().end());
            }
        }
        return false;
    }  

private:
    stack<vector<NestedInteger>::iterator> begins, ends;
};
