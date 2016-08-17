#ifndef LISTNODE_UTILS_H
#define LISTNODE_UTILS_H
#include"ListNode.h"

class ListNode_utils
{
    public:
        ListNode_utils();
        ListNode* create();
        ListNode* create(int num[],int n);
        void print(ListNode* head);
        int get_length(ListNode* head);
        ListNode* search_node(ListNode* head,int pos);
        ListNode* insert_node(ListNode* head,int pos,int data);
        ListNode* delete_node(ListNode* head,int pos);
        ListNode* reverse_node(ListNode* head);
        ListNode* find_mid_node(ListNode* head);
        ListNode* find_mid_node2(ListNode* head);
        ListNode* create_sort(int num[], int n);
        bool isloop(ListNode* head,ListNode** start);
        ListNode* merge_sorted_List(ListNode* head1,ListNode* head2);
        ListNode* merge_sorted_List1(ListNode* head1,ListNode* head2);
        int* josephus(int n,int m);
        virtual ~ListNode_utils();
    protected:
    private:
        ListNode* insert_sorted_node(ListNode* head,ListNode* item);
        ListNode* create_josephus(int n);
};

#endif // LISTNODE_UTILS_H
