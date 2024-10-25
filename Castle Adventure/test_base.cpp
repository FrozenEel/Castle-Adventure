#include "test_base.h"

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <functional>
#include <type_traits>
#include <sstream>

#include "ansi_color.h"

/*static */ size_t TestBase::m_passed = 0;
/*static */ size_t TestBase::m_failed = 0;

void TestBase::pass_e(const std::string & msg, const std::string & file, unsigned int line)
{
    std::cerr << Color::BrightGreen;
    if (file != "" && line != 0)
    {
        std::cerr << file << ":" << line << " - ";
    }
    std::cerr << msg << " PASS" << Color::Reset << std::endl;
    inc_passed();
}

void TestBase::fail_e(const std::string & msg, const std::string & file, unsigned int line)
{
    std::cerr << Color::BrightRed;
    if (file != "" && line != 0)
    {
        std::cerr << file << ":" << line << " - ";
    }
    std::cerr << msg << " " << Color::BgBrightRed << "FAIL"  << Color::Reset << std::endl;
    inc_failed();
}

void TestBase::pass(const std::string & expression, const std::string & file, unsigned int line)
{
    pass_e("expression (" + expression + ") is true.", file, line);
}

void TestBase::fail(const std::string & expression, const std::string & file, unsigned int line)
{
    fail_e("expression (" + expression + ") is not true.", file, line);
}

void TestBase::results ()
{
    std::cout << "Test Results: " << std::endl
              << std::left << std::setw(5) << m_passed << " assertions passed" << std::endl;
    if (m_failed > 0)
    {
        std::cout << Color::BgBrightRed;
    }
    std::cout << std::left << std::setw(5) << m_failed << " assertions failed" << Color::Reset << std::endl;
    std::cout << std::left << std::setw(5) << m_passed + m_failed << " total assertions" << std::endl;

}