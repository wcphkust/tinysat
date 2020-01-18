//
// Created by Sunshine on 16/1/2020.
//
#ifndef CNF_H
#define CNF_H

#include <vector>
#include <string>

using std::string;
using std::vector;

enum Sign {
    pos,
    neg
};

/*
 * The Literal Term
 */
class LiteralTerm {
public:
    string literal;
    Sign sign;

public:
    LiteralTerm(string p_literal);
    LiteralTerm(string p_literal, Sign p_sign);
    ~LiteralTerm();

    /* get the literal */
    string getLiteral();

    /* get the sign */
    Sign getSign();

    /* print the literal */
    string getString();
};

/*
 * Disjunctive clause
 */
class DisClause {
public:
    vector<LiteralTerm> literal_term_items;

public:
    DisClause(vector<LiteralTerm> p_literal_term_items);
    ~DisClause();

    /*get the literal term items*/
    vector<LiteralTerm> getLiteralTermItems();

    /*print the disjunctive clause*/
    string getString();
};

/*
 * Conjunctive Normal Form
 */
class CNF {
public:
    vector<DisClause> disjunctive_clause_items;

public:
    CNF(vector<DisClause> p_disjunctive_clause_items);
    ~CNF();

    /*get the disjunctive clause items*/
    vector<DisClause> getDisjunctiveClauseItems();

    /* print the disjunctive clause */
    string getString();
};

#endif //SAT_CNF_H
