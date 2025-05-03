#include<bits/stdc++.h>
using namespace std;

long long int N,L;
vector<long long int> point;

long long int cut(int left,int right){
    if(right-left<=1)return 0;
    long long mid=(point[right]+point[left])/2;
    long long idx=left;
    while(point[idx]<mid)idx++;
    if(point[idx-1]-point[left]>=point[right]-point[idx])idx--;
    return point[right]-

}

int main(){
    cin>>N>>L;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        point.push_back(tmp);
    }
    sort(point.begin(),point.end());
    int ans=cut(0,L);

}