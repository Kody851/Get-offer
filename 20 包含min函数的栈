题目描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。

class Solution {//设置辅助栈stk2，每次入栈当前的最小元素。
public:
    void push(int value) {
        stk1.push(value);
        if(stk2.empty()) stk2.push(value);
        else if(value<stk2.top()) stk2.push(value);
        else stk2.push(stk2.top());
    }
    void pop() {
        stk1.pop();
        stk2.pop();
    }
    int top() {
        return stk1.top();
    }
    int min() {
        return stk2.top();
    }
private:
    stack<int>stk1;
    stack<int>stk2;
};
