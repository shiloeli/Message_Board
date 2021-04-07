#include <iostream>
#include <string>
#include "Board.hpp"
#include "Direction.hpp"

using ariel::Direction;
using namespace std;

int main(){

ariel::Board board;

	board.post(/*row=*/100, /*column=*/200, Direction::Horizontal, "_");
    board.post(/*row=*/100, /*column=*/214, Direction::Horizontal, "_");
    board.post(/*row=*/101, /*column=*/204, Direction::Horizontal, "Welcome");
    board.post(/*row=*/102, /*column=*/207, Direction::Horizontal, "to");
    board.post(/*row=*/103, /*column=*/207, Direction::Horizontal, "my");
    board.post(/*row=*/104, /*column=*/204, Direction::Horizontal, "projet!");
    board.post(/*row=*/105, /*column=*/200, Direction::Horizontal, "_");

    
    board.show();
    cout<<"\n";

	cout << board.read(/*row=*/101, /*column=*/204, Direction::Horizontal, /*length=*/7) << endl; 
    cout << board.read(/*row=*/102, /*column=*/207, Direction::Horizontal, /*length=*/2) << endl; 
    cout << board.read(/*row=*/103, /*column=*/207, Direction::Horizontal, /*length=*/2) << endl;
    cout << board.read(/*row=*/104, /*column=*/204, Direction::Horizontal, /*length=*/7) << endl;
}