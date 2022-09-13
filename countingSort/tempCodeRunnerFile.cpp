#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
// element array, answer array
vector<short> ar, as;
// counting array
short co[10001] = {0};

int main(){
    cin >> N;
    short temp;
    ar.push_back(0);
    for(int i = 0; i < N; i++){
        cin >> temp;
        ar.push_back(temp);
        as.push_back(0);
        co[temp]++;
    }
    for(int i = 2; i < 10001; i++){
        co[i] += co[i - 1];
    }
    for(int i = N; i > 0; i--){
        temp = ar[i];
        as[co[temp]--] = temp;
    }
    for(int i = 1; i < N+1; i++) cout << as[i] << '\n';

}

