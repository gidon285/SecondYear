ion::Vertical, "Reut");
    board.post(0, 3, Direction::Vertical, "Mas");
    board.post(5, 2, Direction::Horizontal, "Yakir");
    board.post(4, 6, Direction::Horizontal, "temp");
    board.post(1, 6, Direction::Vertical, "ariela");
    board.post(5, 6, Direction::Vertical, "W");
    board.show();
    cout<<'\n'<<endl;
    cout<<board.read(0, 0, Direction::Vertical, 3) <<endl;string("Reu");
    cout<<board.read(0, 0, Direction::Vertical, 4) <<endl; string("Reut");
    cout<<board.read(0, 0, Direction::Vertical, 5) <<endl; string("Reut_");
    
    cout<<board.read(0, 3, Direction::Vertical, 2) <<endl; string("Ma");
    cout<<board.read(0, 3, Direction::Vertical, 3) <<endl; string("Mas");
    cout<<board.read(0, 3, Direction::Vertical, 4) <<endl; string("Mas_");

    cout<<board.read(2, 8, Direction::Vertical, 3) <<endl; string("__m");
    cout<<board.read(5, 2, Direction::Vertical, 10) <<endl; str