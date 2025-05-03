#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int k=0,sg=0,sb=0;
        multiset<int>green,blue;
        for(int i=0;i<sg;i++){
            int x;
            cin>>x;
            green.insert(x);
        }
        for(int i=0;i<sb;i++){
            int x;
            cin>>x;
            blue.inser(x);
        }
        while(!green.empty()&&!blue.empty()){

            vector<int>greensurvior;
            vector<int>bluesurvior;
            for(int i=0;i<k;i++){
                if(green.empty()||blue.empty()){
                    break;
                }
                multiset<int>::iterator g=--green.end();
                multiset<int>::iterator b=--blue.end();
                int gval=*g;
                int bval=*b;
                green.erase(g);
                blue.erase(b);
                if(gval>bval){
                    greensurvior.push_back(gval-bval);
                }
                else if(gval<bval){
                    bluesurvior.push_back(bval-gval);
                }
            }
            for(int i=0;i<greensurvior.size();i++){
                green.insert(greensurvior[i]);
            }
            for(int i=0;i<bluesurvior.size();i++){
                blue.insert(bluesurvior[i]);
            }


        }
        if(gren)


    }



}