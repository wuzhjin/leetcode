/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (50.36%)
 * Likes:    394
 * Dislikes: 0
 * Total Accepted:    76.8K
 * Total Submissions: 148.3K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 * 
 * 
 * push(x) -- 将元素 x 推入栈中。
 * pop() -- 删除栈顶的元素。
 * top() -- 获取栈顶元素。
 * getMin() -- 检索栈中的最小元素。
 * 
 * 
 * 示例:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 * 
 * 
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    // MinStack() {

    // }

    // void push(int x)
    // {
    //     st1.push(x);
    //     if (st2.empty() || x <= st2.top())
    //         st2.push(x);
    // }

    // void pop() {
    //     if (st1.top() == st2.top())
    //         st2.pop();
    //     st1.pop();
    // }
    
    // int top() {
    //     return st1.top();
    // }
    
    // int getMin() {
    //     return st2.top();
    // }
    // stack<int> st1,st2;
       MinStack() {
        minVal = INT_MAX;
    }

    void push(int x)
    {
        if (x <= minVal)
        {
            st1.push(minVal);
            minVal = x;
        }
        st1.push(x);
    }

    void pop() {
        int t = st1.top();
        st1.pop();
        if (t == minVal)
        {
            minVal = st1.top();
            st1.pop();
        }
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return minVal;
    }
    stack<int> st1;
    int minVal;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

