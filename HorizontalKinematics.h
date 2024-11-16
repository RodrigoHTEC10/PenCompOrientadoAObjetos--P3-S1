/*

Author: Rodrigo Alejandro Hurtado Cortés - A01713854
Title: Class - HorizontalCinematic
Date last modification: November 14th, 2024.

Description: Class whose constructor received parameters and those values who are look for and the user does not
know are entered like zero. The methods established in the present class allow to obtain a specific value of either
of the five private instance variables based on the absence of a second value.

This class is also the Parent class of the VerticalCinematic.h that uses the same physic formulas substituting 
the acceleration for the acceleration of gravity (9.81).

*/

//Import section

#include <iostream>
#include <cmath>
#include"Kinematics.h"

using namespace std;

#pragma once



class HorizontalKinematics: public Kinematics{
    private: 

    //--------------------------------------------------------------------------------------//

    public:

        // In case of the value its being looked for, add a 0 in that parameter 
        //Constructors

        //Default Constructor       
        HorizontalKinematics():Kinematics(){ 
        }
        
        //Constructor with parameters
        HorizontalKinematics(double position, double iniV, double finV, double acc, double t):Kinematics(position, iniV,finV,acc,t){
        }


        //--------------------------------------------------------------------------------------//
        //Methods of the Objects
        //--------------------------------------------------------------------------------------//
        //Methods to get Position


        //Lack Acceleration
        double getDisplacementNoA(){
            double displacement = ((getInitialVelocity() + getFinalVelocity())/2) * getTime();
            return displacement;
        }


        //--------------------------------------------------------------------------------------//
        //Methods to get the Final Velocity

        //Lack Acceleration
        double getFinalVelocityNoA(){
            double finalVelocity = 2*(getDisplacement()/getTime())-getInitialVelocity();
            return finalVelocity;
            
        }

        //--------------------------------------------------------------------------------------//
        //Methods to get Initial Velocity

        //Lack Acceleration
        double getInitialVelocityNoA(){
            double initialVelocity = 2*(getDisplacement()/getTime())-getFinalVelocity();
            return initialVelocity;
            
        }

        //--------------------------------------------------------------------------------------//

        //getAccelerationNo(string lack) uses different formulas to calculate the acceleration of the object in 
        //kinematics based on the value or element the user lacks, which is written as the string lack. Then it is 
        //stored in a variable called acceleration and returned to the user as a double.
        double getAccelerationNo(string lack){
            double acceleration = 0.0;
            if(lack == "finalVelocity"){
                acceleration = (2*(getDisplacement()-(getInitialVelocity()*getTime())))/pow(getTime(),2);
            }
            else if(lack == "initialVelocity"){
                acceleration = (2*((getFinalVelocity()*getTime())-getDisplacement()))/pow(getTime(),2);
            }
            else if(lack == "time"){
                acceleration = (pow(getFinalVelocity(),2)-pow(getInitialVelocity(),2))/(2*getDisplacement());
            }
            else{
                acceleration = (getFinalVelocity()-getInitialVelocity())/getTime();
            }
            return acceleration;
        }

        //--------------------------------------------------------------------------------------//
        //Methods to get Time


        //Lack Acceleration
        double getTimeNoA(){
            double time = (2*getDisplacement())/(getInitialVelocity()+getFinalVelocity());
            return time;
        }


};