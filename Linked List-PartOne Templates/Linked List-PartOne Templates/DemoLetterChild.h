#pragma once
#include "DemoLetter.h"
class DemoLetterChild :
	public DemoLetter
{
public:
	DemoLetterChild();
	virtual ~DemoLetterChild();
	virtual void DisplaySomething();
};

