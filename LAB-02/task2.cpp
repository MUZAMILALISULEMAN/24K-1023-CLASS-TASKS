#include<iostream>
using namespace std;
class D2ARRAY{
	
	private:
		int ** arr;
		int rows;
		int cols;
	public:
		D2ARRAY(int rows,int cols,int fill):arr(nullptr),rows(rows),cols(cols){
		arr = new int*[rows];
		for(int i=0;i<rows;i++){
			arr[i] = new int[cols];
		}
		for(int i=0;i<rows;i++){
			
			for(int j=0;j<cols;j++){
				
				arr[i][j] = fill;
			}
			
		}
		
		}
		void resize(int r,int c,int fill){
			int rows2 =r;
			int cols2 = c;
			
			int **arr2 = new int*[rows2];
			for(int i=0;i<rows2;i++){
				
				arr2[i] = new int[cols2];
			}
			int temprows=rows2,tempcols=cols2;
			int flag = 0;
			if(rows2 > rows ){
			
				temprows = rows;
				flag = 1;
			}
			if(cols2 > cols){
				tempcols = cols;
				flag = 1;
			}
			
			if(flag){ //enlarge
				
				for(int i=0;i<rows2;i++){
					for(int j=0;j<cols2;j++){
						arr2[i][j] = fill;
					}
				}
			}
			
			
			
			for(int i=0;i<temprows;i++){
			for(int j=0;j<tempcols;j++){
				arr2[i][j] = arr[i][j];
			}	
			}
			
//			deleting 
			for(int i=0;i<rows;i++){
			delete arr[i];
			}
			delete arr;
			
			arr = arr2;
			rows = rows2;
			cols = cols2;
			

			
			
			
			
			
			
			
			
		}
		
	void display(){
				int t;
		for(int i=0;i<rows;i++){
			
			for(int j=0;j<cols;j++){
				
				t= arr[i][j];
				if(i%2!=0){
				
					if(i+1<rows){
						t = arr[i][j]+arr[i+1][j];
				}else if(i-1>=0){
					t = arr[i][j]+arr[i-1][j];
				} 
			
			
			}
				
				
				cout<<" "<<t;
			}
			cout<<endl;
			
		}
		
	}
	void transpose(){
		
			for(int i=0;i<rows;i++){
			
			for(int j=0;j<cols;j++){
				arr[i][j] = arr[j][i];
				
				}
		}
	}
	
	
	
	~D2ARRAY(){
		for(int i=0;i<rows;i++){
			delete arr[i];
			}
			delete arr;
	}
};
int main(){
D2ARRAY arr1(3,3,2);
arr1.display();
arr1.transpose();
arr1.display();
arr1.resize(2,2,1);
arr1.display();



    return 0;
}