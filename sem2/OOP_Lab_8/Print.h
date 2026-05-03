#pragma once
#include "Object.h"
#include <string>

class Print :
    public Object //Inheritor of object, basic class
{
protected: //attributes
    std::string name;
    std::string author;
public:
    //basic constructors and a virtual destructor
    Print();
    Print(std::string, std::string);
    Print(const Print&);

    virtual ~Print();

    //i/o methods
    void Show();
    void Input();

    //getters and setters
    std::string getName();
    std::string getAuthor();
    void setName(std::string name_);
    void setAuthor(std::string author_);
    //assignment overload
    Print& operator=(const Print&);
    //Event Handler
    void HandleEvent(const TEvent& e);
};