#pragma once
#include <string>
#include "Sequence_old.h"
using namespace std;

template <typename T> 
class Point 
{
public:
	Point()
	{
		data = T();
	}
	Point(T value) {
		data = value;
	}
	T GetData() {
		return data;
	}
	bool operator >(Point<T>* other)
	{
		return (this->GetData() > other->GetData());
	}
	bool operator <(Point<T>* other)
	{
		return (this->GetData() < other->GetData());
	}
	bool operator ==(Point<T>* other)
	{
		return (this->GetData() == other->GetData());
	}
	bool operator >(Point<T> other)
	{
		return (this->GetData() > other.GetData());
	}
	bool operator <(Point<T> other)
	{
		return (this->GetData() < other.GetData());
	}
	bool operator ==(Point<T> other)
	{
		return (this->GetData() == other.GetData());
	}

private:
	T data;
};

template <typename Data, typename Parameters>
class Connection
{
public:

	Connection()
	{
		start_point = nullptr;
		end_point = nullptr;
		params = Parameters();
	}
	Connection(Point<Data>* start, Point<Data>* end, Parameters param) {
		start_point = start;
		end_point = end;
		params = param;
	}

	Point<Data>* GetEnd() {
		return this->end_point;
	}

	Point<Data>* GetStart() {
		return this->start_point;
	}

	Parameters GetParams() {
		return this->params;
	}

	template <typename Data, typename Parameters> friend ostream& operator<<(ostream& out, const Connection<Data, Parameters>& c);

	bool operator >(Connection<Data, Parameters>* other)
	{
		return (this->GetParams() > other->GetParams());
	}
	bool operator ==(Connection<Data, Parameters>* other)
	{
		return (this->GetParams() == other->GetParams());
	}
	bool operator <(Connection<Data, Parameters>* other)
	{
		return (this->GetParams() < other->GetParams());
	}
	bool operator >(Connection<Data, Parameters> other)
	{
		return (this->GetParams() > other.GetParams());
	}
	bool operator ==(Connection<Data, Parameters> other)
	{
		return (this->GetParams() == other.GetParams());
	}
	bool operator <(Connection<Data, Parameters> other)
	{
		return (this->GetParams() < other.GetParams());
	}
private:
	Point<Data>* start_point;
	Point<Data>* end_point;
	Parameters params;
};

template <typename Data, typename Parameters>
ostream& operator<<(ostream& out, const Connection<Data, Parameters>& c)
{
	out << c.start_point->GetData() << "--" << c.params << "-->" << c.end_point->GetData();
	return out;
}

class Way
{
public:
	/*Way(int l, int money, string transport_name) {
		length = l;
		cost = money;
		transport = transport_name;
	}*/

	Way(int l, int money)
	{
		length = l;
		cost = money;
	}

	int Get_efficiency() {
		return length * cost;
	}

	/*string Get_transport_name() {
		return transport;
	}*/
private:
	int length;
	int cost;
	//string transport;
};

template <typename D, typename P> 
class Graph 
{
public:
	Graph() 
	{
		connection_sec = new ArraySortedSequence<Connection<D, P>>();
		//connection_sec = ArraySortedSequence<Connection<D, P>>();
	}

	Graph(ArraySortedSequence<Connection<D, P>> sequence) 
	{
		connection_sec = &sequence;
	}
	void Add(Connection<D, P> way) 
	{
		connection_sec->Append(way);
	}

	ArraySortedSequence<Point<D>> Get_point_list() 
	{
		ArraySortedSequence<Point<D>> sec = ArraySortedSequence<Point<D>>();
		for (int i = 0; i < connection_sec->GetSize(); i++)
		{
			if (!sec.contains(*connection_sec->Get(i).GetStart())) 
			{
				sec.Append(*connection_sec->Get(i).GetStart());
			}

			if (!sec.contains(*connection_sec->Get(i).GetEnd())) 
			{
				sec.Append(*connection_sec->Get(i).GetEnd());
			}
		}
		return sec;
	}

