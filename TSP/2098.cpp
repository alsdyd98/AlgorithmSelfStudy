#include<stdio.h>
// num of cities, cities' weights
int N, W[16][16], dp[1 << 16][16] = {0};
const int MAX = 18000000;
int TSP(int visit, int lastIndex){    
    visit |=  (1 << lastIndex);
    if(visit == ((1 << N) - 1)){ 
        if(W[lastIndex][0] > 0){
            return W[lastIndex][0];}
        return MAX;}
    int& ret = dp[visit][lastIndex];
    if(ret > 0) 
        return ret;
    ret = MAX;

    for(int i = 0; i < N; i++){
        // 지금 인덱스가 아니고, 아직 방문 안하고, 길이 있는 경우
        if(i != lastIndex && (visit & (1 << i)) == 0 && W[lastIndex][i] > 0){
            int temp = TSP(visit, i) + W[lastIndex][i];
            if(ret > temp) 
                ret = temp;
        }
    }
    return ret;
}
int main(){
    scanf("%d",  &N);
    for(int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &W[i][j]);
    printf("%d", TSP(0, 0));


}