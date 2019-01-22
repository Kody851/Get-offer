题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

@知识点：
对于char* string，要求长度，使用strlen(string)

class Solution {
public:
    bool isNumeric(char* string)
    {
        int n=strlen(string);
        if(n==0) return false;
        if((string[0]>'9'||string[0]<'0')&&string[0]!='+'&&string[0]!='-'&&string[0]!='.') return false;//第一位只可能为数字、.、+-
        if(string[n-1]>'9'||string[n-1]<'0') return false;//最后一位必须是数字;当只有一位的时候，它需满足更苛刻的最后一位的条件。
        int count_dot=0,count_e=0,count_sign=0,index_dot=0,index_e=0;
        for(int i=1;i<n-1;i++){
            if((string[i]>'9'||string[i]<'0')&&string[i]!='+'&&string[i]!='-'&&string[i]!='e'&&string[i]!='E'&&string[i]!='.')
                return false;//排除不可能的字符
            if(string[i]=='.') {
                count_dot++;
                index_dot=i;
                if((string[i-1]>'9'||string[i-1]<'0')&&string[i-1]!='+'&&string[i-1]!='-'||string[i+1]>'9'||string[i+1]<'0') return false;
                //由测试样例知，“-.123”是数
                //小数点前是数字或+-，小数点后是数字
            }
            if(string[i]=='e'||string[i]=='E') {
                count_e++;
                index_e=i;
                if((string[i-1]>'9'||string[i-1]<'0'||string[i+1]>'9'||string[i+1]<'0')&&string[i+1]!='+'&&string[i+1]!='-') return false;
                //e/E前是数字，e后数字或+-
            }
            if(string[i]=='+' || string[i]=='-') {
                count_sign++;
                if(string[i-1]!='e'&&string[i-1]!='E'||string[i+1]>'9'||string[i+1]<'0') return false;
                //+-前是e，后是数字
            }
        }
        if(count_dot>1 || count_e>1 || count_sign>1) return false;//除首位外，.、+-、e最多出现一次
        if(count_dot==1&&string[0]=='.') return false;//首位若是.，后面不能出现.
        if(count_dot==1&&count_e==1&&index_dot>index_e) return false;//小数点不能出现在e的后面
        return true;
    }

};
