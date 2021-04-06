#include <iostream>
#include <map>
#include <cstdlib>
#include "Direction.hpp"
#pragma once
using namespace std;


namespace ariel{
    class Board{
        public:
        
            Board();
            ~Board();
            void post ( u_int x, u_int y, Direction dir,string info);
            string read ( u_int x, u_int y, Direction dir, u_int len);
            void show();

        private:
            map< u_int, map <u_int, char> > myMap; 

        };
};
