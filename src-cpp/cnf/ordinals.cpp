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
    // Is the first LHS exp. < the first RHS exp.?
    bool FEB = (lhs->exponents)[0].lt((rhs.exponents)[0]);
    // Is the first LHS exp. = the first RHS exp. and the first LHS coeff. < the first RHS coeff.?
    bool FCB = (lhs->exponents)[0] == (rhs.exponents)[0] && (lhs->coefficients)[0].lt((rhs.coefficients)[0]);
    // Is the first term = the first RHS term, and the LHS right part < the RHS right part?
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

CantorNF CantorNF::fundamentalSeq(int ent) {
    if (!std()) {
        throw std::invalid_argument("Received nonstandard CNF.");
    }
    CantorNF retval;
    if (isLim()) {
        // Is it a singleton, i.e. w^a1*b1?
        if ((this->coefficients).size == 1) {
            // Is the first coefficient > 1?
            if ((this->coefficients)[0] > 1) {
                (this->coefficients)[0]--;
                (this->coefficients).push_back(1);
                (this->exponents).push_back((this->exponents)[0]);
                retval.setVals_CNF(fundamentalSeq(ent).coefficients, fundamentalSeq(ent).exponents);
            }
            else {
                // Is the first exponent a limit ordinal?
                if ((this->exponents)[0].isLim()) {
                    retval.setVals_CNF(this->coefficients, (this->exponents)[0].fundamentalSeq(ent));
                }
                // Is the first exponent zero?
                if ((this->exponents)[0].coefficients.size == 0) {
                    retval.setVals_CNF((this->exponents)[0].coefficients, (this->exponents)[0].exponents);
                }
                else {
                    retval.setVals_CNF(ent, (this->exponents)[0].fundamentalSeq(0));
                }
            } 
        }
        else {
            // Replace the rightmost term with its sequence.
            CantorNF RMTerm;
            std::vector<int> RMCoefficient{(this->coefficients)[(this->coefficients).size-1]};
            std::vector<CantorNF> RMExponent{(this->exponents)[(this->exponents).size-1]}
            RMTerm.setVals_CNF(RMCoefficient, RMExponent);
            CantorNF RMTermSeq = RMTerm.fundamentalSeq(ent);
            (this->coefficients).pop_back()
            for (unsigned i = 0; i < RMTermSeq.coefficients.size; i++) {
                (this->coefficients).push_back((RMTermSeq.coefficients)[i]);
            }
            (this->exponents).pop_back()
            for (unsigned i = 0; i < RMTermSeq.exponents.size; i++) {
                (this->exponents).push_back((RMTermSeq.exponents)[i]);
            }
            retval.setVals_CNF(this->coefficients, this->exponents);
        }
    }
    else {
        if ((this->coefficients).size == 0) {
            retval.setVals_CNF(this->coefficients, this->exponents);
        }
        else {
            (this->coefficients).erase((this->coefficients).end());
            (this->exponents).erase((this->exponents).end());
            retval.setVals_CNF(this->coefficients, this->exponents);
        }
    }
    return retval;
}