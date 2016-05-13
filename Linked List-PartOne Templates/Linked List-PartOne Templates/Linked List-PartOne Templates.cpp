// Linked List-PartOne Templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Template_Single_Linked_List.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Template_Single_Linked_List<char> Letter;

	char L = 'L';
	char M = 'M';
	char O = 'O';
	char B = 'B';
	Letter.addHead(L);
	Letter.addHead(M);
	Letter.addHead(O);
	Letter.addTail(B);

	LinkedList_Iter<char> Iter(Letter);
	while(!Iter.end())
	{
		std::cout << Iter.current() << std::endl;
		Iter++;
		
	}
	std::cout << "-------" << std::endl;
	char T = 'T';
	Iter.begin();

	Iter++;
	
	Letter.Insert(Iter, T);
	

	
	
	Iter.begin();
	while (!Iter.end())
	{
		std::cout << Iter.current() << std::endl;
		Iter++;
	}
	std::cout << "-------" << std::endl;
	Iter.begin();

	Iter++;

	Iter++;

	Letter.remove(Iter);
	
	Iter.begin();
	while (!Iter.end())
	{
		std::cout << Iter.current() << std::endl;
		Iter++;
	}

	system("pause");
	return 0;
}

