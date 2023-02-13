#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
#include<string>
using namespace std;
stack<int> s[3];
int n, k;
long long int cnt = 0;

vector<pair<int, int>> seq;
void hanoii(int n, int from, int via, int to) {

    if (n == 0) {
        return;
    }

    hanoii(n - 1, from, to, via);
    s[from].pop();
    s[to].push(n);
    cout << (from + 1) << " " << (to + 1) << "\n";
    // seq.push_back({from+1,to+1});
    cnt++;
    hanoii(n - 1, via, from, to);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cnt = 0;

    cin >> n;
    int aa = 3;
    string ans = to_string(pow(2, n));
    int idx = ans.find('.');
    ans = ans.substr(0, idx);
    ans[ans.length() - 1] -= 1;
    cout << ans.c_str() << "\n";
    if (n <= 20) {
        for (int i = n; i >= 1; i--) {
            s[0].push(i);
        }
        hanoii(n, 0, 1, 2);
        /*        for (int i = 0; i < seq.size(); ++i) {
                    cout<<seq[i].first<<" "<<seq[i].second<<"\n";
                }}*/
    }
    return 0;
}