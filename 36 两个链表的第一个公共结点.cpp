
1、时间O(m+n)，空间0
class Solution {//指针一早一晚 
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode*cur1=pHead1,*cur2=pHead2;
        int n1=0,n2=0;//先求长度
        while(cur1){
            n1++;
            cur1=cur1->next;
        }
        while(cur2){
            n2++;
            cur2=cur2->next;
        }
        ListNode*HeadLong=pHead1,*HeadShort=pHead2;
        int Dif=n1-n2;
        if(n2>n1){
            HeadLong=pHead2;
            HeadShort=pHead1;
            Dif=n2-n1;
        }
        for(int i=0;i<Dif;i++){//长链表的指针先走
            HeadLong=HeadLong->next;
        }
        while(HeadLong){
            if(HeadLong->val==HeadShort->val) return HeadLong;//找出第一个相等的
            else{
                HeadLong=HeadLong->next;
                HeadShort=HeadShort->next;
            }
        }
        return NULL;//找不到相等节点或者链表为空
    }
};
//190413
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode*p1=pHead1,*p2=pHead2;
        int n1=0,n2=0;
        while(p1){
            n1++;
            p1=p1->next;
        }
        while(p2){
            n2++;
            p2=p2->next;
        }
        int dif=n1-n2;
        ListNode*longlist=pHead1,*shortlist=pHead2;
        if(dif<0){
            longlist=pHead2;
            shortlist=pHead1;
            dif=-dif;
        }
        p1=longlist;
        p2=shortlist;
        for(int i=0;i<dif;i++) p1=p1->next;
        while(p1!=p2){
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
};
2、hash表  时间O(m+n)，空间O(m)
链接：https://www.nowcoder.com/questionTerminal/6ab1d9a29e88450685099d45c9e31e46
来源：牛客网
map法
classSolution {
public:
    ListNode* FindFirstCommonNode( ListNode *pHead1, ListNode *pHead2) {
        map<ListNode*, int> m;
        ListNode *p = pHead1;
        while(p != NULL) {
            m[p] = 1;
            p = p->next;
        }
        p = pHead2;
        while(p != NULL) {
            if(m[p]) {
                return p;
            }
            p = p->next;
        }
        return NULL;
    }
};
set法
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
          if(pHead1==NULL||pHead2==NULL)return NULL;
          unordered_multiset<ListNode*> hashset;
          ListNode *pNode1=pHead1,*pNode2=pHead2;
          //把链表2转存为哈希表
          while(pNode2!=NULL){
              hashset.insert(pNode2);
              pNode2=pNode2->next;
          }
          //遍历第一个链表
          while(pNode1!=NULL){
            if(hashset.find(pNode1)!=hashset.end()){
                return pNode1;
            }
            pNode1=pNode1->next;
          }
          return NULL;
    }
};
3、栈  时间O(m+n)，空间O(m+n)
class Solution {//超时
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        stack<ListNode*>s1,s2;
        ListNode*cur1=pHead1,*cur2=pHead2;
        while(cur1){
            s1.push(cur1);
            cur1=cur1->next;
        }
        while(cur2){
            s2.push(cur2);
            cur2=cur2->next;
        }
        if(s1.top()->val==s2.top()->val){
            while(!s1.empty()&&!s2.empty()){
                if(s1.top()->val!=s2.top()->val) return s1.top()->next;
                else{
                    s1.pop();
                    s2.pop();
                }
            }
            if(!s1.empty()) return pHead2;
            else return pHead1;
        }
        else return NULL;
    }
};
