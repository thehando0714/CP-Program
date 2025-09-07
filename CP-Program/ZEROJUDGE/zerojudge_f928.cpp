#include<bits/stdc++.h>
using namespace std;

int bomb[1020];
int n;

void x1(int where, int bomb[]);
void x2(int where, int bomb[]);
void x3(int where, int bomb[], int k);

void x1(int where, int bomb[]) {
    bomb[where] = 0;
}

void x2(int where, int bomb[]) {
    bomb[where] = 0;

    if (where + 1 < n) {
        if (bomb[where + 1] == 1)
            x1(where + 1, bomb);
        else if (bomb[where + 1] == 2)
            x2(where + 1, bomb);
        else if (bomb[where + 1] >= 3)
            x3(where + 1, bomb, bomb[where + 1]);
    }

    if (where - 1 >= 0) {
        if (bomb[where - 1] == 1)
            x1(where - 1, bomb);
        else if (bomb[where - 1] == 2)
            x2(where - 1, bomb);
        else if (bomb[where - 1] >= 3)
            x3(where - 1, bomb, bomb[where - 1]);
    }
}

void x3(int where, int bomb[], int k) {
    bomb[where] = 0;
    if (where >= k) {
        if (bomb[where - k] == 1) {
            x1(where - k, bomb);
        }
        else if (bomb[where - k] == 2) {
            x2(where - k, bomb);
        }
        else if (bomb[where - k] >= 3) {
            x3(where - k, bomb, bomb[where - k]);
        }
    }
    if (where >= 2 * k) {
        if (bomb[where - 2 * k] == 1) {
            x1(where - 2 * k, bomb);
        }
        else if (bomb[where - 2 * k] == 2) {
            x2(where - 2 * k, bomb);
        }
        else if (bomb[where - 2 * k] >= 3) {
            x3(where - 2 * k, bomb, bomb[where - 2 * k]);
        }
    }
    if (bomb[where + k] == 1) {
        x1(where + k, bomb);
    }
    else if (bomb[where + k] == 2) {
        x2(where + k, bomb);
    }
    else if (bomb[where + k] >= 3) {
        x3(where + k, bomb, bomb[where + k]);
    }

    if (bomb[where + 2 * k] == 1) {
        x1(where + 2 * k, bomb);
    }
    else if (bomb[where + 2 * k] == 2) {
        x2(where + 2 * k, bomb);
    }
    else if (bomb[where + 2 * k] >= 3) {
        x3(where + 2 * k, bomb, bomb[where + 2 * k]);
    }

}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> bomb[i];
    }

    int start;
    cin >> start;

    if (bomb[start] == 1) {
        x1(start, bomb);
    }
    else if (bomb[start] == 2) {
        x2(start, bomb);
    }
    else {
        x3(start, bomb, bomb[start]);
    }

    for (int i = 0; i < n; i++) {
        cout << bomb[i] << " ";
    }
    cout << endl;
}
