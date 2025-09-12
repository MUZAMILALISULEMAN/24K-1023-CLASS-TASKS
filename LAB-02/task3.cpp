#include<iostream>
using namespace std;	
	
int main(){
	int n = 5;
	int size[5] = {2,3,6,7,2};
int **teams = new int*[n];
for(int i=0;i<5;i++){
//	hardcoding the number of columns
 teams[i] = new int[size[i]]; //making team
}
//assigning scores
int len;
for(int i=0;i<n;i++){
	len = size[i];
	for(int j=0;j<len;j++){
		
		teams[i][j] = j+1;
	}
}
//printing whole jagged array
for(int i=0;i<n;i++){
	len = size[i];
	for(int j=0;j<len;j++){
		
		cout<<" "<<teams[i][j];
	}
	cout<<endl;
}

//taking sum

int sum = 0;
for(int i=0;i<n;i++){
	len = size[i];
	for(int j=0;j<len;j++){
		
		sum += teams[i][j];
	}
	cout<<"ROW "<<i+1<<" SUM: "<<sum<<endl;
	sum=0;
}

//memory deallocation
for(int i=0;i<n;i++){
	
	delete[] teams[i];
}
delete[] teams;
	
	return 0;
}