#include<iostream>
using namespace std;
class Node{
	public:
		Node * next;
		string data;
		Node(string data=""):data(data),next(nullptr){}
		
		
};
class LinkedList{
	
	public:
		Node * head;
		LinkedList(){
			Node* n1 = new Node("Data Structures");
			Node* n2 = new Node("Operating Systems");
			Node* n3 = new Node("Computer Networks");
			Node* n4 = new Node("Database Systems");
			head = n1;
			n1->next = n2;
			n2->next = n3;
			n3->next = n4;
		}
		void insertAtFront(string Book){
			Node * n = new Node(Book);
			n->next = head;
			head = n;
			
		}
		void insertAtEnd(string Book){
			Node * n = new Node(Book);
			Node * temp = head;
			while(temp->next!=nullptr){
				temp = temp->next;
			}
			temp->next = n;
			
		}
		bool search(string book){
				Node *temp = head;
			while(temp!=nullptr){
				
				if(temp->data==book){
					cout<<endl<<book<<" Exists"<<endl;
					return true;
				}
				temp= temp->next;
				}
				cout<<endl<<book<<" Doesn't Exists"<<endl;
				return false;
		}
		void InsertAfter(string target,string book){
			Node * temp = head;
			while(temp!=nullptr){
				
				if(temp->data == target){
					Node * n = new Node(book);
					n->next = temp->next;
					temp->next = n;
						break;
				}
				
				temp =  temp->next;
			}
			
		}
		void display(){
			Node *temp = head;
			while(temp!=nullptr){
				
				cout<<" -> "<<temp->data;
				temp= temp->next;
				}
		}
	
	
	
	
	
	
};
int main(){
	LinkedList l1;
	l1.insertAtFront("Artificial Intelligence");
	l1.insertAtEnd("Machine Learning");
	l1.InsertAfter("Operating Systems","Cyber Security");
	l1.display();
	l1.search("Database Systems");
	
	return 0;
}