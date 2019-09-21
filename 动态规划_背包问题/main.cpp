#include <iostream>
#include <vector>
using namespace std;
/**
 * 动态规划背包问题
 * @return
 */
class item{
public:
    int weight;
    int value;
    item(int w, int v){
        weight = w;
        value = v;
    }
};
int dp[100][100];

int n, w; // 总数，总重量
vector<item> items;

int calculate(int n1, int w1){
    if(dp[n1][w1] != -1){
        return dp[n1][w1];
    }
    if(n1 <= 0 || w1 <= 0){
        return dp[n1][w1] = 0;
    }
    item i = items[n1-1];
    int case1 = calculate(n1 - 1, w1 - i.weight) + i.value;
    int case2 = calculate(n1 - 1, w1);
    return dp[n1][w1] =  case1 > case2 ? case1 : case2;
}

int main() {
    cin >> n >> w;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= w; j++){
            dp[i][j] = -1;
        }
    }
    for(int i = 0; i < n; i++){
        int wi, vi;
        cin >> wi >> vi;
        items.push_back(item(wi, vi));
    }
    cout << calculate(n, w);

    return 0;
}