//
// Created by David Yang on 2025-06-11.
//

#ifndef SI_LIB_IOS_BASE_IOS_BASE_H
#define SI_LIB_IOS_BASE_IOS_BASE_H

#include "../stddef/ptrdiff_t.h"

#include "../../compat/sconfig.h"

SI_NAMESPACE_START

using streamsize = si::ptrdiff_t;

class ios_base {
public:
    using fmtflags = unsigned int;
    using iostate  = unsigned char;
    using openmode = unsigned char;
    using seekdir  = unsigned char;

    // basefield
    static SI_CONSTEXPR fmtflags dec = 0x0001; // decimal
    static SI_CONSTEXPR fmtflags oct = 0x0002; // octal
    static SI_CONSTEXPR fmtflags hex = 0x0004; // hexadecimal
    static SI_CONSTEXPR fmtflags basefield = dec | oct | hex;

    // floatfield
    static SI_CONSTEXPR fmtflags scientific = 0x0008; // scientific notation
    static SI_CONSTEXPR fmtflags fixed = 0x0010; // fixed-point notation
    static SI_CONSTEXPR fmtflags floatfield = scientific | fixed;

    // adjustment
    static SI_CONSTEXPR fmtflags left = 0x0020; // left adjustment
    static SI_CONSTEXPR fmtflags right = 0x0040; // right adjustment
    static SI_CONSTEXPR fmtflags internal = 0x0080; // internal adjustment
    static SI_CONSTEXPR fmtflags adjustfield = left | right | internal;

    // formatting options
    static SI_CONSTEXPR fmtflags showbase = 0x0100; // show base prefix
    static SI_CONSTEXPR fmtflags showpoint = 0x0200; // show decimal point
    static SI_CONSTEXPR fmtflags showpos = 0x0400; // show positive sign
    static SI_CONSTEXPR fmtflags skipws = 0x0800; // skip whitespace
    static SI_CONSTEXPR fmtflags unitbuf = 0x1000; // flush output buffer after each output operation
    static SI_CONSTEXPR fmtflags uppercase = 0x2000; // use uppercase letters for hexadecimal digits
    static SI_CONSTEXPR fmtflags boolalpha = 0x4000; // use "true" and "false" for boolean values

    // error state bits
    static SI_CONSTEXPR iostate goodbit = 0x00;
    static SI_CONSTEXPR iostate eofbit = 0x01;
    static SI_CONSTEXPR iostate failbit = 0x02;
    static SI_CONSTEXPR iostate badbit = 0x04;

    // formatting Methods
    [[nodiscard]] fmtflags flags() const {return _fmt_flags;}
    fmtflags flags(const fmtflags fmt) {
        const fmtflags old = _fmt_flags;
        _fmt_flags = fmt;
        return old;
    }

    // setf(hex) -> adds a flag
    fmtflags setf(const fmtflags fmt) {
        fmtflags old = _fmt_flags;
        _fmt_flags |= fmt;
        return old;
    }

    // setf(hex, basefield) -> clears the basefield
    fmtflags setf(const fmtflags fmt, const fmtflags mask) {
        fmtflags old = _fmt_flags;
        _fmt_flags = (_fmt_flags & ~mask) | (fmt & mask);
        return old;
    }

    void unsetf(const fmtflags mask) { _fmt_flags &= ~mask;}

    [[nodiscard]] streamsize precision() const {return _precision;}
    streamsize precision(const streamsize prec) {
        const streamsize old = _precision;
        _precision = prec;
        return old;
    }

    [[nodiscard]] streamsize width() const {return _width;}
    streamsize width(const streamsize wid) {
        const streamsize old = _width;
        _width = wid;
        return old;
    }

    class Init {
    public:
        Init();
        ~Init();
    private:
        static int _init_count;
    };

    [[nodiscard]] int rdstate() const { return _state; }
    void setstate(const int state) { _state |= state; }
    void clear(const int s = goodbit) {_state = s;}

protected:
    ios_base() = default;
    virtual ~ios_base() = default;
private:
    fmtflags _fmt_flags     = dec | skipws;
    streamsize _precision   = 6;
    streamsize _width       = 0;
    int _state              = goodbit;
};

SI_NAMESPACE_END

#endif //SI_LIB_IOS_BASE_IOS_BASE_H
