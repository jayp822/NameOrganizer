#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

struct Node
{
		Node* prev;
		string name;
		Node* next;
};

Node* first = nullptr;
Node* last = nullptr;
Node* curr = nullptr;
Node* newNode;
string name = "";

void PrintForward(Node* first);
void PrintBackward(Node* last);
void sortList();
void freeMemory(Node* first);
	
int main()
{
	while(true)
	{
		cout << "Enter your name in LASTNAME, FIRSTNAME format or enter done to quit: "<<endl;
		getline(cin, name);
		if(name == "Done" || name == "done" )
		{
			break;
		}
		
		newNode = new Node;
		newNode->name = name;
		if(first == nullptr)
		{
			newNode->next = nullptr;
			newNode->prev = nullptr;
			first = newNode;
			last = newNode;
		}else if(newNode->name < first->name)
		{
			newNode->next = first;
			newNode->prev = nullptr;
			first->prev = newNode;
			first = newNode;
		}else if(newNode->name > last->name)
		{
			newNode->next = nullptr;
			newNode->prev = last;
			last->next = newNode;
			last = newNode;
		}else
		{
			curr = first;
			while(curr->name < newNode->name && newNode->name < curr->next->name)
			{
				curr = curr->next;
			}
			newNode->prev= curr;
			newNode->next = curr->next;
			curr->next->prev = newNode;
			curr->next = newNode;
		}
	}
	sortList();
	PrintForward(first);
	PrintBackward(last);
	freeMemory(first);
}

	void PrintForward(Node* first)
	{
		cout << "Ascending order" << endl;
		Node* curr = first;
		if(curr == nullptr)
		{
			cout << "EMPTY LIST";
		}
		else
		{
			while(curr != nullptr)
			{
				cout << curr->name << endl;
				curr = curr->next;
			}
		}
		cout<<endl;
	}
	
	void PrintBackward(Node* last)
	{
		cout << "Descending order" << endl;
		Node* curr = last;
		if(curr == nullptr)
		{
			cout << "EMPTY LIST";
		}
		else
		{
			while(curr != nullptr)
			{
				cout<< curr->name << endl;
				curr = curr->prev;
			}
		}
		cout<<endl;
	}
	void sortList()
	{
		Node* i = first;
		Node* j = nullptr;
		string nameHolder;
		while(i != nullptr)
		{
			j= i->next;
			while(j != nullptr)
			{
				if(i->name > j->name)
				{
					nameHolder = i->name;
					i->name = j->name;
					j->name = nameHolder;
				}
				j = j->next;
			}
			i = i->next;
		}
	}

	void freeMemory(Node* first)
	{
		curr = first;
		while(curr != nullptr)
		{
			Node* oldNode = curr;
			curr = curr->next;
			delete(oldNode);
		}
	}
	



