#include "stdafx.h"
#include "DemoLetterChild.h"
#include "DemoLetter.h"
#include <iostream>
DemoLetterChild::DemoLetterChild()
{
	letter = "child";
}


DemoLetterChild::~DemoLetterChild()
{
}
void DemoLetterChild::DisplaySomething()
{
	std::cout << " I am a Dropped Child "<< letter << std::endl;
}