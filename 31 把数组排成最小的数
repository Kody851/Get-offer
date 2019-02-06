题目描述
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
@知识点：
1、to_string函数，
int a=123;
string b;
b+=to_string(a);
2、sort中的cmp
vector<int>a{3,1,2,4};
sort(a.begin(),a.end(),cmp);
static bool cmp(int a, int b){
        return a>b;//降序
    }

    
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        int n=numbers.size();
        string res="";
        if(n==0) return res;
        vector<string>numstr(n);
        for(int i=0;i<n;i++){
            numstr[i]=to_string(numbers[i]);
        }
        sort(numstr.begin(),numstr.end(),cmp);
        for(int i=0;i<n;i++){
            res+=numstr[i];
        }
        return res;
    }
    static bool cmp(string a, string b){
        return a+b<b+a;//举例，a="12",b="34",a+b=1234<3412=b+a,故排序时a在b前。
    }
};
