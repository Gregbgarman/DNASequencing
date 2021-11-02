#include "Converter.h"
using namespace std;
								
						//TestString.txt-about 90,000 characters or 30,000 amino acids
void ShowMenu();

int main() {
	string huge = "";
	char ch;
	ifstream filein;
	filein.clear();
	filein.open("covid.txt");	//SARS - CoV - 2

	if (!filein) {
		cout << "Error with RNA Protein Codes file" << endl;
		filein.close();
	}

	while (!filein.eof()) {
		
		filein.get(ch);
		if (ch>=65 && ch<=90 || ch>=97 && ch<=122)
			huge += ch;
	}

	char choice;
	//cout << "Enter DNA Sequence" << endl;
	//string input;
	//cin >> input;
	Converter converter(huge);

	do
	{
		ShowMenu();
		cin >> choice;
		choice = toupper(choice);
		if (choice == 'A') {
			converter.ShowmRNASequence();
		}
		else if (choice == 'B') {
			converter.ShowtRNASequence();
		}
		else if (choice == 'C') {
			converter.ShowProteinSequence();
		}
		
	} while (choice!='D');
	
	return 0;
}

void ShowMenu() {
	cout << "A\t\tPrint mRNA sequence" << endl;
	cout << "B\t\tPrint tRNA sequence" << endl;
	cout << "C\t\tPrint Amino Acid Sequence/Protein" << endl;
	cout << "D\t\tExit" << endl;
}