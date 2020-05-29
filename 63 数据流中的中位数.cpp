题目描述
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。我们使用Insert()方法读取数据流，
使用GetMedian()方法获取当前读取数据的中位数。
@知识点
1、
==比&优先，使用&时一定要加括号。
2、
建堆：
vector<int>a;//先建数组
make_heap(a.begin(),a.end(),less<int>());建最大堆
make_heap(a.begin(),a.end(),greater<int>());建最小堆
//添加元素
a.push_back(num);
push_heap(a.begin(),a.end(),less<int>());
//删除堆顶元素
pop_heap(a.begin(),a.end(),less<int>());
a.pop_back();
博客：https://blog.csdn.net/morewindows/article/details/6709644
https://blog.csdn.net/morewindows/article/details/6967409

最优解： 最大堆与最小堆，将数组平均分为两份，分别作为最大堆与最小堆，最大堆的元素全部小于最小堆。通过两堆的堆顶确定中位数。
class Solution {
public:
    vector<int>max,min;
    void Insert(int num)
    {
        if(((max.size()+min.size())&0x1)==0){//总数是偶数，num添加到最小堆
            if(max.size()>0&&num<max[0]){//如果要添加的数小于最大堆堆顶，则先加到最大堆，弹出堆顶，把堆顶元素加到最小堆。保证最大堆元素都小于最小堆。
                max.push_back(num);
                push_heap(max.begin(),max.end(),less<int>());
                num=max[0];
                pop_heap(max.begin(),max.end(),less<int>());
                max.pop_back();
                min.push_back(num);
                push_heap(min.begin(),min.end(),greater<int>());
            }
            else{
                min.push_back(num);
                push_heap(min.begin(),min.end(),greater<int>());
            }
        }
        else{//总数是奇数，num添加到最大堆
            if(min.size()>0&&num>min[0]){
                min.push_back(num);
                push_heap(min.begin(),min.end(),greater<int>());
                num=min[0];
                pop_heap(min.begin(),min.end(),greater<int>());
                min.pop_back();
                max.push_back(num);
                push_heap(max.begin(),max.end(),less<int>());
            }
            else{
                max.push_back(num);
                push_heap(max.begin(),max.end(),less<int>());
            }
        }
    }

    double GetMedian()
    { 
        if (min.size() + max.size() == 0) return 0;
        if(((max.size()+min.size())&0x1)==0)
            return ((double)max[0]+(double)min[0])/2.0;
        else return (double)min[0];
    }
};
