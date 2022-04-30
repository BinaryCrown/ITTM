#ifndef ORDINALS_H // include guard
#define ORDINALS_H

#include<iostream>
#include<vector>

namespace ordinals {
    // CNF class
    class CantorNF {
        public:
            // The ordinal = w^a1*b1 + w^a2*b2 + ... + w^an*bn
            // The vector "coefficients" = b1, b2, ..., bn
            // The vector "exponents" = a1, a2, ..., an
            vector<int> coefficients;  
            vector<CantorNF> exponents;
            bool std();
            bool lt(const CantorNF&);
            
            // Setter
            void setVals(vector<int>, vector<CantorNF>);
    }
}

#endif /* ORDINALS_H */