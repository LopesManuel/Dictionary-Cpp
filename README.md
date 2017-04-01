# Dictionary-Cpp

Be advised that this project is an hobbie, so if you are going to use it have in mind that I can only help you every other weekend. 


I am trying to create a dictionary API, at the moment I only have a class able to receive a dictionary file and create a Trie structure to represent that dictionary. Using this structure I have implemented the following functions: 


## Functions

### Longest:

Returns the biggest word that can be created by rearranging the letters

longest("dcthoyueorza") ->  "coauthored"        
longest("uruqrnytrois") -> "turquois" 

### Suggestion

Returns possible suggestions to finish the word

suggestion("abandone") ->  "abandoned"           
                       ->  "abandoner"           
                       ->  "abandoners"


## TODO:

1. Correction function: 

   * Will return a correction suggestion to a malformed word
   * Branch: CorrectF

2. Add repeated words scoring system:

   * Will try to create a scoring system to return only the most udes words, avoiding "trash"
  
