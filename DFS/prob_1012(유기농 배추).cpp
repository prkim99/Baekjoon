#include <iostream>
#include<vector>
#include<stack>
#include <cstring>

using namespace std;
int field[50][50];
bool visit[50][50];
vector<pair<int, int>> cab;
int m, n, k;
int xd[] = { 0,0,1,-1 };
int yd[] = { 1,-1,0,0 };
bool isPos(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }
    return true;
}

void DFS(int i, int j) {
    stack<pair<int, int>> s;
    s.push({ i,j });
    visit[i][j] = true;
    while (!s.empty()) {
        i = s.top().first;
        j = s.top().second;
        s.pop();
        for (int k = 0; k < 4; ++k) {
            if (isPos(i + xd[k], j + yd[k])) {
                if (field[i + xd[k]][j + yd[k]] && !visit[i + xd[k]][j + yd[k]]) {
                    visit[i + xd[k]][j + yd[k]] = true;
                    s.push({ i + xd[k],j + yd[k] });
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    int tt = 0;
    while (t > tt) {

        cin >> m >> n >> k;
        int val1, val2;
        for (int i = 0; i < k; i++) {
            cin >> val1 >> val2;
            field[val2][val1] = 1;
            cab.push_back({ val2,val1 });
        }
        int cnt = 0;
        for (int i = 0; i < cab.size(); ++i) {
            if (!visit[cab[i].first][cab[i].second]) {
                DFS(cab[i].first, cab[i].second);
                cnt++;
            }
        }
        cout << cnt << "\n";
        memset(field, 0, sizeof(field));
        memset(visit, 0, sizeof(visit));
        cab.clear();
        tt++;
    }
}