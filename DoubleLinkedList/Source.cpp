#include <iostream>
#include <assert.h>
#include <string>;

using namespace std;

template<typename T>
class DoubleLinkedList {
public:
	class Node {
	public:
		T data;
		Node* next;
		Node* prev;

		Node() : data(" "), next(nullptr), prev(nullptr) {}

	};
	Node* front;
	Node* end;
public:
	DoubleLinkedList()
	{
		front = NULL;
		end = NULL;
	}

	DoubleLinkedList(Node* front, Node* end)
	{
		this->front = front;
		this->end = end;
	}

	void forward_Traverse();
	void bacward_Traverse();
	void insertPosition(string, int);
	void DeletePosition(int);


};

template<typename T>
void DoubleLinkedList<T>::forward_Traverse() {
	Node* traverse;
	traverse = front;
	while (traverse != NULL) {

		cout << traverse->data << " ";
		traverse = traverse->next;
	}
	cout << endl;
}

template<typename T>
void DoubleLinkedList<T>::bacward_Traverse() {
	Node* traverse;
	traverse = end;
	while (traverse != NULL) {
		cout << traverse->data << " ";
		traverse = traverse->prev;
	}
	cout << endl;
}

template<typename T>
void DoubleLinkedList<T>::insertPosition(string newElement, int position) {
	Node* newNode = new Node();
	newNode->data = newElement;
	newNode->next = NULL;
	newNode->prev = NULL;
	if (position < 1) {
		cout << "\nposition should be >= 1.";
	}
	else if (position == 1) {
		newNode->next = front;
		front->prev = newNode;
		front = newNode;
	}
	else {
		Node* temp = front;
		for (int i = 1; i < position - 1; i++) {
			if (temp != NULL) {
				temp = temp->next;
			}
		}
		if (temp != NULL) {
			newNode->next = temp->next;
			newNode->prev = temp;
			temp->next = newNode;
			if (newNode->next != NULL)
				newNode->next->prev = newNode;
		}
		else {
			cout << "\nThe previous node is null.";
		}
	}
}

template<typename T>
void  DoubleLinkedList<T>::DeletePosition(int position) {

	if (position < 1) {
		cout << "\nposition should be >= 1.";
	}
	else if (position == 1 && front != NULL) {


		Node* nodeToDelete = front;
		front = front->next;
		free(nodeToDelete);
		if (front != NULL)
			front->prev = NULL;
	}
	else {


		Node* temp = front;
		for (int i = 1; i < position - 1; i++) {
			if (temp != NULL) {
				temp = temp->next;
			}
		}


		if (temp != NULL && temp->next != NULL) {
			Node* nodeToDelete = temp->next;
			nodeToDelete->prev->next = nodeToDelete->next;
			nodeToDelete->next->prev = nodeToDelete->prev;
			free(nodeToDelete);
		}
		else {


			cout << "\nThe node is already null.";
		}
	}

}



void main() {
	DoubleLinkedList<string>::Node* first = NULL;
	DoubleLinkedList<string>::Node* second = NULL;
	DoubleLinkedList<string>::Node* third = NULL;

	first = new DoubleLinkedList<string>::Node;
	second = new DoubleLinkedList<string>::Node;
	third = new DoubleLinkedList<string>::Node;

	first->data = "first";
	first->next = second;
	first->prev = NULL;

	second->data = "second";
	second->next = third;
	second->prev = first;

	third->data = "third";
	third->prev = second;
	third->next = NULL;

	DoubleLinkedList<string> dll(first, third);

	dll.forward_Traverse();
	dll.bacward_Traverse();
	cout << "====================================== " << endl;
	dll.insertPosition("Insert", 1);
	dll.forward_Traverse();
	dll.bacward_Traverse();
	cout << "====================================== " << endl;
	dll.DeletePosition(2);
	dll.forward_Traverse();
	dll.bacward_Traverse();
	cout << "====================================== " << endl;
}