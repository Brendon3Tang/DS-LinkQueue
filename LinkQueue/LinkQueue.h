#pragma once
#include <iostream>
using namespace std;

template<class DataType>
class LinkQueue
{
private:
	class Node
	{
	public:
		DataType data;
		Node* next;
	};

	Node* front, * rear;
	int length;

public:
	LinkQueue();

	~LinkQueue();

	void enQueue(DataType item);

	bool deQueue(DataType &item);

	bool getFront(DataType &item);

	bool isEmpty();

	void clearQueue();

	void displayQueue();

	int queueLength();

};
