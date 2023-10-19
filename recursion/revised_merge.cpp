#include <bits/stdc++.h>
using namespace std;

void merging(vector<int>& a, int begin, int mid, int end){

   int i = begin;
	 int j = mid + 1;
   vector<int> result;

   while (i<=mid && j<=end) {
        if(a[i]<a[j]) result.push_back(a[i++]);
        else result.push_back(a[j++]);
   }

	 while (i<= mid) result.push_back(a[i++]);
	 while (j<= end) result.push_back(a[j++]);

   for (int k = begin; k <= end; k++) 
		 a[k] = result[k - begin];
}

int padd = 0;
void merge_sort(vector<int>& a,int begin,int end){
		// for (int i = 0; i < padd; i++) printf(" ");
		// printf("Merging %d to %d\n", begin, end);

    if(end - begin + 1 <= 1) return ;
    int mid = begin+(end-begin)/2;

		padd += 1;
    merge_sort(a,begin,mid);
    merge_sort(a,mid+1,end);
    merging(a,begin,mid,end);
		padd -= 1;
}

int main()
{
    vector<int> a={2,6,1,6,4,7,2,7};

    merge_sort(a,0,a.size()-1);

    for(int i = 0;i<a.size();i++){
        cout<<a[i]<<" ";
    }   
    cout<<endl;

}