#ifndef DBNODE_UTILS_H
#define DBNODE_UTILS_H
#include "DbNode.h"
#include <cstddef>
class DbNode_utils
{
    public:
        DbNode_utils();
        void print(DbNode* head);
        DbNode* createNode(int data);
        DbNode* createList(int head);
        DbNode* appendNode(DbNode* head,int data);
        virtual ~DbNode_utils();
    protected:
    private:
};

#endif // DBNODE_UTILS_H
