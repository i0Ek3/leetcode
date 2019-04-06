// 155 Min Stack
//
// 设计一个支持 push，pop，top 和能在常数时间内检索最小元素的栈。
//
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.
//
// 基础的数据结构题目。
//

class Solution {
public:

    void push(int x) {

        if (x <= min) {
            st.push(mint);
            min = x;
        }
        st.push(x);
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }

private:
    int min = MIN_MAX;
    stack<int> st;
};

// 另一个简洁的答案。即用两个栈来存储数据，s1 正常存放数据，s2 存放最小值。

class MinStack {
public:
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= getMin())
            s2.push(x);
    }

    void pop() {
        if (s1.top() == getMin())
            s2.pop();
        s1.pop();
    }

    int top() {
        return s1.top();
    }

    int getMin() {
        return s2.top();
    }
private:
    stack<int> s1;
    stack<int> s2;
};
