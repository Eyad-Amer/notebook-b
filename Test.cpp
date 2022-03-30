/**
 * Unit tests.
 *
 * AUTHORS: Eyad Amer
 * Date:  2021-03
 */

#include "doctest.h"
#include "Notebook.hpp"
using namespace ariel;

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
using namespace std;
using ariel::Direction;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}

// Good inputs and results
TEST_CASE("Good inputs and results")
{
    Notebook note;

    CHECK(note.read(0, 0, 0, Direction::Horizontal, 4).compare("____"));
    CHECK(note.read(0, 0, 0, Direction::Horizontal, 4).compare("abcd"));
    //note.write(0, 0, 0, Direction::Horizontal, "abcd");
    CHECK(note.read(0, 0, 0, Direction::Horizontal, 4).compare("abcd"));
    //note.erase(0, 0, 0, Direction::Horizontal, 4);
    CHECK(note.read(0, 0, 0, Direction::Horizontal, 4).compare("~~~~"));

    //note.write(0, 0, 5, Direction::Horizontal, "a");
    CHECK(note.read(0, 0, 5, Direction::Horizontal, 4).compare("a___"));
   // note.erase(0, 0, 5, Direction::Horizontal, 1);
    CHECK(note.read(0, 0, 5, Direction::Horizontal, 4).compare("~___"));
}

// Bad inputs - column length > 100  lenghe sting > 100
TEST_CASE("Bad input - line length is greater than 100")
{
    Notebook note;
    
    // check for the write function
    CHECK_THROWS(note.write(2, 5, 101, Direction::Vertical, "abcd"));
    // writing a string length > 100
    CHECK_THROWS(note.write(0, 0, 0, Direction::Horizontal, "abcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghija")); 
    CHECK_THROWS(note.write(0, 0, 101, Direction::Horizontal, "abcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghijabcdefghija"));                                                          

    // check for the read function
    CHECK_THROWS(note.read(2, 3, 101, Direction::Horizontal, 0));
    // reading a string length > 100
    CHECK_THROWS(note.read(2, 3, 3, Direction::Horizontal, 101));
    CHECK_THROWS(note.read(2, 3, 102, Direction::Horizontal, 101));

    // check for the erase function
    CHECK_THROWS(note.erase(6, 5, 102, Direction::Vertical, 0));
    // erasing a string length > 100
    CHECK_THROWS(note.erase(2, 3, 3, Direction::Horizontal, 101));
    CHECK_THROWS(note.erase(6, 5, 102, Direction::Horizontal, 101));
    
}

// Bad inputs - Negetave number
TEST_CASE("Bad input - Negetave number in the input")
{
    Notebook note;

        // check for the write function
        CHECK_THROWS(note.write(-1, 2, 5, Direction::Vertical, "abcd"));
        CHECK_THROWS(note.write(2, -1, 3, Direction::Horizontal, "aerf"));
        CHECK_THROWS(note.write(0, 1, -1, Direction::Horizontal, "ddf"));
        CHECK_THROWS(note.write(-1, -1, 8, Direction::Vertical, "hyu"));
        CHECK_THROWS(note.write(0, -1, -1, Direction::Horizontal, "a"));
        CHECK_THROWS(note.write(-1, 3, -1, Direction::Vertical, "b"));
        CHECK_THROWS(note.write(-1, -1, -1, Direction::Horizontal, "bad input"));

        // check for the read function
        CHECK_THROWS(note.read(-1, 2, 5, Direction::Vertical, 2));
        CHECK_THROWS(note.read(2, -1, 3, Direction::Horizontal, 0));
        CHECK_THROWS(note.read(0, 1, -1, Direction::Horizontal, 5));
        CHECK_THROWS(note.read(-1, -1, 8, Direction::Vertical, 5));
        CHECK_THROWS(note.read(0, -1, -1, Direction::Horizontal, 7));
        CHECK_THROWS(note.read(-1, 3, -1, Direction::Vertical, 0));
        CHECK_THROWS(note.read(-1, -1, -1, Direction::Horizontal, 1));
        CHECK_THROWS(note.read(-1, 2, 5, Direction::Vertical, -2));
        CHECK_THROWS(note.read(2, -1, 3, Direction::Horizontal, -3));
        CHECK_THROWS(note.read(0, 1, -1, Direction::Horizontal, -5));
        CHECK_THROWS(note.read(-1, -1, 8, Direction::Vertical, -5));
        CHECK_THROWS(note.read(0, -1, -1, Direction::Horizontal, -7));
        CHECK_THROWS(note.read(-1, 3, -1, Direction::Vertical, -1));
        CHECK_THROWS(note.read(-1, -1, -1, Direction::Horizontal, -1));

        // check for the erase function
        CHECK_THROWS(note.erase(-1, 2, 5, Direction::Vertical, 2));
        CHECK_THROWS(note.erase(2, -1, 3, Direction::Horizontal, 0));
        CHECK_THROWS(note.erase(0, 1, -1, Direction::Horizontal, 1));
        CHECK_THROWS(note.erase(-1, -1, 8, Direction::Vertical, 5));
        CHECK_THROWS(note.erase(0, -1, -1, Direction::Horizontal, 7));
        CHECK_THROWS(note.erase(-1, 3, -1, Direction::Vertical, 0));
        CHECK_THROWS(note.erase(-1, -1, -1, Direction::Horizontal, 1));
        CHECK_THROWS(note.erase(-1, 2, 5, Direction::Vertical, -2));
        CHECK_THROWS(note.erase(2, -1, 3, Direction::Horizontal, -5));
        CHECK_THROWS(note.erase(0, 1, -1, Direction::Horizontal, -1));
        CHECK_THROWS(note.erase(-1, -1, 8, Direction::Vertical, -5));
        CHECK_THROWS(note.erase(0, -1, -1, Direction::Horizontal, -7));
        CHECK_THROWS(note.erase(-1, 3, -1, Direction::Vertical, -3));
        CHECK_THROWS(note.erase(-1, -1, -1, Direction::Horizontal, -1));

        // check for the show function
        CHECK_THROWS(note.show(-1));
}


