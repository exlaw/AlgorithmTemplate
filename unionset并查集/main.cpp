#include <iostream>

using namespace std;

const int N = 10000;
class UnionSet{
public:
    int number;
    int id[N];

    UnionSet(int n){
        number = n;
        for(int i = 0; i < n; i++){
            id[i] = i;
        }
    }

    int find(int n){
        if(id[n] != n){
            return find(id[n]);
        }
        return id[n];
    }

    void join(int a, int b){
        int fa = id[a];
        int fb = id[b];
        if(fa == fb) return;

        if(a > b){
            id[fa] = fb;
        }else{
            id[fb] = fa;
        }
    }

};

int main() {
    UnionSet u(4);
    u.join(0,1);
    for(int i = 0; i < 4; i++){
        cout << u.id[i] << " ";
    }
    cout << endl;
    u.join(1,3);
    for(int i = 0; i < 4; i++){
        cout << u.id[i] << " ";
    }
    cout << endl;
    cout << u.find(0) << endl;
    cout << u.find(3) << endl;
    bool result = (u.find(0) == u.find(3));
    cout << result;
    return 0;
}