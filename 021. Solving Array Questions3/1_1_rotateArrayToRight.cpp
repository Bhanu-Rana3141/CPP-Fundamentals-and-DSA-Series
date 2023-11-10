#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArray(vector<int>arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }cout << endl;
}

int main() {
    
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int>arr(n); 

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Steps to rotate: ";
    cin >> k;

    rotate(arr.begin(), arr.end()-k, arr.end());

    printArray(arr,n);

    // Brute force 
/*  reverse(arr.begin(), arr.end());
    printArray(arr, n);

    reverse(arr.begin(), arr.end() - k);
    printArray(arr,n);
    
    reverse(arr.end()-k, arr.end());
    printArray(arr,n);
*/
   
/*
    vector<int>temp(n);
    for(int i=0; i<n; i++){
        temp[(i+k) % n] = arr[i]; 
    }

    // Copying temp elements in arr
    arr = temp;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
*/

    
    return 0;
}