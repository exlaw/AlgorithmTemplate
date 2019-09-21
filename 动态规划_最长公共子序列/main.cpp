#include <iostream>
#include <string>
using namespace std;

/*
 * 求两个字符串的最长公共子序列
 * 关键在与每次都减掉一个元素，并且还能满足相同的性质
 */

int dp[1000][1000];
string str1, str2;
int calculate(int i, int j){
    if(i < 0||j < 0){
        return 0;
    }
    if(str1[i] == str2[j]){
        return dp[i][j] = (calculate(i-1,j-1) + 1);
    }else{
        int case1 = calculate(i-1, j);
        int case2 = calculate(i, j-1);
        return dp[i][j] = case1 > case2 ? case1 : case2;
    }
}

int main() {
    cin >> str1 >> str2;
    cout << calculate(str1.length() -1, str2.length() - 1);
    return 0;
}