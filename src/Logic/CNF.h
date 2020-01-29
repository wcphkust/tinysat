/*
* Created by Sunshine on 16/1/2020.
*/
#ifndef TINYSAT_CNF_H
#define TINYSAT_CNF_H

#include "DisClause.h"

/*
 * Conjunctive Normal Form
 *   * disjunctive_clause_items: the list of the disjunctive items
 *   * ipvector: the interpretation vector
 *     * 1: true
 *     * 0: half, 1/2(for 3-valued logic)
 *     * -1: false
 *     * MAX_INT: undefined logic value
 *   * cnf_ip: the value of conjunctive normal formula
 */
class CNF {
public:
    vector<DisClause> disjunctive_clause_items;
    vector<int> ipvector;
    Value cnf_ip;

public:
    CNF(vector<DisClause> p_disjunctive_clause_items);
    ~CNF();

    /*get the disjunctive clause items*/
    const vector<DisClause>& getDisjunctiveClauseItems();

    /*evaluate the value of CNF clause*/
    Value evaluate();

    /*get the value of CNF*/
    Value getValue();

    /* print the disjunctive clause */
    string getString();
};

#endif //TINYSAT_CNF_H
