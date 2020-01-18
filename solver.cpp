//
// Created by Sunshine on 16/1/2020.
//

#include <iostream>
#include "CNF.h"

using namespace std;

int main() {
    LiteralTerm a = LiteralTerm("a");
    LiteralTerm b = LiteralTerm("b");

    vector<LiteralTerm> p_literal_items;
    p_literal_items.push_back(a);
    p_literal_items.push_back(b);
    DisClause disjunctive_clause(p_literal_items);

    vector<DisClause> p_disjunctive_clause_items;
    p_disjunctive_clause_items.push_back(disjunctive_clause);
    CNF cnf(p_disjunctive_clause_items);
    cout << "test" << endl;
    cout << cnf.getString() << endl;

    return 0;
}
