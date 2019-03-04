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
    struct LNode *next;
}LNode, *LinkList;

void List_Print(LinkList &L)
{
    LinkList p;
    p=L->next;
    while(p!=NULL)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<endl;
    return;
}

int List_Insert(LinkList &L,int i,int e)
{
    LinkList p=L;
    int j=0;
    while((p)&&(j<i-1))
    {
        p=p->next;
        j++;
    }
    if((!p)||(j>i-1))return ERROR;
    LinkList q;
    q=(LinkList)malloc(sizeof(LNode));
    if(!q)exit(OVERFLOW);
    q->data=e;
    q->next=p->next;
    p->next=q;
    L->data++;
    return OK;
}

void List_Create(LinkList &L)  //建立单链表L
{
    L=(LinkList)malloc(sizeof(LNode));  //建立头节点
    if(!L)exit(OVERFLOW);
    L->data=0;
    L->next=NULL;
    int e;
    cin>>e;
    while(e)
    {
        LinkList p=L->next;
        int j=1;
        while(p)
        {
            if(p->data>=e)break;
            p=p->next;
            j++;
        }
        List_Insert(L,j,e);
        cin>>e;
    }
    return;
}

void List_Merge(LinkList L1,LinkList L2,LinkList &L)
{
    LinkList p1=L1->next;
    LinkList p2=L2->next;
    L=L1;
    LinkList p=L1;
    while(p1&&p2)
    {
        if(p1->data<=p2->data)
        {
            p->next=p1;
            p=p1;
            p1=p1->next;
        }
        else
        {
            p->next=p2;
            p=p2;
            p2=p2->next;
        }
    }
    p->next=p1?p1:p2;
    free(L2);
    return;
}

int main ()
{
    LinkList L1,L2,L;
    List_Create(L1);
    List_Create(L2);
    List_Merge(L1,L2,L);
    List_Print(L);
    return 0;
}
