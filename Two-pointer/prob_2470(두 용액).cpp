#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,val;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>val;
        v.push_back(val);
    }
    sort(v.begin(),v.end());
    int s=0;
    int e=v.size()-1;
    int ss=0,ee=0;
    int min=2000000000;
    while(s<e){
        int sum=v[s]+v[e];
        if(abs(sum)<min){
            min=abs(sum);
            ss=s;
            ee=e;
            if(min==0) break;
        }
        if(abs(v[s])<abs(v[e])){
            e--;
        }
        else{
            s++;
        }
    }
    cout<<v[ss]<<" "<<v[ee];
    return 0;
}
