#include<iostream>
#include<cmath>
#include <algorithm>
#include<vector>
#include<cmath>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int m,n,val;
    cin>>n;
    vector<int> v;

    for (int i = 0; i < n; ++i) {
        cin>>val;
        v.push_back(val);
    }
    cin>>m;
    sort(v.begin(), v.end());
    long long int len=v[0];
    long long int sum=0;
    long long int s=1, e=v[n-1];
    e++;
    while(s<e){
        sum=0;
        for (int i = 0; i < n; ++i) {
            if(v[i]>len){
                sum+=len;
            }
            else{
                sum+=v[i];
            }
        }
        if(sum<=m){
            s=len+1;
            len=(s+e)/2;
        }
        else{
            e=len;
            len=(s+e)/2;
        }
    }
    cout<<s-1;

}
