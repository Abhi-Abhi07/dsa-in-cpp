#include<iostream>
using namespace std;

int main(){


//bases of size
// int arr[10]={1,2,3,4};
// cout<<arr<<  "          "<<&arr<<endl;
// cout<<"size : "<<sizeof(arr)<<endl;
// cout<<"1st : "<<sizeof(*arr)<<endl;
// cout<<"2nd : "<<sizeof(&arr)<<endl;
// cout<<"size : "<<sizeof(arr[3])<<endl;
// int *ptr=&arr[2];
// cout<<"size : "<<sizeof(ptr)<<endl;
// cout<<"size : "<<sizeof(*ptr)<<endl;
// cout<<"size : "<<sizeof(&ptr)<<endl;


// double arr[10]={0};
// cout<<"size : "<<sizeof(arr)<<endl;
// double *ptr=&arr[0];
// cout<<"size : "<<sizeof(ptr)<<endl;
// cout<<"size : "<<sizeof(*ptr)<<endl;




// int a[20]={1,2,3,4,5};
// cout<<&a[0]<<endl;
// cout<<&a<<endl;
// cout<<a<<endl;

// int *pt=&a[0];
// cout<<pt<<endl;
// cout<<*pt<<endl;
// cout<<&pt<<endl;



//symbal table ka content -> cannot be change
int arr[10];
//ERROR
// arr=arr+1 //-> show error
int *p=arr+1; 
p=p+1;
cout<<p<<endl;
int *ptr=&arr[0];
cout<<ptr<<endl;
ptr=ptr+1;
cout<<ptr<<endl;

return 0;
}