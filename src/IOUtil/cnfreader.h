//
// Created by chasen on 2/2/2020.
//

#ifndef TINYSAT_CNFREADER_H
#define TINYSAT_CNFREADER_H

#include "../Logic/LiteralTerm.h"
#include "../Logic/DisClause.h"
#include "../Logic/CNF.h"

void trim(string s);
DisClause getClauseTermFileByLine(string s);
CNF getCNFFromFile(string filename="equation1");

LiteralTerm getLiteralTermFromConsoleLine();
CNF getCNFFromConsole();

#endif //TINYSAT_CNFREADER_H
