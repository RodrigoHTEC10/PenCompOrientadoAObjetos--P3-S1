/*

Author: Rodrigo Alejandro Hurtado Cortés - A01713854
Title: Class - HorizontalCinematic
Date last modification: November 9th, 2024.

Description: Class whose constructor received parameters and those values who are look for and the user does not
know are entered like zero. The methods established in the present class allow to obtain a specific value of either
of the five private instance variables based on the absence of a second value.

This class is also the Parent class of the VerticalCinematic.h that uses the same physic formulas substituting 
the acceleration for the acceleration of gravity (9.81).

*/

//Import section

#include <iostream>
#include <cmath>

using namespace std;

#pragma once



class HorizontalCinematic{
    private: 

        //Private Instance Variables
        double displacement;
        double initialVelocity;
        double finalVelocity;
        double acceleration;
        double time;

    //--------------------------------------------------------------------------------------//

    public:

        // In case of the value its being looked for, add a 0 in that parameter 
        //Constructors

        //Default Constructor       
        HorizontalCinematic(){
            displacement = 0.0;
            initialVelocity = 0.0;
            finalVelocity = 0.0;
            acceleration = 0.0;
            time = 0.0;
        }
        
        //Constructor with parameters
        HorizontalCinematic(double position, double ini_v, double fin_v, double acc, double t){
            displacement = position;
            initialVelocity = ini_v;
            finalVelocity = fin_v;
            acceleration = acc;
            time = t;
        }

        //--------------------------------------------------------------------------------------//

        //Getter Methods
        double getDisplacement(){
            return displacement;
        }

        double getInitialVelocityHC(){
            return initialVelocity;
        }

        double getFinalVelocityHC(){
            return finalVelocity;
        }

        double getAcceleration(){
            return acceleration;
        }

        double getTimeHC(){
            return time;
        }
        
        //--------------------------------------------------------------------------------------//
        //Setter Methods
        void setDisplacement(double position){
            displacement = position;
        }

        void setInitialVelocityHC(double ini_v){
            initialVelocity = ini_v;
        }

        void setFinalVelocityHC(double fin_v){
            finalVelocity = fin_v;
        }

        void setAcceleration(double acc){
            acceleration = acc;
        }

        void setTimeHC(double t){
            time = t;
        }

        //--------------------------------------------------------------------------------------//
        //Methods of the Objects
        //--------------------------------------------------------------------------------------//
        //Methods to get Position


        //Lack Acceleration
        double getDisplacementNoA(){
            displacement = ((initialVelocity + finalVelocity)/2) * time;
            return displacement;
        }

        //Lack Final Velocity
        double getDisplacementNoVf(){
            displacement = (initialVelocity * time)+(0.5*acceleration*pow(time,2));
            return displacement;
        }

        //Lack Initial Velocity
        double getDisplacementNoVi(){
            displacement = (finalVelocity * time)-(0.5*acceleration*pow(time,2));
            return displacement;
        }

        //Lack Time
        double getDisplacementNoT(){
            displacement = (pow(finalVelocity,2)-pow(initialVelocity,2))/(2*acceleration);
            return displacement;
        }

        //--------------------------------------------------------------------------------------//
        //Methods to get the Final Velocity


        //Lack Displacement in X
        double getFinalVelocityNoX(){
            finalVelocity = initialVelocity + (acceleration*time);
            return finalVelocity;
        }

        //Lack Initial Velocity
        double getFinalVelocityNoVi(){
            finalVelocity = (0.5*acceleration*pow(time,2)+displacement)/time;
            return finalVelocity;     
        }

        //Lack Acceleration
        double getFinalVelocityNoA(){
            finalVelocity = 2*(displacement/time)-initialVelocity;
            return finalVelocity;
            
        }

        //Lack Time
        double getFinalVelocityNoT(){
            finalVelocity = sqrt(2*acceleration*displacement + pow(initialVelocity,2));
            return finalVelocity;
            
        }

        //--------------------------------------------------------------------------------------//
        //Methods to get Initial Velocity


        //Lack Displacement in X
        double getInitialVelocityNoX(){
            initialVelocity = finalVelocity - (acceleration*time);
            return initialVelocity;
        }

        //Lack Final Velocity
        double getInitialVelocityNoVf(){
            initialVelocity = (-0.5*acceleration*pow(time,2)+displacement)/time;
            return initialVelocity;
            
        }

        //Lack Acceleration
        double getInitialVelocityNoA(){
            initialVelocity = 2*(displacement/time)-finalVelocity;
            return initialVelocity;
            
        }

        //Lack Time
        double getInitialVelocityNoT(){
            initialVelocity = sqrt(pow(finalVelocity,2)-2*acceleration*displacement);
            return initialVelocity;
            
        }

        //--------------------------------------------------------------------------------------//
        //Methods to get Acceleration


        //Lack Displacement in X
        double getAccelerationNoX(){
            acceleration = (finalVelocity-initialVelocity)/time;
            return acceleration;
        }

        //Lack Final Velocity
        double getAccelerationNoVf(){
            acceleration = (2*(displacement-(initialVelocity*time)))/pow(time,2);
            return acceleration;
        }

        //Lack Initial Velocity
        double getAccelerationNoVi(){
            acceleration = (2*((finalVelocity*time)-displacement))/pow(time,2);
            return acceleration;
        }

        //Lack Time
        double getAccelerationNoT(){
            acceleration = (pow(finalVelocity,2)-pow(initialVelocity,2))/(2*displacement);
            return acceleration;
        }

        //--------------------------------------------------------------------------------------//
        //Methods to get Time


        //Lack Acceleration
        double getTimeNoA(){
            time = (2*displacement)/(initialVelocity+finalVelocity);
            return time;
        }

        double getTimeNoX(){
            time = (finalVelocity-initialVelocity)/acceleration;
            return time;
        }

        //Lack Final Velocity
        double getTimeNoVf(){
            time = (-initialVelocity+sqrt(pow(initialVelocity,2)-4*(acceleration*0.5)*(-displacement)))/(2*(acceleration*0.5));
            return time;
        }

        //Lack Initial Velocity
        double getTimeNoVi(){
            time = (finalVelocity-sqrt(pow(finalVelocity,2) +4*(acceleration*0.5)*(-displacement)))/(2*(acceleration*0.5));
            return time;
        }

};