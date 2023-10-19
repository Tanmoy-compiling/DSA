#include <bits/stdc++.h>

using namespace std;

string stringkey(int d)
{
    string key;
       switch(d)
    {
        case 2:
             key="abc";
             break;
        case 3:
             key="def";
             break;
        case 4:
             key="ghi";
             break;
        case 5:
             key="jkl";
             break;
        case 6:
             key="mno";
             break;
        case 7:
             key="pqrs";
             break;
        case 8: 
             key="tuv";
             break;
        case 9:
             key="wxyz";
             break;
    }
    return key;
}

void keypad(int a, string keyp)
{
    if(a==0)
    {
        cout<<keyp<<endl;
        return ;
    }
    // a=a/10;
    int smallNumber=a/10;
    string str=stringkey(a%10);
    for(int i = 0;i<str.size();i++){
        keypad(smallNumber,str[i]+keyp);
    }
}

int main()
{
    int a;
    cout<<"Enter the numbers"<<endl;
    cin>>a;
    string output= " ";
    keypad(a,output);
}