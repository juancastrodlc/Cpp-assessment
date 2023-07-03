#pragma once
#include <iostream>
#include "Message.h"
using namespace std;
// I'm aware there is a queue structure in the STL, however I am implementing one to showcase what I know of CPP
int MAX_QUESIZE = 1000;

struct Node {
	Message& data;
	Node* next = NULL;
	Node() {}
	bool operator==(const Node& other) const
	{
		return data == other.data && next == other.next;
	}
};

struct Queue
{
	Node* front, * rear;
	int queSize = 0;
	Queue()
	{
		front = rear = NULL;
	}

	void enqueue(Message& data)
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
		return front->data.toString();
	}

	unsigned int getCountClients()
	{
		Node* temp;
		temp = front;
		int result = 0;
		while (temp->next != NULL)
		{
			if (typeid(temp->data).name() == "ClientRequest")
			{
				result++;
			}
		}
		return result;
	}

	unsigned int getCountServers()
	{
		Node* temp;
		temp = front;
		int result = 0;
		while (temp->next != NULL)
		{
			if (typeid(temp->data).name() == "ServerResponse")
			{
				result++;
			}
		}
		return result;
	}
};

