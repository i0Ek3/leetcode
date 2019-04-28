// 295 Find Median from Data Stream
//
// 从数据流中找出中位数，如果链表中数字个数是奇数则为中间的那个数，如果为偶数则为两个数的均值。
//
// 定义一个数据结构，可以支持某些操作，如添加数字和找出中位数。
// 
// addNum(1)
// addNum(2)
// findMedian() -> 1.5
// addNum(3) 
// findMedian() -> 2
//

class MedianFinder {
public:
    priority_queue<long> small, large;
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }
        
    double findMedian() {
        return small.size() > large.size() ? small.top() : (small.top() - large.top()) / 2.0;
    }
};

