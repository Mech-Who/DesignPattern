#pragma once
#ifndef __COMMAND_H__
#define __COMMAND_H__

#include <string>
#include <vector>

struct Command;

struct Invoker {
	~Invoker();
	void SetOnStart(Command* cmd);
	void SetOnFinish(Command* cmd);
	void DoSomethingImportant();
protected:
	Command* startCmd;
	Command* finishCmd;
};

struct Receiver
{
	void operation(std::string title, std::string msg);
};

struct Command {
	virtual ~Command() = default;
	virtual void execute() = 0;
};

struct SimpleCommand : public Command
{
	explicit SimpleCommand(std::string msg);
	void execute() override;
protected:
	std::string msg;
};

struct ComplexCommand : public Command
{
	explicit ComplexCommand(Receiver* rec, std::string title, std::string msg);
	void execute() override;
protected:
	Receiver* receiver;
	std::string title;
	std::string msg;
};

#endif // __COMMAND_H__
