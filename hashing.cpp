#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector <int>arr(n);
    for(int i=0; i<n ; i++){
        cin>>arr[i];
    }
    map<int,int> mpp;
    for(int i=0; i<n;i++){
        mpp[arr[i]]++;
    }
    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        cout<<mpp[num]<<endl;
    }
    return 0;
}