#pragma once
#include "Message.h"
#include <stdexcept>
class ClientRequest : public Message {
public:
	string clientId;
	int requestTime;
	ClientRequest(const string& messageId, const string& clientId, int requestTime)
	{

		this->messageId = messageId;
		this->clientId = clientId;
		this->requestTime = requestTime;
		if (!checkMessageLength(this->messageId))
		{
			throw invalid_argument("messageId is too long or too short");
		}
		if (!checkMessageLength(this->clientId))
		{
			throw invalid_argument("clientId is too long or too short");
		}
		if (!(1 <= requestTime <= 1000))
		{
			throw invalid_argument("requestTime must be between 1 and 1000");
		}
	}

	bool operator==(const ClientRequest& other) const
	{
		return clientId == other.clientId && requestTime == other.requestTime && messageId == other.messageId;
	}

	// Inherited via Message
	virtual string toString() override;
};

