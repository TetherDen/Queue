#pragma once
#include <iostream>
using namespace std;

template<class T >
class P_Queue
{
	T* _queue;
	int* _priority;
	unsigned int _capacity; // max размер очереди
	unsigned int _size;    // size
public:
	P_Queue();
	P_Queue(const P_Queue& obj);
	P_Queue& operator=(const P_Queue& obj);

	void enqueue(T val, int pri);
	T dequeue();
	T peek();

	bool isEmpty();
	bool isFull();
	void clear();

	void show();
	int getSize();
	int getCapacity();
	~P_Queue();
};

template<class T>
inline P_Queue<T>::P_Queue()
{
	_capacity = 20;
	_queue = new T[_capacity];
	_priority = new int[_capacity];
	_size = 0;
}

template<class T>
inline P_Queue<T>::P_Queue(const P_Queue& obj)
{
	_capacity = obj._capacity;
	_size = obj._size;
	_queue = new T[obj._capacity];
	for (int i = 0; i < obj._size; i++)
	{
		_queue[i] = obj._queue[i];
		_priority[i] = obj._priority[i];
	}
}

template<class T>
inline P_Queue<T>& P_Queue<T>::operator=(const P_Queue<T>& obj) // проверить
{
	if (this != &obj)
	{
		delete[]_queue;
		delete[]_priority; 
		_capacity = obj._capacity;
		_size = obj._size;
		_queue = new T[obj._capacity];
		_priority = new int[obj._capacity];
		for (int i = 0; i < obj._size; i++)
		{
			_queue[i] = obj._queue[i];
			_priority[i] = obj._priority[i];
		}
	}
	return *this;
}

template<class T>
inline void P_Queue<T>::enqueue(T val, int pri)
{
	if (!isFull())
	{
		_queue[_size] = val;
		_priority[_size] = pri;
		_size++;
	}
}

template<class T>
inline T P_Queue<T>::dequeue()
{
	if (!isEmpty())
	{
		int max_pri = _priority[0];
		int pri_index = 0;
		for (int i = 1; i < _size; i++)
		{
			if (max_pri < _priority[i])
			{
				max_pri = _priority[i];
				pri_index = i;
			}
		}
		T temp = _queue[pri_index];

		for (int i = pri_index; i < _size-1; i++)
		{
			_queue[i] = _queue[i + 1];
			_priority[i] = _priority[i + 1];
		}
		_size--;
		return temp;
	}
	//return T();
	return -1;
}

template<class T>
inline T P_Queue<T>::peek()
{
	if (!isEmpty())
	{
		int max_pri = _priority[0];
		int pri_index = 0;
		for (int i = 1; i < _size; i++)
		{
			if (max_pri < _priority[i])
			{
				max_pri = _priority[i];
				pri_index = i;
			}
		}
		return _queue[pri_index];
	}
	return -1;
}

template<class T>
inline bool P_Queue<T>::isEmpty()
{
	return _size == 0;
}

template<class T>
inline bool P_Queue<T>::isFull()
{
	return _size==_capacity;
}

template<class T>
inline void P_Queue<T>::clear()
{
	delete[]_queue;
	delete[]_priority;
	_size = 0;
	_capacity = 20;
	_queue = new T[_capacity];
	_priority = new int[_capacity];
}

template<class T>
inline void P_Queue<T>::show()
{
	for (int i = 0; i < _size; i++)
	{
		cout << "El: " << _queue[i] << "	" << "Priotiy: " << _priority[i] << endl;
	}
	cout << endl;
}

template<class T>
inline int P_Queue<T>::getSize()
{
	return _size;
}

template<class T>
inline int P_Queue<T>::getCapacity()
{
	return _capacity;
}





template<class T>
inline P_Queue<T>::~P_Queue()
{
	delete[]_queue;
	delete[]_priority;
}

