//
// Created by chasen on 2/2/2020.
//

#include "cnfreader.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include "../Logic/CNF.h"
#include "../Logic/Utils.h"
#include "../Logic/Literal.h"

using std::stringstream;

const string EQUATION_BASE = "/Users/chasen/Documents/CodeBase/Solver/tinysat/data/";

/* The implementation of CNFReader */
CNFReader::CNFReader() {
    literalSet = set<Literal>();
}


string CNFReader::trim(string s) {
    const char ch = ' ';
    s.erase(s.find_last_not_of(" ") + 1);
    s.erase(0, s.find_first_not_of(" "));
    return s;
}


/* The implementation of CNFFileReader */
CNFFileReader::CNFFileReader(string fileName) {

}


DisClause CNFFileReader::getClauseTermFileByLine(string s) {
    vector<string> stokens;
    string token;
    stringstream input(s);
    while(input >> token) {
        stokens.push_back(token);
    }

    vector<LiteralTerm> p_literal_items;
    int size = stokens.size();
    for (int i = 0; i < size - 1; i++) {
        Sign sn = (stokens[i] == "+") ? pos : neg;
        int j = i + 1;
        LiteralTerm term(Literal(stokens[i]), sn);
        i = j;
        p_literal_items.push_back(term);
    }
    DisClause disClauseItem(p_literal_items);

    return disClauseItem;
}


CNF CNFFileReader::getCNFFromFile(string filename) {
    string s;
    vector<DisClause> p_disjunctive_clause_items;
    std::ifstream fin(EQUATION_BASE + filename);

    while(getline(fin, s)) {
        DisClause disClauseItem = getClauseTermFileByLine(s);
        p_disjunctive_clause_items.push_back(disClauseItem);
    }

    CNF cnf(p_disjunctive_clause_items);
    return cnf;
}

/* The implementation of CNFConsoleReader */

//TODO
CNFConsoleReader::CNFConsoleReader() {

}

LiteralTerm CNFConsoleReader::getLiteralTermFromConsoleLine(string s) {
    int index = s.find("|");
    string literal = trim(s.substr(0, index));
    string sign = trim(s.substr(index + 1));
    Sign sn = (sign == "-") ? neg : pos;
    LiteralTerm term(literal, sn);
    return term;
}

// TODO Need to Debug
CNF CNFConsoleReader::getCNFFromConsole() {
    std::cout << "input the number of disjunctions" << std::endl;
    int n;
    string s;

    std::cin >> n;
    int sign = 0;
    vector<DisClause> p_disjunctive_clause_items;

    for (int i = 0; i < n; i++) {
        vector<LiteralTerm> p_literal_items;
        while(true) {
            getline(std::cin, s);
            if (s.empty()) {
                break;
            }
            LiteralTerm t = getLiteralTermFromConsoleLine(s);
            if (t.getString() == "EMPTY_CLAUSE") {
                DisClause clause(p_literal_items);
                p_disjunctive_clause_items.push_back(clause);
                break;
            } else {
                p_literal_items.push_back(t);
            }
        }
    }

    CNF cnf = CNF(p_disjunctive_clause_items);
    return cnf;
}