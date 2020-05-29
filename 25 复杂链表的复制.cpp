题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return pHead;
        //复制节点与next指针
        RandomListNode*cur=pHead;
        RandomListNode*cloneHead=new RandomListNode(-1);
        RandomListNode*cloneCur=cloneHead;
        while(cur){
            RandomListNode*cloneTmp=new RandomListNode(cur->label);
            cloneCur->next=cloneTmp;
            cloneCur=cloneCur->next;
            cur=cur->next;
        }
        cloneCur->next=NULL;
        //用哈希表存储两个链表（用O(n)的空间，达成时间复杂度O(n)）
        unordered_map<RandomListNode*,RandomListNode*>mp;
        cur=pHead;
        cloneCur=cloneHead->next;
        while(cur){
            mp[cur]=cloneCur;
            cur=cur->next;
            cloneCur=cloneCur->next;
        }
        //设置random指针
        cur=pHead;
        cloneCur=cloneHead->next;
        while(cur){
            if(cur->random)
                cloneCur->random=mp[cur->random];//O(1)时间
            cur=cur->next;
            cloneCur=cloneCur->next;
        }
        return cloneHead->next;
    }
};
//最优解，无需辅助空间，时间复杂度O(n)
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead) return pHead;
        //复制并插入
        RandomListNode*cur=pHead;
        while(cur){
            RandomListNode*clone=new RandomListNode(cur->label);
            clone->next=cur->next;
            cur->next=clone;
            cur=clone->next;
        }
        //设置random
        cur=pHead;
        while(cur){
            if(cur->random)
                cur->next->random=cur->random->next;
            cur=cur->next->next;
        }
        //pHead复原，cloneHead为新生成的链表
        /*RandomListNode*cloneHead=pHead->next;
        cur=pHead;
        while(cur->next){
            RandomListNode* tmp=cur->next;
            cur->next=cur->next->next;
            cur=tmp;
        }*/
        cur=pHead;
        RandomListNode*cloneHead=pHead->next;
        RandomListNode*cloneCur=cloneHead;
        while(cloneCur->next){
            cur->next=cur->next->next;
            cloneCur->next=cloneCur->next->next;
            cur=cur->next;
            cloneCur=cloneCur->next;
        }
        cur->next=NULL;
        return cloneHead;
    }
};
