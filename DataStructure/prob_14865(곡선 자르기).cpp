#include <iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    long long int n,v1,v2;
    cin>>n;
    vector<pair<long long int,long long int>> v;
    for(long long int i=0;i<n;i++){
        cin>>v1>>v2;
        v.push_back({v1,v2});
    }
    v.push_back({v[0].first, v[0].second});


    vector<pair<long long int,long long int>> interval;
    bool flag=false;
    long long int c=1;
    long long int tmp=0;
    for(long long int i=1;i<v.size();i++){
        if(v[i].second*v[i-1].second<0){
            if(v[i].second>v[i-1].second){
                interval.push_back({v[i].first,c});
            }
            else{
                if(interval.empty()){
                    tmp=c;
                }
                interval.push_back({v[i].first,c});
                c++;
            }
        }
    }
    if(tmp!=0){
        interval[0].second=c;
    }
    sort(interval.begin(),interval.end());

    stack<long long int> s;
    long long int excluded=0;
    long long int unincluding=0;
    for(long long int i=0;i<interval.size();i++){
        if(s.empty()){
            excluded++;
            s.push(interval[i].second);
        }
        else{
            if(interval[i].second==s.top()){
                if(s.top()==interval[i-1].second) unincluding++;
                s.pop();
            }
            else{
                s.push(interval[i].second);
            }
        }
    }
    cout<<excluded<<" "<<unincluding;

    return 0;
}
