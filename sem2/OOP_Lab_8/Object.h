#pragma once
#include "Event.h"
//A fully abstract class to be stored inside List
class Object
{
public:
	Object();
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual ~Object();

	virtual void HandleEvent(const TEvent& e) = 0;
};