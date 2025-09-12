#include<iostream>
using namespace std;
class DARRAY{
	
	private:
		int * arr;
		int size;
	public:
		DARRAY():arr(nullptr),size(0){}
		void push_back(int data){
			
			if(arr == nullptr){
				arr = new int[1];
				arr[size++] = data;
				return;
			}
			int *temp = new int[size+1];
			for(int i=0;i<size;i++){
				temp[i] = arr[i];
			}
			temp[size++] = data;
			delete[] arr;
			arr = temp;
			
		}
	void display(){
		for(int i=0;i<size;i++){
			cout<<" "<<arr[i];
		}
		cout<<endl;
		
	}
	~DARRAY(){
		delete[] arr;
	}
};
int main(){
DARRAY da;
da.push_back(20);
da.push_back(30);


    return 0;
}