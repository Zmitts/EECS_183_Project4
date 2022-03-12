/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Position.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * <#Name#>
 * <#Uniqname#>
 *
 * Project 4: Battleship
 *
 * <#description#>
 */

#include "Position.h"
#include "utility.h"

const int ASCII_UPPER_CASE_VAL = 65;
const int ASCII_INT_VAL = 49;


Position::Position() {
    row = 0;
    col = 0;
}

Position::Position(int row_in, int col_in) {
    row = check_range(row_in);
    col = check_range(col_in);
    row = check_range(row);
    col = check_range(col);
}

Position::Position(char row_in, char col_in) {
    // TODO: write implementation here.
    row = (row_in)-ASCII_INT_VAL;
    col_in = toupper(col_in);
    col = col_in - ASCII_UPPER_CASE_VAL;
    row = check_range(row);
    col = check_range(col);


}

int Position::get_row() {
    return row;
}

void Position::set_row(int row_in) {
    row = check_range(row_in);
    row = check_range(row);
    return;
}

int Position::get_col() {
    return col;
}

void Position::set_col(int col_in) {
    col = check_range(col_in);
    col = check_range(col);
    return;
}

void Position::read(istream& is) {
    // TODO: write implementation here.
    char alphCol;
    char hold;
    is >> row; // 1
    if (is.fail()) { // (1, A)
        is.clear();
        is >> hold; // (
        is >> row; // 1
        is >> hold; // ,
        is >> alphCol; // A
        is >> hold;

    }
    else {
        is >> alphCol; // A
    }
    col = toupper(alphCol) - ASCII_UPPER_CASE_VAL;

    if (col < 0) {
        col = -col;
    }
    col = check_range(col);
    row--;
    row = check_range(row);
    return;
}

void Position::write(ostream& os) {
    int correctedRow = row + 1;



    char alphcol = col + ASCII_UPPER_CASE_VAL;
    os << "(" << correctedRow << ", " << alphcol << ")";

    return;
}

int Position::check_range(int val) {
    if (val >= 0 && val < MAX_GRID_SIZE) {
        return val;
    }
    else if ((abs(val) <= abs(val - (MAX_GRID_SIZE - 1)))) {
        return 0;
    }
    else {
        return MAX_GRID_SIZE - 1;
    }
}


// Your code goes above this line.
// Don't change the implementations below!

istream& operator>>(istream& is, Position& pos) {
    pos.read(is);
    return is;
}

ostream& operator<<(ostream& os, Position pos) {
    pos.write(os);
    return os;
}
