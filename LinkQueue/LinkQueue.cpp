#include "LinkQueue.h"

template<class DataType>
LinkQueue<DataType>::LinkQueue()
{
	this->front = new Node;
	this->front->next = NULL;
	this->rear = front;
	this->length = 0;
}

template<class DataType>
LinkQueue<DataType>::~LinkQueue()
{
	Node* p, * q;

	p = front->next;
	q = front;
	
	while (p != NULL)
	{
		
		q = p;
		p = p->next;
		//cout << "析构中。。。。。。。。" << endl;
		delete q;
		
	}
	delete p;
	delete front;
	
	//while (front != NULL)
	//{
	//	p = front;
	//	//cout << front->data << endl;
	//	delete p;
	//	this->front = this->front->next;
	//}
}

template<class DataType>
void LinkQueue<DataType>::enQueue(DataType item)
{
	//no matter how many nodes(0 or more than 0) exist, the following codes will work
	Node* newNode = new Node;//create a new node to put in the queue
	newNode->data = item; //store the data into the node
	newNode->next = NULL;//make sure no wild ptr
	this->rear->next = newNode;//put the new node after the original rear-node
	this->rear = newNode;//make the rear-ptr point to the new node.
	length++;//increase the length
	//cout << "enQueue的值是：" << item << endl;
}

template<class DataType>
bool LinkQueue<DataType>::deQueue(DataType& item)
{
	//if the queue is empty
	if (isEmpty())
		return false;

	//if the queue is not empty after we dequeue(front-node does not count);
	Node* p; // create a new ptr to point to the first node after front-node (the node that we are going to dequeue/the node after the front-node)
	p = this->front->next;
	item = p->data; //give the data of the target node to the return parameter:item.
	this->front->next = p->next;//link the front-node to the rest of the nodes. 

	//if the queue is empty after we dequeue(front-node does not count)
	if (p->next == NULL)
		rear = front; // we make rear-ptr and front-ptr point to the same address

	delete p;
	length--;
	return true;
}

template<class DataType>
bool LinkQueue<DataType>::getFront(DataType& item)
{
	if (isEmpty())
		return false;

	item = this->front->next->data;
	return true;

}
	
template<class DataType>
bool LinkQueue<DataType>::isEmpty()
{
	if (rear == front)
		return true;
	return false;
}

template<class DataType>
void LinkQueue<DataType>::clearQueue()
{
	//无法同时运行clearQueue下面这部分与~LinkQueue两个函数
	//Node* p,* q;
	//p = this->front->next;
	//q = this->front;

	//while (p != NULL)
	//{
	//	q = p;
	//	p = p->next;
	//	delete q;
	//}
	//delete p;

	rear = front;
	length = 0;
}

template<class DataType>
void LinkQueue<DataType>::displayQueue()
{
	if (isEmpty())
		cout << "Empty Queue!!!!!" << endl;
	else
	{
		Node* p;
		p = this->front->next;
		cout << "The queue is: " << endl;
		for (int i = 0; i < length; i++)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}

template<class DataType>
int LinkQueue<DataType>::queueLength()
{
	return length;
}

int main()
{
	int item;
	LinkQueue<int> lq;
	lq.enQueue(5);
	lq.enQueue(6);
	lq.enQueue(7);
	lq.enQueue(8);
	lq.enQueue(9);
	lq.enQueue(10);

	lq.displayQueue();

	if (lq.getFront(item))
		cout << "item is: " << item << endl;

	int length = lq.queueLength();
	for (int i = 0; i < length + 1; i++)
	{
		if (!lq.isEmpty())
		{
			lq.deQueue(item);
			cout << item << " " << endl;
		}
		else
		{
			cout << "Queue is empty!!!!" << endl;
		}
	}

	lq.enQueue(100);
	cout << "the length right now is: " << lq.queueLength() << endl;
	lq.clearQueue();
	cout << "the length after clearing is: " << lq.queueLength() << endl;


	return 0;
	
}