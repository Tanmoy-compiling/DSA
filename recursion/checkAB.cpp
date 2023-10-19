#include <bits/stdc++.h>
using namespace std;

bool checkAB(string s){
    
    if(s.size()==0) return true;

    if(s[0]=='a')
    {
        int remaingSubstring=s.substr(1).size();

        if(remaingSubstring>1 && s.find("abb")==0)
            return checkAB(s.substr(3));
        else    return  checkAB(s.substr(1));

    }
    return false;
}

int main(){
    string s;
    cout<<"Enter the string "<<endl;cin>>s;

    bool b=checkAB(s);
    if(b) cout<<"true"<<endl;
    else cout<<"false"<<endl;
}