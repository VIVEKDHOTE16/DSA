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
        j=i;
        while (j>0 && arr[j-1]>arr[j]){
            int temp =arr[j-1];
            arr[j-1]=arr[j];
            arr[j]= temp;
            j--;
        }
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    insertion_sort(arr, n);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}