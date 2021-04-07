#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include "Direction.hpp"

namespace ariel{
    class Board{
        std::unordered_map<unsigned int,std::unordered_map<unsigned int, char>> board_map;
        unsigned int max_row;
        unsigned int max_col;
        unsigned int min_row;
        unsigned int min_col;
        void update_row_col(unsigned int row, unsigned int col);
        
        public:
        Board();
        void post(unsigned int row, unsigned int col, Direction direction, std::string words);
        std::string read(unsigned int row, unsigned int col, Direction direction, unsigned int num_characters);
        void show();
    };
};