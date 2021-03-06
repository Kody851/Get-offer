题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

题解：https://github.com/gatieme/CodingInterviews/tree/master/028-%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E6%8E%92%E5%88%97
全排列题型：https://blog.csdn.net/Jacky_chenjp/article/details/66477538?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase

P197
class Solution {//https://www.cnblogs.com/qqky/p/6918095.html； https://blog.csdn.net/zjxxyz123/article/details/79709240
public:
    vector<string> Permutation(string str) {
        vector<string>res;
        if(str.empty()) return res;
        helper(res, str, 0);
        sort(res.begin(),res.end());//按照字典序输出
        return res;
    }
    void helper(vector<string>&res, string str, int start){//遍历第start位的所有可能性
        if(start==str.size()-1){//一次遍历的结束条件
            res.push_back(str);
            return;
        }
        for(int i=start;i<str.size();i++){
            if(i!=start && str[i]==str[start]) continue;//有与begin位重复的字符串不进行交换，跳过
            swap(str[i],str[start]);//当i==begin时，也要遍历其后面的所有字符;
                                   //当i!=begin时，先交换，使第begin位取到不同的可能字符，再遍历后面的字符
            helper(res,str,start+1);
            swap(str[i],str[start]);//为了防止重复的情况，还需要将begin处的元素重新换回来
        }
    }
};
输入abc
若不排序，输出为[abc,acb,bac,bca,cba,cab] 后两个出错了
过程：abc,acb,abc,bac,bca,bac,abc,cba,cab
