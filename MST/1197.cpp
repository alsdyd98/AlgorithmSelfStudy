#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
//Kruskal's Algorithm

using namespace std;
// 정점의 갯수, 간선의 갯수
int V, E, totalWeight = 0, curV = 0;
const int inf = 1000001;
int parent[10001];
vector<tuple<int, int, int>> weights;

bool compareW(tuple<int, int, int> a, tuple<int, int, int> b){
    return get<2>(a) < get<2>(b);
}
int find(int v){
    if(parent[v] < 0) return v;
    else{
        parent[v] = find(parent[v]);
        return parent[v];
    }
}
bool unity(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return false;
    if(parent[u] < parent[v]){
        parent[u] += parent[v];
        parent[v] = u;
    }
    else{
        parent[v] += parent[u];
        parent[u] = v;
    }
    return true;
}
int main(){
    scanf("%d %d", &V, &E);
    int u, v, w;
    fill_n(parent, 10000, -1);
    for(int i = 0; i < E; i++){
        scanf("%d %d %d", &u, &v, &w);
        weights.push_back(make_tuple(u, v, w));
    }
    sort(weights.begin(), weights.end(), compareW);
    for(vector<tuple<int, int, int>>::iterator weight = weights.begin(); weight != weights.end(); weight++){
        if(find(get<0>(*weight)) == find(get<1>(*weight))) continue;
        if(unity(get<0>(*weight), get<1>(*weight))){
            totalWeight += get<2>(*weight);
            curV++;
        }
        if(curV == (V - 1)) break;
        
    }
    cout << totalWeight;
    
    return 0;
}