// Bad reading results 
TEST_CASE("Wrong reading results")
{
    Notebook note;

    // Bad results of reading string - write function
    note.write(0, 0, 0, Direction::Horizontal, "abcd");
    CHECK(note.read(0, 0, 0, Direction::Horizontal, 4).compare("efgh"));

    // Bad results of reading string - erase function
    note.erase(0, 0, 0, Direction::Horizontal, 4);
    CHECK(note.read(0, 0, 0, Direction::Horizontal, 4).compare("efgh"));

}

// illegal characters input
TEST_CASE("illegal writing characters input")
{
    Notebook note;

    // illegal input
    CHECK_THROWS(note.write(1, 2, 3, Direction::Vertical, "~"));
    CHECK_THROWS(note.write(1, 4, 3, Direction::Vertical, "\n"));
    CHECK_THROWS(note.write(1, 4, 3, Direction::Vertical, "\r"));

}


// Bad inputs - writing on a written or deleted place
TEST_CASE("writing on a written or deleted same place")
{
    Notebook note;

    CHECK_NOTHROW(note.write(0, 0, 0, Direction::Horizontal, "efgh"));
    CHECK_NOTHROW(note.write(0, 0, 0, Direction::Horizontal, "efgh")); // writing on a written plac - Horizontal
    CHECK_NOTHROW(note.write(0, 0, 0, Direction::Vertical, "efgh")); // writing on a written plac - Vertical

    CHECK_NOTHROW(note.write(0, 0, 0, Direction::Horizontal, "efgh"));
    CHECK_NOTHROW(note.write(0, 0, 0, Direction::Horizontal, "efgh")); // writing on a deleted place - Horizontal
    CHECK_NOTHROW(note.write(0, 0, 0, Direction::Vertical, "efgh")); // writing on a deleted place - Vertical



}

// Bad results - The length of the string > length of the line
TEST_CASE("The length of the string exceeds the length of the line")
{
    Notebook note;

    // write function
    CHECK_THROWS(note.write(0, 0, 98, Direction::Horizontal, "abcd"));
    CHECK_THROWS(note.write(0, 0, 96, Direction::Horizontal, "abcdefg"));
    
    // read function
    CHECK_THROWS(note.read(0, 0, 98, Direction::Horizontal, 4));
    CHECK_THROWS(note.read(0, 0, 96, Direction::Horizontal, 7));

    // erase function
    CHECK_THROWS(note.erase(0, 0, 98, Direction::Horizontal, 4));
    CHECK_THROWS(note.erase(0, 0, 96, Direction::Horizontal, 7));

}
