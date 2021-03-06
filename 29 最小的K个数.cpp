题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

1、最大堆 O(nlogk)适合处理海量数据
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.empty()||k<=0||k>input.size()) return vector<int>();
        vector<int>res(input.begin(),input.begin()+k);
        make_heap(res.begin(),res.end(),less<int>());//最大堆
        for(int i=k;i<input.size();i++){
            if(input[i]<res[0]){//若小，把堆顶去掉，新数入堆
                pop_heap(res.begin(),res.end(),less<int>());
                res.pop_back();
                res.push_back(input[i]);
                push_heap(res.begin(),res.end(),less<int>());
            }
        }
        //sort_heap(res.begin(),res.end());//排序
        return res;
    }
};
堆排序手动实现：
void Maxheapsort(vector<int>&a)
{
    int n=a.size();
    //先建堆，最大堆的排序是递增的
    for (int i =n/2-1; i>=0; i--) MaxHeap(a, i, n-1);//只需处理有孩子的节点
    //堆排序
    for (int i=n-1; i>=1; i--){
	swap(a[i], a[0]);
	MaxHeap(a, 0, i-1);
    }
}
//  从i节点开始调整,n为节点总数 从0开始计算 i节点的子节点为 2*i+1, 2*i+2
void MaxHeap(vector<int>&a, int i, int m)//i为要处理的节点标号，m为最后一个节点编号
{
    int j, temp;
    temp = a[i];
    for(j=2*i+1;j<=m;j=2*j+1){//左孩子标号为2j+1
	if (j<m&&a[j]<a[j+1])//在左右孩子中找最小的
		j++;
	if(temp>=a[j]) break;
	a[i] = a[j];     //把较小的子结点往上移动,替换它的父结点
	i = j;
    }
    a[i] = temp;
}
参考：1、大话数据结构P399
     2、https://blog.csdn.net/morewindows/article/details/6709644 
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int n=input.size();
        if(n==0||k<=0||k>n) return vector<int>();
        vector<int>res(input.begin(),input.begin()+k);
        for (int i =k/2-1; i>=0; i--) MaxHeap(res, i, k-1);//建最大堆
        for(int i=k;i<input.size();i++){
            if(input[i]<res[0]){//若小，把堆顶去掉，新数入堆
                res[0]=input[i];
                MaxHeap(res, 0, k-1);
            }
        }
        return res;
    }
    void MaxHeap(vector<int>&a, int i, int m){
        int j, temp;
        temp = a[i];
        for(j=2*i+1;j<=m;j=2*j+1){
            if (j<m&&a[j]<a[j+1])//在左右孩子中找最小的
                j++;
            if(temp>=a[j]) break;
            a[i] = a[j];     //把较小的子结点往上移动,替换它的父结点
            i = j;
        }
        a[i] = temp;
    }
};
-------------------------------------------------------------------------
2、最大堆 multiset（红黑树）实现
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int>res;
        if(input.empty()||k<=0||k>input.size()) return res;
        multiset<int,greater<int>>LeastNumbers;//从大到小排序（允许重复排序）的multiset
        multiset<int,greater<int>>::iterator iterGreatest;//设置迭代器
        for(int i=0;i<input.size();i++){
            if(LeastNumbers.size()<k) LeastNumbers.insert(input[i]);
            else{
                iterGreatest=LeastNumbers.begin();
                if(input[i]<*iterGreatest){
                    LeastNumbers.erase(iterGreatest);
                    LeastNumbers.insert(input[i]);
                }
            }
        }
        for(iterGreatest=LeastNumbers.begin();iterGreatest!=LeastNumbers.end();iterGreatest++){
            res.push_back(*iterGreatest);
        }
        return res;
    }
};
//vector也可设置迭代器
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int>res;
        if(input.empty()||k<=0||k>input.size()) return res;
        multiset<int,greater<int>>LeastNumbers;
        multiset<int,greater<int>>::iterator iterGreatest;
        vector<int>::iterator iterInput=input.begin();
        for(;iterInput!=input.end();iterInput++){
            if(LeastNumbers.size()<k) LeastNumbers.insert(*iterInput);
            else{
                iterGreatest=LeastNumbers.begin();
                if(*iterInput<*iterGreatest){
                    LeastNumbers.erase(iterGreatest);
                    LeastNumbers.insert(*iterInput);
                }
            }
        }
        for(iterGreatest=LeastNumbers.begin();iterGreatest!=LeastNumbers.end();iterGreatest++){
            res.push_back(*iterGreatest);
        }
        return res;
    }
};
3、最小堆 O(klogn)
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int>res;
        if(input.empty()||k<=0||k>input.size()) return res;
        make_heap(input.begin(),input.end(),greater<int>());//建立最小堆
        for(int i=0;i<k;i++){//k次弹出堆顶，即最小的k个数字
            res.push_back(input[0]);
            pop_heap(input.begin(),input.end(),greater<int>());
            input.pop_back();
        }
        return res;
    }
}

4、Partition函数,O(n),但会修改原来数组
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int>res;
        if(input.empty()||k<=0||k>input.size()) return res;
        int start=0,end=input.size()-1;
        int index=Partition(input,start,end);
        while(index!=k-1){//这里用k-1，表示index左边有k-1个，连上index共k个数。防止k=input.size()-1时出现异常
            if(index>k-1){
                end=index-1;
                index=Partition(input,start,end);
            }
            if(index<k-1){
                start=index+1;
                index=Partition(input,start,end);
            }
        }
        for(int i=0;i<k;i++) res.push_back(input[i]);
        return res;
    }
    int Partition(vector<int> &input, int start, int end){
        int small=start-1;
        for(int i=start;i<end;i++){
            if(input[i]<input[end]){
                small++;
                if(small!=i) swap(input[small],input[i]);
            }
        }
        small++;
        swap(input[small],input[end]);
        return small;
    }
};
