#include <iostream>

const int N = 10000;
using namespace std;
int n;
int arr[N];
int target;
int mid_search(){
    int begin = 0;
    int end = n-1;
    while(begin <= end){
        int mid = (begin + end)/2;
        if(arr[mid] == target){
            return mid;
        }
        if(arr[mid] > target){
            end = mid - 1;
        }
        if(arr[mid] < target){
            begin = mid + 1;
        }
    }
    return -1;
}

int main() {
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    cin >> target;
    cout << mid_search();
    return 0;
}