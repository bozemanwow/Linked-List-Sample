// Linked List-PartOne Templates.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Template_Single_Linked_List.h"
#include "DemoLetter.h"
#include "DemoLetterChild.h"
static void DropMessage(char Me);

int _tmain(int argc, _TCHAR* argv[])
{
	
	Template_Single_Linked_List<char> Letter;

	char L = 'L';
	char M = 'M';
	char O = 'O';
	char B = 'B';
	std::cout << "-------Testing add with letters----------" << std::endl;
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
	std::cout << "-------Adding t to the second spot----------" << std::endl;
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
	std::cout << "-------Removing Third Slot----------" << std::endl;
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
	std::cout << "-------DemonStration of Function pointers----------" << std::endl;
	Template_Single_Linked_List<char> Lettertwo;
	LinkedList_Iter<char> Itertwo(Lettertwo);
	Lettertwo.DropCallBackFuncptr = DropMessage;
	Lettertwo.addHead(L);
	Lettertwo.addHead(M);

	Itertwo.begin();
	char Lptr = Lettertwo.Drop(Itertwo);
	char Mptr = Lettertwo.Drop(Itertwo);

	std::cout << Lptr <<" and " << Mptr << " pointers were caught"<<std::endl;


	/*
	Setup like the one below
	*/

	std::cout << "-------Demonstration of Function pointers and class polymorphism----------" << std::endl;

	// Setup with pointers to use polymorphism when needed, so it adds the pointers not the acutal objs
	// that way if I choose to make a dll from this, I wont need to worry about over linking within the dll
	Template_Single_Linked_List<DemoLetter*> DemoLetterList;
	LinkedList_Iter<DemoLetter*> DemoIter(DemoLetterList);
	// using static function of a class to use a c funcptr to do a drop call back within the template class
	// not useing member function pointers to avoid storing a member function ptr for each item added to the list
	DemoLetterList.DropCallBackFuncptr = DemoLetter::DroppedCallBackFunc;
	// Allocate space for child and parent, braces are uses to make pointers fall out of scope
	{
		
		DemoLetter* ParnetPointer = new DemoLetter();
		DemoLetter* ChildPointer = new DemoLetterChild();
		// copies by value the pointers into the list, so just the memory addresses
		DemoLetterList.addHead(ParnetPointer);
		DemoLetterList.addHead(ChildPointer);
	}

	DemoIter.begin();
	// returns a ref of a pointers, copies the values (memory address into the fresh pointers)
	DemoLetter* DemoChildptr = DemoLetterList.Drop(DemoIter);
	DemoLetter* DemoParentptr = DemoLetterList.Drop(DemoIter);
	std::cout <<"After Caught Pointers "  << std::endl;
	DemoParentptr->DisplaySomething();
	DemoChildptr->DisplaySomething();
	// Free Space that been allocated, remove and drop only delete the node
	delete DemoParentptr;
	delete DemoChildptr;
	system("pause");
	return 0;
}
// used with function pointers
static void DropMessage(char Me)
{
	std::cout << Me << " Was Dropped" << std::endl;
}
