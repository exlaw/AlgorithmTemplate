#include <iostream>
#include <vector>
#include <queue>
const int N = 1999;
using namespace std;
class edge{
public:
    int from;
    int end;
    int dis;
    edge(int f, int e, int d){
        from = f;
        end = e;
        dis = d;
    }
};
int n, m;
int _dist[N];
int times[N];
bool inque[N];
vector<vector<edge>> vec;
queue<int> que;

bool spfa(int begin, int n){
    _dist[begin] = 0;
    times[begin] = 1;
    inque[n] = true;
    que.push(begin);
    while(!que.empty()){
        int s = que.front();
        que.pop();
        for(int i = 0; i < vec[s].size(); i++){
            edge e = vec[s][i];
            if(_dist[e.end] > _dist[s] + e.dis){
                _dist[e.end] = _dist[s] + e.dis;
                if(!inque[e.end]){
                    inque[e.end] = true;
                    que.push(e.end);
                    times[e.end] ++;
                    if(times[e.end] > n){
                        return false;
                    }
                }
            }
        }
        for(int i = 0; i < n;i ++){
            cout << _dist[i] << " " ;
        }
        cout << endl;

    }
    return true;
}


int main() {
    cin >> n >> m;
    for(int i = 0;i < n; i++){
        _dist[i] = 999999;
        times[i] = 0;
        inque[i] = false;
        vector<edge> e;
        vec.push_back(e);
    }

    for(int i = 0; i < m; i ++){
        int from, end, dis;
        cin >> from >> end >> dis;
        vec[from].push_back(edge(from, end, dis));
    }
    cout << spfa(0, n) << endl;
    for(int i = 0; i < n;i ++){
        cout << _dist[i] << " " ;
    }
    cout << endl;
    return 0;
}