/*

Author: Rodrigo Alejandro Hurtado Cortés - A01713854
Title: Class - Kinematics
Date last modification: November 14th, 2024.

Description: This abstract class is the parent that hold the common methods and attributes of the Horizontal and Vertical
Kinematics.

*/

//Import section

#include <iostream>
#include <cmath>

using namespace std;

#pragma once



class Kinematics{
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
        Kinematics(){
            displacement = 0.0;
            initialVelocity = 0.0;
            finalVelocity = 0.0;
            acceleration = 0.0;
            time = 0.0;
        }
        
        //Constructor with parameters
        Kinematics(double position, double ini_v, double fin_v, double acc, double t){
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

        double getInitialVelocity(){
            return initialVelocity;
        }

        double getFinalVelocity(){
            return finalVelocity;
        }

        double getAcceleration(){
            return acceleration;
        }

        double getTime(){
            return time;
        }
        
        //--------------------------------------------------------------------------------------//
        //Setter Methods

        void setDisplacement(double position){
            displacement = position;
        }

        void setInitialVelocity(double ini_v){
            initialVelocity = ini_v;
        }

        void setFinalVelocity(double fin_v){
            finalVelocity = fin_v;
        }

        void setAcceleration(double acc){
            acceleration = acc;
        }

        void setTime(double t){
            time = t;
        }

        //--------------------------------------------------------------------------------------//
        //Methods of the Objects
        //--------------------------------------------------------------------------------------//


        //getDisplacementNo(string lack) uses different formulas to calculate the displacement of the object in 
        //kinematics based on the value or element the user lacks, which is written as the string lack. Then it is 
        // stored in its variable and returned to the user as a double.
        double getDisplacementNo(string lack){
            if(lack == "finalVelocity"){
                displacement = (initialVelocity * time)+(0.5*acceleration*pow(time,2));
            }
            else if(lack == "initialVelocity"){
                displacement = (finalVelocity * time)-(0.5*acceleration*pow(time,2));
            }
            else{
                displacement = (pow(finalVelocity,2)-pow(initialVelocity,2))/(2*acceleration);
            }
            return displacement;

        }

        //--------------------------------------------------------------------------------------//

        //getFinalVelocityNo(string lack) uses different formulas to calculate the final velocity of the object in 
        //kinematics based on the value or element the user lacks, which is written as the string lack. Then it is 
        // stored in its variable and returned to the user as a double.
        double getFinalVelocityNo(string lack){
            if(lack == "displacement"){
                finalVelocity = initialVelocity + (acceleration*time);
            }
            else if(lack == "initialVelocity"){
                finalVelocity = (0.5*acceleration*pow(time,2)+displacement)/time;
            }
            else{
                finalVelocity = sqrt(2*acceleration*displacement + pow(initialVelocity,2));
            }
            return finalVelocity;

        }


        //--------------------------------------------------------------------------------------//

        //getInitialVelocityNo(string lack) uses different formulas to calculate the initial velocity of the object in 
        //kinematics based on the value or element the user lacks, which is written as the string lack. Then it is 
        // stored in its variable and returned to the user as a double.
        double getInitialVelocityNo(string lack){
            if(lack == "displacement"){
                initialVelocity = finalVelocity - (acceleration*time);
            }
            else if(lack == "finalVelocity"){
                initialVelocity = (-0.5*acceleration*pow(time,2)+displacement)/time;
            }
            else{
                initialVelocity = sqrt(pow(finalVelocity,2)-2*acceleration*displacement);
            }
            return initialVelocity;
        }

        //--------------------------------------------------------------------------------------//

        //getInitialVelocityNo(string lack) uses different formulas to calculate the initial velocity of the object in 
        //kinematics based on the value or element the user lacks, which is written as the string lack. Then it is 
        // stored in its variable and returned to the user as a double.
        double getTimeNo(string lack){
            if(lack == "displacement"){
                time = (finalVelocity-initialVelocity)/acceleration;
            }
            else if(lack == "finalVelocity"){
                time = (-initialVelocity+sqrt(pow(initialVelocity,2)-4*(acceleration*0.5)*(-displacement)))/(2*(acceleration*0.5));
            }
            else{
                time = (finalVelocity-sqrt(pow(finalVelocity,2) +4*(acceleration*0.5)*(-displacement)))/(2*(acceleration*0.5));
            }

            if (time < 0){
                return time*-1;
            }
            else {
                return time;
            }
        }

};