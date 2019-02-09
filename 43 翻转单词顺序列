//trick：多次翻转
先翻转整个序列，再翻转每个单词

class Solution {
public:
    string ReverseSentence(string str) {
        int n=str.size();
        if(n==0) return str;
        //每个单词反转
        int start=0,end=0;
        for(int i=0;i<n;i++){
            if(str[i]==' '){
                end=i-1;
                myReverse(str,start,end);
                start=i+1;
            }
        }
        myReverse(str,start,n-1);//最后一个单词翻转，它后面没有空格了，在for循环里执行不到
        //全句反转
        myReverse(str,0,n-1);
        return str;
    }
    void myReverse(string &str, int i, int j){
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



class Solution {
public:
    string ReverseSentence(string str) {
        int n=str.size();
        if(n==0) return str;
        reverse(str, 0, n-1);
        int start=0;
        for(int i=0;i<n;i++){
            if(str[i]==' ') {
                reverse(str, start, i-1);
                start=i+1;
            }
        }
        reverse(str, start, n-1);//注意考虑这一条
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
