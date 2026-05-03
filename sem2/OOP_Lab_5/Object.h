#pragma once
class Object //fully abstract class
{
public:
	Object();
	~Object();
	virtual void Show() = 0;
};

