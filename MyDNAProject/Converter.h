#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iostream>
#include <fstream>
using namespace std;

class Converter {

public:
	Converter(string DNASequence);		//initialize codes in this constructor
	void ShowmRNASequence();
	void ShowProteinSequence();
	void ShowtRNASequence();

private:
	void ConvertDNAtomRNA(string DNASequence);
	void ConvertmRNAtotRNA();
	void InitializetRNACodes();
	string mRNAString;
	string tRNAString;
	unordered_map<string, string> AminoAcidRNACodes;
	
};
