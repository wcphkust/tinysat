//
// Created by chasen on 4/2/20.
//

#include "Literal.h"

Literal::Literal() {
    literal = "";
}

Literal::Literal(string p_literal) {
    literal = p_literal;
}

string Literal::getString() {
    return literal;
}

struct LiteralCompare {
    bool operator()(Literal& a, Literal& b) const {
        return a.getString().compare(b.getString());
    }
};
