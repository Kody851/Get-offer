题目描述
请实现两个函数，分别用来序列化和反序列化二叉树
@知识点1
string转char*
法1：char*res=new char[s.size()];//先申请内存
     strcpy(res,s.c_str());再复制
法2： char* chr = strdup(s.c_str());//无需申请内存，用完要free()函数释放内存，否则内存泄漏
@知识点2
strcat(ret, left);
strcat(ret, right);//字符串连接
@知识点3
atoi()的参数是 const char* ,因此对于一个字符串str我们必须调用 c_str()的方法把这个string转换成
const char*类型的,而stoi()的参数是const string*,不需要转化为 const char*。
string s1 = "2147482", s2 = "-214748";

string s3 = "214748666666663", s4 = "-21474836488";

cout << stoi(s1) << endl;

cout << stoi(s2) << endl;

cout << atoi(s3.c_str()) << endl;

cout << atoi(s4.c_str()) << endl;
--------------------- 
原文：https://blog.csdn.net/qq_33221533/article/details/82119031 

解答
法1
class Solution {  
public:
    char* Serialize(TreeNode *root) {    
        string s="";
        SerializeHelper(root, s);
        char*res=new char[s.size()];//把string变成char*
        strcpy(res,s.c_str());
        return res;
    }
    void SerializeHelper(TreeNode *root, string &s){
        if(!root) {
            s+='#';
            //s+=',';//不能加此行
            return;
        }
        s+=to_string(root->val);
        s+=',';
        SerializeHelper(root->left, s);
        SerializeHelper(root->right, s);
    }
    TreeNode* Deserialize(char *str) 
    {
        if(str==NULL)
            return NULL;
        TreeNode* ret=DeserializeHelper(str);
        return ret;
    
    }
    TreeNode* DeserializeHelper(char*& str)
    {
        if(*str=='#')
        {
            str++;
            return NULL;
        }
        int num=0;
        while(*str!='\0'&&*str!=',')
        {
            num=num*10+((*str)-'0');//对于两位数及以上，需要累加
            str++;
        }
        TreeNode* root=new TreeNode(num);
        if(*str=='\0') return root;
        else str++;
        root->left=DeserializeHelper(str);
        root->right=DeserializeHelper(str);
        return root;
    }
};
法2
class Solution {
public:
    char* Serialize(TreeNode *pRoot) {
        string s;
        if (!pRoot)
            return NULL;
        deque<TreeNode*> q;
        q.push_back(pRoot);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                if (q.front()) {
                    q.push_back(q.front()->left);
                    q.push_back(q.front()->right);
                    s += to_string(q.front()->val) + ' ';
                } else {
                    s += "# ";
                }
                q.pop_front();
            }
        }
        char* chr = strdup(s.c_str());
        return  chr;
    }
    TreeNode* Deserialize(char *str) {
        if (!str)
            return nullptr;
        int k = 0;
        auto ret = nextNode(str, k);
        deque<TreeNode*> q;
        q.push_back(ret);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {               
                q.front()->left = nextNode(str, k);
                q.front()->right = nextNode(str, k);
                if (q.front()->left)
                    q.push_back(q.front()->left);
                if (q.front()->right)
                    q.push_back(q.front()->right);
                q.pop_front();
            }
        }
        return ret;
    }
    TreeNode* nextNode(char *str,int &i) {
        string s;
        while (str[i] != '\0'&&str[i] != ' ') {
            if (str[i] == '#') {
                i += 2;
                return nullptr;
            }
            s += str[i];
            i++;
        }
        if (str[i] == ' ')
            i++;
        if (!s.empty())
            return new TreeNode(stoi(s));
        return nullptr;
    }
};
