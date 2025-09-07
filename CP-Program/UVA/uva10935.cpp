#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    bool first=true;
    while(cin>>n,n){
        /*if(!first){
            cout<<"\n";
        }
        first=false;*/
        queue<int>graph;
        for(int i=1;i<=n;i++){
            graph.push(i);
        }
        vector<int>dis;
        while(graph.size()!=1){
            dis.push_back(graph.front());
            graph.pop();
            graph.push(graph.front());
            graph.pop();
        }
        cout<<"Discarded cards:";
        if(!dis.empty()){
            cout<<" ";
        }
        for(int i=0;i<dis.size();i++){
            cout<<dis[i];
            if(i!=dis.size()-1){
                cout<<", ";
            }
            
        }
        cout<<"\n";
        cout<<"Remaining card: "<<graph.front()<<endl;
       
    }
    


}