#include<iostream>
using namespace std;
class Node{
	public:
		Node * next;
		Node * prev;
		int data;
		Node(int data=0):data(data),next(nullptr),prev(nullptr){}
		
		
};
class DoublyLinkedList{
	
	public:
		Node * head;
		DoublyLinkedList(){
			head = nullptr;
		}
		void removeFromFront(){
			if(head == nullptr) return;
			if(head->next != nullptr){
			Node * temp = head->next;
			temp->prev = nullptr;
			delete head;
			head = temp;
			}else{
				delete head;
				head = nullptr;
			}
		}		
		void insertAtEnd(int compartment) {
			Node * n = new Node(compartment);
			if(head==nullptr){
				head = n;
				return;
			}
			Node * temp = head;
			while(temp->next!=nullptr){
				temp = temp->next;
			}
			n->prev = temp; 
			temp->next = n;
		}
		bool search(int comp){
				Node *temp = head;
			while(temp!=nullptr){
			
				
				if(temp->data==comp){
					cout<<endl<<comp<<" Exists"<<endl;
					return true;
				}
				temp= temp->next;
				}
				cout<<endl<<comp<<" Doesn't Exists"<<endl;
				return false;
		}
		
		void display(){
			Node *temp = head;
			cout<<endl;
			while(temp!=nullptr){
				
				cout<<" -> "<<temp->data;
				temp= temp->next;
				}
				cout<<endl;
		}
	
	
	
	
	
	
};
int main(){
	DoublyLinkedList l1;
	l1.insertAtEnd(2);
	l1.insertAtEnd(5);
	l1.display();
	l1.search(5);
	l1.removeFromFront();
	l1.display();
	
	return 0;
}