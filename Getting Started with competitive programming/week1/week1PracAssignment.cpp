#include <iostream>
#include <cmath>
using namespace std;

bool willVisitAllCups(int n) {
    int k = log2(n);
    return (n == pow(2, k));
}

int main() {
    int n;
    cin >> n;

    if (willVisitAllCups(n)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}