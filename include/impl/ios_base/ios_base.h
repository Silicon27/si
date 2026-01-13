//
// Created by David Yang on 2025-06-11.
//

#ifndef SI_LIB_IOS_BASE_IOS_BASE_H
#define SI_LIB_IOS_BASE_IOS_BASE_H

#include <__format/concepts.h>

#include "../../compat/sconfig.h"

SI_NAMESPACE_START

class ios_base {
public:
    using fmtflags = unsigned int;

    // basefield
    static const fmtflags dec = 0x0001; // decimal
    static const fmtflags oct = 0x0002; // octal
    static const fmtflags hex = 0x0004; // hexadecimal
    static const fmtflags basefield = dec | oct | hex;

    // floatfield
    static const fmtflags scientific = 0x0008; // scientific notation
    static const fmtflags fixed = 0x0010; // fixed-point notation
    static const fmtflags floatfield = scientific | fixed;

    // adjustment
    static const fmtflags left = 0x0020; // left adjustment
    static const fmtflags right = 0x0040; // right adjustment
    static const fmtflags internal = 0x0080; // internal adjustment
    static const fmtflags adjustfield = left | right | internal;

    // formatting options
    static const fmtflags showbase = 0x0100; // show base prefix
    static const fmtflags showpoint = 0x0200; // show decimal point
    static const fmtflags showpos = 0x0400; // show positive sign
    static const fmtflags skipws = 0x0800; // skip whitespace
    static const fmtflags unitbuf = 0x1000; // flush output buffer after each output operation
    static const fmtflags uppercase = 0x2000; // use uppercase letters for hexadecimal digits
    static const fmtflags boolalpha = 0x4000; // use "true" and "false" for boolean values

    [[nodiscard]] fmtflags flags() const {return _fmt_flags;}
    void flags(fmtflags fmt) { _fmt_flags = fmt; }

    // error state bits
    static const int goodbit = 0;
    static const int eofbit = 1;
    static const int failbit = 2;
    static const int badbit = 4;

    [[nodiscard]] int rdstate() const { return _state; }
    void setstate(const int state) { _state |= state; }
    void clear(const int s = goodbit) {_state = s;}


private:
    fmtflags _fmt_flags = dec;
    int _state = goodbit;
};

SI_NAMESPACE_END

#endif //SI_LIB_IOS_BASE_IOS_BASE_H
