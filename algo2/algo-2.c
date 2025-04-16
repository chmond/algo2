#include "stdio.h"

int array_search(int pole[],int n,int k){
    for (int i = 0; i < n; i++)
    {
        if  (pole[i] == k){
            return i;
        }
    }
    return -1;
}


int binary_search(int pole[],int n,int k){
    int l = 0;
    int p = n - 1;

    while (l <= p)
    {
        int s=((l + p)/2);
        if (pole[s]==k)
        {
            return s;
        }
        else if(pole[s] > k)
        {
            p = s-1;
        }
        else if(pole[s] < k){
            l = s+1;
        }
    }
    return -1;
}

int interpol_binary_search(int pole[],int n,int k){
    int l = 0;
    int p = n - 1;
    int x = pole[l];
    int y = pole[p];

    while ((pole[l] < pole[p]) && (pole[l] <= k) && (k <= pole[p]))
    {
        float r=(k-x/(y-x));
        int s=(l+(p-l)*r);
        if (pole[s]==k)
        {
            return s;
        }
        else if(pole[s] > k)
        {
            p = s-1;
        }
        else if(pole[s] < k){
            l = s+1;
        }
    }
    return -1;


}

int main(){
    int k = 3;
    int arr[] = {1,2,3,4,5,6};
    int arrr[] = {1,5,2,9,3};
    printf("%d\n",array_search(arrr,sizeof(arrr)/sizeof(int),k));
    printf("%d\n",binary_search(arr,sizeof(arr)/sizeof(int),k));
    printf("%d\n",binary_search(arr,sizeof(arr)/sizeof(int),k));
}
