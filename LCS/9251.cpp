#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string A, B;
int** c;

int LCS(int i, int j);
int main(){
    cin >> A >> B;
    c = new int* [A.length() + 1];
    for(int i = 0; i < A.length() + 1; i++){
        c[i] = new int[B.length() + 1];
        for(int j = 0; j < B.length() + 1; j++){
            c[i][j] = -1;
        }
    }
    for(int i = 0; i < A.length() + 1; i++){
        c[i][0] = 0;
    }
    for(int j = 0; j < B.length() + 1; j++){
        c[0][j] = 0;
    }
    LCS(A.length(),B.length());
    cout << c[A.length()][B.length()];
}

int LCS(int i, int j){
    if(i == -1 || j == -1){
        return 0;
    }
    if(c[i][j] == -1){
        if(A.at(i-1) == B.at(j-1)){
            c[i][j] = LCS(i - 1, j - 1) + 1;
        }
        else{
            c[i][j] = max(LCS(i -1,j), LCS(i, j-1));
        }
    }

    return c[i][j];
    
}
