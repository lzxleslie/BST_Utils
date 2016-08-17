#include "BTreeUtils.h"
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
BTreeUtils::BTreeUtils()
{
    //ctor
}
void BTreeUtils::inorderRec(Node* root){
    if(root==NULL)
        return;
    if(root->left!=NULL)
        inorderRec(root->left);
    cout<<root->data<<",";
    if(root->right!=NULL)
        inorderRec(root->right);
}
void BTreeUtils::inorder(Node* root){
    stack<Node*> s;
    Node* p = root;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)
        {
            s.push(p);
            p=p->left;
        }
        if(!s.empty())
        {
            p = s.top();
            cout<<p->data<<",";
            s.pop();
            p = p->right;
        }
    }

}
void BTreeUtils::preorderRec(Node* root)
{
    if(root!=NULL)
    {
        cout<<root->data<<",";
        if(root->left!=NULL)
            preorderRec(root->left);
        if(root->right!=NULL)
            preorderRec(root->right);
    }
}
void BTreeUtils::preorder(Node* root)
{
    stack<Node*> s;
    Node* p = root;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)
        {
            s.push(p);
            cout<<p->data<<",";
            p=p->left;
        }
        if(!s.empty())
        {
            p = s.top();
            s.pop();
            p=p->right;
        }
    }
}
void BTreeUtils::postorderRec(Node* root)
{
    if(root!=NULL)
    {
        if(root->left!=NULL)
            postorderRec(root->left);
        if(root->right!=NULL)
            postorderRec(root->right);
        cout<<root->data<<",";
    }
}
void BTreeUtils::postorder(Node* root)
{
   stack<Node*> s;
   s.push(root);
   Node* pre = NULL;
   while(!s.empty())
   {
        Node* current = s.top();
        if((current->left==NULL&&current->right==NULL)||(pre!=NULL&&(pre==current->left||pre==current->right)))
        {
            s.pop();
            cout<<current->data<<",";
            pre = current;
        }
        else
        {
            if(current->right!=NULL)
                s.push(current->right);
            if(current->left!=NULL)
                s.push(current->left);
        }
   }
}
void BTreeUtils::leverorder(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* p = q.front();
        q.pop();
        cout<<p->data<<",";
        if(p->left!=NULL)
            q.push(p->left);
        if(p->right!=NULL)
            q.push(p->right);
    }
}
int BTreeUtils::getDepthRec(Node* root)
{
    if(root==NULL)
        return 0;
    return getDepthRec(root->left)>getDepthRec(root->right)?getDepthRec(root->left)+1:getDepthRec(root->right)+1;
}
int BTreeUtils::getDepth(Node* root)
{
    int leleft,leright;
    leleft=leright=0;
    Node* p,*q;
    p=q=root;
    while(p!=NULL)
    {
        p=p->left;
        leleft++;
    }
    while(q!=NULL)
    {
        q=q->right;
        leright++;
    }
    return leleft>leright?leleft:leright;
}
bool BTreeUtils::isBST(Node* root)
{
    stack<Node*> s;
    Node* p = root;
    int num = -1;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)
        {
            s.push(p);
            p=p->left;
        }
        if(!s.empty())
        {
            p=s.top();
            s.pop();
            if(p->data<num)
                return false;
            else
            {
                num = p->data;
                p=p->right;
            }
        }
    }
    return true;
}
string BTreeUtils::serializeTree(Node* root)
{
    queue<Node*> q;
    q.push(root);
    string str;
    string strtemp;
    int nextlevel=0;
    int tobeprint = 1;
    while(!q.empty())
    {
        Node* p = q.front();
        q.pop();
        strtemp+=to_string(p->data);
        if(p->left!=NULL)
        {
            q.push(p->left);
            ++nextlevel;
        }
        if(p->right!=NULL)
        {
            q.push(p->right);
            ++nextlevel;
        }
        --tobeprint;
        if(tobeprint==0)
        {
            str +=strtemp+"#";
            strtemp.clear();
            tobeprint=nextlevel;
            nextlevel=0;
        }
    }
    return str;
}
BTreeUtils::~BTreeUtils()
{
    //dtor
}
