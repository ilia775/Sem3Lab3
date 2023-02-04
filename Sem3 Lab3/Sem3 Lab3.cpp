#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "myrand.h"
#include "PriorityQueue.h"

//template <typename D, typename P>
//void PrintPointList(Graph<D, P>* graph)
//{
//	ArraySortedSequence<Point<P>> list = graph->Get_point_list();
//	cout << "Колчисество вершин: " << list.GetLenght() << endl;
//	for (int i = 0; i < list.GetLenght(); i++)
//	{
//		cout << list.Get(i).Get_data() << endl;
//	}
//}

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

template <typename D, typename P>
void GraphInterface()
{
	/*Graph<int, int>* graph = new Graph<int, int>();
	Point<int> p1 = Point<int>(1);
	Point<int> p2 = Point<int>(2);
	Connection<int, int> line1_2 = Connection<int, int>(&p1, &p2, 10);
	graph->Add(line1_2);*/
	Graph<D, P>* graph = new Graph<D, P>();
	int numofpoints = rand(10, 21);
	int MAXP = 10, MINP = -10;
	ArraySortedSequence<Point<D>> Psec = ArraySortedSequence<Point<D>>(numofpoints);
	for (int i = 0; i < numofpoints; i++)
	{
		Psec[i] = Point<D>(rand(MINP, MAXP));
	}
	int numofcon = rand(30, 100);
	for (int i = 0; i < numofcon; i++)
	{
		graph->Add(Connection<D, P>(&Psec[rand(0, Psec.GetLenght() - 1)], &Psec[rand(0, Psec.GetLenght() - 1)], rand(1, 100)));
	}
	graph->PrintConnections();
	graph->PrintPoints();
	try
	{
		cout << graph->FindWay(2, 3) << endl;
	}
	catch (string ex) {
		cout << ex << endl;
	}
}

int main() {
	/*Graph<int, int>* graph = new Graph<int, int>();
	Point<int> p1 = Point<int>(1);
	Point<int> p2 = Point<int>(2);
	Connection<int, int> line1_2 = Connection<int, int>(&p1, &p2, 10);
	graph->Add(line1_2);*/
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	GraphInterface<int, int>();
	return 0;
}