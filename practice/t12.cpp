#include <bits/stdc++.h>
using namespace std;

void check(long &max1, long &max2, long num)
{
    if (num > max1)
    {
        if (max1 != 0)
        {
            max2 = max1;
        }
        max1 = num;
    }
}

long solve(vector<int> &A, vector<int> &B)
{
    vector<int> temp;
    int j = 0;
    long sum = 0, max1 = 0, max2 = 0;

    for (int i = 0; i < A.size(); i++)
    {
        if (temp.size() == 0 ||A[i] < temp[j])
        {
            temp.push_back(A[i]);
            j++;
            check(max1, max2, B[i]);
        }
        
        else if(A[i]>temp[j])
        {
            // cout << max1 << " " << max2 << endl;
            for (int i = 0; i < temp.size(); i++)
            {
                cout << temp[i] << endl;
            }
            sum += max1 + max2;
            temp.clear();
            cout<<"break"<<endl;
            temp.push_back(A[i]);
            max1 = B[i];
            max2 = 0;
            j = 1;
        }
    }
    return sum;
}

int main()
{
    vector<int> A = {-1, -2, -3, 4, 3, 2, 1};
    vector<int> B = {4, 6, 2, 4, 8, 4, 5};
    long ans = solve(A, B);
    cout << ans << endl;
}