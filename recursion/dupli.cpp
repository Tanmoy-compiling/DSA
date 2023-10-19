#include <bits/stdc++.h>
using namespace std;

string replace10(string s){
    if(s.length()==1)
        return s;
    if(s[0]==s[1])
    {
        return replace10(s.substr(1));
    }
    else
         return s[0]+replace10(s.substr(1));
}

int main()
{
    string s ;
    cout<<"Enter the value of a string"<<endl;
    cin>>s;
    cout<< replace10(s) <<endl;
}
