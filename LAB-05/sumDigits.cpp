#include<iostream>
using namespace std;
int findSum(int n){
	if(n==0){
		return 0;
	}
	int digit  = n%10;  
	n/=10;
	return digit+ findSum(n);
}
int main(){

cout<<findSum(1222);



return 0;
}
