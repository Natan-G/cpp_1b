#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <vector>
#include "mat.hpp"


void throwException()
{	
	throw std::invalid_argument("Mat size is always odd");

}

void validInput(int num_1 , int num_2){

    if(num_1%2==0 || num_2%2==0){
        throwException();
    }
    if(num_1 <1 || num_2<1){
        throwException();
    }
}


namespace ariel{
    std::string mat(int num_1, int num_2, char str_1, char str_2){

        validInput(num_1 , num_2);

        int const min = 33;
        int const max = 126;

        if(str_2<min || str_1<min){
            throwException();
        }
        if(str_2>max || str_2>max){
            throwException();
        }

        string ans;

        if((num_1==1) && (num_2 == 1)){
            ans.push_back(str_1);
            return ans; 
        }
        
        if(num_1 == 1){
            for(int i=0 ; i<num_2 ; i++){
                ans.push_back(str_1);

                if(i != (num_2-1)){
                    ans.append("\n");
                }
            }
            return ans;
        }

        if(num_2 == 1){

            for(int i=0 ; i<num_1 ; i++){
                ans.push_back(str_1);
            }
            return ans;
        }


        vector<vector<char>> matrix_vector(num_2 , vector<char>(num_1));


        int top = 0;
        int down = num_2-1;
        int left = 0;
        int right = num_1-1;

        // direction : 0 move from left to right , 1 top to down , 2 right to left, 3 from bottom to top
        int dir=0;

        bool help = false;
        char temp = str_1;


        while(top<=down && left<=right){
            //left to right
            if(dir==0){
                for(int i=left ; i<=right ; i++){
                    matrix_vector[top][i] = temp;
                }
                top+=1;
            }
            //top to down
            else if(dir==1){
                for(int i=top ; i<=down ; i++){
                    matrix_vector[i][right]=temp;
                }
                right -=1;
            }
            //right to left
            else if(dir==2){
                for(int i=right ; i>=left ; i--){
                    matrix_vector[down][i]=temp;
                }
                down-=1;
            }
            //bottom to top
            else if(dir==3){
                for(int i=down ; i>=top ; i--){
                    matrix_vector[i][left]=temp;
                }
                left+=1;
            }
            //if dir==3 we finish the currect square, switch to the second charecter
            if(dir==3){
                if(help){
                    temp=str_1;
                    help=false;
                }
                else{
                    temp=str_2;
                    help=true;
                }
            }
            dir = (dir+1)%4;

        }


        //print the resault
        for(int i=0 ; i<num_2 ; i++){
            for(int j=0 ; j<num_1 ; j++){
                ans+=matrix_vector[i][j];
            }
        }
    

        return ans;     
    }
}