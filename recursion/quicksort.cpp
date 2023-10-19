#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& a, int si, int ei)
{
    int pivot=a[si];
    int pi=0;
    for(int i = si; i<=ei; i++) if(a[i]<pivot) pi++;
    swap(a[si],a[si+pi]); 
    pi+=si;
    int left=si,right=ei;
    while(left<pi && right>pi){
        if(a[left]<pivot) left++;
        else if(a[right]>pivot) right--;
        else if(a[left]>pivot || a[right]<pivot) swap(a[left],a[right]);
    }
    return pi;
}

vector<int> quick_sort(vector<int>& a,int si,int ei ){
    if(si>=ei)
        return a;
    
    int pi=partition(a,si,ei);
    quick_sort(a,si,pi-1);
    quick_sort(a,pi+1,ei);

    return a;
}


int main()
{
    vector<int> a = {2,6,1,6,4,7,2,7};
    quick_sort(a,0,a.size()-1);

    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}