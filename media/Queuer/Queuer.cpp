// Queuer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Queue.h"
#include "ClientRequest.h"
#include "ServerResponse.h"

int main()
{
	Queue* queue = new Queue();
	Message* message = new ClientRequest("m1", "C1", 10);
	Message* message2 = new ServerResponse("m2", "S1", "4bytes,1second");
	Message* message3 = new ClientRequest("m3", "C2", 15);
	queue->enqueue(message);
	queue->enqueue(message2);
	queue->enqueue(message3);
	cout << queue->getCountClients() << endl;
	cout << queue->getCountServers() << endl;
	cout << queue->getFront() << endl;
	queue->dequeue();
	cout << queue->getFront() << endl;
}

