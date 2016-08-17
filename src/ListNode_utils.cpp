#include "ListNode_utils.h"
#include <iostream>
using namespace std;
ListNode_utils::ListNode_utils()
{
    //ctor
}
void ListNode_utils::print(ListNode* head)
{
    while(head!=NULL)
    {
        if(head->next==NULL)
            cout<<head->data;
        else
            cout<<head->data<<"->";
        head = head->next;
    }
}
ListNode* ListNode_utils::create(){
    ListNode* head = new ListNode;
    ListNode* tmp;
    head->data = 0;
    int NodeNum =0;
    while(1)
    {
        cout<<"please input a interge, enter 0 to quit"<<endl;
        int x;
        cin>>x;
        if(x==0)
            break;
        ListNode* p = new ListNode;
        NodeNum++;
        p->data = x;
        if(NodeNum==1)
            head->next = p;
        else
            tmp->next = p;
        tmp = p;
    }
    tmp->next = NULL;
    return head;
}
ListNode* ListNode_utils::create(int num[],int n)
{
    if(n<=0||num==NULL)
        return NULL;
    ListNode* head = new ListNode;
    head->data = num[0];
    ListNode*p,*q;
    for(int i=1;i<n;i++)
    {
        p = new ListNode;
        p->data = num[i];
        if(i==1)
            head->next = p;
        else
            q->next = p;
        q=p;
    }
    q->next = NULL;
    return head;
}
ListNode* ListNode_utils::create_sort(int num[],int n)
{
    if(n<=0||num==NULL)
        return NULL;
    ListNode* head = new ListNode;
    head->data = num[0];
    ListNode* Pre;
    for(int i =1;i<n;i++)
    {
        Pre=head;
        ListNode* p = new ListNode;
        p->data = num[i];
        if(p->data<=head->data)
        {
            ListNode* tmp = head;
            head = p;
            head->next = tmp;
        }
        else
        {
            while(Pre->next!=NULL&&p->data>Pre->next->data)
                Pre = Pre->next;
            if(Pre->next==NULL)
                Pre->next = p;
            else
            {
                p->next = Pre->next;
                Pre->next = p;
            }

        }
    }
    return head;
}
ListNode* ListNode_utils::create_josephus(int n)
{
    ListNode* head,*p,*q;
    head = new ListNode;
    head->data = 1;
    q=head;
    for(int i=2;i<=n;i++)
    {
        p = new ListNode;
        p->data = i;
        q->next = p;
        q=p;
    }
    q->next = head;
    return head;
}
int ListNode_utils::get_length(ListNode* head)
{
    int len =0;
    while(head!=NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}
ListNode* ListNode_utils::search_node(ListNode* head,int pos)
{
    if(pos<0)
        return NULL;
    while(head!=NULL&&pos!=0)
    {
        head=head->next;
        pos--;
    }
    return head;
}
ListNode* ListNode_utils::insert_node(ListNode* head,int pos, int data)
{
    if(pos<0)
        return head;
    ListNode* p = search_node(head,pos);
    if(p!=NULL)
    {
        ListNode* q = p->next;
        ListNode* t = new ListNode;
        t->data = data;
        t->next = q;
        p->next = t;
    }
    return head;
}
ListNode* ListNode_utils::delete_node(ListNode* head,int pos)
{
    ListNode* p = search_node(head,pos);
    if(p!=NULL)
    {
        ListNode* q = p->next;
        p->data = q->data;
        p->next = q->next;
        delete q;
        q=NULL;
    }
    return head;
}
ListNode* ListNode_utils::reverse_node(ListNode* head)
{
    ListNode* p,*q,*r;
    if(head==NULL)
        return head;
    p=NULL;
    q = head;
    while(q!=NULL)
    {
        r = q->next;
        q->next = p;
        p=q;
        q=r;
    }
    return p;
}
ListNode* ListNode_utils::find_mid_node(ListNode* head)
{
    if(head==NULL||head->next==NULL)
        return head;
    ListNode* p, *q;
    p=q=head;
    while(q!=NULL&&q->next!=NULL)
    {
        p = p->next;
        q = q->next->next;
    }
    return p;
}
ListNode* ListNode_utils::find_mid_node2(ListNode* head)
{
    int i=0;
    int j=0;
    ListNode* p,*q;
    p=q=head;
    while(q!=NULL)
    {
        if(i/2>=j)
        {
            j++;
            p = p->next;
        }
        i++;
        q=q->next;
    }
    return p;
}
bool ListNode_utils::isloop(ListNode* head,ListNode** start)
{
    if(head==NULL)
    {
        *start = NULL;
        return false;
    }
    ListNode*p,*q;
    do
    {
        p = p->next;
        q = q->next->next;
    }while(q!=NULL&&q->next!=NULL&&p!=q);
    if(p==q)
    {
        *start=p;
        return true;
    }
    else
        return false;
}
ListNode* ListNode_utils::merge_sorted_List(ListNode* head1,ListNode* head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    ListNode* head, *p, *nextP;
    if(get_length(head1)>get_length(head2))
    {
        head = head1;
        p = head2;
    }
    else
    {
        head = head2;
        p = head1;
    }

    while(p!=NULL)
    {
        nextP = p->next;
        insert_sorted_node(head,p);
        p=nextP;
    }
    return head;
}
ListNode* ListNode_utils::insert_sorted_node(ListNode* head,ListNode* item)
{
    if(item==NULL)
        return head;
    ListNode*p,*q;
    p =head;
    q=NULL;
    while(p->data<item->data&&p!=NULL)
    {
        q=p;
        p=p->next;
    }
    if(p==head)
    {
        ListNode* tmp = head;
        head = item;
        head->next = tmp;
    }
    else
    {
        q->next = item;
        item->next = p;
    }
    return head;
}
ListNode* ListNode_utils::merge_sorted_List1(ListNode* head1,ListNode* head2)
{
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    ListNode* head = NULL;
    if(head1->data<=head2->data)
    {
        head = head1;
        head->next = merge_sorted_List1(head1->next,head2);
    }
    else
    {
        head = head2;
        head->next = merge_sorted_List1(head1,head2->next);
    }
    return head;
}
int * ListNode_utils::josephus(int n,int m)
{
    if(n<=0||m<=0)
        return NULL;
    int *num = new int[n];
    int j=0;
    ListNode* head = create_josephus(n);
    m%=n;
    while(head!=head->next)
    {
        int i=0;
        for(;i<m-1;i++)
            head = head->next;
        num[j++] = head->data;
        ListNode* tmp = head->next;
        head->data = tmp->data;
        head->next = tmp->next;
        delete tmp;
        tmp = NULL;
    }
    num[j] = head->data;
    return num;
}
ListNode_utils::~ListNode_utils()
{
    //dtor
}
