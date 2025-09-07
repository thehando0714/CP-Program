#include<iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
	while (t--)
	{
		long long  a, b, c;
		cin >> a >> b >> c;
		cout << min( min(a,c),(a + b + c) / 3 ) << endl;
	}

}