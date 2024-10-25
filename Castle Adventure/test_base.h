#ifndef TEST_BASE_H
#define TEST_BASE_H

#include <string>
#include <iostream>
#include <stdexcept>
#include <functional>
#include <type_traits>
#include <sstream>

#include "ansi_color.h"

#define assert_true_quiet(expression) \
    do {\
        if ((expression) == false) {\
            TestBase::fail(#expression, __FILE__, __LINE__); \
        }\
        else\
        {\
            TestBase::inc_passed();\
        }\
    } while (false)

#define TEST_PASS(message) pass_e(message, __FILE__, __LINE__)
#define TEST_FAIL(message) fail_e(message, __FILE__, __LINE__)

#define assert_true(expression) \
    do {\
        if ((expression)) {\
            TestBase::pass(#expression, __FILE__, __LINE__); \
        }\
        else {\
            TestBase::fail(#expression, __FILE__, __LINE__); \
        }\
    } while (false)

#define assert_expression_throws(exception, expression) \
    TestBase::assert_throws<exception>([]() { expression; }, "expression ("#expression ") ", #exception, __FILE__, __LINE__)

#define assert_object_expression_throws(exception, object, expression) \
    TestBase::assert_throws<exception>([&object]() { expression; }, "expression ("#expression ") ", #exception, __FILE__, __LINE__)

#define assert_function_throws(exception, function) \
    TestBase::assert_throws<exception>(function, "function "#function "() ", #exception, __FILE__, __LINE__)


class TestBase
{
    private:
        static size_t m_passed;
        static size_t m_failed;
    protected:
        static void pass_e(const std::string & msg, const std::string & file = "", unsigned int line = 0);
        static void fail_e(const std::string & msg, const std::string & file = "", unsigned int line = 0);
        static void pass(const std::string & expression, const std::string & file = "", unsigned int line = 0);
        static void fail(const std::string & expression, const std::string & file = "", unsigned int line = 0);

        template <typename ExceptionType>
        void assert_throws(std::function<void()> function, const std::string & expression, const std::string & exception,
            const std::string & file = "", unsigned int line = 0);

    public:
        TestBase() {};
        static void inc_passed() { m_passed++; }
        static void inc_failed() { m_failed++; }
        static void results ();
        static size_t getNumFailed() { return m_failed; }

        virtual void run_tests() = 0;

};

// Function to assert that a given function throws a specific exception type
template <typename ExceptionType>
void TestBase::assert_throws(std::function<void()> function, const std::string & expression,  const std::string & exception,
    const std::string& file, unsigned int line) 
{
    try {
        // Call the function
        function();
        // If no exception is thrown, the test fails
        TestBase::fail_e(expression + "did not throw expected exception " + exception, file, line);
    } catch (const ExceptionType& e) {
        // If the expected exception type is thrown, the test passes
        TestBase::pass_e(expression + "threw " + exception + " as expected.", file, line);
    } catch (...) {
        // If an unexpected exception type is thrown, the test fails
        TestBase::fail_e(expression + "threw unexpected exception.", file, line);
    }
}

#endif