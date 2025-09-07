// Online C++ compiler to run C++ program online
#include <iostream>
#include<set>

using namespace std;

int main() {
    set<long long>graph;
    graph.insert(1);
    int idx=0;
    long long ugly=1;
    while(idx<1500){
        
        auto it1=graph.begin();
        ugly=*it1;
        graph.insert(*it1*2);
        graph.insert(*it1*3);
        graph.insert(*it1*5);
        graph.erase(graph.begin());
        idx++;
    }
    cout<<"The 1500'th ugly number is "<<ugly<<".\n";

    return 0;
}