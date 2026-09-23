#include <stdio.h>
#include <math.h>
 int linearsearch(int a[] , int n , int k){
    for(int i = 0 ; i< n ; i++){
        if(a[i] == k){
            return i;
        }
    }
    return -1;
 }

 int sentinelsearch(int a[], int k , int n){
    a[n] = k;
    int i = 0;
    while ( a[i] != k)
    {
        i++;
    }
    if(i < n){
        return i;
    }else{
        return -1;
    }
 }

 int jumpsearch(int a[], int n , int k){
    int d = sqrt(n);
    int i = 0; 
    int j =i + d;
    while (j < n && a[j] < k)
    {
        i += d;
        j += d;
    }
    if(j >= n){
        j = n-1;
    }
    while (i <= j && a[i] != k )
    {
        i++;
    }
    if(i < n && a[i] == k){
        return i;
    }else{
        return -1;
    }
 }

 int binarysearch(int a[], int n , int k){
    int left = 0;
    int right = n-1;
    while(left <= right){
        int mid = (left + right)/2;
        if(a[mid] == k){
            return mid;
        }
        if(a[mid] < k ){
            left = mid + 1;
        }
        if(a[mid] > k ){
            right = mid - 1;
        }
    }
    return -1;
 }
