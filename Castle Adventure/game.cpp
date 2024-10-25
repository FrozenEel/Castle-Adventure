#include <iostream>
#include <string>
#include <stdexcept>
#include "room.h"
#include "ansi_color.h"
#include "test_random.h"
#include "test_castle.h"

void parse_command_line(int argc, char* argv[], std::string &output_file, bool& doTest);
void usage(const std::string & me);
void run_tests();


int main(int argc, char* argv[])
{
    std::string output_file;
    bool doTest = false;

    try
    {
        parse_command_line(argc, argv, output_file, doTest);
        if (doTest)
        {
            run_tests();
        }
        else
        {
            Castle the_castle;
            std::cout << "Generating castle..." << std::endl;
            the_castle.generate();
            std::cout << "Saving to "<< output_file << "..." << std::endl;
            the_castle.save(output_file);
        }
    }
    catch(const std::invalid_argument& e)
    {
        std::cerr << Color::BgRed << "ERROR:" << Color::Red << " " << e.what() << Color::Reset << std::endl;
        usage(argv[0]); 
    }
    catch(...)
    {
        std::cerr << Color::BgRed << "UNHANDLED ERROR. PROGRAM ABORTED" << Color::Reset << std::endl;
    }

    return 0;
}

void usage(const std::string & me)
{
    std::cerr << "Usage:" << std::endl;
    std::cerr << me << " [<output_file>] [--test]" << std::endl;
}

void run_tests()
{
    std::cout << Color::BrightBlue << "======= UNIT TESTS =======" << Color::Reset << std::endl;
    TestCastle castle_tests;
    castle_tests.run_tests();
    castle_tests.results();
}

void parse_command_line(int argc, char* argv[], std::string &output_file, bool& doTest)
{
    bool got_output_file = false;
    for (int i = 1; i < argc; i++)
    {
        std::string arg {argv[i]};
        if (arg == "--test")
        {
            if (doTest == false)
            {
                doTest = true;
            }
            else
            {
                throw std::invalid_argument("--test specified twice. Why?");
            }
        }
        else if (got_output_file == false)
        {
            got_output_file = true;
            output_file = argv[i];
        }
        else
        {
            throw std::invalid_argument("Extra argument \"" + arg + "\".");
        }
    }
    if (got_output_file == false && doTest == false)
    {
        throw std::invalid_argument("You must specify either an output file or --test");
    }
}
