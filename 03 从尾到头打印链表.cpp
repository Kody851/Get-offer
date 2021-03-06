题目描述
输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int>res;
        if(!head) return res;
        stack<int>stk;
        ListNode*cur=head;
        while(cur){
            stk.push(cur->val);
            cur=cur->next;
        }
        while(!stk.empty()){
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};
class Solution {//循环比递归更鲁棒，本解法可能会出现函数调用栈溢出
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int>res;
        if(!head) return res;
        res=printListFromTailToHead(head->next);
        res.push_back(head->val);
        return res;
    }
};
