#ifndef ITTM_H // include guard
#define ITTM_H

#include<iostream>
#include<vector>
#include<string>

namespace ITTM {
    // Transition rule
    class TransitionRule {
        public:
            int currentState;           // -1 = limit, 0 = initial state
            std::string currentCell;
            std::string newContent;
            int moveDirection;          // -1 = left, 0 = don't move, 2 = right
            int nextState;

            // Setter
            void setVals_TR(int, std::string, std::string, int, int);
    }
}

#endif /* ITTM_H */