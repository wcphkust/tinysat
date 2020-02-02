//
// Created by chasen on 29/1/2020.
//

#include <iostream>
#include "Utils.h"

/*
 * Echo the value
 */
void echo_value(Value val) {
    switch(val) {
        case one: {
            std::cout << "one" << std::endl;
            break;
        }
        case zero: {
            std::cout << "zero" << std::endl;
            break;
        }
        case half: {
            std::cout << "half" << std::endl;
            break;
        }
        case undef: {
            std::cout << "undef" << std::endl;
            break;
        }
    }
}

/*
 * Overload && for Value with support for 3-valued logic
 */
Value operator && (Value const& v1, Value const& v2) {
    if (v1 == one and v2 == one) {
        return one;
    }
    if (v1 == zero or v2 == zero) {
        return zero;
    }
    return half;
}

/*
 * Overload || for Value with support for 3-valued logic
 */
Value operator || (Value const& v1, Value const& v2) {
    if (v1 == one or v2 == one) {
        return one;
    }
    if (v1 == zero and v2 == zero) {
        return zero;
    }
    return half;
}