	/*ArraySortedSequence<Connection<D, P>> Get_connection_list()
	{
		return ArraySortedSequence<Connection<D, P>>(connection_sec);
	}*/
	
	Graph<D, P> FindWay(Point<D>* point1, Point<D>* point2) 
	{
		ArraySortedSequence<int> numbers = ArraySortedSequence<int>();
		Point<D>* start = point1;
		P parameter;
		int k = 0;
		ArraySortedSequence<Connection<D, P>> result_sec = ArraySortedSequence<Connection<D, P>>();
		for (int j = 0; j < connection_sec->GetLenght(); j++)
		{
			parameter = connection_sec->Get(0).GetParams();
			for (int i = 0; i < connection_sec->GetLenght(); i++)
			{
				if (connection_sec->Get(i).GetStart() == start && !(numbers.contains(i)) && parameter > connection_sec->Get(i).GetParams())
				{
					parameter = connection_sec->Get(i).GetParams();
					k = i;
				}
			}
			result_sec.Append(connection_sec->Get(k));
			numbers.Append(k);
			start = connection_sec->Get(k).GetEnd();
			if (start == point2) 
			{
				break;
			}
		}
		return Graph<D, P>(result_sec);
	}
	Graph<D, P> FindWay(D d1, D d2)
	{
		/*ArraySortedSequence<Point<D>> list = this->Get_point_list();
		Point<D>* p1 = nullptr, * p2 = nullptr;
		for (int i = 0; i < list.GetLenght(); i++)
		{
			if (p1 == nullptr) if (list.Get(i).Get_data() == d1) p1 = &list.Get(i);
			if (p2 == nullptr) if (list.Get(i).Get_data() == d2) p2 = &list.Get(i);
		}*/
		Point<D>* p1 = nullptr, * p2 = nullptr;
		for (int i = 0; i < connection_sec->GetLenght(); i++)
		{
			if (p1 == nullptr) if (connection_sec->Get(i).GetStart()->GetData() == d1) p1 = connection_sec->Get(i).GetStart();
			if (p2 == nullptr) if (connection_sec->Get(i).GetStart()->GetData() == d2) p2 = connection_sec->Get(i).GetStart();
		}
		if (p1 != nullptr && p2 != nullptr) return FindWay(p1, p2);
		else throw "Error PointNotFound";
	}
	//friend void PrintConnetions(Graph<D, P>* graph);
	void PrintConnections()
	{
		//cout << "Количество связей: " << connection_sec.GetLenght() << endl;
		for (int i = 0; i < connection_sec->GetLenght(); i++)
		{
			cout << connection_sec->Get(i) << endl;
		}
	}

	void PrintPoints()
	{
		ArraySortedSequence<Point<P>> list = this->Get_point_list();
		//cout << "Количество узлов: " << list->GetLenght() << endl;
		for (int i = 0; i < list.GetLenght(); i++)
		{
			cout << list.Get(i).GetData() << endl;
		}
	}
	template <typename D, typename P> friend ostream& operator<<(ostream& out, const Graph<D, P>& g);
private:
	ArraySortedSequence<Connection<D, P>>* connection_sec;
};

template <typename D, typename P>
ostream& operator<<(ostream& out, const Graph<D, P>& g)
{
	int len = g.connection_sec->GetLenght();
	for (int i = 0; i < len ; i++)
	{
		out<< g.connection_sec->Get(i).GetStart()->GetData() << "--" << g.connection_sec->Get(i).GetParams() << "-->" << g.connection_sec->Get(i).GetEnd()->GetData() << endl;
		//out << g.connection_sec.Get(i) << endl;
	}
	return out;
}

//template <typename D, typename P>
//void PrintConnetions(Graph<D, P>* graph)
//{
//	ArraySortedSequence<Connection<D, P>> list = ArraySortedSequence<Connection<D, P>>(graph->connection_sec);
//	cout << "Количество связей: " << list.GetLenght() << endl;
//	for (int i = 0; i < list.GetLenght(); i++)
//	{
//		cout << list.Get(i) << endl;
//	}
//}