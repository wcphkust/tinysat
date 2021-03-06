/*
* Created by Sunshine on 16/1/2020.
*/

# include "CNF.h"

CNF::CNF(vector<DisClause> p_disjunctive_clause_items) {
    int size = p_disjunctive_clause_items.size();
    for (int i = 0; i < size; i++) {
        disjunctive_clause_items.push_back(&p_disjunctive_clause_items[i]);
    }
    cnf_ip = undef;
}

CNF::~CNF() {

}

//TODO:polish
const vector<DisClause>& CNF::getDisjunctiveClauseItems() {
    int size = disjunctive_clause_items.size();
    vector<DisClause> disClauseVec;
    for (int i = 0; i < size; i++) {
        disClauseVec.push_back(*disjunctive_clause_items[i]);
    }
    return disClauseVec;
}

Value CNF::evaluate() {
    string str = "";
    int size = disjunctive_clause_items.size();
    Value evaluated_ip = (*disjunctive_clause_items[0]).getValue();
    for (int i = 1; i < size; i++) {
        evaluated_ip = (evaluated_ip && (*disjunctive_clause_items[i]).getValue());
    }
    echo_value(evaluated_ip);
    return evaluated_ip;
}

Value CNF::getValue() {
    if (cnf_ip == undef) {
        cnf_ip = evaluate();
    }
    return cnf_ip;
}

string CNF::getString() {
    string str = "";
    int size = disjunctive_clause_items.size();
    if (size == 0) {
        return "EMPTY_CNF";
    } else {
        str = (*disjunctive_clause_items[0]).getString();
        for (int i = 1; i < size; i++) {
            str = str + " " + "and" + " " + (*disjunctive_clause_items[i]).getString();
        }
    }
    str = "(" + str + ")";
    return str;
}
