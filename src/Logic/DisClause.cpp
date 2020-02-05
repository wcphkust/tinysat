//
// Created by chasen on 29/1/2020.
//

#include "DisClause.h"

DisClause::DisClause(vector <LiteralTerm> p_literal_term_items) {
    int size = p_literal_term_items.size();
    for (int i = 0; i < size; i++) {
        literal_term_items.push_back(&p_literal_term_items[i]);
    }
    clause_ip = undef;
}


DisClause::~DisClause() {

}

//TODO:polish
const vector<LiteralTerm>& DisClause::getLiteralTermItems() {
    int size = literal_term_items.size();
    vector<LiteralTerm> literalTermVec;
    for (int i = 0; i < size; i++) {
        literalTermVec.push_back(*literal_term_items[i]);
    }
    return literalTermVec;
}


Value DisClause::evaluate() {
    int size = literal_term_items.size();
    Value evaluated_ip = (*literal_term_items[0]).getValue();
    for (int i = 1; i < size; i++) {
        evaluated_ip = (evaluated_ip || (*literal_term_items[i]).getValue());
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
        str = (*literal_term_items[0]).getString();
        int size = literal_term_items.size();
        for (int i = 1; i < size; i++) {
            str = str + " " + "or" + " " + (*literal_term_items[i]).getString();
        }
    }
    str = "(" + str + ")";
    return str;
}
