#include <iostream>
#include <algorithm>
using namespace std;
int N;
int dp[1000001] = {0};
int Cal(int i){
    if(i == 1 || dp[i] != 0) return dp[i];
    if(i % 2 != 0 && i % 3 != 0){
        dp[i] = Cal(i - 1) + 1;
        return dp[i];
    }
    if(i % 2 != 0 && i % 3 == 0){
        dp[i] = min(Cal(i - 1), Cal(i / 3)) + 1;
    }
    else if(i % 2 == 0 && i % 3 != 0){
        dp[i] = min(Cal(i - 1), Cal(i / 2)) + 1;
    }
    else{
        dp[i] = min(min(Cal(i - 1), Cal(i / 2)), Cal(i / 3)) + 1;
    }
    return dp[i];
}
int main(){
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    cin >> N;

    cout << Cal(N);
}