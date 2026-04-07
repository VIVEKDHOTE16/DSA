#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int mini = i;

        // find index of minimum element
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[mini]) {
                mini = j;
            }
        }

        // swap only if needed
        if(mini != i) {
            swap(arr[i], arr[mini]);
        }
    }
}

void insertion_sort( int arr[],int n){
    for (int i=0; i<=n-1;i++){
        int j=i;
        while (j>0 && arr[j-1]>arr[j]){
            int temp =arr[j-1];
            arr[j-1]=arr[j];
            arr[j]= temp;
            j--;
        }
    }
}

void merge(vector<int> &arr, int low , int mid , int high){
    vector<int>temp;

    int left=low;
    int right=mid+1;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }

    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
         right++;
        
    }  
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void mS(vector<int> &arr,int low,int high){
    if(low>=high) return;
    int mid= (low+high)/2;
    mS(arr,low,mid);
    mS(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int partition(vector<int> &arr,int low,int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=arr[pivot] && i<= high-1){
            i++;
        }
        while(arr[j]>=arr[pivot] && j>= low+1){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;

}
void qs(vector<int> &arr,int low,int high){
    if(low<high){
        int pIndex = partition(arr,low,high);
        qs(arr,low,pIndex-1);
        qs(arr,pIndex+1,high);
    }
}


int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    qs(arr,0,n-1); 

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}