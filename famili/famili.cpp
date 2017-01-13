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
	short int age, x;    // x - height of node
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
	age = x = 0;
}


class familyTree
{

public:

	node* start;

	familyTree();


};

familyTree::familyTree()
{
	start = NULL;
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
		cout << "\n\n\n\tFamily tree no = " << n << "\n\n\t1. Add new person\n\t2. Find relationship b/w two persons\n\t3. Search\n\t4. Destroy\n\t5. Display\n\t6. Change family tree\n\t7. Connect two family trees\n\t8. Exit\n\n\tEnter your choice = ";
		cin >> opt;
		cout << endl;

		switch (opt)
		{

		default:
			cout << "Invalid input";
			break;

		case 1:
			break;

		case 2:
		
			break;

		case 3:
			break;
		case 4:
		
			break;

		case 5:
			break;
		case 6:
			
			break;

		case 7:
			break;
		case 8:
			return 0;

		}
		cout << "\n\nPress any key to continue.....";
		cin >> c;
	}
}


