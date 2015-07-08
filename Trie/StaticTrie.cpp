#define Max 10005
int getId(char c)
{
    return c>='a'?c-'a':c-'A'+26;
}
struct Trie
{
    struct Tree
    {
        int Next[52];
        bool word;
        void clear()
        {
            word=false;
            memset(Next,-1,sizeof(Next));
        }
    }T[Max];
    int ptr;
    void clear()
    {
        ptr=1;
        T[0].clear();
        memset(T[0].Next,0,sizeof(T[0].Next));
    }
    void Insert(const char *str)
    {
        int p=0;
        for(int i=0;str[i];i++)
        {
            int id=getId(str[i]);
            if(T[p].Next[id]<=0)
            {
                T[p].Next[id]=ptr;
                T[ptr++].clear();
            }
            p=T[p].Next[id];
        }
        T[p].word=true;
    }
    bool Search(const char *str)
    {
        int p=0;
        for(int i=0;str[i];i++)
        {
            int id=getId(str[i]);
            if(T[p].Next[id]>0)
            {
                p=T[p].Next[id];
            }
            else return false;
        }
        return T[p].word;
    }
};
Trie A;
