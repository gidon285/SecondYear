#include "Direction.hpp"
#include "Board.hpp"
using namespace std;

void ariel::Board::post(u_int x, u_int y, Direction dir,string info)
{
    u_int len = info.length();
    if (dir == Direction::Horizontal){

        for (u_int i = 0; i < len; i++){

            this->myMap[x][y + i] = info.at(i);
        }
        return;
    }
    for (u_int i = 0; i < len; i++){

        this->myMap[x + i][y] = info.at(i);
    }
}
string ariel::Board::read(u_int x, u_int y, Direction dir, u_int len)
{
    string ans;
    if (dir == Direction::Horizontal){
        for (u_int i =0; i < len ; i++){

            if(this->myMap.find(x) == this->myMap.end() || this->myMap[x].find(y+i) == this->myMap[x].end() ) {
                
                ans += "_";

            }else{
                ans += this->myMap[x][y+i];
            }
        }

        return ans;
    }

    for (u_int i =0; i < len ; i++){

        if(this->myMap.find(x+i) == this->myMap.end() || this->myMap[x+i].find(y) == this->myMap[x+i].end() ) {
            
            ans += "_";

        }else{
            ans += this->myMap[x+i][y];
        }
    }   

    return ans;

}
ariel::Board::Board(){
}
ariel::Board::~Board(){
}
void ariel::Board::show(){

    for (u_int i = 0; i < this->myMap.size(); i++){
        string line;
        for (u_int j = 0; j < this->myMap[i].size(); j++){
            line += this->myMap[i][j];
        }
        cout << line << endl;
    }
}