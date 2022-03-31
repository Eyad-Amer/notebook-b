/**
 * Heading for Notebook
 *
 * Author: Eyad Amer
 * Since : 2022-03
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include "Direction.hpp"

using namespace std;
using ariel::Direction;

struct emptyLine
{
    char empty = '_';
};

// class Heading
namespace ariel
{
    class Notebook
    {

    private:
        unordered_map<int, unordered_map<int, unordered_map<int, emptyLine>>> notebook;

    public:
        Notebook();
        ~Notebook();
        void write(int page, int row, int column, Direction dir, const string &str);
        string read(int page, int row, int column, Direction dir, int length);
        void erase(int page, int row, int column, Direction dir, int length);
        void show(int page);
    };
} // namespace ariel