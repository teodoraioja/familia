// famili.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define WINDOWS
//#define LINUX

/** FAMILY TREE */

#include<iostream>
#include<iostream>
#include<string>
#include<string.h>
#include<stdlib.h>

using namespace std;


struct node
{



	


	char name[50];
	short int  x;    // x - height of node
	bool g;             // g- gender

	node* fc;           // Pointer to first child
	node* ns;           // Pointer to next sibiling

	node();
	void getData();
};

node::node()
{
	fc = ns = NULL;
	g = 0;
	strcpy_s(name, "");
}

void node::getData()
{
	char ch;
	cout << "\nName: ";
	cin >> name;
	cout << name << " is (m/f): ";
	cin >> ch;
	if (ch == 'm')
		g = 1;
}


class familyTree
{

public:

	node* start;

	familyTree();


	void addSib(node*, node*);          
	void addChild(node*, node*);
	void addNew();

	node* search(char[]);// search furnctions
	node* trDown(node*, char[]);   
	node* trRight(node*, char[]);


};

familyTree::familyTree()
{
	start = NULL;
}

node* familyTree::search(char s[50])
{
	/*
	Searches for name itto it's sibilings and their children
	Returns the pointer of node where the name is present
	*/

	node *ptr = start;
	if (strcmp(ptr->name, s) == 0)
		return ptr;
	else if (trRight(start, s) != NULL)
		return trRight(start, s);
	else if (trDown(start, s) != NULL)
		return trDown(start, s);
	else
	{
		return NULL;
		cout << "***Not found***8";
	}


	
	return 0;
}

node* familyTree::trDown(node* ptr, char s[50])
{
	// Searches all the children

	ptr = ptr->fc;

	while (ptr != NULL)
	{
		if (strcmp(ptr->name, s) == 0)
			return ptr;
		else if (trRight(ptr, s) != NULL)
			return trRight(ptr, s);
		else
			ptr = ptr->fc;
	}
	return NULL;
}

node* familyTree::trRight(node* ptr, char s[50])
{

	//  Searches all the sibilings

	ptr = ptr->ns;

	while (ptr != NULL)
	{
		if (strcmp(ptr->name, s) == 0)
			return ptr;
		else if (trDown(ptr, s) != NULL)
			return trDown(ptr, s);
		else
			ptr = ptr->ns;
	}
	return NULL;
}

void familyTree::addSib(node* a, node* b)
{
	// b is added as sibling of a

	while (a->ns != NULL)
		a = a->ns;
	a->ns = b;

	b->x = a->x;
}

void familyTree::addChild(node* a, node* b)
{

	// b is added as child as a (or) b is added as sibiling to last child of a

	if (a->fc == NULL)
		a->fc = b;
	else
		addSib(a->fc, b);

	b->x = a->x + 1;
}

void familyTree::addNew()
{
	node* temp = new node;
	temp->getData();

	if (start == NULL)
	{
		start = temp;
		temp->x = 0;
	}

	else
	{
		cout << "\nEnter any relation's: ";
		char name[50];
		cin >> name;
		cout << "\n1. Child\n2. Sibiling\n\n" << temp->name << " is ____ to " << name << " : ";
		int opt;
		cin >> opt;
		switch (opt)
		{
		case 1:
			addChild(search(name), temp);
			break;
		case 2:
			addSib(search(name), temp);
			break;

		}
	}
	cout << "\nPerson sucessfully added.\n";
}



int main()
{
	familyTree T[100];
	int opt, n, n1, n2;
	char c, name[50];
	cout << "\nEnter the family tree number = ";
	cin >> n;
	while (1)
	{
#ifdef WINDOWS
		system("cls");
#endif // WINDOWS
#ifdef LINUX
		system("clear");
#endif // LINUX
		cout << "\n\n\n\tFamily tree no = " << n << "\n\n\t1. Add new person\n\t2. Find relationship b/w two persons\n\t3. Exit\n\n\tEnter your choice = ";
		cin >> opt;
		cout << endl;

		switch (opt)
		{

		default:
			cout << "Invalid input";
			break;

		case 1:
			T[n].addNew();
			break;

		case 2:
		
			break;

		case 3:
			return 0;
		

		}
		cout << "\n\nEnter your choice =";
		cin >> c;
	}
}


