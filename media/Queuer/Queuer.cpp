// Queuer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Queue.h"
#include "ClientRequest.h"
#include "ServerResponse.h"

int main()
{

	try
	{
		Queue* queue = new Queue();
		Message* message = new ClientRequest("m1", "C1", 10);
		Message* message2 = new ServerResponse("m2", "S1", "4bytes,1second");
		Message* message3 = new ClientRequest("m3", "C2", 15);
		Message* message4 = new ClientRequest("m4", "C3", 10);
		Message* message5 = new ServerResponse("m5", "S2", "0123456789012345678901234567890123456789");
		queue->enqueue(message);
		queue->enqueue(message2);
		queue->enqueue(message3);
		queue->enqueue(message4);
		queue->enqueue(message5);
		cout << "Clients: " << queue->getCountClients() << endl;
		cout << "Servers: " << queue->getCountServers() << endl;

		cout << queue->getFront() << endl;
		queue->dequeue();
		cout << queue->getFront() << endl;
		queue->dequeue();
		cout << queue->getFront() << endl;
		while (queue->queSize > 0)
		{
			queue->dequeue();
		}
		delete message;
		delete message2;
		delete message3;
		delete message4;
		delete message5;
	}
	catch (const std::exception& ex)
	{
		cout << "Error executing Queuer: " << ex.what() << endl;
	}

}

