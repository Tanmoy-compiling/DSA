#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int count = 0;
    while (n)
    {
        count +=n&1;
        n>>=1;
    }

    return 0;
}