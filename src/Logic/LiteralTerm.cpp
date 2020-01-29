//
// Created by chasen on 29/1/2020.
//

#include "LiteralTerm.h"

LiteralTerm::LiteralTerm(string p_literal) {
    literal = p_literal;
    sign = pos;
    ip = one;
}


LiteralTerm::LiteralTerm(string p_literal, Sign p_sign) {
    literal = p_literal;
    sign = p_sign;
    ip = one;
}


LiteralTerm::~LiteralTerm() {

}


string LiteralTerm::getLiteral() {
    return literal;
}


Sign LiteralTerm::getSign() {
    return sign;
}


Value LiteralTerm::getValue() {
    return ip;
}


string LiteralTerm::getString() {
    string str = (sign == neg) ? ("not " + literal) : literal;
    str = "(" + str + ")";
    return str;
}