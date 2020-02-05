//
// Created by chasen on 29/1/2020.
//

#ifndef TINYSAT_DISCLAUSE_H
#define TINYSAT_DISCLAUSE_H

#include <vector>
#include "LiteralTerm.h"

using std::vector;

/*
 * Disjunctive clause
 */
class DisClause {
public:
    vector<LiteralTerm*> literal_term_items;
    Value clause_ip;

public:
    DisClause(vector<LiteralTerm> p_literal_term_items);
    ~DisClause();

    /*get the literal term items*/
    const vector<LiteralTerm>& getLiteralTermItems();

    /*evaluate the value of disjunctive clause*/
    Value evaluate();

    /*get the value of disjunctive clause*/
    Value getValue();

    /*print the disjunctive clause*/
    string getString();
};

#endif //TINYSAT_DISCLAUSE_H
