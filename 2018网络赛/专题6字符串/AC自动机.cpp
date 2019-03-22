
struct node
{
    int count;  //�Ƿ�Ϊ 
    struct node *next[26];  //ÿ���ڵ���ӽڵ㣨26�������ӽڵ����26���� 
    struct node *fail;
    void init()
    {
        int i;
        for(i=0;i<26;i++)
            next[i]=NULL;
        count=0;
        fail=NULL;
    }
}*root;
void insert()
{
    int len,k;
    node *p=root;
    len=strlen(str);
    for(k=0;k<len;k++)
    {
        int pos=str[k]-'a';
        if(p->next[pos]==NULL)
        {
            p->next[pos]=new node;
            p->next[pos]->init();
            p=p->next[pos];
        }
        else 
            p=p->next[pos];
    }
    p->count++;
}
void getfail()
{
    int i;
    node *p=root,*son,*temp;
    queue<struct node *>que;
    que.push(p); 
    //bfs����failָ��
    while(!que.empty())
    {
        temp=que.front();
        que.pop();
        for(i=0;i<26;i++)
        {
            son=temp->next[i];
            if(son!=NULL)
            {
                if(temp==root) {son->fail=root;}
                else
                {
                    p=temp->fail;
                    while(p)//����Ѱ��һ��ʹ��node�ɳԽ��ַ�i
                    {
                        if(p->next[i])
                        {
                            son->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(!p)  son->fail=root;
                }
                que.push(son);
            }
        }
    }
}
void query()
{
    int len,i,cnt=0;
    len=strlen(str);
    node *p,*temp;
    p=root;
    for(i=0;i<len;i++)
    {
        int pos=str[i]-'a';
        while(!p->next[pos]&&p!=root)  p=p->fail;      
        p=p->next[pos];
        if(!p) p=root;
        temp=p;
        while(temp!=root)
        {
            if(temp->count>=0) 
            {
                cnt+=temp->count;
                temp->count=-1;  
            }
            else break; 
            temp=temp->fail; 
        }
    }
    printf("%d\n",cnt);
}
