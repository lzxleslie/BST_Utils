#ifndef DBNODE_H
#define DBNODE_H
typedef struct DbNode
{
    int data;
    DbNode* left;
    DbNode* right;
}DbNode;

#endif // DBNODE_H
