//
//  main.cpp
//  LinkList
//
//  Created by Agrroc-mac on 2018/8/12.
//  Copyright © 2018年 Agrroc-mac. All rights reserved.
//

#include <iostream>
#include <stdio.h>

//定义链表节点
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode;

//定义双链表节点
typedef struct DLNode{
    int data;
    struct DLNode *llink;
    struct DLNode *rlink;
}DLNode;

//创建双链表的函数——头插法
void creatDLinkListH(DLNode *&head){
    head= (DLNode *)malloc(sizeof(DLNode));
    head->rlink= NULL;
    head->llink= NULL;
    DLNode *p= NULL;
    printf("请输入双链表的节点个数：");
    int n;
    scanf("%d",&n);
    for (int i= 0; i< n; ++i) {
        p= (DLNode *)malloc(sizeof(DLNode));
        printf("请输入第%d个节点：",i+1);
        scanf("%d",&p->data);
//        p->rlink= head->rlink;    //错误情况：没有考虑当链表为空时第一个节点怎么插入，只是单纯的
//        p->llink= head;           //按照插入操作来处理了
//        head->rlink= p;
//        p->rlink->llink= p;
        p->rlink= head->rlink;
        if (head->rlink!=NULL) {    //判断链表是否为空
            head->rlink->llink= p;
        }
        head->rlink= p;
        p->llink= head;
    }
    printf("双链表头插法的顺序：");
    return;
}

//遍历双链表节点
void travelDList(DLNode *head)
{
    DLNode *tr= head->rlink;
    while (tr!=NULL) {
        printf("%d ",tr->data);
        tr= tr->rlink;
    }
    printf("\n");
    return;
}

//把最大的节点放在第一个
void maxFirst(DLNode *head)
{
    DLNode *p= head->rlink,*q=p;   //p为遍历节点，q为指向最大节点
    int max= p->data;
    //找最值
    while (p!=NULL) {
        if (max< p->data) {
            max= p->data;
            q= p;
        }
        p= p->rlink;
    }
    //“删除”节点
    DLNode *l= q->llink, *r= q->rlink;
    l->rlink= r;
    if (r!= NULL) { //考虑q是最后一个节点的情况
        r->llink= l;
    }
    //插入
    q->rlink= head->rlink;
    q->llink= head;
    head->rlink= q;
    q->rlink->llink= q;
    
    printf("最大节点在前的顺序：");
    travelDList(head);
}

//创建链表函数——尾插法
void creatLinklistR(LNode *&head)
{
    head=(LNode *)malloc(sizeof(LNode));    //分配一个头节点
    head->next=NULL;    //链表为带头链表，此时链表为空
    LNode *p=NULL, *r=head;//p指向新创建的节点，r指向最终节点
    printf("请输入链表中节点的个数:");
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
    {
        p=(LNode *)malloc(sizeof(LNode));   //为节点分派空间
        p->next=NULL;
        printf("请输入第%d个数字：",i+1);
        scanf("%d",&p->data);   //把值符给p节点
        p->next=r->next;    //把尾节点r所指向的符给新增p所指向的
        r->next=p;  //把新增节点p作为当前尾节点的后续节点
        r=p;//把
    }
    printf("尾插法插入的顺序：");
}

//创建链表——头插法
void creatLinklistH(LNode *&head)
{
    head=(LNode *)malloc(sizeof(LNode));
    head->next=NULL;
    LNode *p=NULL;
    printf("请输入链表的中节点的个数：");
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
    {
        p=(LNode *)malloc(sizeof(LNode));
        p->next=NULL;
        printf("请输入第%d个数字：",i+1);
        scanf("%d",&p->data);
        p->next=head->next; //把头节点的后继节点作为新节点的后继
        head->next=p;   //头节点后面插入新增节点p
    }
    printf("头插法插入的顺序：");
}

//遍历链表函数
void travelList(LNode *head)
{
    LNode *s = head->next;  //s指向开始节点
    while (s!=NULL)
    {
        //遍历每一个节点
        printf("%d",s->data);
        s=s->next;
    }
    printf("\n");
    return ;
}

