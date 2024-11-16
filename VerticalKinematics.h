/*

Author: Rodrigo Alejandro Hurtado Cortés - A01713854
Title: Class - VerticalCinematic
Date last modification: November 14th, 2024.

Description: Class that inherits its methods and constructor from the Kinematics.h
class due to the use of the same formulas for both physics problems changing a posible acceleration
for the acceleration of gravity (9.81). 

*/

//Include section

#include <iostream>
#include "Kinematics.h"

using namespace std;

#pragma once



class VerticalKinematics: public Kinematics{
    
    //--------------------------------------------------------------------------------------//

    public:

        // In case of the value its being looked for, add a 0 in that parameter
        //Default Constructor
        VerticalKinematics():Kinematics(){
        }
        
        //Constructor with parameters
        VerticalKinematics(double position, double ini_v, double fin_v, double t):Kinematics(position, ini_v,fin_v,-9.81,t){
        }

};