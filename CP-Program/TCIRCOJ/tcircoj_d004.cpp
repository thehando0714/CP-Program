#include<iostream>
#include<string>
using namespace std;

string input;

int pos=0;
int com(int pow) {
	char ch = input[pos++];
	if (ch == '0') return 0;  
	if (ch == '1') return pow * pow;  

	
	int half = pow / 2;
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		ans += com(half);
	}
	return ans;
}


int main() {
	
	int n;
	int trueans;
	getline(cin, input);
	cin >> n;
	if (input[0] == '1') {
		cout << n * n;
	}
	else if (input[0] == '0') {
		cout << '0';
	}
	else {
		trueans=com(n);
		cout << trueans;
	}
}