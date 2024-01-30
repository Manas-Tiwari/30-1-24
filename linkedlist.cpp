/**
 *  
 *  This program implements a Singly Linked List with insert, delete and search methods.
 *
 * */



#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int val;
	Node* next;
	int size;
	Node(){
		this->val = 0;
		this->next = nullptr;
		size = 1;
	}

	Node(int v){
		this->val = v;
		this->next = nullptr;
		size = 1;
	}

	int get_size() {
		return this->size;
	}

	friend void search(Node* head, int target){
		while(head != nullptr){
			if (head->val == target) {
				cout << "Target found in the linked list.\n";
				return ;
			}
			head = head->next;
		}
		cout << "Target Not Found." << endl;
	}

	friend Node* insert(Node* head, int pos, int x) {
		Node* headPtr = head;
		Node* tail = nullptr;
		int ctr = 1;
		while(head != nullptr){
			if (ctr == pos) break;
			tail = head;
			head = head->next;
			ctr++;
		}	
		Node* node = new Node(x);
		node->next = head;
		if (tail == nullptr){
			return node;
		}
		tail->next = node;
		return headPtr;
	}

	friend Node* deleteNode(Node* head, int ele){
		Node* tmp = head;
		Node* tail = nullptr;
		while(tmp != nullptr){
			if (tmp->val == ele) break;
			tail = tmp;
			tmp = tmp->next;
		}
		if (tail == nullptr){
			tmp = tmp->next;
			delete head;
			return tmp;
		}
		Node* t = tmp->next;
		delete tmp;
		tail->next = t;
	}

	friend void print(Node* head) {
		while(head != nullptr){
			cout << head->val << " ";
			head = head->next;
		}
		cout << endl;
	}
};



int main() {
	Node* head = new Node(10);
	head->next = new Node(20);
	head->next->next = new Node(30);
	cout << "=========================\n";
	cout << "1.Insert  2.Search  3.Delete  4.Print Linked List  5.Exit\n";
	int ch;
	cout << "Enter choice: ";
	cin >> ch;
	if (ch > 4 || ch < 1){
		cout << "Exiting!...\n";
		return 0;
	}
	if (ch == 1){
		int pos, el;
		cout << "Enter position and val: ";
		cin >> pos >> el;
		head = insert(head, pos, el);
		cout << "Element added.\n";
		print(head);
	}
	else if (ch == 2){
		int el;
		cout << "Enter element to search for: ";
		cin >> el;
		search(head, el);
		print(head);
	}
	else if (ch == 3){
		int el;
		cout << "Enter element val to delete: ";
		cin >> el;
		head = deleteNode(head, el);
		cout << "Node deleted.\n";
		print(head);
	}
	else {
		print(head);
	}
	
	return 0;
}
