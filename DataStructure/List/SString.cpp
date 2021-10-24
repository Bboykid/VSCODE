
#define  MAXLEN 255
typedef struct SString
{
    /* data */
    char  ch[MAXLEN];
    int length;
}SString;

typedef struct
{
    /* data */
    char *ch;
    int length;
}HString;


bool SubString(SString &Sub, SString S, int pos, int len)
{
    if(pos + len -1 > S.length )
        return false;
    for(int i = pos ; i < pos + len; i++)
    {
        Sub.ch[i-pos+1] = S.ch[i];
    }
    Sub.length = len;
    return true;
}



int StrCompare(SString S, SString T)
{
    for(int i = 1 ; i<=S.length && i <= T.length; i++)
    {
        if(S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    return S.length - T.length;
}

/**
int Index(SString S, SString T)
{
    int i = 1;
    int len1 = S.length;
    int len2 = T.length;
    SString temp;
    while(i+len2-1 <= len1)
    {
        SubString(temp,S,i,len2);
        if(StrCompare(temp,T)==0)
            return i;
        else
            ++i;
    }
    //不存在
    return 0;
}
**/

int Index(SString S, SString T)
{
    int k = 1;
    int i = k, j = 1;
    while(i<=S.length && j<= T.length) {
        if(S.ch[i] == S.ch[j])
        {
            ++i;
            ++j;
        } else {
            k++;
            i = k;
            j = 1;
        }
    }
    if( j > T.length )
        return k;
    else
        return 0;   
}

void get_next(SString T, int *next)
{
    int i=1,j=0;
    next[1]=0;
    //*******************//
    while( i < T.length )
    {
        if( j == 0 || T.ch[i] == T.ch[j] )
        {
            ++i;
            ++j;
            next[i]=j;
        }
        else
            j = next[j];
    }
}

int KMP(SString S, SString T)
{
    int i =1, j =1;
    int next[MAXLEN];
    get_next(T,next);
    while(i <= S.length && j <=T.length)
    {
        if( j == 0 || S.ch[i] == T.ch[j] )
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if(j>T.length)
        return i - T.length;
    else 
        return 0;
}

