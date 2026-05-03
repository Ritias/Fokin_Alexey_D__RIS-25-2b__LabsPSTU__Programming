#pragma once
//Event type constants
const int evNothing = 0;   //no event
const int evMessage = 100; //message event

//Command constants for message events
const int cmAdd = 1;   //add element to list
const int cmDel = 2;   //delete element from list
const int cmShow = 3;  //show all elements
const int cmName = 4;  //display print name
const int cmMake = 5;  //create something
const int cmSize = 6;  //show list size
const int cmQuit = 101;//exit application

//Event structure for handling commands
struct TEvent {
	int what;           //type of event (evNothing or evMessage)
	union {
		int command;     //command for evMessage
		struct {
			int message;  //additional message data
			int a;        //parameter
		};
	};
};