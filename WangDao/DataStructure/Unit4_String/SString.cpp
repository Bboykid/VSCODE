
   #define MAXLEN 255
        typedef struct {
            char ch[MAXLEN];
            int length;
        }SString;


void get_next(SString T,int next[])
{
    int i=1,j=0;
    next[1] = 0;
    while( i<T.length )
    {
        if( j==0 || T.ch[i]==T.ch[j] )
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

int Index_KMP(SString S, SString T)
{
    int next[T.length+1];
    get_next(T,next);
    int i=1,j=1;
    while( i<=S.length &&j<=T.length )
    {
        if( j==0 && S.ch[i]!=T.ch[j] )
        {
            i++;
            j++;
        }
        else
            j = next[j];
    }
    if( j>T.length )
        return i-T.length;//匹配成功
    else    
        return 0;
}