#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    srand(time(NULL));
}
void bubblesortdown(int a[], int n){
    for(int i = 0; i<n ; i++){
        for(int j= 0 ; j<n-1-i ;j++){
            if(a[j] < a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
void bubblesortup(int a[], int n){
    for(int i = 0; i<n ; i++){
        for(int j= 0 ; j<n-1-i ;j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void selectionsortup(int a[], int n){
    for(int i = 0 ; i<n-1 ; i++){
        int vitrimin = i;
        for(int j = i+1 ; j<n ;j++){
            if(a[vitrimin] > a[j]){
                vitrimin = j;
            }
        }
        if(vitrimin != i){
            int temp = a[i];
            a[i] = a[vitrimin];
            a[vitrimin] = temp;
        }
    }
}

void selectionsortdown(int a[], int n){
    for(int i = 0 ; i<n-1 ; i++){
        int vitrimin = i;
        for(int j = i+1 ; j<n ;j++){
            if(a[vitrimin] < a[j]){
                vitrimin = j;
            }
        }
        if(vitrimin != i){
            int temp = a[i];
            a[i] = a[vitrimin];
            a[vitrimin] = temp;
        }
    }
}

void insertionsortup(int a[], int n){
    for(int i = 1 ; i<n ; i++){
        int key = a[i];
        int j = i-1;
        while (j >= 0 && a[j]<key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void insertionsortdown(int a[], int n){
    for(int i = 1 ; i<n ; i++){
        int key = a[i];
        int j = i-1;
        while (j >= 0 && a[j]>key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void shellsortup(int a[], int n){
    for(int gap = n/2; gap > 0 ; gap/=2){
        for(int i = gap ;i<n; i++){
            int key = a[i];
            int j = i - gap;
            while(j >= 0 && a[j] > key){
                a[j + gap] = a[j];
                j -= gap;
            }
            a[j+gap] = key;

        }
    }
}

void shellsortdown(int a[], int n){
    for(int gap = n/2; gap > 0 ; gap/=2){
        for(int i = gap ;i<n; i++){
            int key = a[i];
            int j = i - gap;
            while(j >= 0 && a[j] < key){
                a[j + gap] = a[j];
                j -= gap;
            }
            a[j+gap] = key;

        }
    }
}

int n;
int left = 0;
int right = n -1;
int partitionlomutoup(int a[], int left , int right){
    int pivot = a[right];
    int i = left-1;
    for(int j = left ; j < right ;j++){
        if(a[j] <= pivot){
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        a[right] = a[i+1];
        a[i+1] = pivot;
    }
    return i+1;
}

void quicksortup(int a[], int left , int right){
    if(left < right){
        int p = partitionlomutoup(a, left , right);  
        quicksortup(a, left , p -1);
        quicksortup(a, p-1 , right);
    }
}

int n;
int left = 0;
int right = n -1;
int partitionlomutodown(int a[], int left , int right){
    int pivot = a[right];
    int i = left-1;
    for(int j = left ; j < right ;j++){
        if(a[j] >= pivot){
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        a[right] = a[i+1];
        a[i+1] = pivot;
    }
    return i+1;
}

void quicksortdown(int a[], int left , int right){
    if(left < right){
        int p = partitionlomutodown(a, left , right);  
        quicksortdown(a, left , p -1);
        quicksortdown(a, p-1 , right);
    }
}

int random_pivotup(int a[], int left , int right){
    int random_index = left + rand() % (right - left + 1);

    int temp = a[random_index];
    a[random_index] = a[right];
    a[right] = temp;
    
    return partitionlomutoup(a,left,right);
}

void quicksortup(int a[], int left , int right){
    if(left < right){
        int p = random_pivotup(a, left , right);  
        quicksortup(a, left , p -1);
        quicksortup(a, p-1 , right);
    }
}

int random_pivotdown(int a[], int left , int right){
    int random_index = left + rand() % (right - left + 1);

    int temp = a[random_index];
    a[random_index] = a[right];
    a[right] = temp;
    
    return partitionlomutodown(a,left,right);
}

void quicksortdown(int a[], int left , int right){
    if(left < right){
        int p = random_pivotdown(a, left , right);  
        quicksortdown(a, left , p -1);
        quicksortdown(a, p-1 , right);
    }
}

void merge(int a[], int left , int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1];
    int R[n2];
    int k = left;
    for(int i = 0;i <n1 ;i++){
        L[i] = a[left + i];
    }
    for(int j = 0;j <n2 ;j++){
    R[j] = a[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    while(i <n1 && j<n2){
        if(L[i] <= R[j]){   
            a[k] = L[i];
            i++;
            k++;
        }else{
            a[k] = R[j];
            j++;
            k++;
        }
    }
    while(i < n1){
        a[k] = L[i];
        k++;
        i++;
    }
    while(j < n2){
        a[k] = R[j];
        k++;
        j++;
    }
}


void mergesort(int a[], int left, int right){
    if(left < right){
        int mid = (left + right) / 2;

        mergesort(a, left, mid);
        mergesort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}