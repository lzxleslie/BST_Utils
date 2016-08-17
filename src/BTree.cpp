#include "BTree.h"
BTree::BTree()
{
}
BTree::BTree(int num[],int len){
    root = new Node(num[0]);
    for(int i=1;i<len;i++)
    {
        insertNode(num[i]);
    }
}
void BTree::insertNode(int data){
    Node* p,* par;
    Node* newNode = new Node(data);
    p=par=root;
    while(p!=NULL)
    {
        par=p;
        if(data<p->data)
            p = p->left;
        else if(data>p->data)
            p = p->right;
        else if(data == p->data)
        {
            delete newNode;
            return;
        }
    }
    newNode->parent = par;
    if(newNode->data>par->data)
        par->right = newNode;
    else if(newNode->data<par->data)
        par->left = newNode;
}
void BTree::insertNodeRec(int data){
    if(root==NULL)
        return;
    insertNoderec(root,data);
}
void BTree::insertNoderec(Node* current,int data){
    if(data<current->data)
    {
        if(current->left==NULL)
        {
            current->left = new Node(data);
            current->left->parent = current;
        }
        else
        {
            insertNoderec(current->left,data);
        }
    }
    else if(data>current->data)
    {
        if(current->right==NULL)
        {
            current->right = new Node(data);
            current->left->parent = current;
        }
        else
            insertNoderec(current->right,data);
    }
    return;
}
Node* BTree::searchNode(int data){
    if(root==NULL)
        return NULL;
    return searchNode(root,data);
}
Node* BTree::searchNode(Node* current,int data){
    if(data>current->data)
    {
        if(current->right==NULL)
            return NULL;
        else
            searchNode(current->right,data);
    }
    else if(data<current->data)
    {
        if(current->left==NULL)
            return NULL;
        else
            searchNode(current,data);
    }
    return current;
}
void BTree::deleteNode(int data){
    Node* node = searchNode(data);
    if(node!=NULL)
        deleteNode(node);
}
void BTree::deleteNode(Node* current){
    if(current->left!=NULL)
        deleteNode(current->left);
    if(current->right!=NULL)
        deleteNode(current->right);
}
Node* BTree::getRoot(){
    return root;
}
BTree::~BTree()
{
    //dtor
}
