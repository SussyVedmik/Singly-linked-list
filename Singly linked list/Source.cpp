#include <iostream>
using namespace std;

struct Element
{
	char data;
	Element* Next;
};

class List
{
	Element* Head;
	Element* Tail;
	int Count;

public:
	List();

	~List();

	void Add(char data);

	void Del();

	void DelAll();

	void Print();

	int GetCount();

	void DelPos(int i) {
		Element* temp = Head;
		while (i < 2) {
			temp = temp->Next;
			i--;
		}
		Element* del = temp->Next;
		temp->Next = del->Next;
		delete del;
	}

	void Insert(char data, int pos) {
		if (pos < 0) {
			cout << "Invalid Pos!" << endl;
			return;
		}

		Element* nNode = new Element;
		nNode->data = data;
		if (pos == 0) {
			nNode->Next = Head;
			Head = nNode;
			if (Tail == nullptr) Tail = nNode;
		}
		else {
			Element* pNode = Head;
			for (int i = 0; i < pos - 1 && pNode != nullptr; i++) {
				pNode = pNode->Next;
			}
			if (pNode != nullptr) {
				nNode->Next = pNode->Next;
				pNode->Next = nNode;
				if (pNode == Tail) Tail = nNode;
			}
			else {
				if (Tail != nullptr) {
					Tail->Next = nNode;
					Tail = nNode;
				}
				else {
					Head = Tail = nNode;
				}
			}
		}
		Count++;
	}

	int Find(char data) {
		Element* cur = Head;
		int temp = 0;
		while (cur != nullptr) {
			if (cur->data == data) {
				return temp;
			}
			cur = cur->Next;
			temp++;
		}
		return -1;
	}

};

List::List()
{
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	DelAll();
}

int List::GetCount()
{
	return Count;
}

void List::Add(char data)
{
	Element* temp = new Element;

	temp->data = data;
	temp->Next = NULL;
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	else {
		Head = Tail = temp;
	}
}

void List::Del()
{
	Element* temp = Head;
	Head = Head->Next;
	delete temp;
}

void List::DelAll()
{
	while (Head != 0)
		Del();
}

void List::Print()
{
	Element* temp = Head;
	while (temp != 0)
	{
		cout << temp->data << " ";
		temp = temp->Next;
	}

	cout << "\n\n";
}

void main()
{
	List lst;

	char s[] = "Yes\n";
	cout << s << "\n";
	int len = strlen(s);
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	lst.Print();
	lst.Insert('K', 4);
	lst.Insert('A', 8);
	lst.Print();

	int temp = lst.Find('W');
	if (temp != -1) {
		cout << "Element found" << temp << endl;
	}
	else {
		cout << "Element not found" << endl;
	}

	system("pause");
}