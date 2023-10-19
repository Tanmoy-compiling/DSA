#include <bits/stdc++.h>
using namespace std;

string replace10(string s,char a,char b){
    if(s.length()==0)
        return s;
    if(s[0]==a)
    {
        s[0]=b;
        return s[0]+replace10(s.substr(1),a,b);
    }
    else
         return s[0]+replace10(s.substr(1),a,b);
}

int main()
{
    string s ;
    cout<<"Enter the value of a string"<<endl;
    cin>>s;
    char a,b;
    cout<<"enter the value to be replace"<<endl;
    cin>>a>>b;
    cout<< replace10(s,a,b) <<endl;
}
