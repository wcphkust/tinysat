//
// Created by chasen on 4/2/20.
//

#ifndef TINYSAT_LITERAL_H
#define TINYSAT_LITERAL_H

#include <iostream>
using std::string;


class Literal {
public:
    string literal;

public:
    Literal();
    Literal(string p_literal);
    string getString();
};

#endif //TINYSAT_LITERAL_H
