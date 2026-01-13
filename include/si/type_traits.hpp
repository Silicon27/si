//
// Created by David Yang on 2025-05-30.
//

#ifndef SI_LIB_TYPE_TRAITS_HPP
#define SI_LIB_TYPE_TRAITS_HPP

#include "../compat/sconfig.h"
#include "stddef.hpp"

// include implementations
#include "../impl/type_traits/is_referenceable.h"
#include "../impl/type_traits/remove_reference.h"
#include "../impl/type_traits/remove_const.h"
#include "../impl/type_traits/remove_volatile.h"
#include "../impl/type_traits/remove_cv.h"
#include "../impl/type_traits/remove_extent.h"
#include "../impl/type_traits/add_const.h"
#include "../impl/type_traits/add_volatile.h"
#include "../impl/type_traits/add_lvalue_reference.h"
#include "../impl/type_traits/add_rvalue_reference.h"
#include "../impl/type_traits/add_pointer.h"
#include "../impl/type_traits/conditional.h"
#include "../impl/type_traits/enable_if.h"
#include "../impl/type_traits/integral_constant.h"
#include "../impl/type_traits/is_integral.h"
#include "../impl/type_traits/is_floating_point.h"
#include "../impl/type_traits/is_arithmetic.h"
#include "../impl/type_traits/is_enum.h"
#include "../impl/type_traits/is_union.h"
#include "../impl/type_traits/is_class.h"
#include "../impl/type_traits/is_array.h"
#include "../impl/type_traits/is_same.h"
#include "../impl/type_traits/is_const.h"
#include "../impl/type_traits/is_reference.h"
#include "../impl/type_traits/is_function.h"
#include "../impl/type_traits/is_void.h"
#include "../impl/type_traits/is_null_pointer.h"
#include "../impl/type_traits/is_pointer.h"
#include "../impl/type_traits/is_member_pointer.h"
#include "../impl/type_traits/is_member_object_pointer.h"
#include "../impl/type_traits/is_member_function_pointer.h"
#include "../impl/type_traits/is_lvalue_reference.h"
#include "../impl/type_traits/is_rvalue_reference.h"
#include "../impl/type_traits/is_trivially_copyable.h"
#include "../impl/type_traits/decay.h"

SI_NAMESPACE_START
    // explicitly include size_t from stddef.hpp
    using si::size_t;
    using si::void_t;
    using si::nullptr_t;
SI_NAMESPACE_END

#endif //SI_LIB_TYPE_TRAITS_HPP