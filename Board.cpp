#include <iostream>
#include <string>
#include "Board.hpp"
#include "Direction.hpp"
#include <unordered_map>


using namespace std;

namespace ariel{

    Board::Board(){
        max_row = 0;
        max_col = 0;
        min_row = UINT32_MAX;
        min_col = UINT32_MAX;
    }

    void Board::update_row_col(unsigned int row, unsigned int col){
        if(row > max_row){
             max_row = row;
        }
        if(row < min_row){
            min_row = row;
        }
        
        if(col > max_col){
            max_col = col;
        }
        if(col < min_col){
            min_col = col;
        }
    }

    void Board::post(unsigned int row, unsigned int col, Direction direction, string words){

        if(words.length() == 0){
            return;
        }
    
        update_row_col(row, col);
        unsigned int length = words.length();
        unsigned int index = 0;

        if(direction == Direction::Horizontal){
            unsigned int temp_col = col+length-1;
            update_row_col(max_row, temp_col);
           
            while (index < length){
                board_map[row][col++] = words.at(index);
                index++;
            }

        }else{
            unsigned int temp_row = row+length-1;
             update_row_col(temp_row, max_col);

            while (index < length){
                board_map[row++][col] = words.at(index);
                index++;
            }
        }
    }

    string Board::read(unsigned int row, unsigned int col, Direction direction, unsigned int num_characters){
        unsigned int index = 0;
        string print_str;

        if(direction == Direction::Horizontal){
            while (index<num_characters){
                if(board_map[row][col] == '\0'){
                    print_str += "_";
                    col++;
                }else{
                print_str += board_map[row][col++];
                }
                index++;
            }

        }else{
             while (index<num_characters){
                 if(board_map[row][col] == '\0'){
                     print_str += "_";
                     row++;
                 }else{
                print_str += board_map[row++][col];
                 }
                index++;
            }
        }
        return print_str;
        }

    void Board::show(){
        for(unsigned int i=min_row; i <= max_row; i++){
            for(unsigned int j=min_col; j<= max_col; j++){
                if(board_map[i][j]== '\0'){
                    cout<<"_";
                }else{
                cout<<Board::board_map[i][j];
                }
            }
            cout<<"\n";
        }
    }
    };