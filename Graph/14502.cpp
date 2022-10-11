#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> board;
int main(){
    int N, M;
    //get input to board about N, M
    cin >> N >> M;
    board.resize(N + 1);
    for(int i = 1; i <= N; i++){
        board[i].resize(M + 1);
        for(int j = 1; j <= M; j++){
            cin >> board[i][j];
        }
    }


}