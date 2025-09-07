#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	string inp;
	getline(cin, inp);
	int a = inp[0] - '0', b = inp[2] - '0';
	if (b==8) {
		if (a != 8) {
			a += 1;
			b = 1;
		}
	}
	else if(b<8){
		b++;
	}
	cout << a << '-' << b<<endl;
}
