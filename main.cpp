#include <iostream>
#include "tlist.h"

using namespace std;


int main()
{
   // create a list of integers
   List< int > tests;

   int gr;
   cout << "Enter some grades (negative to quit):\n> ";
   do
   {
	cin >> gr;
	if (gr >= 0)
		tests.Insert(gr);

   } while (gr >= 0);

   cout << "The 7th element is: " << tests.GetElement(7) << '\n';
   cout << "The 2nd element is: " << tests.GetElement(2) << '\n';

   cout << "Here is the list of grades:\n\n";
   tests.Print(cout);

/////////////////////////////////////////////////////
   
   cout << "\n\nCreating a list of doubles\n";

   List< double > stats(0);
   double num;
   cout << "Enter some floating point numbers (negative to quit):\n> ";
   do
   {
	cin >> num;
	if (num >= 0)
		stats.Insert(num);

   } while (num >= 0);
   
   cout << "The 6th element is: " << stats.GetElement(6) << '\n';
   cout << "The 2nd element is: " << stats.GetElement(2) << '\n';

   cout << "Here is the list of doubles:\n\n";
   stats.Print(cout);

   cout << "\n\n";
   return 0;
}
