#include "ordinals.h"
#include "ittm.h"
#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace ordinals;
using namespace ITTM;
using namespace std;

TransitionRule parseRule() {

}

int main() {
    std::string fileaddress;
    std::cout << "Address of ITTM code: ";
    cin >> fileaddress;
    std::string command;
    std::vector<string> commands;
    ifstream CMDFile(fileaddress);
    while (getline (CMDFile,command)) {
        // Get the command from the file
        commands.push_back(commands);
    }
    CMDFile.close();
    // We've now gotten all the commands. Parsing time!
    std::vector<TransitionRule> ITTMRuleset;
    std::vector<char> initialTape;
    ITTM sim(ITTMRuleset, initialTape);
    return 0;
}