#include <iostream>
#include <string>
#include "alphabetTree.h"

/* ************************************************ *
 * This program will check if it is possible to     *
 * scrabble the input to obtain the desired outuput.*
 *  Ex:                                             *
 *  correction("abandoned") ->  "coauthored"        *
 *  correction("abandoned") -> "turquois"           *
 * ************************************************ */

// This vareable will hold our dictionary 
AlphabetTree* dic;

int main()
{   // Create our dictionary based in the file given
	dic = new AlphabetTree("dictionary.txt");
	string alphabet;
	cin >> alphabet;
	do
	{
		cout << "longest(\"" << alphabet << "\") -> " << dic->longest(alphabet) << endl;
	}while( cin >> alphabet );
	return 0;
}