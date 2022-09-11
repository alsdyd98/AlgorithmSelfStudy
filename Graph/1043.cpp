#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
// we are using set to make connections between groups
int N, M, group = 1;
int visited[51] = {0};
set<int> groupConnection[51];
vector<int> truthGroup;
vector<bool> checkGroup;

void addGroup(vector<int> nodes){
    bool alreadyGrouped = false;
    int tempGroup = 9999;
    for(int node : nodes){
        if(visited[node] != 0){
            groupConnection[visited[node]].insert(group);
            groupConnection[group].insert(visited[node]);
            tempGroup = min(tempGroup, visited[node]);
        }
    }
    tempGroup = min(tempGroup, group);
    for(int node: nodes){
        visited[node] = tempGroup;
    }
    group++;
    checkGroup.push_back(false);
}
void dfsUtils(int group, bool* groupVisited){
    if(groupVisited[group] == true) return;
    checkGroup[group] = true;
    groupVisited[group] = true;
    for(int i : groupConnection[group]){
        dfsUtils(i, groupVisited);
    }
}

void dfs(int group){
    bool groupVisited[51]= {0};
    dfsUtils(group, groupVisited);
}
int main(){
    checkGroup.push_back(true);
    int temp, numPeople, K;
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++){
        cin >> temp;
        truthGroup.push_back(temp);
    }
    for(int i = 0; i < M; i++){
        cin >> numPeople;
        vector<int> party(numPeople);
        for(int j = 0; j < numPeople; j++){
            cin >> party[j];
        }
        addGroup(party);
    }
    for(vector<int>::iterator truthNode = truthGroup.begin(); truthNode != truthGroup.end(); truthNode++){
        checkGroup[visited[*truthNode]] = true;
        dfs(visited[*truthNode]);
        // for(int j : groupConnection[*truthNode]){
        //     checkGroup[j] = true;
        // }
        
    }
    int count = 0;
    for(bool i : checkGroup){
        if(i == false) count++;
    }
    cout << count;
}