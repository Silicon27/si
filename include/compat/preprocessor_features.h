//
// Created by David Yang on 2025-06-04.
//

#ifndef PREPROCESSOR_FEATURES_H
#define PREPROCESSOR_FEATURES_H

#if defined(__has_builtin)
    #define SI_HAS_BUILTIN(x) __has_builtin(x)
#else
    #define SI_HAS_BUILTIN(x) 0
#endif

#if defined(__has_feature)
    #define SI_HAS_FEATURE(x) __has_feature(x)
#else
    #define SI_HAS_FEATURE(x) 0
#endif

#if defined(__has_cpp_attribute)
    #define SI_HAS_CPP_ATTRIBUTE(x) __has_cpp_attribute(x)
#else
    #define SI_HAS_CPP_ATTRIBUTE(x) 0
#endif

#if defined(__has_include)
    #define SI_HAS_INCLUDE(x) __has_include(x)
#else
    #define SI_HAS_INCLUDE(x) 0
#endif

#endif //PREPROCESSOR_FEATURES_H
