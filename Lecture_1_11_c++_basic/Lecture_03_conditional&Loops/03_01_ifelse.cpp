#include<iostream>
using namespace std;

int main(){

/*
int a;
cout<<"Enter the number : "<<endl;
cin>>a;

//if a is positive
if (a>0){
    cout<<"a is positive"<<endl;
}
else{
    cout<<"a is negative"<<endl;
}
*/


/*
// Find any letter of ASCII value
int a;
a=cin.get();
cout<<"Value of a is : "<<a<<endl;
*/


/*
//Enter the two number which gretest
int a,b;
cout<<"Enter the value of a : "<<endl;
cin>>a;
cout<<"Enter the value of b : "<<endl;
cin>>b;

if (a>b){
    cout<<"A is Greater"<<endl;
}
else{
    cout<<"B is Greater"<<endl;
}
*/


/*
int a;
cout<<"Enter the number : "<<endl;
cin>>a;

if (a>0){
    cout<<"a is positive"<<endl;
}
else{
    if(a<0){
        cout<<"a is negative"<<endl;
    }
    else{
        cout<<"A is zero"<<endl;
    } 
}
*/


/*
int a;
cout<<"Enter the number : "<<endl;
cin>>a;

if (a>0){
    cout<<"a is positive"<<endl;
}
else if(a<0){
    cout<<"a is negative"<<endl;
}
else{
    cout<<"A is zero"<<endl;
}
*/



// Find the caracter are lowercase, uppercase or numeric.
char ch;
cout<<"Enter a character "<<endl;
cin>>ch;

if(ch>=97 && ch<=122){
    cout<<"This is lowercase letter";
}
else if(ch>=65 && ch<=90){
    cout<<"This is uppercase letter";
}
else if(ch>=48 && ch<=57){
    cout<<"This is numric word";
}


return 0;
}