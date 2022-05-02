#ifndef ITTM_H // include guard
#define ITTM_H

#include "ordinals.h"
#include<iostream>
#include<vector>
#include<string>

namespace ITTM {
    // Transition rule
    class TransitionRule {
        public:
            int currentState;           // -1 = limit, 0 = initial state
            char currentCell;
            char newContent;
            int moveDirection;          // -1 = left, 0 = don't move, 2 = right
            int nextState;

            // Setter
            void setVals_TR(int, char, char, int, int);
    }

    // ITTM
    class ITTM {
        public:
            std::vector<TransitionRule> ITTMRuleset;                // Ruleset for the ITTM
            std::vector<char> initialTape;
            std::vector<char> getTapeAtStep(ordinals::CantorNF);
            int getStateAtStep(ordinals::CantorNF);
            int getReadHeadPosAtStep(ordinals::CantorNF);

            // Setter
            void setVals_ITTM(std::vector<TransitionRule>, std::vector<char>);
    }
}

#endif /* ITTM_H */