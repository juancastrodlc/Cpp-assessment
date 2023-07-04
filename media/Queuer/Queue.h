#pragma once
#include <iostream>
#include "Message.h"
#include "NullMessage.h"
using namespace std;
// I'm aware there is a queue structure in the STL, however I am implementing one to showcase what I know of CPP
int MAX_QUESIZE = 1000;

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

	void enqueue(Message* data)
	{

		Node* q;
		q = new Node;
		q->data = data;
		q->next = NULL;
		if (queSize >= MAX_QUESIZE)
		{
			cout << "Cannot queue more elements.";
			return;
		}
		if (front == NULL) {
			front = rear = q;
			return;
		}
		rear->next = q;
		rear = q;
		queSize++;
		return;
	}

	void dequeue()
	{
		Node* temp;
		if (front == NULL) {
			cout << "Queue is empty";
			return;
		}
		temp = front;
		front = front->next;
		delete temp;
		queSize--;
		return;
	}

	string getFront()
	{
		if (front == NULL)
		{
			return string("Queue is empty");
		}
		return front->data->toString();
	}

	unsigned int getCountByClass(const string& className)
	{
		Node* temp;
		temp = front;
		int result = 0;
		string typeName = typeid((*temp->data)).name();
		if (typeid(*temp->data).name() == className)
		{
			result++;
		}
		while (temp->next != NULL)
		{
			temp = temp->next;
			typeName = typeid((*temp->data)).name();
			if (typeName == className)
			{
				result++;
			}
		}
		return result;
	}

	unsigned int getCountClients()
	{
		return getCountByClass("class ClientRequest");
	}

	unsigned int getCountServers()
	{
		return getCountByClass("class ServerResponse");
	}
};

