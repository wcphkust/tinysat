//
// Created by Sunshine on 16/1/2020.
//

# include "CNF.h"
# include <string>

/*
 * The implementation of LiteralTerm
 */
LiteralTerm::LiteralTerm(string p_literal) {
    literal = p_literal;
    sign = pos;
}

LiteralTerm::LiteralTerm(string p_literal, Sign p_sign) {
    literal = p_literal;
    sign = p_sign;
}

LiteralTerm::~LiteralTerm() {

}

string LiteralTerm::getLiteral() {
    return literal;
}

Sign LiteralTerm::getSign() {
    return sign;
}

string LiteralTerm::getString() {
    string str = (sign == neg) ? ("not " + literal) : literal;
    str = "(" + str + ")";
    return str;
}

/*
 * The implementation of DisClause
 */
DisClause::DisClause(vector <LiteralTerm> p_literal_term_items) {
    literal_term_items = p_literal_term_items;
}

DisClause::~DisClause() {

}

const vector<LiteralTerm>& DisClause::getLiteralTermItems() {
    return literal_term_items;
}

string DisClause::getString() {
    string str = "";
    if (literal_term_items.size() == 0) {
        return "EMPTY_CLAUSE";
    } else {
        str = literal_term_items[0].getString();
        for (int i = 1; i < literal_term_items.size(); i++) {
            str = str + " " + "and" + " " + literal_term_items[i].getString();
        }
    }
    str = "(" + str + ")";
    return str;
}

/*
 * The implementation of Conjunctive Normal Form
 */
CNF::CNF(vector <DisClause> p_disjunctive_clause_items) {
    disjunctive_clause_items = p_disjunctive_clause_items;
}

CNF::~CNF() {

}

const vector<DisClause>& CNF::getDisjunctiveClauseItems() {
    return disjunctive_clause_items;
}

string CNF::getString() {
    string str = "";
    if (disjunctive_clause_items.size() == 0) {
        return "EMPTY_CNF";
    } else {
        str = disjunctive_clause_items[0].getString();
        for (int i = 1; i < disjunctive_clause_items.size(); i++) {
            str = str + " " + "and" + " " + disjunctive_clause_items[i].getString();
        }
    }
    str = "(" + str + ")";
    return str;
}
