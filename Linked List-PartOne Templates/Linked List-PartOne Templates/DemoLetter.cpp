#include "stdafx.h"
#include "DemoLetter.h"
#include <iostream>

DemoLetter::DemoLetter()
{
	letter = "parent";
}


DemoLetter::~DemoLetter()
{
}
void DemoLetter::DisplaySomething()
{
	std::cout << "I am Dropped Parent " << letter<< std::endl;
}

void DemoLetter::DroppedCallBackFunc(DemoLetter* _Me)
{
	_Me->DisplaySomething();
}