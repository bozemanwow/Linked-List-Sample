#pragma once
#include <string>
class DemoLetter
{
public:
	std::string letter;
	DemoLetter();
	virtual ~DemoLetter();
	virtual void DisplaySomething();
	// to setup c style function ptr
	static void DroppedCallBackFunc(DemoLetter* _Me);
	
};

