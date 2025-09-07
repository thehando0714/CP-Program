#include<bits/stc++.h>


using namespace std;

int main() {
    int n;
    while (cin >> n) {
        stack<int>st;
        queue<int>qu;
        priority_queue<int>pq;
        bool isst = true, isqu = true, ispq = true;
        while (n--) {
            int act;
            cin >> act;
            if (act == 1) {
                int tmp;
                cin >> tmp;
                st.push(tmp);
                qu.push(tmp);
                pq.push(tmp);
            }
            else {
                int tmp;
                cin >> tmp;
                if (st.empty() || st.top() != tmp) {
                   
                    isst = false;
                }
                else {
                    st.pop();
                }
                if (qu.empty() ||qu.front() != tmp ) {
                   
                    isqu = false;
                }
                else  {
                    qu.pop();
                }

                if (pq.empty() || pq.top() != tmp) {
                    ispq = false;
                }
                else {
                    pq.pop();
                    
                }
            }
            
        }
        if (isst && isqu || isst && ispq || ispq && isqu) {
            cout << "not sure\n";
        }
        else if (isst) {
            cout << "stack\n";
        }
        else if (isqu) {
            cout << "queue\n";
        }
        else if (ispq) {
            cout << "priority queue\n";
        }
        else {
            cout << "impossible\n";
        }

    }

}