//把链表的节点元素逆置
void reverseList(LNode *head)
{
    LNode *t= NULL; //创建一个节点，用来标记当前第一个节点
    LNode *r =head; //创建一个尾节点
    while (r->next!=NULL) {
        r=r->next;  //使r指向最后节点
    }
    if (head->next!=NULL){  //如果链表不为空
        while(head->next!=r){   //如果开始节点不等于最终节点
            t= head->next;  //链表第一个节点
            head->next=t->next; //从链表中取出
            t->next= r->next;   //最终节点所指向的赋给t
            r->next= t; //t作为之前尾节点的后继，r一直都是指向逆置之前的尾节点
        }
        printf("逆置后的顺序：");
        travelList(head);
    }
    else printf("没有元素");
}

//寻找最大节点
void findMaxNode(LNode *head)
{
    LNode *p, *q;   //q节点指向当前最大节点，p节点遍历节点
    int max=head->next->data;
    q=p=head->next;
    while (p!=NULL) {
        if (max< p->data) {
            max= p->data;
            q=p;
        }
        p= p->next;
    }
    printf("最大的元素是：%d\n",max);
}

//寻找最小元素
void findMinNode(LNode *head)
{
    LNode *p, *q;   //q节点指向当前最大节点，p节点遍历节点
    int min=head->next->data;
    q=p=head->next;
    while (p!=NULL) {
        if (min> p->data) {
            min= p->data;
            q=p;
        }
        p= p->next;
    }
    printf("最小的元素是：%d\n",min);
}

//从小到大归并链表节点
void merge(LNode *A,LNode *B, LNode *&C)
{
    LNode *p, *q;   //因为链表是递增的，所以用q,p来指向最小节点
    p= A->next; q= B->next;
    LNode *r;
    C= A;
    C->next= NULL;
    free(B);
    r= C;   //r指向C的最终节点，因为此时的头节点就是终端节点
    while (p!=NULL && q!=NULL ) {
        if (p->data <= q->data) {
            r->next= p;
            p= p->next;
            r= r->next;
        }
        else
        {
            r->next= q;
            q= q->next;
            r= r->next;
        }
    }
    if (p!=NULL) {
        r->next = p;
    }
    if (q!=NULL) {
        r->next = q;
    }
}

//若线性表的从小到大，那么归并后从大到小
void mergeR(LNode *A,LNode *B, LNode *&C)
{
    LNode *p= A->next, *q= B->next;
    LNode *s;
    C= A;
    C->next= NULL;
    free(B);    //因为有两个头节点，只需要一个，所以把A当作新链表C的头节点，同时释放B节点。
    while (p!=NULL && q!=NULL) {
        //比较两者的大小，先把AB中较小的用头插法插入C链表中
        //注意的是，从大到小每次插入的节点都需要一个新指针s所指向，保证s的后继节点p不能丢
        if (p->data <= q->data) {
            s=p;
            p= p->next;
            s->next= C->next;
            C->next= s;
        }
        else
        {
            s=q;
            q= q->next;
            s->next= C->next;
            C->next= s;
        }
    }
    while (p!=NULL) {
        s=p;
        p= p->next;
        s->next= C->next;
        C->next= s;

    }
    while (q!=NULL) {
        s=q;
        q= q->next;
        s->next= C->next;
        C->next= s;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
//    LNode *head= NULL;  //初始化头节点
//    creatLinklistR(head);   //调用创建尾插法函数
//    creatLinklistH(head);
//    travelList(head);   //调用遍历函数
//    reverseList(head);
//    findMaxNode(head);
//    findMinNode(head);
//    DLNode *head= NULL; //初始化双链表头节点
//    creatDLinkListH(head);  //调用双链表头插法函数
//    travelDList(head);
//    maxFirst(head);
    
    //归并两个链表
    LNode *A= NULL;
    printf("第1个链表：\n");
    creatLinklistR(A);
    travelList(A);
    LNode *B= NULL;
    printf("第2个链表：\n");
    creatLinklistR(B);
    travelList(B);
    printf("归并后的新链表：");
    LNode *C= NULL;
    merge(A, B, C);   //从小到大
//    mergeR(A, B, C);    //从大到小
    travelList(C);
    
    return 0;
}
