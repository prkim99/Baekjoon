#include <iostream>
#include <vector>
using namespace std;
vector<int> road[10];

int n;
int fee=-1;

void Backtracking(int st,int node,int cnt, int cost, int visit[]) {
    if(cnt==n+1){
        if(road[node][st]!=0){
        if (fee==-1||cost+road[node][st]<fee){
            fee=cost+road[node][st];
            }
        }
        return;
    }


    for (int i = 0; i < road[node].size(); ++i) {
        if(road[node][i]!=0){
        if (visit[i]==0){
            visit[i]=cnt;
            Backtracking(st,i,cnt+1,cost+road[node][i],visit);
            visit[i]=0;
        }}
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    int val;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> val;
            road[i].push_back(val);
        }
    }
    for (int y = 0; y < n; y++) {
        int visit[10]={0,};
        visit[y]=1;
        Backtracking(y,y, 2,0, visit);
    }
    cout << fee;
    return 0;
}
