#include<iostream>
using namespace std;
void printSingleDigit(int n){
	if(n >= 0 && n<=9){
		cout<<n;
		return;
	}
	printSingleDigit(n/10);
}
int main(){


printSingleDigit(20091);


return 0;
}
