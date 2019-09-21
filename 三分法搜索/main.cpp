#include <iostream>
using namespace std;

/**
 *  三分法查找的模型（有极大值点的序列）
 */
int n;
int arr[1000];

int search(){
    int l = 0, r = n-1;
    while(r - l > 3){
        int lmid = (l + r)/2;
        int rmid = (lmid + r)/2;
        if(arr[lmid] > arr[rmid]) r = rmid;
        else l = lmid;
        cout << l << " " << r << endl;
    }

    int max= 0;
    for(int i = l; i <=r; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << search();
    return 0;
}