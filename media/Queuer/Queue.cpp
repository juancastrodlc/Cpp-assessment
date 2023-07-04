#include "Queue.h"

inline void Queue::enqueue(Message* data)
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

inline void Queue::dequeue()
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

inline string Queue::getFront()
{
	if (front == NULL)
	{
		return string("Queue is empty");
	}
	return front->data->toString();
}

inline unsigned int Queue::getCountByClass(const string& className)
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

inline unsigned int Queue::getCountClients()
{
	return getCountByClass("class ClientRequest");
}

inline unsigned int Queue::getCountServers()
{
	return getCountByClass("class ServerResponse");
}
