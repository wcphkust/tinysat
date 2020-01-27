/*
* Created by Sunshine on 16/1/2020.
*/
#ifndef MYSAT_CNF_H
#define MYSAT_CNF_H

#include <vector>
#include <string>
#include <optional>
#include <iostream>

using namespace std;

/*
 * The sign of literal in LiteralTerm
 */
enum Sign {
    pos,
    neg
};

/*
 * The value of literal
 */
enum Value {
    one,
    zero,
    half,
    undef
};

Value operator || (Value const& v1, Value const& v2);
Value operator && (Value const& v1, Value const& v2);
void echo_value(Value val);

/*
 * The Literal Term
 */
class LiteralTerm {
public:
    string literal;
    Sign sign;
    Value ip;

public:
    LiteralTerm(string p_literal);
    LiteralTerm(string p_literal, Sign p_sign);
    ~LiteralTerm();

    /* get the literal */
    string getLiteral();

    /* get the sign */
    Sign getSign();

    /* evaluate */
    Value getValue();

    /* print the literal */
    string getString();
};


/*
 * Disjunctive clause
 */
class DisClause {
public:
    vector<LiteralTerm> literal_term_items;
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


/*
 * Conjunctive Normal Form
 */
class CNF {
public:
    vector<DisClause> disjunctive_clause_items;
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

#endif //MYSAT_CNF_H
