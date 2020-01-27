//
// Created by Sunshine on 16/1/2020.
//
#ifndef CNF_H
#define CNF_H

#include <vector>
#include <string>
#include <optional>
#include <iostream>

using namespace std;

enum Sign {
    pos,
    neg
};

enum Value {
    one,
    zero,
    half,
    undefined
};

Value operator && (Value const& v1, Value const& v2) {
    if (v1 == one and v2 == one) {
        return one;
    }
    if (v1 == zero or v2 == zero) {
        return zero;
    }
    return half;
}

Value operator || (Value const& v1, Value const& v2) {
    if (v1 == one or v2 == one) {
        return one;
    }
    if (v1 == zero and v2 == zero) {
        return zero;
    }
    return half;
}

void echo_value(Value val) {
    switch(val) {
        case one: {
            cout << "one" << endl;
            break;
        }
        case zero: {
            cout << "zero" << endl;
            break;
        }
        case half: {
            cout << "half" << endl;
            break;
        }
        case undefined: {
            cout << "undefined" << endl;
            break;
        }
    }
}

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
