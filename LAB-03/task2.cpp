#include<iostream>
using namespace std;
class Book{
	public:
		Book * next;
		string title;
		Book(string title=""):title(title),next(nullptr){}
		
		
};
class LinkedList{
	
	public:
		Book * head;
		Book * tail;
		LinkedList(){
		  head = nullptr;
		  tail = nullptr;
		}

		void insertAtEnd(string book){
			if(head==nullptr){
				head = new Book(book);
				tail = head;
			}
			
			Book * n = new Book(book);
			tail->next = n;
			
		}
		void deleteAtFront(){
			if(head == nullptr) return;
			Book * next = head->next;
			delete head;
			head = next;
		}
		bool searchByTitle(string title){
			if(head == nullptr) return false;
			Book *temp = head;
			while(temp!=nullptr){
				
				if(temp->title==title){
					cout<<endl<<title<<" Exists"<<endl;
					return true;
				}
				temp= temp->next;
				}
				cout<<endl<<title<<" Doesn't Exists"<<endl;
				return false;
		}
		int searchByPosition(string title){
			
			if(head == nullptr) return -1;
			int pos = 0;
			Book *temp = head;
			while(temp!=nullptr){
				pos++; 
				if(temp->title==title){
				cout<<endl<<title<<" is at "<<pos<<endl;
				return pos;
				}
				temp= temp->next;
			}
			cout<<endl<<title<<" is not here"<<endl;
				return -1;
			
			
		}
		void display(){
			if(head == nullptr) return;
			cout<<endl;
			Book *temp = head;
			while(temp!=nullptr){
				
				cout<<" -> "<<temp->title;
				temp= temp->next;
				}
				cout<<endl;
		}
	
	
	
	
	
	
};
int main(){
	LinkedList l1;
	l1.insertAtEnd("Harry Potter");
	l1.insertAtEnd("Jumanji");
	l1.display();
	l1.searchByTitle("Harry Potter");
    l1.searchByPosition("Jumanji");
	l1.deleteAtFront();
	l1.display();
	return 0;
}