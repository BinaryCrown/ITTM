#include "ordinals.h"
#include "ittm.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace ordinals;
using namespace ITTM;
using namespace std;

TransitionRule parseRule(string rule_code) {

}

int main() {
    string fileaddress;
    string aos;
    cout << "Accuracy of ITTM simulation: ";
    cin >> aos;
    cout << "\n Address of ITTM code: ";
    cin >> fileaddress;
    string command;
    vector<string> commands;
    ifstream CMDFile(fileaddress);
    while (getline (CMDFile,command)) {
        // Get the command from the file
        commands.push_back(commands);
    }
    CMDFile.close();
    // We've now gotten all the commands. Parsing time!
    vector<TransitionRule> ITTMRuleset;
    vector<char> initialTape;
    ITTM sim(ITTMRuleset, initialTape);
    string bs;
    cout << "\n Program parsed. Begin simulation? (y/n)"
    cin >> bs;
    switch (bs) {
        case "n":
            return 0
        case "N":
            return 0
        case "no":
            return 0
        case "No":
            return 0
        case "NO":
            return 0
        case "nO":
            return 0
    }
    cout "\n Beginning simulation..."
    return 0;
}