//
// Created by Junie on 2026-01-13.
//

#ifndef SI_LIB_TYPE_TRAITS_DECAY_H
#define SI_LIB_TYPE_TRAITS_DECAY_H

#include "../../compat/sconfig.h"
#include "remove_reference.h"
#include "is_array.h"
#include "remove_extent.h"
#include "is_function.h"
#include "add_pointer.h"
#include "remove_cv.h"
#include "conditional.h"

SI_NAMESPACE_START

    template<typename T>
    struct decay {
    private:
        using U = remove_reference_t<T>;
    public:
        using type = typename conditional<
            is_array_v<U>,
            remove_extent_t<U>*,
            typename conditional<
                is_function_v<U>,
                add_pointer_t<U>,
                remove_cv_t<U>
            >::type
        >::type;
    };

    template <typename T> using decay_t = typename decay<T>::type;

SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_DECAY_H
