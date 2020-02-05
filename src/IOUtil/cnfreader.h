//
// Created by chasen on 2/2/2020.
//

#ifndef TINYSAT_CNFREADER_H
#define TINYSAT_CNFREADER_H

#include "../Logic/Literal.h"
#include "../Logic/LiteralTerm.h"
#include "../Logic/DisClause.h"
#include "../Logic/CNF.h"

class CNFReader {
public:
    set<Literal> literalSet;
    vector<DisClause> disClauseSet;

public:
    CNFReader();
    string trim(string s);
};


class CNFFileReader : public CNFReader{
public:
    string fileName;

public:
    CNFFileReader(string fileName="equation1");
    DisClause getClauseTermFileByLine(string s);
    CNF getCNFFromFile(string filename="equation1");
};


class CNFConsoleReader : public CNFReader {
public:

public:
    CNFConsoleReader();
    LiteralTerm getLiteralTermFromConsoleLine(string s);
    // TODO Need to Debug
    CNF getCNFFromConsole();
};

#endif //TINYSAT_CNFREADER_H
