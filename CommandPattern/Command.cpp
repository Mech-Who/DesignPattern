#include "Command.h"
#include <iostream>

using namespace std;


void Invoker::SetOnStart(Command* cmd)
{
	startCmd = cmd;
}

void Invoker::SetOnFinish(Command* cmd)
{
	finishCmd = cmd;
}

void Invoker::DoSomethingImportant()
{
	startCmd->execute();
	finishCmd->execute();
}

Invoker::~Invoker() 
{
	delete startCmd;
	delete finishCmd;
}

void Receiver::operation(std::string title, std::string msg)
{
	cout << "Receiver: [title]: " << title
		<< ", [message]: " << msg
		<< endl;
}

SimpleCommand::SimpleCommand(std::string msg)
: msg(msg){}

void SimpleCommand::execute()
{
	cout << "SimpleCommand: [message]: " << msg 
		<< endl;
}

ComplexCommand::ComplexCommand(Receiver* rec, std::string title, std::string msg)
: receiver(rec), title(title), msg(msg){}

void ComplexCommand::execute()
{
	receiver->operation(title, msg);
}
