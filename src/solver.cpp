/*
* Created by Sunshine on 16/1/2020.
*/

#include <iostream>
#include "Logic/CNF.h"
#include "Logic/DisClause.h"
#include "IOUtil/cnfreader.h"
#include "Logic/Literal.h"

void test() {
    LiteralTerm b(Literal("b"), pos);
    LiteralTerm a(Literal("a"), pos);
    LiteralTerm c(Literal("c"), pos);

    vector<LiteralTerm> p_literal_items_1;
    p_literal_items_1.push_back(a);
    p_literal_items_1.push_back(b);
    p_literal_items_1.push_back(c);
    DisClause disjunctive_clause1(p_literal_items_1);

    vector<LiteralTerm> p_literal_items_2;
    p_literal_items_2.push_back(a);
    p_literal_items_2.push_back(b);
    p_literal_items_2.push_back(c);
    DisClause disjunctive_clause2(p_literal_items_2);

    vector<DisClause> p_disjunctive_clause_items;
    p_disjunctive_clause_items.push_back(disjunctive_clause1);
    p_disjunctive_clause_items.push_back(disjunctive_clause2);

    CNF cnf(p_disjunctive_clause_items);
    echo_value(cnf.getValue());
    std::cout << cnf.getString() << std::endl;
}

int main() {
    CNF cnf = getCNFFromFile();
    std::cout << cnf.getString() << std::endl;
    return 0;
}
