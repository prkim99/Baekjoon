#include<iostream>
#include<cmath>
#include <algorithm>
#include<vector>
#include<cmath>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k,n,val;
    cin>>k>>n;
    vector<int> v;

    for (int i = 0; i < k; ++i) {
        cin>>val;
        v.push_back(val);
    }


    int c=ceil((double)n/k);
    sort(v.begin(),v.end());
    int index=k-1;
    long long int cnt=0;
    long long int s=1,e=v[index];
    e++;
    long long int len=(s+e)/2;
    while(s<e){
        cnt=0;
        for (int i = 0; i < k; ++i) {
            cnt+=v[i]/len;
        }
        if(cnt>=n){
            s=len+1;
            len=(s+e)/2;
        }
        else {
            e=len;
            len=(s+e)/2;
        }
    }
    cout<<s-1;

}
