#ifndef __AlphabetTree__   
#define __AlphabetTree__

#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <stack>


const int S_MAX_DEPTH = 2;

using namespace std;
 
class TreeNode
{
	public:
		// Saves the letter of the node
		char letter;
		// Saves the depth of the node
		int depth;
		// Saves if the letter is the end of a word
		bool isWord;
		// Points to the previous letter
        TreeNode * parent;
        // Points to all possible next letters
        vector<TreeNode*> * children; 

        TreeNode()
        {
        	parent = nullptr;
        	children = new vector<TreeNode*>();
        	isWord = false;
        }
        TreeNode(char let, TreeNode * p): letter(let), parent(p)
        {
        	depth = p->depth + 1;
        	children = new vector<TreeNode*>();
        	isWord = false;
        }
};

class AlphabetTree
{
	// Root will have a null letter.
	TreeNode * root;
	// Dictionary size (number of added) 
	int size;

public:
	AlphabetTree();
	AlphabetTree(char const* file);
	//~AlphabetTree();
	// Adds new word to the alphabet
	void addWord(string word);
	// Prints of nodes in the tree
	void printSize(){ cout << size << endl;};
	/* Receives a set of letters and returns the longest*
 	 * possible string in the dictionary 				*/
	string longest(string input);
	// Searchs the tree for the possible word we can make with the toVisit vector
	string dfs(TreeNode * nodeAt, vector<char> & toVisit, vector<bool> visited);
	// Check if a word exists in the dictionary
	bool exists(string input);
	// Returns a list of possible corrections
	vector<string> suggestions(string input);
	// Search for the closests words possible
	vector<TreeNode*> getSuggestions(TreeNode *nodeAt, int);	
	// Returns the word that ends at that node
	string getWord(TreeNode *nodeAt);
};

#endif