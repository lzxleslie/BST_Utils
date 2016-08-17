#ifndef BTREE_H
#define BTREE_H
#include "Node.h"
class BTree
{
    public:
        BTree();
        BTree(int num[],int len);
        void insertNode(int data);
        void insertNodeRec(int data);
        Node* searchNode(int data);
        void deleteNode(int data);
        Node* getRoot();
        virtual ~BTree();
    protected:
    private:
        Node* root;
        void insertNoderec(Node* current,int data);
        Node* searchNode(Node* current,int data);
        void deleteNode(Node* current);
};

#endif // BTREE_H
