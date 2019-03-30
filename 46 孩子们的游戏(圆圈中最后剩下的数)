题目描述
每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。HF作为牛客的资深元老,自然也准备了一些小游戏。
其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。然后,他随机指定一个数m,让编号为0的小朋友开始报数。
每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....
这样下去....直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)

class Solution {//用数组模拟环
public:
    int LastRemaining_Solution(int n, int m)
    {
        vector<int>array(n,0);
        int i=-1, step=0, count=n;
        while(count>0){//跳出循环时将最后一个元素也设置为了-1
            i++;
            if(i==n) i=0;//环
            if(array[i]==-1) continue;//跳过被删除的对象
            step++;//位置很重要，必须放在continue后面
            if(step==m){//找到待删除的对象
                step=0;
                array[i]=-1;
                count--;
            }
        }
        return i;//返回跳出循环时的i,即最后一个被设置为-1的元素
    }
};
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        vector<int>a(n);
        int i=-1,NumOfDelete=0,step=-1;
        while(NumOfDelete<n){//删除元素个数，全删掉，i指向最后一个删掉的
            i++;
            if(i==n) i=0;
            if(a[i]==-1){
                continue;
            }
            step++;
            if(step==m-1){
                a[i]=-1;
                NumOfDelete++;
                step=-1;
            }
        }
        return i;
    }
};
