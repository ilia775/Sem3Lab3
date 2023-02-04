#pragma once
#include <iostream>
#include "Sequence_old.h"

//template <typename E, typename P>
//class IPriorityQueue : 
//{
//public:
//	E Peek(const int index) = 0;
//	E PeekFirst() = 0;
//	E PeekLast() = 0;
//	void Enqueue(E item, P priority) = 0;
//	E Dequeue() = 0;
//private:
//	E& Get(int index) = 0;
//	E& GetFirts() = 0;
//	E& GetLast() = 0;
//	IPriorityQueue<E> GetSubSequence(int start, int end) = 0;
//	void Append(E data) = 0;
//	void Prepend(E data) = 0;
//	void InsertAt(int index) = 0;
//	void Remove(int index) = 0;
//};
template <typename E, typename P>
class ListPriorityQueue;
template <typename E, typename P>
class ArrayPriorityQueue;
template <typename E, typename P>
class PriorityPair
{
private:
	E elem;
	P priority;
public:
	//template <typename E1, typename P1> friend class ListPriorityQueue<E1, P1>;
	//template <typename E1, typename P1> friend class ArrayPriorityQueue<E1, P1>;
	PriorityPair()
	{
		elem = E();
		priority = P();
	}
	PriorityPair(E nelem, P npriority)
	{
		elem = nelem;
		priority = npriority;
	}
	E GetElem() { return elem; }
	P GetPriority() { return priority; }
	bool operator>(PriorityPair other)
	{
		return this->priority > other.priority;
	}
	bool operator<(PriorityPair other)
	{
		return this->priority < other.priority;
	}
	bool operator==(PriorityPair other)
	{
		return this->priority == other.priority;
	}
	bool operator>(PriorityPair* other)
	{
		return this->priority > other->priority;
	}
	bool operator<(PriorityPair* other)
	{
		return this->priority < other->priority;
	}
	bool operator==(PriorityPair* other)
	{
		return this->priority == other->priority;
	}
};

//template <typename E, typename P>
//class ListPriorityQueue : private ListSortedSequence<PriorityPair<E, P>>
//{
//public:
//	E Peek(const int index)
//	{
//		return this->Get(index).GetElem();
//	}
//	E PeekFirst()
//	{
//		return this->GetFirst().GetElem();
//	}
//	E PeekLast()
//	{
//		return this->GetLast().GetElem();
//	}
//	void Enqueue(E elem, P priority)
//	{
//		PriorityPair<E, P> p1 = PriorityPair<E, P>(elem, priority);
//		int insertionindex = -1;
//		if (this->GetLenght() != 0)
//		{
//			for (int i = 0; i < this->GetLenght(); i++)
//			{
//				if (this->Get(i) < p1)
//				{
//					insertionindex = i;
//					break;
//				}
//			}
//			if (insertionindex == -1) insertionindex = this->GetLenght();
//			this->InsertAt(p1, insertionindex);
//		}
//		else this->Append(p1);
//	}
//	E Dequeue()
//	{
//		if (this->GetLenght() != 0)
//		{
//			E res = this->PeekFirst();
//			this->Remove(0);
//		}
//		else throw "Error IndexOutOfRange";
//	}
//private:
//	/*void Prepend(PriorityPair<E, P> item) override
//	{
//		Enqueue(item);
//	}
//	void Append(PriorityPair<E, P> item) override
//	{
//		Enqueue(item);
//	}
//	void InsertAt(int index, PriorityPair<E, P> item) override
//	{
//		throw " ERROR invalid operation";
//	}
//	void Remove(int index) override
//	{
//		throw " ERROR invalid operation";
//	}*/
//};

template <typename E, typename P>
class ArrayPriorityQueue : private ArraySortedSequence<PriorityPair<E, P>>
{
public:
	E Peek(const int index)
	{
		return this->Get(index).GetElem();
	}
	E PeekFirst()
	{
		return this->GetFirst().GetElem();
	}
	E PeekLast()
	{
		return this->GetLast().GetElem();
	}
	void Enqueue(E elem, P priority)
	{
		PriorityPair<E, P> p1 = PriorityPair<E, P>(elem, priority);
		int insertionindex = -1;
		if (this->GetLenght() != 0)
		{
			for (int i = 0; i < this->GetLenght(); i++)
			{
				if (this->Get(i) < p1)
				{
					insertionindex = i;
					break;
				}
			}
			if (insertionindex == -1) insertionindex = this->GetLenght();
			this->InsertAt(p1, insertionindex);
		}
		else this->Append(p1);
	}
	E Dequeue()
	{
		if (this->GetLenght() != 0)
		{
			E res = this->PeekFirst();
			this->Remove(0);
		}
		else throw "Error IndexOutOfRange";
	}
private:
	/*void Prepend(PriorityPair<E, P> item) override
	{
		Enqueue(item);
	}
	void Append(PriorityPair<E, P> item) override
	{
		Enqueue(item);
	}
	void InsertAt(int index, PriorityPair<E, P> item) override
	{
		throw " ERROR invalid operation";
	}
	void Remove(int index) override
	{
		throw " ERROR invalid operation";
	}*/
};