//
// Created by chasen on 29/1/2020.
//

#include "DisClause.h"

DisClause::DisClause(vector <LiteralTerm> p_literal_term_items) {
    literal_term_items = p_literal_term_items;
    clause_ip = undef;
}


DisClause::~DisClause() {

}

const vector<LiteralTerm>& DisClause::getLiteralTermItems() {
    return literal_term_items;
}


Value DisClause::evaluate() {
    int size = literal_term_items.size();
    Value evaluated_ip = literal_term_items[0].getValue();
    for (int i = 1; i < size; i++) {
        evaluated_ip = (evaluated_ip || literal_term_items[i].getValue());
    }
    return evaluated_ip;
}


Value DisClause::getValue() {
    if (clause_ip == undef) {
        clause_ip = evaluate();
    }
    return clause_ip;
}


string DisClause::getString() {
    string str = "";
    if (literal_term_items.size() == 0) {
        return "EMPTY_CLAUSE";
    } else {
        str = literal_term_items[0].getString();
        int size = literal_term_items.size();
        for (int i = 1; i < size; i++) {
            str = str + " " + "or" + " " + literal_term_items[i].getString();
        }
    }
    str = "(" + str + ")";
    return str;
}
