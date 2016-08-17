#ifndef SORT_UTILS_H
#define SORT_UTILS_H


class sort_utils
{
    public:
        sort_utils();
        static void insert_sort(int num[],int n);
        static void print_data(int num[],int n);
        static void bubble_sort(int num[],int n);
        static void shell_sort(int num[],int n);
        static void quick_sort(int num[],int n);
        static void select_sort(int num[],int n);
        static void heap_sort(int num[],int n);
        static void merge_sort(int num[],int n);
        static void radix_sort(int num[],int n);
        virtual ~sort_utils();
    protected:
    private:
        static void quick_sort(int num[],int low,int high);
        static void maxHeapify(int num[],int index,int heapSize);
        static void buildMaxheap(int num[],int n);
        static void msort(int num[],int tmp[],int low, int high);
        static void merge_m(int num[],int tmp[],int lpos, int rpos,int end_m);
        static int digit_number(int number);
        static int kth_digit(int number,int kth);
        static int find_max(int num[],int len);
};

#endif // SORT_UTILS_H
