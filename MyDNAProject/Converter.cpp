#include "Converter.h"
using namespace std;

Converter::Converter(string DNASequence) {
    ConvertDNAtomRNA(DNASequence);          //DNA to mRNA
    ConvertmRNAtotRNA();                    //mRNA to tRNA
    InitializetRNACodes();
}

void Converter::ConvertDNAtomRNA(string DNASequence) {
    mRNAString = "";

    for (int i = 0; i < DNASequence.length(); i++) {         //DNA to mRNA
        if (toupper(DNASequence[i]) == 'A') {
            mRNAString += 'U';

        }
        else if (toupper(DNASequence[i]) == 'T') {
            mRNAString += 'A';

        }
        else if (toupper(DNASequence[i]) == 'C') {
            mRNAString += 'G';

        }
        else if (toupper(DNASequence[i]) == 'G') {
            mRNAString += 'C';

        }
    }
}

void Converter::ConvertmRNAtotRNA() {
    tRNAString = "";

    for (int i = 0; i < mRNAString.length(); i++) {         //mRNA to tRNA
        if (mRNAString[i]== 'A') {
            tRNAString += 'U';
        }
        else if (mRNAString[i] == 'U') {
            tRNAString += 'A';
        }
        else if (mRNAString[i] == 'C') {
            tRNAString += 'G';
        }
        else if (mRNAString[i] == 'G') {
            tRNAString += 'C';
        }
    }
}

void Converter::ShowProteinSequence() {
    cout << "\n";
    int counter = 0;

    string codon = "";
    for (int i = 0; i < mRNAString.length(); i++) {
        counter++;
        codon += mRNAString[i];

        if (codon.length() == 3) {
            unordered_map<string, string>::const_iterator Pair = AminoAcidRNACodes.find(codon);
            cout << Pair->second;
            codon = "";
        }

        if (counter == 3) {
            if (i != mRNAString.length() - 1) {
                cout << "-";
                counter = 0;
            }
        }
    }

    cout << "\n\n\n";
}

void Converter::InitializetRNACodes() {   

    ifstream filein;
    filein.clear();
    filein.open("RNAProteinCodes.txt");

    if (!filein) {
        cout << "Error with RNA Protein Codes file" << endl;
        filein.close();
        return;
    }

    string RNAStrand="";
    string temp = "";
    char c;

    while (!filein.eof()) {
        filein.get(c);

        if (c == ':' || c==',') {

            if (c == ':') {
                RNAStrand = temp;

            }
            else if (c == ',') {                      
                AminoAcidRNACodes[RNAStrand] = temp;             
           }
            temp = "";

        }
      
        else if (c == '\n' || c == ' ') {

        }

        else {                      //building sequences and amino acids
            temp = temp + c;

        }
        
    }
    filein.close();
}

void Converter::ShowmRNASequence() {
    cout << mRNAString << endl;
}

void Converter::ShowtRNASequence() {
    cout << tRNAString << endl;
}
