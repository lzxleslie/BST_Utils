#include "sort_utils.h"
#include <math.h>
#include <cstring>
#include <iostream>
using namespace std;
sort_utils::sort_utils()
{
    //ctor
}
void sort_utils::print_data(int num[],int n)
{
    for(int i=0;i<n;i++)
        cout<<num[i]<<",";
}
void sort_utils::insert_sort(int num[],int n)
{
    for(int i=1;i<n;i++)
    {
        int temp = num[i];
        int j=i-1;
        for(;j>=0&&temp<num[j];j--)
        {
            num[j+1]=num[j];
        }
        num[j+1]=temp;
    }
}
void sort_utils::bubble_sort(int num[],int n)
{
    for(int i=0;i<n;i++)
    {
        int exchange=0;
        for(int j=i+1;j<n;j++)
        {
            if(num[i]>num[j])
            {
                int temp = num[i];
                num[i]=num[j];
                num[j]=temp;
                exchange=1;
            }
        }
        if(exchange!=1)
            return;
    }
}
void sort_utils::shell_sort(int num[],int n)
{
    for(int h=n/2;h>0;h=h/2)
    {
        for(int i=h;i<n;i++)
        {
            int temp = num[i];
            int j=i-h;
            for(;j>=0&&temp<num[j];j-=h)
            {
                int tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;
            }
            num[j+h] = temp;
        }
    }
}
void sort_utils::quick_sort(int num[],int n)
{
    quick_sort(num,0,n);
}
void sort_utils::quick_sort(int num[],int low,int high)
{
    int i=low;
    int j=high;
    int privo = num[low];
    if(i<j)
    {
        while(i<j)
        {
            while(i<j&&num[j]>privo)
                j--;
            if(i<j)
                num[i++] = num[j];
            while(i<j&&num[i]<privo)
                i++;
            if(i<j)
                num[j--] = num[i];
        }
        num[i] = privo;
        quick_sort(num,low,i-1);
        quick_sort(num,i+1,high);
    }
}
void sort_utils::select_sort(int num[],int n)
{
    int l,temp;
    for(int i=0;i<n;i++)
    {
        l=i;
        temp=num[i];
        for(int j=i;j<n;j++)
        {
            if(num[j]<temp)
            {
                temp = num[j];
                l=j;
            }
        }
        int tmp = num[i];
        num[i]=num[l];
        num[l] = tmp;
    }
}
void sort_utils::maxHeapify(int num[],int index,int heapSize)
{
    int largest=0;
    int left = (index<<1)+1;
    int right = (index<<1)+2;
    if((left<=heapSize)&&(num[left]>num[index]))
        largest=left;
    else
        largest=index;
    if((right<=heapSize)&&(num[right]>num[largest]))
        largest = right;
    if(largest!=index)
    {
        int temp = num[index];
        num[index] = num[largest];
        num[largest] = temp;
        maxHeapify(num,largest,heapSize);
    }
}
void sort_utils::buildMaxheap(int num[],int n)
{
    int i;
    int heapSize = n;
    for(i=(n>>1);i>=0;i--)
    {
        maxHeapify(num,i,heapSize);
    }
}
void sort_utils::heap_sort(int num[],int n)
{
    int i;
    buildMaxheap(num,n-1);
    for(i=n-1;i>=1;i--)
    {
        int temp = num[0];
        num[0] = num[i];
        num[i] = temp;
        maxHeapify(num,0,i-1);
    }
}
void sort_utils::merge_sort(int num[],int n)
{
    int *tmp = NULL;
    tmp = new int[n];
    if(tmp!=NULL)
    {
        msort(num,tmp,0,n-1);
        delete []tmp;
    }
}
void sort_utils::msort(int num[],int tmp[],int low, int high)
{
    if(low>=high)
        return;
    int middle = (low+high)/2;
    msort(num,tmp,low,middle);
    msort(num,tmp,middle+1,high);
    merge_m(num,tmp,low,middle+1,high);

}
void sort_utils::merge_m(int num[],int tmp[],int lpos,int rpos, int end_m)
{
    int i,lEnd,NumElements,tmpPos;
    lEnd = rpos-1;
    tmpPos = lpos;
    NumElements = end_m-lpos+1;
    while(lpos<=lEnd&&rpos<=end_m)
    {
        if(num[lpos]<=num[rpos])
            tmp[tmpPos++] = num[lpos++];
        else
            tmp[tmpPos++] = num[rpos++];
    }
    while(lpos<=lEnd)
        tmp[tmpPos++] = num[lpos++];
    while(rpos<=end_m)
        tmp[tmpPos++] = num[rpos++];
    for(i =0;i<NumElements;i++,end_m--)
        num[end_m] = tmp[end_m];
}
void sort_utils::radix_sort(int num[],int n)
{
    int *temp[10];
    int count_m[10] = {0,0,0,0,0,0,0,0,0,0};
    int max_m = find_max(num,n);
    int maxdigit = digit_number(max_m);
    int i,j,k;
    for(i=0;i<10;i++)
    {
        temp[i] = new int[n];
        memset(temp[i],0,sizeof(int)*n);
    }
    for(i=0;i<maxdigit;i++)
    {
        memset(count_m,0,sizeof(int)*10);
        for(j=0;j<n;j++)
        {
            int xx = kth_digit(num[j],i);
            temp[xx][count_m[xx]] = num[j];
            count_m[xx]++;
        }
        int index =0;
        for(j=0;j<10;j++)
        {
            for(k=0;k<count_m[j];k++)
                num[index++] = temp[j][k];
        }
    }
}
int sort_utils::find_max(int num[],int n)
{
    int max_m = num[0];
    for(int i=1;i<n;i++)
    {
        if(num[i]>max_m)
            max_m = num[i];
    }
    return max_m;
}
int sort_utils::digit_number(int number)
{
    int digit = 0;
    do
    {
        number/=10;
        digit++;
    }while(number!=0);
    return digit;
}
int sort_utils::kth_digit(int number, int kth)
{
    number/=pow(10,kth);
    return number%10;
}
sort_utils::~sort_utils()
{
    //dtor
}
