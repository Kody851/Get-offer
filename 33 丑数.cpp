题目描述
把只包含质因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含质因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

1、直接法
class Solution {//复杂度过大
public:
    int GetUglyNumber_Solution(int index) {
        if(index<=0) return 0;
        int count=0;
        int number=1;
        while(count<index){
            if(isUgly(number)) count++;
            number++;
        }
        return number;
    }
    bool isUgly(int num){//判断一个数是不是丑数
        while(num%2==0) num/=2;
        while(num%3==0) num/=3;
        while(num%5==0) num/=5;
        if(num==1) return true;
        else return false;
    }
};

2、空间换时间（最优解）
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<=0) return 0;
        vector<int>array;
        int p2=0,p3=0,p5=0,tmp=1;
        array.push_back(tmp);
        while(array.size()<index){
            tmp=min(array[p2]*2, min(array[p3]*3,array[p5]*5));
            if(tmp==array[p2]*2) p2++;
            if(tmp==array[p3]*3) p3++;
            if(tmp==array[p5]*5) p5++;
            array.push_back(tmp);
        }
        return array[index-1];
    }
};
/*链接：https://www.nowcoder.com/questionTerminal/6aa9e04fc3794f68acf8778237ba065b
来源：牛客网
 
通俗易懂的解释：
首先从丑数的定义我们知道，一个丑数的因子只有2,3,5，那么丑数p = 2 ^ x * 3 ^ y * 5 ^ z，换句话说一个丑数一定由另一个丑数乘以2或者乘以3或者乘以5得到，那么我们从1开始乘以2,3,5，就得到2,3,5三个丑数，在从这三个丑数出发乘以2,3,5就得到4，6,10,6，9,15,10,15,25九个丑数，我们发现这种方法会得到重复的丑数，而且我们题目要求第N个丑数，这样的方法得到的丑数也是无序的。那么我们可以维护三个队列：*/
