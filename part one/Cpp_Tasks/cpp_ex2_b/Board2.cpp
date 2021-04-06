// #include "Direction.hpp"
// #include "Board.hpp"
// #include <vector>
// using namespace std;

// vector<char> vector_from_string(string str){
//     vector<char> temp(str.begin(), str.end());
//     return temp;
// }
// string string_from_vector(vector<char> &vec){
//     string ans;
//     for(u_int i = 0 ; i < vec.size()-1; i++){
//         ans += vec.at(i);
//     }
//     return ans;
// }
// string ariel::Board::make_generic_line (u_int length, u_int line_num) const{
  
//     u_int high = to_string(length).length();
//     u_int low = to_string(line_num).length();
//     u_int spaces = ( high - low);

//     string temp = '#'+to_string(line_num)+'.'+ string(spaces, ' ');
//     temp += string( (this->writeable_x) , '_')+'#';
    
//     return temp;

// }
// string ariel::Board::reconstruct_line( string line , u_int height, u_int line_num){

//     string ans;
//     u_int high = to_string(height).length();
//     u_int low = to_string(line_num-1).length();

//     u_int spaces = high - low;
//     ans = '#'+to_string(line_num-1)+'.'+ string(spaces, ' ');
//     u_int index = line.find_first_of('.');
//     while( isalpha(line.at(index)) == 0 &&  line.at(index) != '_'  ){
//         index++;
//     }
//     ans += line.substr(index,line.length())+'#';
//     return ans;

// }
// ariel::Board::Board(){

//     this->visable_x = base + extra_x;
//     this->visable_y = base + extra_y;
//     this->space = 1;
//     this->writeable_x = base + to_string(base).length() + extra_x;
//     this->writeable_y = base ;
    

//     vector<char> vicky;
//     string a_line;

//     a_line = string(this->writeable_x, '#');
//     vicky = vector_from_string(a_line);
//     this->matrix.push_back(vicky);

//     for( u_int i = 0 ; i < this->writeable_y; i++){
//         a_line = make_generic_line(this->writeable_x,i);
//         vicky = vector_from_string(a_line);
//         this->matrix.push_back(vicky);
//     }

//     a_line = string(this->writeable_x, '#');
//     vicky = vector_from_string(a_line);
//     this->matrix.push_back(vicky);


// }
// ariel::Board::Board(u_int width, u_int height){

//     this->visable_x = width + extra_x+ to_string(height).length();
//     this->visable_y = height + extra_y;
//     this->space = to_string(height).length() - 1;
//     this->writeable_x = width ;
//     this->writeable_y = height  ;

//     string a_line;
//     vector<char> vicky;

//     a_line = string(this->visable_x ,'#');
//     vicky = vector_from_string(a_line);
//     this->matrix.push_back(vicky);

//     for( u_int i = 0 ; i < this->writeable_y; i++){
//         a_line = make_generic_line(this->writeable_y,i);
//         vicky = vector_from_string(a_line);
//         this->matrix.push_back(vicky);
//     }

//     a_line = string(this->visable_x, '#');
//     vicky = vector_from_string(a_line);
//     this->matrix.push_back(vicky);
// }
// ariel::Board::~Board(){
    
// }
// void ariel::Board::post(u_int x, u_int y, Direction dir, const string &info){

//     if( check_x_cordinate(x) ){
//         resize_x(x);
//     }
//     if( check_y_cordinate(y) ){
//         resize_y(y);
//     }
    
//     const u_int strlen = info.length();
//     u_int offsetX = x + extra_x + ( to_string(this->writeable_y).length() - to_string(x).length());
//     u_int offsetY = y + extra_y -1;   

//     if(dir == Direction::Horizontal){
            
//         check_y_direction(y, offsetX, strlen);
//         for(u_int i =0; i < strlen; i++){
//             this->matrix.at(offsetY).at(offsetX+i) = info.at(i);
//         }

//         return;
//     }

//     check_x_direction(x, offsetY, strlen);
//     for(u_int i =0; i < strlen; i++){
//         this->matrix.at(offsetY+i).at(offsetX) = info.at(i);
//     }
// }
// string ariel::Board::read ( u_int x, u_int y, Direction dir, u_int size){

//     if( check_x_cordinate(x) ){
//         resize_x(x+size);
//     }
//     if( check_y_cordinate(y) ){
//         resize_y(y+size);
//     }
//     string ans;
//     u_int offsetX = x + extra_x + ( to_string(this->writeable_y).length() - to_string(x).length());
//     u_int offsetY = y + extra_y -1;
    
