#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
vector<pair<int,int>> v;
int arr[1000000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int val;
    for (int i = 0; i < n; ++i) {
        cin>>val;
        v.push_back({val,i});
    }
    sort(v.begin(),v.end());
    arr[v[0].second]=0;
    for (int i = 1; i < v.size(); ++i) {
        if (v[i].first>v[i-1].first){
            arr[v[i].second]=arr[v[i-1].second]+1;
        }
        else{
            arr[v[i].second]=arr[v[i-1].second];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout<<arr[i]<<" ";
    }

    return 0;
}
