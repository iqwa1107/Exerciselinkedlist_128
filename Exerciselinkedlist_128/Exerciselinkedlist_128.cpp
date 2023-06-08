#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	int rollNumber;
	string name;
	Node* next;
	Node* prev;
};
class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** ar, Node** ikhwa);
	bool listEmpty();
	bool delNode(int rollNo);
	void traverse();
};
void CircularLinkedList::addNode() { 
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> nim;
	cout << "\nEnter the roll name of the student: ";
	cin >> nm;
	Node* newnode = new Node(); //step 1
	newnode->rollNumber = nim; //step 2
	newnode->name = nm; // step 2

	/*insert a node in yhe beginning of a doubly - linked list*/

	if (LAST == NULL || nim <= LAST->rollNumber)
	{
		if (LAST != NULL && nim <= LAST->rollNumber) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newnode->next = LAST; //step 3 
		if (LAST != NULL)
			LAST-> prev= newnode; //step 4
		newnode->prev = NULL; //step 5
		LAST = newnode;//step 6
		return;
	}
	/*insert a node batween tow nodes in the list*/
	Node* ikhwa = LAST; // stap 1.a
	Node* ar = NULL; // stap 1.b
	while (ikhwa->next != NULL && ikhwa->next->rollNumber < nim) // step 1.c
	{
		ar = ikhwa; //1.d
		ikhwa = ikhwa->next; //1.e

	}

	if (ikhwa->next != NULL && nim == ikhwa->rollNumber)
	{
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}
	newnode->next = ikhwa; // steep 4
	newnode->prev = ikhwa; // step 5
	if (ikhwa->next != NULL)
		ikhwa->next->prev = newnode; //step6
	ikhwa->next = newnode; //step 7

}
bool CircularLinkedList::search(int rollno, Node** ar, Node** ikhwa) {
	*ar = LAST->next;
	*ikhwa = LAST->next;
	while (*ikhwa != LAST) {
		if (rollno == (*ikhwa)->rollNumber) {
			return true;
		}
		*ar = *ikhwa;
		*ikhwa = (*ikhwa)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode(int rollNo) {
	Node* ar, * ikhwa;
	ar = ikhwa = NULL;
	if (search(rollNo, &ar, &ikhwa) == false)
		return false;
	if (ikhwa->next != NULL)
		ikhwa->next->prev = ar; // step 2
	if (ar != NULL)
		ar->next = ikhwa; // step 3
	else
		LAST = ikhwa->next;

	delete ikhwa; // step 4
	return true;
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != NULL)
		{
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
				break;
			}
			case '2': {
				
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}