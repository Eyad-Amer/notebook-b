/**
 * Notebook function
 * 
 * Author: Eyad Amer
 * Since : 2022-03
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "Direction.hpp"
#include "Notebook.hpp"

using namespace std;
using ariel::Direction;

const int Maxcol = 100; // Maximum line length
const int start = 0;
const char empty = '_';

namespace ariel
{

    Notebook note;

    // Construction.
    Notebook::Notebook(){

    }

    // Destruction.
    Notebook::~Notebook(){

    }

    // Write the string in a notebook in the appropriate place.
    void Notebook::write(int page, int row, int column, Direction dir, const string &str){
        // if the inputs is Negetave number
        if(page < 0 || row < 0 || column < 0){
            throw invalid_argument("illegal inputs - Negetave number in the input!");
        }

        // if the line length is greater than 100
        if(column > Maxcol){
            throw invalid_argument("illegal input - line length is greater than 100!");
        }

        // if the input string length greater than 100
        if(str.length() > Maxcol){
            throw invalid_argument("illegal input - writing string length greater than 100!");
        }

        // if the input string is illegal input
        if(str == "~" || str == "\n" || str == "\r"){
            throw invalid_argument("illegal writing characters input!");
        } 

        // if the length of the string exceeds the length of the line
        if(column + (int)str.length() > Maxcol){
            throw invalid_argument("illegal inputs - the length of the string exceeds the length of the line!");
        }
/*
        // if the write function is writing on a written or deleted same place
        if(note.read(page, row, column, dir, str.length()).compare(str) != 0){
            throw invalid_argument("Wrong reading results!");
        }*/
    }

    // Reads what is written in the notebook in the given position and length, and returns a string.
    string Notebook::read(int page, int row, int column, Direction dir, int length){
        // if the inputs is Negetave number
        if(page < 0 || row < 0 || column < 0 || length < 0){
            throw invalid_argument("illegal inputs - Negetave number in the input!");
        }

        // if the line length is greater than 100
        if(column > Maxcol){
            throw invalid_argument("illegal input - line length is greater than 100!");
        }

        // if the input string length greater than 100
        if(length > Maxcol){
            throw invalid_argument("illegal input - reading string length greater than 100!");
        }

        // if the length of the string exceeds the length of the line
        if(column + length > Maxcol){
            throw invalid_argument("illegal inputs - the length of the string exceeds the length of the line!");
        }

        return "";
    }

    // Deletes what is written in the relevant location and direction.
    void Notebook::erase(int page, int row, int column, Direction dir, int length){
        // if the inputs is Negetave number
        if(page < 0 || row < 0 || column < 0 || length < 0){
            throw invalid_argument("illegal inputs - Negetave number in the input!");
        }

        // if the line length is greater than 100
        if(column > Maxcol){
            throw invalid_argument("illegal input - line length is greater than 100!");
        }

        // if the input string length greater than 100
        if(length > Maxcol){
            throw invalid_argument("illegal input - erasing string length greater than 100!");
        }

        // if the length of the string exceeds the length of the line
        if(column + length > Maxcol){
            throw invalid_argument("illegal inputs - the length of the string exceeds the length of the line!");
        }
    }

    // shows the notebook's page in a reasonable way.
    void Notebook::show(int page){
        // if the input page is Negetave number
        if(page < 0){
            throw invalid_argument("illegal inputs - Negetave number in the input!");
        }
    }
    
} // namespace ariel
