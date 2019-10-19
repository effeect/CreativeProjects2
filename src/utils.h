#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <random>

// return random int in the range 0-max
int randInt(int max);

// tokenizer - splits the sent string on the sent seperator and sends it back as a vector
// of strings. e.g 'hello how are you' -> {"hello", "how", "are", "you"}
std::vector<std::string> tokenise(std::string input, char sep);

// updates the sent map by adding the sent vector of words to it
// with first order analyis. e.g.:
// input: hello how are you ->
// action: add the following entries to the map:
// hello -> how
// how -> are
// are -> you
// returns the updated map
std::map <std::string, std::string> addWordsToMarkov(std::map <std::string, std::string> markov, std::string words);

// returns a vector of strings representing the string keys of the sent map
std::vector <std::string> getMapKeys(std::map<std::string, std::string> theMap);
