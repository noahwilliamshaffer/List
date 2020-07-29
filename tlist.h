#include <iostream>

using namespace std;

#ifndef _LIST_H
#define _LIST_H

template< class T >
class List
{
public:
  List(int s = 10);		// allocate array size s and set up empty list
  ~List();			// clean up dynamic allocation
  List(const List< T >& );	// copy constructor
  List& operator=(const List< T >& );  // assignment operator overload

  void Insert(T item);		// loads "item" into list
  T GetElement(unsigned int n);	// return item at index n
  void Print(ostream& os);	// prints the list

private:
  T* data;			// pointer to dynamic array
  int size;			// number of items
  int max;			// allocated array size

  void Clone(const List< T >& );// for use in copies
  void Resize(int newsize);	// adjust allocation

};

// member function definitions

template< class T >
List< T >::List(int s)
{
   size = 0;
   max = s;
   if (max <= 0)
   {
	data = 0;		// null pointer
	max = 0;
   }
   else
	data = new T[max];
}

template< class T >
List< T >::~List()
{
   if (data != 0)
	delete [] data;
}

template< class T >
List< T >::List(const List< T >& L)
{
   Clone(L);
}

template< class T >
List< T >& List< T >::operator=(const List< T >& L)
{
   if (this != &L)
   {
	if (data != 0)
	   delete [] data;
	Clone(L);
   }
   return *this;
}


template< class T >
void List< T >::Insert(T item)
{
   if (max == size)
	Resize(max + 5);
   data[size] = item;
   size++;
}

template< class T >
T List< T >::GetElement(unsigned int n)
// returns item in list with index n.  if n too large, returns last item.
{
   if (n >= size)
	n = size-1;
   return data[n];
}

template< class T >
void List< T >::Print(ostream& os)
// prints a comma separated list to the output stream os
{
   if (size == 0)
	os << "List empty";

   int i;
   for (i = 0; i < size-1; i++)
	os << data[i] << ", ";
   os << data[i];
}

template< class T >
void List< T >::Resize(int newsize)
// dynamic resizing of array
{
   max = newsize;
   T* temp = new T[max];
   for (int i = 0; i < size; i++)
	temp[i] = data[i];
   if (data != 0)
	delete [] data;
   data = temp;
}

template< class T >
void List< T >::Clone(const List< T >& L)
{
   max = L.max;
   size = L.size;
   data = new T[max];
   for (int i = 0; i < size; i++)
	data[i] = L.data[i];   
}

#endif


