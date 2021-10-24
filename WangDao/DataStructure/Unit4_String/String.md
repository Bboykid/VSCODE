4.1.2
    串的存储结构
    1.定长顺序存储
        #define MAXLEN 255
        typedef struct {
            char ch[MAXLEN];
            int length;
        }SString;
    2.堆分配存储（动态）
        typedef struct{
            char *ch;
            int length;
        }HString;

4.1.3 串的基本操作
    StrAssign(&T,chars):赋值操作。把串T赋值为chars
    StrCopy(&T,S):赋值操作，由串S复制得到串T
    StrEmpty(S)
    StrCompare(S,T)
    StrLength(S)
    SubString(&Sub,S,pos,len):求子串。用Sub返回S串第pos个字符起长度为len的子串
    Concat(&T,S1,S2):串连接。用T返回S1和S2连接的新串
    Index(S,T):定位操作
    ClearString
    DestroyString

4.2 串的模式匹配
    4.2.1 简单模式匹配
        int Index(SString S,SString T)
        {
            int k = 1;
            int i =k,j=1;
            while(S<=S.length && j<=T.length)
            {
                if(S.ch[i]==T.ch[i])
                {
                    ++i;
                    ++j;
                }
                else
                {
                    k++;//指针后退重新开始匹配
                    i=k;
                    j=1;
                }
            }
            if(j>T.length)
                return k;
            else
                return 0;
        }
    4.2.2 改进的模式匹配算法——KMP算法
        
    