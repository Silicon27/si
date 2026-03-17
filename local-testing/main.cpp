//
// Created by David Yang on 2025-05-30.
//
#include <iostream>
#include <cassert>
#include "../include/si/vector.hpp"
#include "../include/si/type_traits.hpp"
#include "../include/si/memory.hpp"
#include "../include/si/stddef.hpp"
#include "../include/si/string.hpp"
#include "../include/si/utility.hpp"
#include "../include/si/pointer.hpp"
#include "../include/si/log.hpp"

void test_vector() {
    std::cout << "Testing si::vector..." << std::endl;
    si::vector<int> vec = {1, 2, 3, 4, 5};
    assert(vec.size() == 5);
    vec.append({6, 7, 8});
    assert(vec.size() == 8);
    
    vec.push_back(9);
    assert(vec.size() == 9);
    assert(vec[8] == 9);
    
    vec.reserve(20);
    assert(vec.capacity() >= 20);
    
    int sum = 0;
    for (int i : vec) sum += i;
    assert(sum == 45); // 1+2+3+4+5+6+7+8+9 = 45
    
    vec[2] = 100;
    assert(vec[2] == 100);

    const si::vector<int>& cvec = vec;
    assert(cvec[2] == 100);

    std::cout << "si::vector tests passed!" << std::endl;
}

void test_type_traits() {
    std::cout << "Testing si::type_traits..." << std::endl;
    static_assert(si::is_integral_v<int>, "int should be integral");
    static_assert(!si::is_integral_v<float>, "float should not be integral");
    static_assert(si::is_floating_point_v<double>, "double should be floating point");
    static_assert(si::is_arithmetic_v<int>, "int should be arithmetic");
    static_assert(si::is_arithmetic_v<float>, "float should be arithmetic");
    
    static_assert(si::is_same_v<si::remove_const_t<const int>, int>, "remove_const failed");
    static_assert(si::is_pointer_v<int*>, "int* should be a pointer");
    static_assert(si::is_reference_v<int&>, "int& should be a reference");
    
    static_assert(si::is_void_v<void>, "void should be void");
    static_assert(si::is_null_pointer_v<si::nullptr_t>, "nullptr_t should be null pointer");
    
    std::cout << "si::type_traits tests passed!" << std::endl;
}

void test_stddef() {
    std::cout << "Testing si::stddef..." << std::endl;
    si::size_t s = 10;
    si::ptrdiff_t p = 5;
    si::nullptr_t n = nullptr;
    (void)s; (void)p; (void)n;
    std::cout << "si::stddef tests passed!" << std::endl;
}

void test_memory() {
    std::cout << "Testing si::memory..." << std::endl;
    si::allocator<int> alloc;
    int* ptr = alloc.allocate(5);
    assert(ptr != nullptr);
    alloc.deallocate(ptr, 5);
    std::cout << "si::memory tests passed!" << std::endl;
}

void test_string() {
    std::cout << "Testing si::string..." << std::endl;
    si::string str;
    // basic_string is very minimal currently, just testing instantiation
    (void)str;
    std::cout << "si::string tests passed!" << std::endl;
}

void test_utility() {
    std::cout << "Testing si::utility..." << std::endl;
    int x = 10;
    int&& r = si::move(x);
    assert(&r == &x);
    std::cout << "si::utility tests passed!" << std::endl;
}

void test_log() {
    std::cout << "Testing si::log..." << std::endl;
    
    // Test global functions
    si::info("Testing global info: %d", 42);
    si::warn("Testing global warn: %s", "hello");
    
    // Test ostream interface
    si::info() << "Ostream style log: " << 123 << " and " << 3.14;
    si::error() << "Ostream error message!";
    
    // Test ostream_sink with std::cerr
    auto cerr_sink = std::make_shared<si::ostream_sink>(std::cerr);
    si::default_logger().add_sink(cerr_sink);
    si::info("This message should also appear on cerr");
    
    // Test backtracing
    si::enable_backtrace(5);
    for (int i = 0; i < 10; ++i) {
        si::debug("Backtrace message %d", i);
    }
    si::info("Now dumping backtrace (should only show messages 5-9):");
    si::dump_backtrace();
    
    si::logger log;
    
    auto stdout_sink = std::make_shared<si::stdout_sink>();
    stdout_sink->set_level(si::log_level::TRACE);
    log.add_sink(stdout_sink);
    
    auto file_sink = std::make_shared<si::file_sink>("test_log.txt");
    file_sink->set_level(si::log_level::INFO);
    log.add_sink(file_sink);
    
    log.trace("Trace message: %d", 1);
    log.debug("Debug message: %s", "hello");
    log.info("Info message: float %f", 3.14);
    log.warn("Warning message");
    log.error("Error message");
    log.fatal("Fatal error: memory at %p", (void*)0xDEADBEEF);
    
    log.flush();
    
    if (file_sink->is_open()) {
        std::cout << "Log written to test_log.txt" << std::endl;
    } else {
        std::cout << "Failed to open test_log.txt" << std::endl;
    }
    
    std::cout << "si::log tests passed (visual check for colors above)!" << std::endl;
}

int main() {
    test_vector();
    test_type_traits();
    test_stddef();
    test_memory();
    test_string();
    test_utility();
    test_log();
    
    std::cout << "\nAll tests completed successfully!" << std::endl;
    return 0;
}
