
//there are b rabbits standin onf an infite number line ever rabbit has ome specific characteristic repersented by lowercase latin letters given by a string A . INitially they are at some interger position Bi. They will start moving when you order them with i unit per second. Their inita direction will be given by c, which contains only 1 or -1 and -1 mean opposite direction. If two rabbits with same they will change their direction. find the sum of distance all the possible pair of rabbits after D seconds when you orderred them to move

// Input Format : first argument A second argument is an integer array B third argument is an integer array C fourth argument is an integer D

// Output Format : return an integer

// Input : A = "aba" B = [-2,0,2] C = [1,-1,-1] D = 3

// Output : 8

// Explanation : after 0 second the postions are [-2,0,2] after 1 second the postions are [-1,-1,1] after 2 second the postions are [0,2,0] after 3 second the postions are [-1,3,1] so the answer is 8

//input 2: A = "cd" B = [1,0] C = [1,-1] D = 2

//output 2: 5

//explanation 2: after 0 second the postions are [1,0] after 1 second the postions are [2,-1] after 2 second the postions are [3,-2] so the answer is 5

//problem Constraints: 1<=N<=10^5 Ai={lowercase latin alphabets} -10^6<=Bi<=10^6 C={1,-1} 0<=D<=10^6

#include<bits/stdc++.h>
using namespace std;

long solve(string A, vector<int> &B, vector<int> &C, int D) {
    int n = A.size();
    vector<int> pos, neg;
    for(int i=0;i<n;i++){
        if(A[i] == 'G'){
            pos.push_back(B[i]);
        }
        else{
            neg.push_back(B[i]);
        }
    }
    sort(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    int p = pos.size(), q = neg.size();
    long ans = 0;
    long temp = 0;
    for(int i=0;i<p;i++){
        temp += pos[i];
    }
    for(int i=0;i<q;i++){
        temp += abs(neg[i]);
    }
    ans += temp*(D-1);
    temp = 0; // Move initialization outside the loop
    for(int i=0;i<n;i++){
        if(A[i] == 'G'){
            ans += C[i];
        }
        else{
            ans -= C[i];
        }
    }
    return ans;
}

int main(){
    string A = "aba";
    vector<int> B = {-2,0,2};
    vector<int> C = {1,-1,-1};
    int D = 3;
    cout<<solve(A,B,C,D);
}