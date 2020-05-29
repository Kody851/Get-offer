题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
输出描述:
如果当前字符流没有存在出现一次的字符，返回#字符。
class Solution
{
public:
  //Insert one char from stringstream
    unsigned int hash[256]={0};//char hash[256]={0}也行
    string s;
    void Insert(char ch)
    {
        s+=ch;
        hash[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(int i=0;i<s.size();i++){
            if(hash[s[i]]==1) return s[i];
        }
        return '#';
    }
};

剑指offer版：
链接：https://www.nowcoder.com/questionTerminal/00de97733b8e4f97a3fb5c680ee10720
来源：牛客网

利用一个int型数组表示256个字符，这个数组初值置为-1.
没读出一个字符，将该字符的位置存入字符对应数组下标中。
若值为-1标识第一次读入，不为-1且》0表示不是第一次读入，将值改为-2.
之后在数组中找到>0的最小值，该数组下标对应的字符为所求。
public class Solution {
    //Insert one char from stringstream
    private int[] occurence = new int[256];
    private int index;
    
    public Solution(){
        for(int i=0;i<256;i++){
            occurence[i] = -1;
        }
        index = 0;
    }
    void Insert(char ch)
    {
        if(occurence[ch] == -1)
            occurence[ch] = index;
        else if(occurence[ch] >= 0)
            occurence[ch] = -2;
        
        index++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char ch = '\0';
        int minIndex = Integer.MAX_VALUE;
        for(int i=0;i<256;i++){
            if(occurence[i] >=0 && occurence[i]<minIndex){
                ch = (char)i;
                minIndex = occurence[i];
            }
        }
        if(ch == '\0')
            return '#';
        return ch;
    }
}
class Solution
{
public:
    private: int occurrence[256];
    private: int index;
    public: Solution(){
        for(int i=0;i<256;i++) occurrence[i]=-1;
        index=0;
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if(occurrence[ch]==-1) occurrence[ch]=index;
        else occurrence[ch]=-2;
        index++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char ch='\0';
        int minIndex=INT_MAX;
        for(int i=0;i<256;i++){
            if(occurrence[i]>=0&&occurrence[i]<=minIndex){
                ch=(char) i;//ch=i;
                minIndex=occurrence[i];
            }
        }
        return ch!='\0' ? ch : '#';
    }

};
