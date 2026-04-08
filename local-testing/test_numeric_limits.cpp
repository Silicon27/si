#include "si/type_traits.hpp"
#include "impl/memory/next_power_of_2.hpp"
#include <cstdio>
#include <climits>

static_assert(si::numeric_limits<unsigned int>::digits == sizeof(unsigned int) * CHAR_BIT, "unsigned int digits mismatch");
static_assert(si::numeric_limits<int>::digits == sizeof(int) * CHAR_BIT - 1, "int digits mismatch");
// char signedness check: must match implementation
static_assert(si::numeric_limits<char>::digits == ((char(-1) < 0) ? (sizeof(char) * CHAR_BIT - 1) : (sizeof(char) * CHAR_BIT)), "char digits mismatch");

int main() {
    static_assert(si::is_unsigned_v<unsigned int>, "unsigned int should be unsigned");
    unsigned int a = 5;
    unsigned int b = si::next_power_of_two<unsigned int>(a);
    std::printf("next power of two for %u is %u\n", a, b);
    return 0;
}


