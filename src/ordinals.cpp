#include "ordinals.h"
#include<iostream>

using namespace ordinals;
using namespace std;

bool operator==(const CantorNF& lhs, const CantorNF& rhs) {
    return (lhs.coefficients == rhs.coefficients) && (lhs.exponents == rhs.coefficients);
}

void CantorNF::setVals_CNF(vector<int> coefficients, vector<CantorNF> exponents) {
    this->coefficients = coefficients;
    this->exponents = exponents;
}

bool CantorNF::lt(const CantorNF& rhs) {
    bool FEB = (lhs->exponents)[0].lt((rhs.exponents)[0]);
    bool FCB = (lhs->exponents)[0] == (rhs.exponents)[0] && (lhs->coefficients)[0].lt((rhs.coefficients)[0]);
    (this->coefficients).erase((this->coefficients).begin());
    (this->exponents).erase((this->exponents).begin());
    (rhs.coefficients).erase((rhs.coefficients).begin());
    (rhs.exponents).erase((rhs.exponents).begin());
    CantorNF NextPartLHS;
    NextPartLHS.setVals_CNF(this->coefficients, this->exponents);
    CantorNF NextPartRHS;
    NextPartRHS.setVals_CNF(rhs.coefficients, rhs.exponents);
    NPB = lt(rhs);
    return FEB || FCB || NPB;
}

bool comp(const CantorNF& lhs, const CantorNF& rhs) {
    return lhs.lt(rhs);
}

bool CantorNF::std() {
    // Make sure all the coefficients are nonzero
    bool NONZ;
    for (unsigned i = 0; i < (this->coefficients).size; i++) {
        if ((this->coefficients)[i] == 0) {NONZ = false;}
    }
    // Make sure each exponent is itself standard
    bool RECS;
    for (unsigned j = 0; j < (this->exponents).size; j++) {
        if (!((this->exponents)[j].std())) {RECS = false;}
    }
    if ((this->coefficients).size > 1) {
        // Make sure each consecutive exponent is > the previous one
        bool DESC = sort((this->exponents).begin(), (this->exponents).end(), comp) == this->exponents;
        return ((this->coefficients).size == (this->exponents).size) && DESC && NONZ && RECS;
    }
    return ((this->coefficients).size == (this->exponents).size) && NONZ && RECS;
}

bool CantorNF::isLim() {
    return ((this->exponents)[(this->exponents).size-1]).exponents.size > 0;
}