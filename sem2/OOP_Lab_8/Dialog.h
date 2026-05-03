#pragma once
#include "List.h"
#include "Event.h"

//Dialog class for user interaction and event-driven interface
class Dialog :
    public List
{
public:
    Dialog();
    virtual ~Dialog();

    //Event handling and execution flow
    virtual void GetEvent(TEvent& event);
    virtual int Execute();
    virtual void HandleEvent(TEvent& event);
    virtual void ClearEvent(TEvent& event);

    //State management
    bool Valid();
    void EndExec();

protected:
    int EndState;  //flag indicating whether to terminate execution
};