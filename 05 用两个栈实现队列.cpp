题目描述
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if(stack2.empty()) {
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int tmp=stack2.top();
        stack2.pop();
        return tmp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
扩展：两个队列实现一个栈
将queue1用作进栈出栈，queue2作为一个中转站

入栈时，直接压入queue1中

出栈时，先将queue1中的元素除最后一个元素外依次出队列，并压入队列queue2中，将留在queue1中的最后一个元素出队列即为出栈元素，最后还要把queue2中的元素再次压入queue1中

实现代码如下：
//进栈操作
void stackpush(queue<int> &q1,queue<int> &q2,int m)
{
    q1.push(m);
}

//出栈操作
void stackpop(queue<int> &q1,queue<int> &q2,int &m)
{
    int p = q1.size();
    for (int i=0;i<p-1;i++)
    {
        q2.push(q1.front());
        q1.pop();
    }
    m = q1.front();
    q1.pop();
    int l = q2.size();
    for (int j = 0;j<l;j++)
    {
        q1.push(q2.front());
        q2.pop();
    }
}
