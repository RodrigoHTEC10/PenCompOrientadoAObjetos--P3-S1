/*

Author: Rodrigo Alejandro Hurtado Cortés - A01713854
Title: Class - Position
Date last modification: November 12th, 2024.

Description: This object contains the two components of a position on the axis X and Y.

*/

//Import section
#include <iostream>

using namespace std;

#pragma once

class Position{
    private:
    
        //Private Instance Variables
        double positionx;
        double positiony;

    public:

        //Default Constructor
        Position(){
            positionx = 0.0;
            positiony = 0.0;
        }


        //Constructor with parameters
        Position(double x, double y){
            positionx = x;
            positiony = y;
        }

        //Getters

        double getPosX(){
            return positionx;
        }

        double getPosY(){
            return positiony;
        }

        //Setters
        void setPosX(double x){
            positionx = x;
        }

        void setPosY(double y){
            positiony = y;
        }


        
};