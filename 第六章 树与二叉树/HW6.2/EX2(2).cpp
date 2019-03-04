#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<cstring>

using namespace std;

#define TRUE            1
#define FALSE           0
#define OK              1
#define ERROR           0
#define INFEASIBLE      -1
#define OVERFLOW        -2

typedef enum PointerTag{Link,Thread};  //Link==0：指针，Thread==1：线索

typedef struct BiThrNode
{
    char data;
    struct BiThrNode *lc,*rc;  //左右孩子指针
    PointerTag LTag,RTag;  //左右标记
}BiThrNode,*BiThrTree;

BiThrTree Pre;
BiThrTree prevv;
BiThrTree succ;

int BiThrTree_Create(BiThrTree &T) //按先序遍历输入构造二叉树
{
    char c;
    cin>>c;
    if(c=='#')
    {
        T=NULL;
        return ERROR;
    }
    else
    {
        if(!(T=(BiThrNode *)malloc(sizeof(BiThrNode))))
            exit(OVERFLOW);
        else
        {
            T->data=c;
            if(BiThrTree_Create(T->lc))
                T->LTag=Link;
            if(BiThrTree_Create(T->rc))
                T->RTag=Link;
        }
    }
    return OK;
}

void In_Order_Threading(BiThrTree &T)  //中序遍历建立线索二叉树
{
    if(!T)return;
    if(T->LTag==Link)
        In_Order_Threading(T->lc);
    if(!T->lc)
    {
        T->LTag=Thread;
        T->lc=Pre;
    }
    if(Pre)
    {
        if(!Pre->rc)
        {
            Pre->RTag=Thread;
            Pre->rc=T;
        }
    }
    Pre=T;
    if(T->RTag==Link)
        In_Order_Threading(T->rc);
    return;
}

void In_Order_Visit(BiThrTree T,char c,BiThrTree &N)
{
    if(!T)return;
    while(T)
    {
        while(T->LTag==Link)
            T=T->lc;
        cout<<T->data;
        if(N&&!succ)
            succ=T;
        if(T->data==c)
            N=T;
        if(!N)
            prevv=T;
        while(T->rc&&T->RTag==Thread)
        {
                T=T->rc;
                cout<<T->data;
                if(N&&!succ)
                    succ=T;
                if(T->data==c)
                    N=T;
                if(!N)
                    prevv=T;
        }
        T=T->rc;
    }
    return;
}

int main()
{
    BiThrTree T;
    BiThrTree_Create(T);
    Pre=NULL;
    In_Order_Threading(T);
    Pre->RTag=Thread;
    Pre->rc=NULL;
    char c;
    cin>>c;
    BiThrTree N=NULL;
    In_Order_Visit(T,c,N);
    cout<<endl;
    if(N)
    {
        if(succ)
            cout<<"succ is "<<succ->data<<succ->RTag<<endl;
        else
            cout<<"succ is NULL"<<endl;
        if(prevv)
            cout<<"prev is "<<prevv->data<<prevv->LTag<<endl;
        else
            cout<<"prev is NULL"<<endl;
    }
    else
        cout<<"Not found";
    return 0;
}

