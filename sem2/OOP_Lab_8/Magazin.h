#pragma once
#include "Print.h"
#include <string>

//Magazine class inheriting from Print
class Magazin :
    public Print
{
protected:
    int pages; //number of pages in the magazine

public:
    //Basic constructors and destructor
    Magazin();
    Magazin(std::string, std::string, int);
    Magazin(const Magazin&);

    ~Magazin();

    //Formatted input and output
    void Show();
    void Input();

    //Basic getters and setters
    int getPages();
    void setPages(int);

    //Assignment operator
    Magazin& operator= (const Magazin&);
};