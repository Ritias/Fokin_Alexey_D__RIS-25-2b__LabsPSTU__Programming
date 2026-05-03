#include "Dialog.h"
#include <string>

//Basic constructor - initializes empty list with execution flag false
Dialog::Dialog() : List(0) {
	EndState = 0;
}
Dialog::~Dialog() {}

//Parse user input and convert to event structure
void Dialog::GetEvent(TEvent& event) {
	std::string Operations = "+-mszq?";
	std::string s;
	std::string param;
	char code;
	std::cout << '>';
	std::getline(std::cin, s);
	code = s[0];
	if (Operations.find(code) >= 0) {
		event.what = evMessage;
		switch (code) {
		case 'm': event.command = cmMake; break;//create m size
		case '+': event.command = cmAdd; break;//Add
		case '-': event.command = cmDel; break;//Del
		case 's': event.command = cmShow; break;//Show
		case 'z': event.command = cmName; break;//Names
		case '?': event.command = cmSize; break;//Size
		case 'q': event.command = cmQuit; break;//End
		}
		//Extract parameter if present
		if (s.length() > 1) {
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());
			event.a = A;
		}
	}
	else {
		event.what = evNothing;  //invalid command - ignore
	}
}

//Main execution loop - processes user commands until exit
int Dialog::Execute() {
	TEvent event;
	std::cout << "GUIDE:\nm N -> initialize List of N elements\n+ -> add Element\n- -> delete Element\ns -> Show List\nz -> Show Names\nq -> End\n---------------------------------------------------------------\n";
	do {
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} while (!Valid());
	return EndState;
}

//Check if execution should continue
bool Dialog::Valid() {
	return !(EndState == 0);
}

//Reset event to do-nothing state
void Dialog::ClearEvent(TEvent& event) {
	event.what = evNothing;
}

//Signal to exit execution loop
void Dialog::EndExec() {
	EndState = 1;
}

//Process event and execute appropriate actions
void Dialog::HandleEvent(TEvent& event) {
	if (event.what == evMessage) {
		switch (event.command) {
		case cmMake:
			for (int i = 0; i < event.a; i++) {
				Add();
			}
			ClearEvent(event); break;
		case cmAdd:
			Add();
			ClearEvent(event); break;
		case cmDel:
			Del();
			ClearEvent(event); break;
		case cmShow:
			Show();
			ClearEvent(event); break;
		case cmName:
			default:List::HandleEvent(event); //forward to parent class for name display
			ClearEvent(event); break;
		case cmSize:
			std::cout << (*this)() << '\n';
			ClearEvent(event); break;
		case cmQuit:
			EndExec();
			ClearEvent(event); break;
		}
	}
}