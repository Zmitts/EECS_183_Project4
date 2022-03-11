/**
 * Copyright 2019 University of Michigan EECS183
 *
 * test.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * Project 4: Battleship
 *
 * Contains functions for testing classes in the project.
 */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "Position.h"
#include "Ship.h"
#include "Player.h"
#include "Game.h"
#include "utility.h"

using namespace std;


void test_position();
void test_ship();
void test_player();
void test_game();

void startTests() {
   // test_position();
    test_ship();
    test_player();

    return;
}

void test_position() {
        cout << "testing check_range: ";
        Position test5;
        test5.write(cout);
        cout << endl;
        Position test(3, 10);
        Position test1('3', 'C');
        Position test2('4', 'c');
        test.write(cout);
        cout << endl;
        test1.write(cout);
        cout << endl;
        test2.write(cout);

        cout << "testing read: ";
        Position test3;
        Position test4;
        test3.read(cin);
        test3.write(cout);
        cout << endl;
        // testing Position default constructor here
        Position start_pos;
        Position end_pos;
        cout << "Testing Position::Position() - default constructor\n";
        cout << "start_pos, expected output: (1,A) actual output: " << start_pos << endl;
        cout << "end_pos, expected output: (1,A) actual output: " << end_pos << endl;

        // testing Position setters here
        start_pos.set_row(4);
        start_pos.set_col(5);
        test4.set_row(1);
        test4.set_col(3);

        cout << "\nTesting Position::set_row() and Position::set_col()\n";
        cout << "start_pos, expected output: (5,F) actual output: " << start_pos << endl;

        cout << "start_pos, expected output: (2,D) actual output: " << test4 << endl;

        // testing Position read
        ifstream input_file;
        input_file.open("grid1.txt");
        if (input_file.good()) {
            // can use the Position::read() function directly
            start_pos.read(input_file);

            // or use the extraction operator
            input_file >> end_pos;

            cout << "\nTesting Position::read()\n";
            cout << "start_pos, expected output: (1,A) actual output: " << start_pos << endl;
            cout << "end_pos, expected output: (4,A) actual output: " << end_pos << endl;
        }
        else {
            cout << "\nError opening grid1.txt\n";
        }

        return;
}

void test_ship() {
    // Write your tests here
    Ship test; 
    cout << "Testing defalt exprect (1, A)(1, A) actual: " << test.get_start() << test.get_end() << endl;

    
    Position start(2, 8);
    Position end(0, 8);
    Ship test1(start, end);
    cout << "testing custom construnctor expected (3, H)(1, H) actual: " << test1.get_start() << test1.get_end() << endl;
    
    Position start1(0, 0);
    Position end1(0, 3);
    Ship test2(start1, end1);
    cout << "testing is_horziontal expect 01 actual: " << test1.is_horizontal() << test2.is_horizontal() << endl;

    Position pos(0, 1);
    Position start2(0, 3);
    Position end2(0, 0);
    Ship test3(start2, end2);
    cout << "testing has_position expected 101 actual: " << test2.has_position(pos) << test1.has_position(pos) << test3.has_position(pos) << endl;

    return;
}

void test_player() {
    // Write your tests here
    return;
}

