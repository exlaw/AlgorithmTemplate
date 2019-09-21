#include <iostream>
#include <queue>
#include <vector>
/**
 *
 *  拓扑排序模版
 */
using namespace std;
class node{
public:
    int id;
    int dgree;
    vector<node*> next;
    node(int name){
        id = name;
    }
};
int n, m;
queue<node> que;
vector<node> vec;

void topology_sort(){
    for(int i = 0; i < n; i++){
        if(vec[i].dgree == 0){
            que.push(vec[i]);
        }
    }
    while(!que.empty()){
        node n = que.front();
        que.pop();
        cout << n.id << " ";
        for(int i = 0; i < n.next.size(); i++){
            n.next[i] -> dgree --;
            if(n.next[i] -> dgree == 0){
                que.push(*n.next[i]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        vec.push_back(node(i));
    }
    for(int i = 0; i < m; i++){
        int begin, end;
        cin >> begin >> end;
        vec[begin].next.push_back(&vec[end]);
        vec[end].dgree ++;
    }
    topology_sort();
    return 0;
}