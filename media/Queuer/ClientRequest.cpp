#include "ClientRequest.h"

string ClientRequest::toString()
{

	return string(messageId + " " + clientId + " " + to_string(requestTime));
}
