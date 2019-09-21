#include <iostream>
#include <queue>
using namespace std;
int n, m;
const int NUM = 100000;
class edge{
public:
    int begin;
    int end;
    int dis;
    edge(int b, int e, int d){
        begin = b;
        end = e;
        dis = d;
    }
    bool operator < (const edge& e) const{
        return dis > e.dis;
    }
};

class UnionSet{
public:
    int id[NUM];
    int number;

    UnionSet(int n1){
        number = n1;
        for(int i = 0; i < n1; i++){
            id[i] = i;
        }
    }

    int find(int n){
        if(id[n] != n){
            return id[n] = find(id[n]);
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
            id[fb]= fa;
        }
    }
};


priority_queue<edge> que;

int main() {
    cin >> n >> m;
    UnionSet u(n);
    for(int i = 0; i < m; i++){
        int begin, end, dis;
        cin >> begin >> end >> dis;
        que.push(edge(begin, end, dis));
    }
    int count = 0;
    while(count < n -1){
        edge e = que.top();
        que.pop();
        if(u.find(e.begin)== u.find(e.end)){
            continue;
        }else{
            cout << e.begin << " " <<e.end << " " << e.dis << endl;
            u.join(e.begin, e.end);
            count += 1;
        }
    }
    return 0;
}