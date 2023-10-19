#include <bits/stdc++.h>
using namespace std;



string strConcat(int a,int b,int countA,int countB,string& output){
    if(a==0 && b==0)
        return output;

    if(a>=b && countA<2){
        output+="a";
        cout<<output<<" "<<countA<<" "<<countB<<" "<<a<<" "<<b<<endl;
        return strConcat(a-1,b,countA+1,0,output);
    }
    else {
        output+='b';
        cout<<output<<" "<<countA<< " "<<countB<<" "<<a<<" "<<b<<endl;
        return strConcat(a,b-1,0,countB+1,output);
    }
    return output;
}

class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string output="";
       strConcat(a,b,0,0,output);
        return output;
    }
};

int main(){
    Solution a;
    string output=a.strWithout3a3b(4,1);
    cout<<output<<endl;
}