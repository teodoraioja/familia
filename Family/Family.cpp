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
	std::cout << "\nName: ";
	cin >> name;
	std::cout << name << " is (m/f): ";
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
	void find();
	void deleteTree(node*);                // Function to delete full tree



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
		std::cout << "***Not found***";
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
		std::cout << "\nEnter any relation's: ";
		char name[50];
		cin >> name;
		std::cout << "\n1. Child\n2. Sibiling\n\n" << temp->name << " is ____ to " << name << " : ";
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
	std::cout << "\nPerson sucessfully added.\n";
}

void familyTree::find()
{

	char name1[50], name2[50];
	std::cout << "Enter names of two persons:\n";
	cin >> name1 >> name2;
	node* ptr1 = search(name1);
	node* ptr2 = search(name2);
	node* ptr;
	node* ptrk = ptr1;
	node* ptrk1 = ptr2;

	switch (ptr1->x - ptr2->x)
	{

	case 0:
		std::cout << 'o';
		char s[50];
		strcpy_s(s, "sister");
		if (ptr1->g)
			strcpy_s(s, "brother");

		ptr = ptr1;
		while (ptr != NULL)
		{
			if (ptr == ptr2)
			{
				std::cout << endl << name1 << " is " << name2 << "'s " << s << endl;
				return;
			}
			ptr = ptr->ns;
		}
		ptr = ptr2;
		while (ptr != NULL)
		{
			if (ptr == ptr1)
			{
				std::cout << endl << name1 << " is " << name2 << "'s " << s << endl;
				return;
			}
			ptr = ptr->ns;
		}
		std::cout << endl << name1 << " and " << name2 << " are Cousins";
		break;

	case 1:
		std::cout << '1';
		char str3[50];
		strcpy_s(str3, "daughter");
		if (ptr1->g)
			strcpy_s(str3, "son");
		ptr2 = ptr2->fc;
		while (ptr2 != NULL)
		{
			if (ptr2 == ptr1)
			{
				std::cout << endl << name1 << " is " << name2 << "'s " << str3;
				return;
			}
			ptr2 = ptr2->ns;
		}
		strcpy_s(str3, "niece");
		if (ptr1->g)
			strcpy_s(str3, "nephew");
		std::cout << endl << name1 << " is " << name2 << "'s " << str3;
		break;
	case -1:
		std::cout << '-1';
		char str[10];
		strcpy_s(str, "mother");
		if (ptrk->g)
			strcpy_s(str, "father");

		ptr = ptrk->fc;
		while (ptr != NULL)
		{
			if (ptr == ptrk1)
			{
				std::cout << endl << name1 << " is " << name2 << "'s " << str;
				return;
			}
			ptr = ptr->ns;
		}
		strcpy_s(str, "aunt");
		if (ptrk->g)
			strcpy_s(str, "uncle");
		std::cout << endl << name1 << " is " << name2 << "'s " << str;
		break;

	case 2:
		std::cout << '2';
		char str1[50];
		strcpy_s(str1, "daughter");
		if (ptr2->g)
			strcpy_s(str1, "son");
		ptr2 = ptr2->fc->fc;
		while (ptr2 != NULL)
		{
			if (ptr2 == ptr1)
			{
				std::cout << endl << name1 << " is grand " << str1 << " of " << name2;
				return;
			}
			ptr2 = ptr2->ns;
		}
		break;
	case -2:
		std::cout << '-2';
		char str2[50];
		strcpy_s(str2, "mother");

		if (ptr1->g)
			strcpy_s(str2, "father");

		ptr1 = ptr1->fc->fc;

		while (ptr1 != NULL)
		{
			if (ptr1 == ptr2)
			{
				std::cout << endl << name1 << " is grand " << str2 << " of " << name2;
				return;
			}
			ptr1 = ptr1->ns;
		}

		break;
	case 3:
		std::cout << '3';
		char strg1[50];
		strcpy_s(strg1, "daughter");
		if (ptr2->g)
			strcpy_s(strg1, "son");
		ptr2 = ptr2->fc->fc;
		while (ptr2 != NULL)
		{
			if (ptr2 == ptr1)
			{
				std::cout << endl << name1 << " is grand grand " << strg1 << " of " << name2;
				return;
			}
			ptr2 = ptr2->ns;
		}
		break;
	case -3:
		std::cout << '-3';
		char strg2[50];
		strcpy_s(strg2, "mother");

		if (ptr1->g)
			strcpy_s(strg2, "father");

		ptr1 = ptr1->fc->fc;

		while (ptr1 != NULL)
		{
			if (ptr1 == ptr2)
			{
				std::cout << endl << name1 << " is grand grand " << strg2 << " of " << name2;
				return;
			}
			ptr1 = ptr1->ns;
		}

		break;
	default:
		std::cout << "Too far relationship! It's a  " << ptr1->x - ptr2->x << "degree";
		break;
	}
}


void familyTree::deleteTree(node* ptr)
{
	node* temp = ptr;

	if (ptr == NULL)
		return;

	while (ptr != NULL)
	{
		deleteTree(ptr->fc);
		temp = ptr;
		ptr = ptr->ns;
		delete temp;
	}

	start = NULL;
}


int main()
{
	familyTree T[100];
	int opt, n, n1, n2;
	char c, name[50];
	std::cout << "\nEnter the family tree number = ";
	cin >> n;
	while (1)
	{

		std::cout << "\n\n\n\tFamily tree no = " << n << "\n\n\t1. Add new person\n\t2. Find relationship b/w two persons\n\t3. Delete tree\n\t4. Exit\n\n\tEnter your choice = ";
		cin >> opt;
		std::cout << endl;

		switch (opt)
		{
		case 1:
			T[n].addNew();
			break;
		case 2:
			T[n].find();
			break;
		case 3:
			T[n].deleteTree(T[n].start);
			cout << "Tree " << n << " has been deleteed sucessfully";
			break;

		case 4:
			return 0;
		default:
			std::cout << "Invalid input";
			break;

		}
		cout << "\n\nPress any key to continue.....";
		cin >> c;
	}
}


