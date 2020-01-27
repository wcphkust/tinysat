//
// Created by Sunshine on 16/1/2020.
//

#include <iostream>
#include "CNF.h"

using namespace std;


int main() {
    LiteralTerm a = LiteralTerm("a", pos);
    LiteralTerm b = LiteralTerm("b", neg);
    LiteralTerm c = LiteralTerm("c", pos);

    vector<LiteralTerm> p_literal_items_1;
    p_literal_items_1.push_back(a);
    p_literal_items_1.push_back(b);
    p_literal_items_1.push_back(c);
    DisClause disjunctive_clause1(p_literal_items_1);

    vector<LiteralTerm> p_literal_items_2;
    p_literal_items_2.push_back(a);
//    p_literal_items_2.push_back(b);
//    p_literal_items_2.push_back(c);
    DisClause disjunctive_clause2(p_literal_items_2);

    vector<DisClause> p_disjunctive_clause_items;
    p_disjunctive_clause_items.push_back(disjunctive_clause1);
    p_disjunctive_clause_items.push_back(disjunctive_clause2);

    CNF cnf(p_disjunctive_clause_items);
    echo_value(cnf.getValue());
    cout << cnf.getString() << endl;

    return 0;
}
