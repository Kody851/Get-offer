题目描述
请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

class Solution {//本题的思路是从后往前算
public:
    void replaceSpace(char *str,int length) {
        if(str==NULL||length<0) return;
        int num_space=0,len=0;
        int i=0;
        while(str[i]!='\0'){
            len++;
            if(str[i]==' ') num_space++;
            i++;
        }
        /*int len=strlen(str);//获取str长度（‘\0’前的长度）
        int num_space=0;
        for(int i=0;i<len;i++){
            if(str[i]==' ') num_space++;
        }*/
        int len_new=len+2*num_space;
        if(len_new>length) return;//该题目char *str=new char[length];length是定义的空间大小，len后都是'\0'（好几个）
        int p1=len, p2=len_new;//需要从'\0'开始！
        while(p1>=0&&p2>=0){
            if(str[p1]!=' '){
                str[p2]=str[p1];
                p1--;
                p2--;
            }
            else{
                str[p2--]='0';
                str[p2--]='2';
                str[p2--]='%';
                p1--;
            }
        }
    }
};
