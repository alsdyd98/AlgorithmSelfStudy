#include <iostream>
#include <vector>
using namespace std;
int N;
// element array, answer array
// vector<short> ar, as;
// counting array
int co[10010] = {0};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;

    int temp;
    for(int i = 0; i < N; i++){
        cin >> temp;
        co[temp]++;
    }
    // for(int i = 2; i < 10001; i++){
    //     co[i] += co[i - 1];
    // }
    // for(int i = N; i > 0; i--){
    //     temp = ar[i];
    //     as[co[temp]--] = temp;
    // }
    for(int i = 1; i <= 10000; i++) {
        for(int j=0; j<co[i]; j++){
            cout << i << '\n';
        }
    }
    
    // cout << as[i] << '\n';

}