//     if( dir == Direction::Horizontal){

//         for (u_int i =0; i < size; i++){
//             ans +=  this->matrix.at(offsetY).at(offsetX+i);
//         }

//         return ans;
//     }

//     for (u_int i =0; i < size; i++){
//         ans +=  this->matrix.at(offsetY+i).at(offsetX);
//     }

//     return ans;
// }
// void ariel::Board::check_x_direction(u_int x ,u_int offset, u_int strlen)  {

//     if( x > this->writeable_x ){
//         resize_x(x);
//     }
//     u_int to_post = x + strlen;
//     if( to_post > this->writeable_y){
//         resize_y(to_post +1);
//     }


// }
// void ariel::Board::check_y_direction(u_int y,u_int offset, u_int strlen)  {

//     if( y > this->writeable_y ){
//         resize_y(y);
//     }
//     u_int to_post = offset + strlen;
//     if( to_post > this->writeable_x){
//         resize_x(to_post + 1);
//     }
    
// }
// void ariel::Board::resize_x(u_int x) {

//     vector<char> vicky;
//     string a_line;
//     u_int to_add = 0;
//     const u_int start = 0;
//     const u_int fit = extra_x + to_string(this->writeable_y).length()+1;

//     this->writeable_x = x;
//     x += fit;                      
//     to_add = x - this->visable_x;
//     this->visable_x = x;
//     a_line = string(this->visable_x, '#');
//     vicky = vector_from_string(a_line);
//     this->matrix.at(start).swap(vicky);

//     for (u_int i = 1; i <= this->writeable_y ; i++){

//         vicky = this->matrix.at(i);
//         a_line = string_from_vector(vicky);
//         a_line += string((to_add ), '_' ) + '#';
//         vicky = vector_from_string(a_line);
//         this->matrix.at(i).swap( vicky );
//     }  
//     a_line = string(this->visable_x, '#');
//     vicky = vector_from_string(a_line);
//     this->matrix.at(this->visable_y-1).swap(vicky);

// }
// void ariel::Board::resize_y(u_int y){

//     string a_line;
//     vector<char> vicky;
//     const u_int start =0;

//     if(this->writeable_y == y){
//         y++;
//     }

//     for( u_int i = 1; i < y; i++){
//         if( i > this->writeable_y -1 ){
            
//             a_line = make_generic_line(this->writeable_x, i);
//             vicky = vector_from_string(a_line);
//             if( i == this->writeable_y +1 ){
//                 this->matrix.at(i).swap(vicky);
//                 cout<< string_from_vector(this->matrix.at(i))<<endl;
//             }
//             else{
//                 this->matrix.push_back(vicky);
//                 cout<< string_from_vector(this->matrix.at(i))<<endl;
//             }
//         }
//         else{
//         string temp = string_from_vector(this->matrix.at(i));
//         a_line = reconstruct_line(temp, y+1, i);
//         cout<< a_line << endl;
//         vicky = vector_from_string(a_line);
//         this->matrix.at(i).swap(vicky);
//         }
//     }

//     this->space = to_string(y).length() - to_string(this->writeable_y).length();
//     this->writeable_y = y;
//     this->visable_y = y + 1;
//     this->visable_x += this->space;

//     a_line = string(this->visable_x, '#');
//     vicky = vector_from_string(a_line);
//     this->matrix.push_back(vicky);
//     this->matrix.at(start).swap(vicky);

// }
// bool ariel::Board::check_x_cordinate(u_int cord)const {

//     return cord > this->writeable_x ;
// }
// bool ariel::Board::check_y_cordinate(u_int cord)const {
    
//     return cord > this->writeable_y ;
// }
// void ariel::Board::show(){
//     for( auto const &vec : this->matrix ){
//         string line ;
//         int i =0;
//         for( auto const &ch : vec ){
//             line += ch;
//             if(ch == '_')i++;
//         }
//         cout<< line<< i << endl;
//     }
// }
// int main(){
//     // ariel::Board board1(10,7);
//     // board1.show();
//     ariel::Board board(12,10);
//     // board.show();
//     // board.post(10,2,ariel::Direction::Horizontal, "gid");
//     // board.show();
//     // board.read(20,4,ariel::Direction::Horizontal, 2);
//     // board.post(18,4,ariel::Direction::Horizontal, "shm");
//     // board.show();
//     // board.read(11,99,ariel::Direction::Horizontal, 2);
//     cout<< board.read(34, 14, ariel::Direction::Vertical, 5)<< endl;
//     // board.show();
//     // ariel::Board board2(10,10);
//     // board2.show();
// }