#include <iostream>
#include <string>
#include "tlist.h"

using namespace std;

template < class T >
void TestList(List<T> theList, string label, int val1, int val2)
{
   T gr;
   cout << "Enter some " << label << " (negative to quit):\n> ";
   do
   {
	cin >> gr;
	if (gr >= 0)
		theList.Insert(gr);

   } while (gr >= 0);

   cout << "Element " << val1 << " is: " << theList.GetElement(val1) << '\n';
   cout << "Element " << val2 << " is: " << theList.GetElement(val2) << '\n';

   cout << "Here is the list of " << label << ":\n\n";
   theList.Print(cout);
}

int main()
{
   // create a list of integers
   List< int > tests;
   List< double > stats(0);

   TestList(tests, "grades", 7, 2);
   TestList(stats, "floats", 6, 2);
}

