#pragma once
#include <string>
#include <typeinfo>
using namespace std;
class Message
{
public:
	string messageId;
	Message() {}
	bool operator==(const Message& other) const
	{
		return messageId == other.messageId;
	}
	virtual bool checkMessageLength(string& messageId)
	{
		int len = messageId.length();
		return 1 <= len <= 50;
	}
	virtual string toString() = 0;
};

