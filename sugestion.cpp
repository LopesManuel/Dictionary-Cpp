#include <iostream>
#include <string>
#include "alphabetTree.h"

/* ************************************************ *
 * This program will check if it is possible to     *
 * scrabble the input to obtain the desired outuput.*
 *  Ex:                                             *
 *  sugestion("abandone") ->  "abandoned"           *
 *  					  ->  "abandoner"           *
 *  					  ->  "abandoners"          *
 * ************************************************ */

// This vareable will hold our dictionary 
AlphabetTree* dic;

using namespace std;

int main()
{   // Create our dictionary based in the file given
	dic = new AlphabetTree("dictionary.txt");
	string alphabet;
	cin >> alphabet;
	do{
		std::vector<string> suggestions = dic->suggestions(alphabet);
		for(int i = 0; i < suggestions.size(); i++)
		cout << "sugestion(\"" << alphabet << "\") -> " << suggestions[i]  << endl;
	}while( cin >> alphabet );
	return 0;
}