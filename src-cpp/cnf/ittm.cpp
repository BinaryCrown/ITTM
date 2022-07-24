#include "ittm.h"
#include<iostream>

using namespace ITTM;
using namespace std;

void getTapeEnt(vector<char> tape, int entry) {
    return (entry < tape.size) ? tape[entry] : "_"; 
}

void TransitionRule::setVals_TR(int currentState, char currentCell, char newContent, int moveDirection, int nextState) {
    if (currentState < -1 || nextState < -1) {
        throw std::invalid_argument("Received invalid transition rule state.");
    }
    if (moveDirection < -1 || moveDirection > 1) {
        throw std::invalid_argument("Received invalid transition rule move direction.");
    }
    this->currentState = currentState;
    this->currentCell = currentCell;
    this->newContent = newContent;
    this->moveDirection = moveDirection;
    this->nextState = nextState;
}

void ITTM::setVals_ITTM(std::vector<TransitionRule> ITTMRuleset, std::vector<char> initialTape) {
    if (ITTMRuleset.size == 0) {
        throw std::invalid_argument("Received empty ITTM ruleset.")
    }
    // Make sure no rules activate simultaneously
    std::vector<int> activationSteps;
    this->ITTMRuleset = ITTMRuleset;
    this->initialTape = initialTape;
}

std::vector<char> ITTM::getTapeAtStep(ordinals::CantorNF step, unsigned maxCount) {
    if (!step.std()) {
        throw std::invalid_argument("Received nonstandard CNF.");
    }
    if (step.coefficients.size == 0) {
        return this->initialTape;
    }
    if (isLim(step)) {
        int maxPrevLen = 0;
        for (unsigned i = 0; i <= maxCount; i++) {
            if (getTapeAtStep(step[i], maxCount).size() > maxPrevLen) {
                maxPrevLen = getTapeAtStep(step.fundamentalSeq(i), maxCount).size();
            }
        }
        std::vector<char> newTape;
        for (unsigned i = 0; i < maxPrevLen; i++) {
            // Set ith element of tape to bitwise limsup of ith element of previous tapes
            newTape[i] = "_";
            for (unsigned j = 0; j < maxCount; j++) {
                if getTapeAtStep(step[i], maxCount)
            }
        }
    }
    else {
        std::vector<char> previousTape = getTapeAtStep(step.fundamentalSeq(0), maxCount);
        int previousState = this.getStateAtStep(step.fundamentalSeq(0));
        int previousSymbol = getTapeEnt(previousTape, getReadHeadPosAtStep(step.fundamentalSeq(0)))
        for (unsigned i = 0; i < (this->ITTMRuleset).size; i++) {
            if ((this->ITTMRuleset)[i].currentState == previousState && (this->ITTMRuleset)[i].currentCell == previousSymbol) {
                break;
            }
            // Make sure it doesn't count the last ruleset by default
            if (i+1 == (this->ITTMRuleset).size) {
                throw std::invalid_argument("No transition rule available.")
            }
        }
        std::vector<char> newTape{};
        for (unsigned i = 0; i <= getReadHeadPosAtStep(step.fundamentalSeq(0)); i++) {
            char k = (i < getReadHeadPosAtStep(step.fundamentalSeq(0))) ? "_" : (this->ITTMRuleset)[i].newContent);
            newTape.push_back((i < previousTape.size) ? previousTape[i] : k);
        }
        return newTape;
    }
}

int ITTM::getStateAtStep(ordinals::CantorNF step) {
    if (!step.std()) {
        throw std::invalid_argument("Received nonstandard CNF.");
    }
    if (step.coefficients.size == 0) {return 0;}
    if (isLim(step)) {return -1;}
    else {
        int previousState = this.getStateAtStep(step.fundamentalSeq(0));
        int previousSymbol = getTapeEnt(currentTape, getReadHeadPosAtStep(step.fundamentalSeq(0)));
        int previousState = this.getStateAtStep(step.fundamentalSeq(0));
        for (unsigned i = 0; i < (this->ITTMRuleset).size; i++) {
            if ((this->ITTMRuleset)[i].currentState == previousState && (this->ITTMRuleset)[i].currentCell == previousSymbol) {
                break;
            }
            if (i+1 == (this->ITTMRuleset).size) {
                throw std::invalid_argument("No transition rule available.")
            }
        }
        return (this->ITTMRuleset)[i].nextState;
    }
}

int ITTM::getReadHeadPosAtStep(ordinals::CantorNF step) {
    if (!step.std()) {
        throw std::invalid_argument("Received nonstandard CNF.");
    }
    if (step.coefficients.size == 0) {return 0;}
    if (isLim(step)) {return 0;}
    else {
        std::vector<char> previousTape = getStateAtStep(step.fundamentalSeq(0));
        int previousPos = getReadHeadPosAtStep(step.fundamentalSeq(0));
        int previousState = this.getStateAtStep(step.fundamentalSeq(0));
        int previousSymbol = getTapeEnt(previousTape, previousPos);
        for (unsigned i = 0; i < (this->ITTMRuleset).size; i++) {
            if ((this->ITTMRuleset)[i].currentState == previousState && (this->ITTMRuleset)[i].currentCell == previousSymbol) {
                break;
            }
            if (i+1 == (this->ITTMRuleset).size) {
                throw std::invalid_argument("No transition rule available.")
            }
        }
        return previousPos + (this->ITTMRuleset)[i].moveDirection;
    }
}
