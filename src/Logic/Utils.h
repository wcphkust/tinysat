//
// Created by chasen on 29/1/2020.
//

#ifndef TINYSAT_UTILS_H
#define TINYSAT_UTILS_H

/*
 * The sign of literal in LiteralTerm
 */
enum Sign {
    pos,
    neg
};

/*
 * The value of literal
 */
enum Value {
    one,
    zero,
    half,
    undef
};

Value operator || (Value const& v1, Value const& v2);
Value operator && (Value const& v1, Value const& v2);
void echo_value(Value val);

#endif //TINYSAT_UTILS_H
