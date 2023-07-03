#include "ServerResponse.h"

string ServerResponse::toString()
{
	return string(messageId + " " + serverId + " " + metadata);
}
