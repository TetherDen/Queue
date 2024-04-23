#include <iostream>
#include <ctime>
#include "P_Queue.h"
using namespace std;

//  Завдання №1
//  Створіть шаблонний клас звичайної черги для роботи
//  з цілими значеннями.Потрібно створити реалізації для
//  типових операцій над елементами :
//   IsEmpty — перевірка черги на порожнечу;
//   IsFull — перевірка черги на заповнення;
//   Enqueue — додавання елемента в чергу;
//   Dequeue — видалення елемента з черги;
//   Show — відображення всіх елементів черги на екран.

template <class T >
class Queue
{
	T* _queue;
	unsigned int _capacity; // max размер очереди
	unsigned int _size;    // size
public:
	Queue(): _capacity(10), _queue(new T[10]), _size(0) {}
	Queue(const Queue& obj)
	{
		_capacity = obj._capacity;
		_size = obj._size;
		_queue = new T[obj._capacity];
		for (int i = 0; i < obj._size; i++)
		{
			_queue[i] = obj._queue[i];
		}
	}

	Queue& operator=(const Queue& obj)
	{
		if (this != &obj)
		{
			delete[]_queue;
			_capacity = obj._capacity;
			_size = obj._size;
			_queue = new T[obj._capacity];
			for (int i = 0; i < obj._size; i++)
			{
				_queue[i] = obj._queue[i];
			}
		}
		return *this;
	}

	bool isEmpty()
	{
		return _size == 0;
	}

	bool isFull()
	{
		return _size == _capacity;
	}

	void enqueue(T value)
	{
		if (_capacity == _size)
		{
			_capacity += 10;
			T* newQueue = new T[_capacity];
			for (int i = 0; i < _size; i++)
			{
				newQueue[i] = _queue[i];
			}
			delete[]_queue;
			_queue = newQueue;
		}
		_queue[_size] = value;
		++_size;
	}

	T  dequeue()
	{
		T result = 0;  //  0?
		if (!isEmpty())
		{
			result = _queue[0];
			for (int i = 0; i < _size - 1; i++) //
			{
				_queue[i] = _queue[i + 1];
			}
			--_size;
		}
		return result;
	}

	int getSize()
	{
		return _size;
	}
	int getCapacity()
	{
		return _capacity;
	}

	void show()
	{
		for (int i = 0; i < _size; i++)
		{
			cout << _queue[i] << " ";
		}
		cout << endl;
	}

	void clear()
	{
		delete[]_queue;
		_size = 0;
		_capacity = 10;
		_queue = new T[_capacity];
	}
	~Queue()
	{
		if (_queue != nullptr)
		{
			delete[]_queue;
		}
	}


};





int main()
{
	srand(time(0));
	//Queue <double>q1;
	//for (int i = 0; i < 5; i++)
	//{
	//	q1.enqueue(rand() % (100 - 1) + 1);
	//}
	//q1.show();

	//cout << q1.dequeue()<< " ";
	//cout << q1.dequeue()<< " ";
	//cout << q1.dequeue()<< " ";
	//cout << q1.dequeue()<< " ";
	//cout << q1.dequeue()<< " ";
	//cout << q1.dequeue()<< " "<<endl;

	//cout << "q3: " << endl;
	//Queue <char>q3;
	//for (int i = 0; i < 10; i++)
	//{
	//	q3.enqueue(rand() % (100 - 1) + 1);
	//}
	//q3.show();
	//cout << "getsize: " << q3.getSize()<<endl;
	//q3.enqueue(100);
	//q3.show();
	//cout << "getsize: " << q3.getSize() << endl;

	//cout<<"isFull: "<<q3.isFull()<<endl;
	//cout<<"isCapacity: "<<q3.getCapacity()<<endl;


	P_Queue <char>q1;

	cout << "dequeue :" << q1.dequeue()<<endl;

	for (int i = 0; !q1.isFull(); i++)
	{
		q1.enqueue(rand() % (125 - 65) + 65, (rand() % (10 - 1) + 1));
	}
	q1.show();

	cout << "Peek: " << q1.peek() << endl;

	cout << "dequeue: " << endl;
	for (int i = 0; !q1.isEmpty(); i++)
	{
		cout << q1.dequeue() << " ";
	}







	return 0;
}