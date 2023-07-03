#pragma once
#include "Message.h"

class NullMessage :
	public Message
{
public:

	NullMessage() = default;

	// Inherited via Message
	virtual string toString() override;
};

