# BST_Utils
包括单链表、双向链表、循环链表、二叉搜索树等等数据结构的建立、遍历、查找、增删等操作；其中二叉树的操作均包括递归与非递归
包括 冒泡、插入、选择、快速、希尔、堆、基数等排序方法
main函数
#include "BTree.h"
#include "BTreeUtils.h"
#include<iostream>
#include"sort_utils.h"
#include "ListNode_utils.h"
int main(){
    int num[]={5,2,3,4,1,6,7,8,9,10};
    int len = 10;
    //BTree* Tree =new BTree(num,len);
    //BTreeUtils TreeUtils;
    //TreeUtils.leverorder(Tree->getRoot());
    //string str = TreeUtils.serializeTree(Tree->getRoot());
    //cout<<endl<<str.c_str()<<endl;
    //sort_utils mysort;
    //mysort.print_data(num,len);
    //cout<<endl;
    //mysort.radix_sort(num,len);
    //mysort.print_data(num,len);
    ListNode_utils ListNodeU;
    //ListNode* head = ListNodeU.create(num,len);
    //ListNodeU.print(head);
    //cout<<endl<<ListNodeU.get_length(head)<<endl;
    //ListNode* n = ListNodeU.search_node(head,2);
    //if(n==NULL)
    //    cout<<"NULL"<<endl;
    //else
    //    cout<<n->data<<endl;
    //ListNode* newhead = ListNodeU.insert_node(head,2,35);
    //ListNodeU.delete_node(newhead,3);
    //ListNodeU.print(newhead);
    //newhead = ListNodeU.reverse_node(newhead);
    //cout<<endl;
    //ListNodeU.print(newhead);
    //cout<<endl;
    //cout<<ListNodeU.find_mid_node(newhead)->data<<":"<<ListNodeU.find_mid_node2(newhead)->data;
    //ListNode* head_1 = ListNodeU.create_sort(num,len-2);
    //ListNode* head_2 = ListNodeU.create_sort(num,len-2);
    //ListNodeU.print(head_1);
    //ListNodeU.print(head_2);

    //ListNode* head_3 = ListNodeU.merge_sorted_List1(head_1,head_2);


    //ListNode* head_4 = ListNodeU.merge_sorted_List(head_1,head_2);
   // ListNode* head_4 = ListNodeU.delete_node(head_3,1);
   // ListNodeU.print(head_1);
    //cout<<endl;
   // ListNode* head_5 = ListNodeU.merge_sorted_List(head_3,head_4);
    //ListNodeU.print(head_3);
   // cout<<endl<<ListNodeU.find_mid_node2(head_1)->data;
    int *p = ListNodeU.josephus(len,2);
    for(int i=0;i<len;i++)
        cout<<p[i]<<"->";
    delete p;
    p=NULL;
    return 0;
}
标准代码仅供参考，有异议留言交流
