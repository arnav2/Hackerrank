#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
namespace mp = boost::multiprecision;
using namespace std;

// Complete the extraLongFactorials function below.
void extraLongFactorials(int n) {
	mp::cpp_int u = 1;
    for(int i = 1; i <= n; i++)
        u *= i;
    cout << u << endl;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    extraLongFactorials(n);

    return 0;
}
