#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int N, M;
int* numArray;
int main(){
    cin >> N >> M;
    numArray = new int[M];
    for(int i = 0; i < M; i++){
        numArray[i] = 1;
    }
    while(numArray[0] != N){
        for(int i = 0; i < M - 1; i++){
            cout << numArray[i] << ' ';
        }
        cout << numArray[M-1] <<'\n';
        int lastIndex = M-1;
        numArray[lastIndex]++;
        while(numArray[lastIndex] == N+1){
            numArray[lastIndex] = 0;
            lastIndex--;
            numArray[lastIndex] += 1;
            if(lastIndex == 0) break;
        }
        for(int i = lastIndex + 1; i < M; i++){
            numArray[i] = numArray[i -1];
        }
    }
    for(int i = 0; i < M - 1; i++){
        cout << numArray[i] << ' ';
    }
    cout << numArray[M-1] <<'\n';


}