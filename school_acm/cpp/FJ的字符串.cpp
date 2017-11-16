/*
1053: FJ的字符串

问题描述 

　　FJ在沙盘上写了这样一些字符串： 

　　A1  =  “A” 

　　A2  =  “ABA” 

　　A3  =  “ABACABA” 

　　A4  =  “ABACABADABACABA” 

　　…  … 

　　你能找出其中的规律并写所有的数列AN吗？ 
*/

#include<iostream>  
#include<string>  
using namespace std;  
string cal(int n){  
    if(n==1)  
        return "A";  
    else  
        return cal(n-1)+(char)('A'+n-1)+cal(n-1);  
}  
int main(){  
    int n;  
    cin>>n;  
    cout<<cal(n);  
    cout<<endl;  
    return 0;  
}  