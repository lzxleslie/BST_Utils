#ifndef BTREEUTILS_H
#define BTREEUTILS_H
#include"Node.h"
#include<string>
using namespace std;
class BTreeUtils
{
    public:
        BTreeUtils();
        virtual ~BTreeUtils();
        static void inorderRec(Node* root);
        static void inorder(Node* root);
        static void preorderRec(Node* root);
        static void preorder(Node* root);
        static void postorderRec(Node* root);
        static void postorder(Node* root);
        static void leverorder(Node* root);
        static int getDepthRec(Node* root);
        static int getDepth(Node* root);
        static bool isBST(Node* root);
        static string serializeTree(Node* root);
    protected:
    private:
};

#endif // BTREEUTILS_H
