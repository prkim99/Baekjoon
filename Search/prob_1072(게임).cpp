#include<iostream>
#include<cmath>

using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    long long int x,y;
    cin>>x>>y;
    long double cur=y*100/x;

    if(cur>=99){
        cout<<-1;return 0;}

    int a=ceil(((cur+1)*x-(100*y))/(99-cur));

    cout<<a;

}
