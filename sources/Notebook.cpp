/**
 * Notebook function
 *
 * Author: Eyad Amer
 * Since : 2022-03
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include "Direction.hpp"
#include "Notebook.hpp"

using namespace std;
using ariel::Direction;

const int Maxcol = 100;   // maximum line length
const int Start = 0;      // starting Line
const int MinAscii = 32;  // minimum llegal input
const int MaxAscii = 126; // maximum llegal input

namespace ariel
{

    // Construction.
    Notebook::Notebook()
    {
    }

    // Destruction.
    Notebook::~Notebook()
    {
    }

    // Write the string in a notebook in the appropriate place.
    void Notebook::write(int page, int row, int column, Direction dir, const string &str)
    {

        // if the inputs is Negetave number
        if (page < Start || row < Start || column < Start)
        {
            throw invalid_argument("illegal inputs - Negetave number in the input!");
        }

        // if the line length is greater than 100
        if (column >= Maxcol)
        {
            throw invalid_argument("illegal input - line length is greater than 100!");
        }

        // if the input string is illegal input
        for (unsigned long i = 0; i < str.length(); i++)
        {
            char c = str[i];
            if (c < MinAscii || c > MaxAscii || c == '~' || c == '\n' || c == '\r')
            {
                throw invalid_argument("illegal writing characters input!");
            }
        }

        // if the Direction input is illegal
        if (dir != Direction::Horizontal && dir != Direction::Vertical)
        {
            throw invalid_argument("illegal inputs - the Direction is illegal");
        }

        // if the input string length greater than 100
        if ((dir == Direction::Horizontal) && (str.length() >= Maxcol))
        {
            throw invalid_argument("illegal input - writing string length greater than 100!");
        }

        // if the length of the string exceeds the length of the line
        if ((dir == Direction::Horizontal) && (column + (int)str.length() >= Maxcol))
        {
            throw invalid_argument("illegal inputs - the length of the string exceeds the length of the line!");
        }

        // initialization the notebook
        if (this->notebook.find(page) == this->notebook.end())
        {
            for (int i = 0; i < Maxcol; i++)
            {
                notebook[page][row][i].empty = '_';
            }
        }

        // writing on Horizontal Direction
        if (dir == Direction::Horizontal)
        {
            for (unsigned long i = 0; i < str.length(); i++)
            {
                if (this->notebook[page][row][column].empty == '_')
                {
                    this->notebook[page][row][column++].empty = str[i];
                }
                else
                {
                    throw invalid_argument("illegal inputs - writing on a written or deleted same place!");
                }
            }
        }

        // writing on Vertical Direction
        if (dir == Direction::Vertical)
        {
            for (unsigned long i = 0; i < str.length(); i++)
            {
                if (this->notebook[page][row][column].empty == '_')
                {
                    this->notebook[page][row++][column].empty = str[i];
                }
                else
                {
                    throw invalid_argument("illegal inputs - writing on a written or deleted same place!");
                }
            }
        }
    }

    // Reads what is written in the notebook in the given position and length, and returns a string.
    string Notebook::read(int page, int row, int column, Direction dir, int length)
    {

        string StrReading = string(""); // the results

        // if the inputs is Negetave number
        if (page < Start || row < Start || column < Start || length < Start)
        {
            throw invalid_argument("illegal inputs - Negetave number in the input!");
        }

        // if the line length is greater than 100
        if (column >= Maxcol)
        {
            throw invalid_argument("illegal input - line length is greater than 100!");
        }

        // if the length of the string exceeds the length of the line
        if ((dir == Direction::Horizontal) && (column + length > Maxcol))
        {
            throw invalid_argument("illegal inputs - the length of the string exceeds the length of the line!");
        }

        // if the Direction input is illegal
        if (dir != Direction::Horizontal && dir != Direction::Vertical)
        {
            throw invalid_argument("illegal inputs - the Direction is illegal");
        }

        // initialization the notebook
        if (this->notebook.find(page) == this->notebook.end())
        {
            for (int i = 0; i < Maxcol; i++)
            {
                notebook[page][row][i].empty = '_';
            }
        }

        // reading horizontal direction
        if (dir == Direction::Horizontal)
        {
            for (int i = 0; i < length; i++)
            {
                StrReading += this->notebook[page][row][column++].empty;
            }
        }

        // reading vertical direction
        else if (dir == Direction::Vertical)
        {
            for (int i = 0; i < length; i++)
            {
                StrReading += this->notebook[page][row++][column].empty;
            }
        }
        return StrReading;
    }

    // Deletes what is written in the relevant location and direction.
    void Notebook::erase(int page, int row, int column, Direction dir, int length)
    {
        // if the inputs is Negetave number
        if (page < Start || row < Start || column < Start || length < Start)
        {
            throw invalid_argument("illegal inputs - Negetave number in the input!");
        }

        // if the line length is greater than 100
        if (column >= Maxcol)
        {
            throw invalid_argument("illegal input - line length is greater than 100!");
        }

        // if the input string length greater than 100
        if ((dir == Direction::Horizontal) && (length >= Maxcol))
        {
            throw invalid_argument("illegal input - writing string length greater than 100!");
        }

        // if the length of the string exceeds the length of the line
        if ((dir == Direction::Horizontal) && (column + length > Maxcol))
        {
            throw invalid_argument("illegal inputs - the length of the string exceeds the length of the line!");
        }

        // if the Direction input is illegal
        if (dir != Direction::Horizontal && dir != Direction::Vertical)
        {
            throw invalid_argument("illegal inputs - the Direction is illegal");
        }

        // initialization the notebook
        if (this->notebook.find(page) == this->notebook.end())
        {
            for (int i = 0; i < Maxcol; i++)
            {
                notebook[page][row][i].empty = '_';
            }
        }

        // erasing horizontal direction
        if (dir == Direction::Horizontal)
        {
            for (int i = 0; i < length; i++)
            {
                this->notebook[page][row][column++].empty = '~';
            }
        }

        // erasing vertical direction
        if (dir == Direction::Vertical)
        {
            for (int i = 0; i < length; i++)
            {
                this->notebook[page][row++][column].empty = '~';
            }
        }
    }

    // shows the notebook's page in a reasonable way.
    void Notebook::show(int page)
    {
        // if the input page is Negetave number
        if (page < 0)
        {
            throw invalid_argument("illegal inputs - Negetave number in the input!");
        }

        for (int i = 0; i < Maxcol; i++)
        {
            cout << read(page, i, 0, Direction::Horizontal, Maxcol) << "\n";
        }
    }
} // namespace ariel