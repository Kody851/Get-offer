题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

@知识点
双端队列
deque<int>dq;
dq.back()  dq.front()   dq.push_back()  dq.pop_back()  dq.pop_front()


class Solution {//剑指P290
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int>res;
        if(num.empty()||size<=0||size>num.size()) return res;
        deque<int>index;//双端队列
        for(unsigned int i=0;i<size;i++){
            while(!index.empty()&&num[i]>num[index.back()])
                index.pop_back();
            index.push_back(i);
        }
        for(unsigned int i=size;i<num.size();i++){
            res.push_back(num[index.front()]);
            while(!index.empty()&&num[i]>num[index.back()])
                index.pop_back();
            if(!index.empty()&&(i-dq.front()>=size))
                index.pop_front();
            index.push_back(i);
        }
        res.push_back(num[index.front()]);
        return res;
    }
};
