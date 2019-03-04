#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

#define TRUE            1
#define FALSE           0
#define OK              1
#define ERROR           0
#define INFEASIBLE      -1
#define OVERFLOW        -2

typedef struct LNode
{
    int data;
    struct LNode *prior;
    struct LNode *next;
}LNode, *LinkList;

void List_Print(LinkList &L)
{
    LinkList p;
    p=L->next;
    while(p!=L)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<endl;
    return;
}

void List_Create(LinkList &L)  //建立双向循环链表L
{
    L=(LinkList)malloc(sizeof(LNode));  //建立头节点
    if(!L)exit(OVERFLOW);
    L->data=0;
    L->next=L;
    L->prior=L;
    int n,e;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        LinkList p;
        p=(LinkList)malloc(sizeof(LNode));
        if(!p)exit(OVERFLOW);
        cin>>e;
        p->data=e;
        p->prior=L->prior;
        p->prior->next=p;
        p->next=L;
        L->prior=p;
        L->data++;
    }
    List_Print(L);
    return;
}

int List_Insert(LinkList &L,int i,int e)
{
    LinkList p=L;
    int j=0;
    while((j<L->data)&&(j<i-1))
    {
        p=p->next;
        j++;
    }
    if((j>L->data)||(j>i-1))return ERROR;
    LinkList q;
    q=(LinkList)malloc(sizeof(LNode));
    if(!q)exit(OVERFLOW);
    q->data=e;
    q->prior=p;
    q->next=q->prior->next;
    q->prior->next=q;
    q->next->prior=q;
    L->data++;
    return OK;
}

int List_Delete(LinkList &L,int i)
{
    LinkList p=L->next;
    int j=1;
    while((j<=L->data)&&(j<i))
    {
        p=p->next;
        j++;
    }
    if((j>L->data)||(j>i))return ERROR;
    LinkList q=p;
    q->prior->next=q->next;
    q->next->prior=q->prior;
    free(q);
    L->data--;
    return OK;
}

int List_Search(LinkList L,int e)
{
    LinkList p=L->next;
    for(int i=1;i<=L->data;i++)
    {
        if(e==p->data)return i;
        p=p->next;
    }
    return -1;
}

int main()
{
    LinkList L;
    List_Create(L);
    int i,e,flag;
    cin>>i>>e;
    flag=List_Insert(L,i,e);
    if(flag)List_Print(L);
    else cout<<-1<<endl;
    cin>>i;
    flag=List_Delete(L,i);
    if(flag)List_Print(L);
    else cout<<-1<<endl;
    cin>>e;
    cout<<List_Search(L,e)<<endl;
    cout<<L->data;
    return 0;
}
