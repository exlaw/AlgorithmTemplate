#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <cstdio>

using namespace std;

/**
 *  算法输入：  n 节点数， m 变数
 *  下面有 m 个 例子， 每个例子下面是  开始节点， 终止节点， 距离的结构
 *
 *  这个例子下着重注意操作符重载的写法， 还有优先队列的使用
 */

class edge{
public:
    int id;
    int dis;
    edge(int n, int d){
        this->id = n;
        this->dis = d;
    }

    bool operator <(const edge& e) const {
        return dis > e.dis;
    }

    friend ostream& operator << (ostream& out, edge & e){
        out << e.id << " " << e.dis << endl;
        return out;
    }

};


vector<vector<edge>> edges;
priority_queue<edge> que;
const int inf = 100000;
int n, m;

void getMinDis(int b, int* d){

    fill(d, d+n+1, inf);
    while(!que.empty()){
        que.pop();
    }
    d[b] = 0;
    edge e(b, 0);
    que.push(e);

    while(!que.empty()){
        edge e = que.top();
        int begin = que.top().id, dis = que.top().dis;
        que.pop();

        if(d[begin] != dis) continue;
        for(int i = 0 ; i < edges[begin].size(); i++){
            int point = edges[begin][i].id;
            if(d[begin] + edges[begin][i].dis < d[point]) {
                d[point] = d[begin] + edges[begin][i].dis;
                que.push(edge(point, d[point]));
            }
        }

    }
}

int dis[100];
int main() {
    cin >> n >> m;
    for(int i =0 ; i < n; i ++){
        vector<edge> e;
        edges.push_back(e);
    }
    for(int i = 0 ;i < m ; i++){
        int from, to , d;
        cin >> from >> to >> d;
        edges[from].push_back(edge(to, d));
        edges[to].push_back(edge(from, d));
    }
    getMinDis(0, dis);
    for(int i = 0; i < n; i++){
        cout << dis[i] << " ";
    }
    return 0;
}