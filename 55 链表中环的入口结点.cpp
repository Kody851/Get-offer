题目描述P139
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(!pHead||!pHead->next) return NULL;
        //判断有无环
        ListNode*p1=pHead;
        ListNode*p2=pHead;
        while(p1&&p2){//双指针，一快一慢
            p1=p1->next->next;
            p2=p2->next;
            if(p1==p2) break;
        }
        if(p1!=p2) return NULL;
        //求出环内结点数目
        ListNode*tmp=p1;
        p1=p1->next;
        int NumOfNodesInCircle=1;
        while(p1!=tmp){
            p1=p1->next;
            NumOfNodesInCircle++;
        }
        //找出入口结点
        p1=pHead;
        p2=pHead;//双指针，一早一晚
        for(int i=0;i<NumOfNodesInCircle;i++){
            p1=p1->next;
        }
        while(p1!=p2){
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
};
02/15:
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(!pHead) return NULL;
        //判断是否存在环
        ListNode*p1=pHead;
        ListNode*p2=pHead;
        while(p1&&p1->next){
            p1=p1->next->next;
            p2=p2->next;
            if(p1==p2) break;
        }
        if(!p1) return NULL;
        //计算环内结点数
        int NumOfCurcle=1;
        ListNode*cur=p1->next;
        while(cur!=p1){
            NumOfCurcle++;
            cur=cur->next;
        }
        //定位环的入口结点
        p1=pHead;
        p2=pHead;
        for(int i=0;i<NumOfCurcle;i++) p1=p1->next;
        while(p1!=p2){
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
};
