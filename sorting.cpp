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
        while(arr[i]<=pivot && i<= high-1){
            i++;
        }
        while(arr[j]>=pivot && j>= low+1){
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

bool check(vector<int>& nums) {
    int n=nums.size();
    int count=0;

    for (int i=1;i<n;i++){
        if (nums[i-1]>nums[i])
        count++;
    }
    if (nums[n-1]>nums[0])
    count++;
    return count<=1;
 
 }

 void leftrotate(int arr[],int n , int d){
    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr,arr+n);
 }

 class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                j=i;
                break;
            }
        }
        if(j==-1) return;

        for (int i=j+1;i<n;i++){
            if(nums[i] != 0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    } 
};

int missingNum(vector<int>& arr) {
    int xor1 = 0, xor2 = 0;
    int n = arr.size();

    for(int i = 0; i < n; i++){
        xor2 ^= arr[i];      // XOR of array
        xor1 ^= (i + 1);     // XOR of 1 to n
    }

    xor1 ^= (n + 1);         // include last number

    return xor1 ^ xor2;
}

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxi = 0;
    int cnt = 0;

    for(int i = 0; i < nums.size(); i++){
        if(nums[i] == 1){
            cnt++;
            maxi = max(maxi, cnt);   // correct line
        } else {
            cnt = 0;
        }
    }

    return maxi;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int result = findMaxConsecutiveOnes(nums);
    cout << "Maximum consecutive 1s: " << result << endl;

    return 0;
}
