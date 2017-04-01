#include <iostream>
#include <string>

using namespace std;

// Check if it is possible to create 
// the desired output with the alphabet
bool scrabble(string alphabet, string output )
{
	int charsFound = 0;
	for( int i = 0; i < output.length(); i++ )
	{
		for( int j = 0; j < alphabet.length(); j++ )
		{
			if ( output[i] == alphabet[j] || alphabet[j] == '?')
			{
				alphabet[j] = '-';
				charsFound++;
				break;
			}
		}
	}
	return charsFound == output.length();
}
/* ********************************************
 * This program will check if it is possible to scrabble the input
 * to obtain the desired outuput. 
 *  Ex: 
 *	scrabble("ladilmy", "daily") -> true
 *  scrabble("eerriin", "eerie") -> false
 * ******************************************** 
 */
int main()
{
	string alphabet;
	string output;
	cin >> alphabet >> output;
	do
	{
		cout << "scrabble(\"" << alphabet << "\", \"" << output << "\") -> ";
		bool result = scrabble(alphabet, output);
		if ( result )
			cout << "true" <<endl;
		else
			cout << "false" <<endl;
	}while( cin >> alphabet >> output );
	return 0;
}