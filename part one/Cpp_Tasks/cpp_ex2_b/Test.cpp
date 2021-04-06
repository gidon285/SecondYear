#include "doctest.h"
#include <iostream>
#include "Board.hpp"
using namespace ariel;

TEST_CASE("Bad / Good input for makeing Message-Board"){

    for (int i =0 ; i < 5; i++){
        for (int j = 2; j < 4; j++)
        {
            CHECK_THROWS(Board board(i,j));
        }
    }

    for (int i = 0; i < 5; i++){

        int a  = rand() % 20 + 5;
        int b  = rand() % 20 + 5;
        CHECK_NOTHROW(Board board(a,b));
        
    }

}
TEST_CASE("Post Read tests!"){

    std::string txt = "seperjon"; // txt for testing.
    int size = txt.length();      // txt size.
    // Bad input!
    Board board(6,6);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            CHECK_THROWS(board.post(i,j,Direction::Horizontal, txt));
        }

    }
    // Good input

    Board board1;
    for(int i = 0 ; i < 5 ; i++){
        board1.post(i,i,Direction::Vertical,txt);
        CHECK(txt == board1.read(i,i,Direction::Vertical,size));
    }

    Board board2(600,600);
    board2.post(100,100,Direction::Horizontal, txt);
    CHECK( txt == board2.read(100,100,Direction::Horizontal,size));

    for( int i =0 ; i < 5 ; i++){
        board2.post(100+(i*10),100+(i*10),Direction::Horizontal, txt);
        CHECK( txt == board2.read(100+(i*10),100+(i*10),Direction::Horizontal,size));
    }

    Board board3(600,600);
    board3.post(100,100,Direction::Vertical, txt);
    CHECK( txt == board3.read(100,100,Direction::Vertical,size));

    for( int i =0 ; i < 5 ; i++){
        board3.post(100+(i*10),100+(i*10),Direction::Vertical, txt);
        CHECK( txt == board3.read(100+(i*10),100+(i*10),Direction::Vertical,size));
    }


}


