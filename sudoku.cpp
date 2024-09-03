#include <iostream>

#define SIZE 9

int grid[9][9] = {
    8,0,1,  0,0,5,  6,0,9,
    0,0,9,  0,0,0,  0,5,0,
    0,5,6,  0,9,1,  0,7,4,

    0,3,0,  4,7,0,  0,0,6,
    5,0,8,  1,0,2,  4,0,0,
    7,0,0,  0,3,8,  9,0,2,

    0,2,0,  0,0,3,  0,6,0,
    0,0,0,  0,8,7,  0,4,0,
    0,8,3,  2,5,0,  7,0,0,
};

void print(int grid[SIZE][SIZE]);
bool valid(int grid[SIZE][SIZE], int row, int col, int num);
bool solve(int grid[SIZE][SIZE]);

int main(){
    solve(grid);
    print(grid);

    return 0;
}

void print(int grid[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        if(i % 3 == 0){
            std::cout << std::endl;
        }
        for(int j = 0; j < SIZE; j++){
            if (j %3 == 0){
                std::cout << "\t";
            }
            std::cout << grid[i][j] << ",";
        }
        std::cout << std::endl;
    }
}

bool valid(int grid[SIZE][SIZE], int row, int col, int num){

    for(int i = 0; i < SIZE; i++){
        if(grid[row][i] == num) return false;
        if(grid[i][col] == num) return false;
    }

    int srow = row - row % 3;
    int scol = col - col % 3;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(grid[srow + i][scol + j] == num) return false;
        }
    }

    return true;
}

bool solve(int grid[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(grid[i][j] == 0){
                for(int x = 1; x <= SIZE; x++){
                    if(valid(grid, i, j, x)){
                        grid[i][j] = x;
                        if(solve(grid)){
                            return true;
                        }
                        grid[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }

    return true;
}