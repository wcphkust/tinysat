//
// Created by chasen on 29/1/2020.
//

#ifndef TINYSAT_LITERALTERM_H
#define TINYSAT_LITERALTERM_H

#include <iostream>
#include "Utils.h"
#include "Literal.h"

using std::string;

/*
 * The Literal Term
 */
class LiteralTerm {
public:
    Literal* literal;
    Sign sign;
    Value ip;

public:
    LiteralTerm(Literal p_literal);
    LiteralTerm(Literal p_literal, Sign p_sign);
    ~LiteralTerm();

    /* get the literal */
    string getLiteral();

    /* get the sign */
    Sign getSign();

    /* evaluate */
    Value getValue();

    /* print the literal term */
    string getString();
};


#endif //TINYSAT_LITERALTERM_H
