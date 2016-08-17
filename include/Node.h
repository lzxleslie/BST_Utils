#ifndef NODE_H
#define NODE_H

#include <cstddef>
class Node
{
    public:
        Node():data(-1),parent(NULL),left(NULL),right(NULL){}
        virtual ~Node(){}
        Node(int num):data(num),parent(NULL),left(NULL),right(NULL){}
        int data;
        Node* parent;
        Node* left;
        Node* right;
    protected:
    private:
};

#endif // NODE_H
