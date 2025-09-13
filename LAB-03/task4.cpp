#include<iostream>
using namespace std;
class Node {
    public:
        Node * next;
        int data;
        Node(int data=0):data(data),next(nullptr){}
};
class LinkedList {
    public:
        Node * head;
        LinkedList(){
            head = nullptr;
        }

        void insertAtEnd(int value){
            if(head==nullptr){
                head = new Node(value);
                return;
            }
            
            Node * n = new Node(value);
            Node * temp = head;
			while(temp->next!=nullptr){
				temp = temp->next;
			}
			temp->next = n;
        }

        void display(){
            if(head == nullptr) return;
            cout<<endl;
            Node *temp = head;
            while(temp!=nullptr){
                cout<<" -> "<<temp->data;
                temp= temp->next;
            }
            cout<<endl;
        }
        
        Node* mergeSorted(Node* h1, Node* h2) {
            if(h1 == nullptr) return h2;
            if(h2 == nullptr) return h1;
            Node* mergedHead = nullptr;
            Node* mergedTail = nullptr;
            if(h1->data < h2->data) {
                mergedHead = h1;
                h1 = h1->next;
            } else {
                mergedHead = h2;
                h2 = h2->next;
            }
            mergedTail = mergedHead;
            while(h1 != nullptr && h2 != nullptr) {
                if(h1->data < h2->data) {
                    mergedTail->next = h1;
                    h1 = h1->next;
                } else {
                    mergedTail->next = h2;
                    h2 = h2->next;
                }
                mergedTail = mergedTail->next;
            }
            if(h1 != nullptr) mergedTail->next = h1;
            if(h2 != nullptr) mergedTail->next = h2;
            return mergedHead;
        }

        void merge(const LinkedList &l2){
            head = mergeSorted(head, l2.head);
        }
};
int main(){
	LinkedList l1,l2,l3;
	l1.insertAtEnd(1);
	l1.insertAtEnd(3);
	l1.insertAtEnd(5);
	l2.insertAtEnd(2);
	l2.insertAtEnd(4);
	l2.insertAtEnd(6);
	l1.display();
	l2.display();
	l1.merge(l2);
	l1.display();
	l3.insertAtEnd(7);
	l3.insertAtEnd(8);
	l3.insertAtEnd(9);
	l1.merge(l3);
	l1.display();
	return 0;
}
