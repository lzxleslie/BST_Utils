#include "DbNode_utils.h"
void DbNode_utils::print(DbNode* head)
{
    DbNode* p = head;
    while(p!=NULL)
    {
        cout<<p->data<<"->";
        p = p->right;
    }
}

DbNode* DbNode_utils::createNode(int data)
{
    DbNode* pnode = new DbNode;
    pnode->data = data;
    pnode->left = pnode;
    pnode->right = pnode;
    return pnode;
}
DbNode* DbNode_utils::createList(int head)
{
    DbNode* pnode = new DbNode;
    pnode->data = head;
    pnode->left = pnode->right = pnode;
    return pnode;
}
DbNode* DbNode_utils::appendNode(DbNode* head,int data)
{
    DbNode* node = new DbNode;
    node->data = data;
    DbNode* p = head,*q;
    while(p!=NULL)
    {
        q = p;
        p = p->right;
    }
    q->right = node;
    node->left = q;
    return head;
}
DbNode_utils::DbNode_utils()
{
    //ctor
}

DbNode_utils::~DbNode_utils()
{
    //dtor
}
