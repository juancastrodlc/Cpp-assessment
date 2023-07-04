#pragma once
#include <iostream>
#include "Message.h"
#include "NullMessage.h"
using namespace std;
// I'm aware there is a queue structure in the STL, however I am implementing one to showcase what I know of CPP
#ifndef MAX_QUESIZE
#define MAX_QUESIZE 1000
#endif // !MAX_QUESIZE


struct Node {
	Message* data = NULL;
	Node* next = NULL;
	Node() {}
	bool operator==(const Node& other) const
	{
		return data == other.data && next == other.next;
	}
};

struct Queue
{
	Node* front = NULL, * rear = NULL;
	int queSize = 0;
	Queue()
	{
		front = rear = NULL;
	}

	void enqueue(Message* data);

	void dequeue();

	string getFront();

	unsigned int getCountByClass(const string& className);

	unsigned int getCountClients();

	unsigned int getCountServers();
};

