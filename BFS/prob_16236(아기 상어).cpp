#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
#include <cstring>
using namespace std;
vector<pair<int, int>> fish;
int sea[20][20];

int baby, n, moveCnt;
int cnt, minsize;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool isPos(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        return false;
    }return true;
}

void eat(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({ sx,sy });
    int dist[20][20] = { 0, };
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (isPos(xx, yy) && dist[xx][yy] == 0 && sea[xx][yy] <= baby && !(xx == sx && yy == sy)) {
                dist[xx][yy] = dist[x][y] + 1;
                if (dist[xx][yy] > minsize) {
                    break;
                }
                if (sea[xx][yy] < baby && sea[xx][yy] != 0) {
                    fish.push_back({ xx,yy });
                    minsize = dist[xx][yy];
                }
                q.push({ xx,yy });
            }
        }
    }
}

int main() {
    int shark1, shark2;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> sea[i][j];
            //fish[sea[i][j]].push_back({i,j});
            if (sea[i][j] == 9) {
                shark1 = i;
                shark2 = j;
                sea[i][j] = 0;
            }
        }
    }
    baby = 2;
    minsize = 400;
    eat(shark1, shark2);
    while (!fish.empty()) {
        sort(fish.begin(), fish.end());
        shark1 = fish[0].first;
        shark2 = fish[0].second;
        fish.clear();
        sea[shark1][shark2] = 0;
        cnt++;
        moveCnt += minsize;
        minsize = 400;
        if (baby == cnt) {
            baby++;
            cnt = 0;
        }
        eat(shark1, shark2);
    }
    cout << moveCnt << "\n";


    return 0;
}