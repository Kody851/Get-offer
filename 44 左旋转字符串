题目描述
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。

1、技巧：左部分翻转，右部分翻转，整体翻转，搞定！
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int size=str.size();
        if(size==0||n<0) return str;
        if(n>size) n=n%size;
        reverse(str, 0, n-1);
        reverse(str, n, size-1);
        reverse(str, 0, size-1);
        return str;
    }
    void reverse(string &str, int i, int j){
        if(i>=j) return;
        while(i<j){
            char tmp=str[i];
            str[i]=str[j];
            str[j]=tmp;
            i++;
            j--;
        }
    }
};

2、两部分分别赋值
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int size=str.size();
        if(size==0||n<0) return str;
        if(n>size) n=n%size;
        string res="";//辅助变量
        for(int i=n;i<size;i++){
            res+=str[i];
        }
        for(int i=0;i<n;i++){
            res+=str[i];
        }
        return res;
    }
};

3、拼接、取值
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int size=str.size();
        if(size==0||n<0) return str;
        if(n>size) n=n%size;
        str+=str;//拼接
        return str.substr(n,size);//使用函数 substr
    }
};
4、substr
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len=str.size();
        if(n<=0||len==0) return str;
        if(n>len) n=n%len;
        return str.substr(n,len-n)+str.substr(0,n);
    }
};
