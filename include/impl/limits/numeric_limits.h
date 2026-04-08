//
// Created by GitHub Copilot on 2026-04-08. Moved to impl/limits
//

#ifndef SI_LIB_LIMITS_NUMERIC_LIMITS_H
#define SI_LIB_LIMITS_NUMERIC_LIMITS_H

#include "../../compat/sconfig.h"
#include "../type_traits/is_integral.h"
#include "../type_traits/is_unsigned.h"
#include "../type_traits/is_same.h"
#include <climits> // for CHAR_BIT
#include <cfloat>  // for float limits

// Some platforms may not define the denorm macros; provide fallbacks
#ifndef FLT_DENORM_MIN
#   define SI_FLT_DENORM_MIN 0.0f
#else
#   define SI_FLT_DENORM_MIN FLT_DENORM_MIN
#endif

#ifndef DBL_DENORM_MIN
#   define SI_DBL_DENORM_MIN 0.0
#else
#   define SI_DBL_DENORM_MIN DBL_DENORM_MIN
#endif

#ifndef LDBL_DENORM_MIN
#   define SI_LDBL_DENORM_MIN 0.0L
#else
#   define SI_LDBL_DENORM_MIN LDBL_DENORM_MIN
#endif

SI_NAMESPACE_START

    // primary template: mirrors std::numeric_limits defaults
    template <typename T>
    struct numeric_limits {
        static constexpr bool is_specialized = false;

        static constexpr int digits = 0;      // number of radix digits
        static constexpr int digits10 = 0;    // number of base-10 digits

        static constexpr bool is_signed = false;
        static constexpr bool is_integer = false;
        static constexpr bool is_exact = false;
        static constexpr int radix = 0;

        static constexpr T min() noexcept { return T(); }
        static constexpr T max() noexcept { return T(); }
        static constexpr T lowest() noexcept { return T(); }

        static constexpr T epsilon() noexcept { return T(); }
        static constexpr T round_error() noexcept { return T(); }

        static constexpr int min_exponent = 0;
        static constexpr int min_exponent10 = 0;
        static constexpr int max_exponent = 0;
        static constexpr int max_exponent10 = 0;

        static constexpr bool has_infinity = false;
        static constexpr bool has_quiet_NaN = false;
        static constexpr bool has_signaling_NaN = false;
        static constexpr bool has_denorm = false;
        static constexpr bool has_denorm_loss = false;

        static constexpr T infinity() noexcept { return T(); }
        static constexpr T quiet_NaN() noexcept { return T(); }
        static constexpr T signaling_NaN() noexcept { return T(); }
        static constexpr T denorm_min() noexcept { return T(); }
    };

    // helper for digits10 calculation (floor)
    static constexpr int digits10_from_digits(int d) {
        // log10(2) ~ 0.301029995663981195
        return static_cast<int>(d * 0.301029995663981195);
    }

    // Integral specializations (signed and unsigned)
    // Note: `char` signedness is implementation-defined and we detect it.

    // unsigned char
    template <> struct numeric_limits<unsigned char> {
        static constexpr bool is_specialized = true;
        static constexpr int digits = sizeof(unsigned char) * CHAR_BIT;
        static constexpr int digits10 = digits10_from_digits(digits);
        static constexpr bool is_signed = false;
        static constexpr bool is_integer = true;
        static constexpr bool is_exact = true;
        static constexpr int radix = 2;
        static constexpr unsigned char min() noexcept { return 0; }
        static constexpr unsigned char max() noexcept { return static_cast<unsigned char>(UCHAR_MAX); }
        static constexpr unsigned char lowest() noexcept { return min(); }
        static constexpr unsigned char epsilon() noexcept { return 0; }
        static constexpr unsigned char round_error() noexcept { return 0; }
        static constexpr int min_exponent = 0;
        static constexpr int min_exponent10 = 0;
        static constexpr int max_exponent = 0;
        static constexpr int max_exponent10 = 0;
        static constexpr bool has_infinity = false;
        static constexpr bool has_quiet_NaN = false;
        static constexpr bool has_signaling_NaN = false;
        static constexpr bool has_denorm = false;
        static constexpr bool has_denorm_loss = false;
        static constexpr unsigned char infinity() noexcept { return 0; }
        static constexpr unsigned char quiet_NaN() noexcept { return 0; }
        static constexpr unsigned char signaling_NaN() noexcept { return 0; }
        static constexpr unsigned char denorm_min() noexcept { return 0; }
    };

    // signed char
    template <> struct numeric_limits<signed char> {
        static constexpr bool is_specialized = true;
        static constexpr int digits = sizeof(signed char) * CHAR_BIT - 1;
        static constexpr int digits10 = digits10_from_digits(digits);
        static constexpr bool is_signed = true;
        static constexpr bool is_integer = true;
        static constexpr bool is_exact = true;
        static constexpr int radix = 2;
        static constexpr signed char min() noexcept { return static_cast<signed char>(SCHAR_MIN); }
        static constexpr signed char max() noexcept { return static_cast<signed char>(SCHAR_MAX); }
        static constexpr signed char lowest() noexcept { return min(); }
        static constexpr signed char epsilon() noexcept { return 0; }
        static constexpr signed char round_error() noexcept { return 0; }
        static constexpr int min_exponent = 0;
        static constexpr int min_exponent10 = 0;
        static constexpr int max_exponent = 0;
        static constexpr int max_exponent10 = 0;
        static constexpr bool has_infinity = false;
        static constexpr bool has_quiet_NaN = false;
        static constexpr bool has_signaling_NaN = false;
        static constexpr bool has_denorm = false;
        static constexpr bool has_denorm_loss = false;
        static constexpr signed char infinity() noexcept { return 0; }
        static constexpr signed char quiet_NaN() noexcept { return 0; }
        static constexpr signed char signaling_NaN() noexcept { return 0; }
        static constexpr signed char denorm_min() noexcept { return 0; }
    };

    // char (implementation-defined signedness)
    template <> struct numeric_limits<char> {
        static constexpr bool is_specialized = true;
        static constexpr bool char_is_signed = (char(-1) < 0);
        static constexpr int digits = char_is_signed ? (sizeof(char) * CHAR_BIT - 1) : (sizeof(char) * CHAR_BIT);
        static constexpr int digits10 = digits10_from_digits(digits);
        static constexpr bool is_signed = char_is_signed;
        static constexpr bool is_integer = true;
        static constexpr bool is_exact = true;
        static constexpr int radix = 2;
        static constexpr char min() noexcept { return static_cast<char>(CHAR_MIN); }
        static constexpr char max() noexcept { return static_cast<char>(CHAR_MAX); }
        static constexpr char lowest() noexcept { return min(); }
        static constexpr char epsilon() noexcept { return 0; }
        static constexpr char round_error() noexcept { return 0; }
        static constexpr int min_exponent = 0;
        static constexpr int min_exponent10 = 0;
        static constexpr int max_exponent = 0;
        static constexpr int max_exponent10 = 0;
        static constexpr bool has_infinity = false;
        static constexpr bool has_quiet_NaN = false;
        static constexpr bool has_signaling_NaN = false;
        static constexpr bool has_denorm = false;
        static constexpr bool has_denorm_loss = false;
        static constexpr char infinity() noexcept { return 0; }
        static constexpr char quiet_NaN() noexcept { return 0; }
        static constexpr char signaling_NaN() noexcept { return 0; }
        static constexpr char denorm_min() noexcept { return 0; }
    };

    // unsigned short
    template <> struct numeric_limits<unsigned short> {
        static constexpr bool is_specialized = true;
        static constexpr int digits = sizeof(unsigned short) * CHAR_BIT;
        static constexpr int digits10 = digits10_from_digits(digits);
        static constexpr bool is_signed = false;
        static constexpr bool is_integer = true;
        static constexpr bool is_exact = true;
        static constexpr int radix = 2;
        static constexpr unsigned short min() noexcept { return 0; }
        static constexpr unsigned short max() noexcept { return static_cast<unsigned short>(USHRT_MAX); }
        static constexpr unsigned short lowest() noexcept { return min(); }
    };

    // short
    template <> struct numeric_limits<short> {
        static constexpr bool is_specialized = true;
        static constexpr int digits = sizeof(short) * CHAR_BIT - 1;
        static constexpr int digits10 = digits10_from_digits(digits);
        static constexpr bool is_signed = true;
        static constexpr bool is_integer = true;
        static constexpr bool is_exact = true;
        static constexpr int radix = 2;
        static constexpr short min() noexcept { return static_cast<short>(SHRT_MIN); }
        static constexpr short max() noexcept { return static_cast<short>(SHRT_MAX); }
        static constexpr short lowest() noexcept { return min(); }
    };

    // unsigned int
    template <> struct numeric_limits<unsigned int> {
        static constexpr bool is_specialized = true;
        static constexpr int digits = sizeof(unsigned int) * CHAR_BIT;
        static constexpr int digits10 = digits10_from_digits(digits);
        static constexpr bool is_signed = false;
        static constexpr bool is_integer = true;
        static constexpr bool is_exact = true;
        static constexpr int radix = 2;
        static constexpr unsigned int min() noexcept { return 0u; }
        static constexpr unsigned int max() noexcept { return static_cast<unsigned int>(UINT_MAX); }
        static constexpr unsigned int lowest() noexcept { return min(); }
    };

    // int
    template <> struct numeric_limits<int> {
        static constexpr bool is_specialized = true;
        static constexpr int digits = sizeof(int) * CHAR_BIT - 1;
        static constexpr int digits10 = digits10_from_digits(digits);
        static constexpr bool is_signed = true;
        static constexpr bool is_integer = true;
        static constexpr bool is_exact = true;
        static constexpr int radix = 2;
        static constexpr int min() noexcept { return INT_MIN; }
        static constexpr int max() noexcept { return INT_MAX; }
        static constexpr int lowest() noexcept { return min(); }
    };

    // unsigned long
    template <> struct numeric_limits<unsigned long> {
        static constexpr bool is_specialized = true;
        static constexpr int digits = sizeof(unsigned long) * CHAR_BIT;
        static constexpr int digits10 = digits10_from_digits(digits);
        static constexpr bool is_signed = false;
        static constexpr bool is_integer = true;
        static constexpr bool is_exact = true;
        static constexpr int radix = 2;
        static constexpr unsigned long min() noexcept { return 0ul; }
        static constexpr unsigned long max() noexcept { return ULONG_MAX; }
        static constexpr unsigned long lowest() noexcept { return min(); }
    };

    // long
    template <> struct numeric_limits<long> {
        static constexpr bool is_specialized = true;
        static constexpr int digits = sizeof(long) * CHAR_BIT - 1;
        static constexpr int digits10 = digits10_from_digits(digits);
        static constexpr bool is_signed = true;
        static constexpr bool is_integer = true;
        static constexpr bool is_exact = true;
        static constexpr int radix = 2;
        static constexpr long min() noexcept { return LONG_MIN; }
        static constexpr long max() noexcept { return LONG_MAX; }
        static constexpr long lowest() noexcept { return min(); }
    };

    // unsigned long long
    template <> struct numeric_limits<unsigned long long> {
        static constexpr bool is_specialized = true;
        static constexpr int digits = sizeof(unsigned long long) * CHAR_BIT;
        static constexpr int digits10 = digits10_from_digits(digits);
        static constexpr bool is_signed = false;
        static constexpr bool is_integer = true;
        static constexpr bool is_exact = true;
        static constexpr int radix = 2;
        static constexpr unsigned long long min() noexcept { return 0ull; }
        static constexpr unsigned long long max() noexcept { return ULLONG_MAX; }
        static constexpr unsigned long long lowest() noexcept { return min(); }
    };

    // long long
    template <> struct numeric_limits<long long> {
        static constexpr bool is_specialized = true;
        static constexpr int digits = sizeof(long long) * CHAR_BIT - 1;
        static constexpr int digits10 = digits10_from_digits(digits);
        static constexpr bool is_signed = true;
        static constexpr bool is_integer = true;
        static constexpr bool is_exact = true;
        static constexpr int radix = 2;
        static constexpr long long min() noexcept { return LLONG_MIN; }
        static constexpr long long max() noexcept { return LLONG_MAX; }
        static constexpr long long lowest() noexcept { return min(); }
    };

    // Floating point specializations (map to C macros in <cfloat>)
    template <> struct numeric_limits<float> {
        static constexpr bool is_specialized = true;
        static constexpr int digits = FLT_MANT_DIG;
        static constexpr int digits10 = FLT_DIG;
        static constexpr bool is_signed = true;
        static constexpr bool is_integer = false;
        static constexpr bool is_exact = false;
        static constexpr int radix = FLT_RADIX;
        static constexpr float min() noexcept { return FLT_MIN; } // smallest positive normalized
        static constexpr float max() noexcept { return FLT_MAX; }
        static constexpr float lowest() noexcept { return -FLT_MAX; }
        static constexpr float epsilon() noexcept { return FLT_EPSILON; }
        static constexpr float round_error() noexcept { return 0.5f; }
        static constexpr int min_exponent = FLT_MIN_EXP;
        static constexpr int min_exponent10 = FLT_MIN_10_EXP;
        static constexpr int max_exponent = FLT_MAX_EXP;
        static constexpr int max_exponent10 = FLT_MAX_10_EXP;
        static constexpr bool has_infinity = true;
        static constexpr bool has_quiet_NaN = true;
        static constexpr bool has_signaling_NaN = true;
        static constexpr bool has_denorm = (SI_FLT_DENORM_MIN != 0.0f);
        static constexpr bool has_denorm_loss = false;
        static constexpr float infinity() noexcept { return __builtin_inff(); }
        static constexpr float quiet_NaN() noexcept { return __builtin_nanf("" ); }
        static constexpr float signaling_NaN() noexcept { return quiet_NaN(); }
        static constexpr float denorm_min() noexcept { return SI_FLT_DENORM_MIN; }
    };

    template <> struct numeric_limits<double> {
        static constexpr bool is_specialized = true;
        static constexpr int digits = DBL_MANT_DIG;
        static constexpr int digits10 = DBL_DIG;
        static constexpr bool is_signed = true;
        static constexpr bool is_integer = false;
        static constexpr bool is_exact = false;
        static constexpr int radix = FLT_RADIX;
        static constexpr double min() noexcept { return DBL_MIN; }
        static constexpr double max() noexcept { return DBL_MAX; }
        static constexpr double lowest() noexcept { return -DBL_MAX; }
        static constexpr double epsilon() noexcept { return DBL_EPSILON; }
        static constexpr double round_error() noexcept { return 0.5; }
        static constexpr int min_exponent = DBL_MIN_EXP;
        static constexpr int min_exponent10 = DBL_MIN_10_EXP;
        static constexpr int max_exponent = DBL_MAX_EXP;
        static constexpr int max_exponent10 = DBL_MAX_10_EXP;
        static constexpr bool has_infinity = true;
        static constexpr bool has_quiet_NaN = true;
        static constexpr bool has_signaling_NaN = true;
        static constexpr bool has_denorm = (SI_DBL_DENORM_MIN != 0.0);
        static constexpr bool has_denorm_loss = false;
        static constexpr double infinity() noexcept { return __builtin_inf(); }
        static constexpr double quiet_NaN() noexcept { return __builtin_nan(""); }
        static constexpr double signaling_NaN() noexcept { return quiet_NaN(); }
        static constexpr double denorm_min() noexcept { return SI_DBL_DENORM_MIN; }
    };

    template <> struct numeric_limits<long double> {
        static constexpr bool is_specialized = true;
        static constexpr int digits = LDBL_MANT_DIG;
        static constexpr int digits10 = LDBL_DIG;
        static constexpr bool is_signed = true;
        static constexpr bool is_integer = false;
        static constexpr bool is_exact = false;
        static constexpr int radix = FLT_RADIX;
        static constexpr long double min() noexcept { return LDBL_MIN; }
        static constexpr long double max() noexcept { return LDBL_MAX; }
        static constexpr long double lowest() noexcept { return -LDBL_MAX; }
        static constexpr long double epsilon() noexcept { return LDBL_EPSILON; }
        static constexpr long double round_error() noexcept { return 0.5L; }
        static constexpr int min_exponent = LDBL_MIN_EXP;
        static constexpr int min_exponent10 = LDBL_MIN_10_EXP;
        static constexpr int max_exponent = LDBL_MAX_EXP;
        static constexpr int max_exponent10 = LDBL_MAX_10_EXP;
        static constexpr bool has_infinity = true;
        static constexpr bool has_quiet_NaN = true;
        static constexpr bool has_signaling_NaN = true;
        static constexpr bool has_denorm = (SI_LDBL_DENORM_MIN != 0.0L);
        static constexpr bool has_denorm_loss = false;
        static constexpr long double infinity() noexcept { return __builtin_infl(); }
        static constexpr long double quiet_NaN() noexcept { return __builtin_nanl(""); }
        static constexpr long double signaling_NaN() noexcept { return quiet_NaN(); }
        static constexpr long double denorm_min() noexcept { return SI_LDBL_DENORM_MIN; }
    };

SI_NAMESPACE_END

#endif // SI_LIB_LIMITS_NUMERIC_LIMITS_H

