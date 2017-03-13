#include "alphabetTree.h"

/* Creates an empty alphabet tree  */
AlphabetTree::AlphabetTree()
{
	root = new TreeNode();
	size = -1;
	root->depth = -1;
}
/* Creates an alphabet tree using the words in the file*/
AlphabetTree::AlphabetTree(const char* file)
{	// First create the root ( all words will start by the root )
	root = new TreeNode();
	// Open file
    ifstream inFile (file);
    // While we can read words from file
    while (!inFile.eof()){
    	// Temporaly save the word
		string word;
        inFile>>word;
        // Ignore newline char
        if ( word[0] != '\n')
        { // Add new word to the alphabet
        	addWord(word);
    	}
    }
}
/* Adds new word to the alphabet */
void AlphabetTree::addWord(string word)
{	// Node that we are exploring, we start at the root
	TreeNode * nodeAt = root;
	for(int i = 0; i < word.length(); i++)
	{	/* Lets check if there is any child with the letter word[i]
		 *  - If true: continue throught that node  
		 *  - Else: create a node with that letter  */
		TreeNode * nextNode = nullptr;
		for( int j = 0; j < nodeAt->children->size(); j++ )
		{	
			TreeNode * child = nodeAt->children->at(j);
			if (  child->letter == word[i] )
			{ // Continue throught that node 
				nextNode = child;
				break;
			}
		}
		if ( nextNode == nullptr )
		{   // If there isn't already a node with that letter create one
			nextNode = new TreeNode( word[i] , nodeAt);
			// Add the created child to its parent
			nodeAt->children->push_back(nextNode);
			// Add one to the number of letters in our diccionary
			size++; 
		}
		// Continue to the next node 
		nodeAt = nextNode;
		if ( nodeAt != nullptr && i == word.length() -1 ){
			nodeAt->isWord = true;
		}
	}
}

/* Receives a string and returns true if there is an      *
 * entry for that word in the dictionary, false otherwise */
bool AlphabetTree::exists( string word)
{	// Node that we are exploring, we start at the root
	TreeNode * nodeAt = root;
	for(int i = 0; i < word.length(); i++)
	{	/* Lets check if there is any child with the letter word[i]
		 *  - If true: continue throught that node  
		 *  - Else: return false  */
		TreeNode * nextNode = nullptr;
		for( int j = 0; j < nodeAt->children->size(); j++ )
		{	
			TreeNode * child = nodeAt->children->at(j);
			if (  child->letter == word[i] )
			{ // Continue throught that node 
				nextNode = child;
				break;
			}
		}
		if ( nextNode == nullptr )
		{   // If there isn't a node with that letter then word doesn't exist
			return false;
		}
		// Continue to the next node 
		nodeAt = nextNode;
	}
	return true;
}

/* Receives a set of letters and returns the longest*
 * possible string in the dictionary 				*/
string AlphabetTree::longest(string input)
{	// Lets save the largest string found 
	string lStrFound = "";
	// We need to start at least once at each letter
	for ( int i = 0; i < input.length(); i++ )
	{   // Create a vector with the chars we need to visit 
		vector<char> toVisit( input.begin(), input.end() );
		// Create a vector to save which letters we already visit 
		vector<bool> visited(input.length());
		for( int j = 0; j < input.length(); j++ )
			visited[j] = false;
		// We will start our search at input[i]
		visited[i] = true;
		// Node that we are exploring, we start at the root
		TreeNode * nodeAt = nullptr;
		// Lets check if there is any child with the char strtChar
		for( int j = 0; j < root->children->size(); j++ )
		{	
			TreeNode * child = root->children->at(j);
			if (  child->letter == input[i] )
			{ // Continue throught that node 
				nodeAt = child;
				break;
			}
		}
		 // If there is a node with that letter
		if ( nodeAt != nullptr ) 
		{  	// Search for the biggest word starting at input[i]
		  	string tmpStrFound = dfs( nodeAt, toVisit, visited);
		  	// Save the largest string found
		  	if ( tmpStrFound.length() > lStrFound.length() ){
		  		lStrFound = tmpStrFound;
		  	}
		}
	}	


	return lStrFound;
}

string AlphabetTree::dfs(TreeNode * nodeAt, vector<char> & toVisit, vector<bool> visited)
{
	// Keep track of the biggest string found yet
	string bgstStrFound = ""; 
	bgstStrFound += nodeAt->letter;
	// We need to save the biggest suffix found
	string maxChldrnStr = ""; 

	for( int i = 0; i < nodeAt->children->size(); i++ )
	{	
		TreeNode * child = nodeAt->children->at(i);
		string tmpStrFound = "";

		for( int j = 0; j < toVisit.size(); j++ )
		{ // If it was not visited yet, then 
			if (  child->letter == toVisit[j] && !visited[j])
			{	// Mark it as viewed so we don't visit it twice		
				visited[j] = true;
				// Recursion throught the children 
			 	tmpStrFound = dfs( child, toVisit, visited);
			 	// Mark it as not viewed so we can visit it on the other nodes		
				visited[j] = false;
			  	// Save the largest string found
			  	if ( tmpStrFound.length() > maxChldrnStr.length() && ( tmpStrFound.length() > 1 || child->isWord ) )
			  		maxChldrnStr = tmpStrFound;
		  	}
		}

	}
	
	bgstStrFound += maxChldrnStr;
	return bgstStrFound;
}