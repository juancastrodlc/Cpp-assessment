#pragma once
#include "Message.h"
#include <stdexcept>

class ServerResponse : public Message {
public:
	string serverId;
	string metadata;
	ServerResponse(const string& messageId, const string& serverId, const string& metadata) {
		this->messageId = messageId;
		this->serverId = serverId;
		this->metadata = metadata;
		if (!checkMessageLength(this->messageId))
		{
			throw invalid_argument("messageId is too long or too short");
		}
		if (!checkMessageLength(this->serverId))
		{
			throw invalid_argument("serverId is too long or too short");
		}
		if (!checkMessageLength(this->metadata))
		{
			throw invalid_argument("metadata is too long or too short");
		}

	}

	bool operator==(const ServerResponse& other) const
	{
		return serverId == other.serverId && metadata == other.metadata && messageId == other.messageId;
	}

	// Inherited via Message
	virtual string toString() override;
};

