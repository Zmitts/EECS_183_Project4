/**
 * Copyright 2019 University of Michigan EECS183
 *
 * Ship.cpp
 * Project UID 8885f2d9f10d2f99bc099aa9c3fc0543
 *
 * <#Name#>
 * <#Uniqname#>
 *
 * Project 4: Battleship
 *
 * <#description#>
 */

#include <cmath>

#include "Ship.h"


Ship::Ship() {
    // TODO: write implementation here.
    start;
    end;
    num_hits = 0;
    size = 0;


}

Ship::Ship(Position start_in, Position end_in) {
    // TODO: write implementation here.
    num_hits = 0;
    start.set_row(start_in.get_row());
    start.set_col(start_in.get_col());
    end.set_row(end_in.get_row());
    end.set_col(end_in.get_col());

    if (!is_horizontal()) {
        size = abs(start.get_row() - end.get_row()) + 1;
    }
    else {
        size = abs(start.get_col() - end.get_col()) + 1;
    }



}

Position Ship::get_start() {
    // TODO: write implementation here.

    return start;
}

Position Ship::get_end() {
    // TODO: write implementation here.
    return end;
}

int Ship::get_size() {
    // TODO: write implementation here.
    return size;
}

bool Ship::is_horizontal() {
    // TODO: write implementation here.
    if (start.get_col() == end.get_col()) {
        return false;
    }
    else {
        return true;
    }

}

bool Ship::has_position(Position pos) { // this just doesn't work
    // TODO: write implementation here.
    if (!is_horizontal()) {
        if (start.get_row() > end.get_row()) {
            if (pos.get_col() == start.get_col() && pos.get_col() == end.get_col()
                && pos.get_row() <= start.get_row() && pos.get_row() >= end.get_row()) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if (pos.get_col() == start.get_col() && pos.get_col() == end.get_col()
                && pos.get_row() >= start.get_row() && pos.get_row() <= end.get_row()) {
                return true;
            }
            else {
                return false;
            }
        }


    }
    else {
        if (start.get_col() > end.get_col()) {
            if (pos.get_row() == start.get_row() && pos.get_row() == end.get_row()
                && pos.get_col() <= start.get_col() && pos.get_col() >= end.get_col()) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if (pos.get_row() == start.get_row() && pos.get_row() == end.get_row()
                && pos.get_col() >= start.get_col() && pos.get_col() <= end.get_col()) {
                return true;
            }
            else {
                return false;
            }
        }

    }

}

void Ship::hit() {
    // TODO: write implementation here.
    if (num_hits < size) {
        ++num_hits;
    }
    return;
}

bool Ship::has_sunk() {
    // TODO: write implementation here.
    if (num_hits == size) {
        return true;
    }
    else {
        return false;
    }
}
