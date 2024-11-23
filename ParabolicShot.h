/*

Author: Rodrigo Alejandro Hurtado Cortés - A01713854
Title: Class - ParabolicShot
Date last modification: November 22nd, 2024.

Description: This class creates the Object ParabolicShot that based on the initial velocity,
angle of inclination and specific time of the proyectile can obtain different values thanks
to its methods. 

*/

//Include section

#include <iostream>
#include <cmath>

using namespace std;

#pragma once



class ParabolicShot{
    private:

        //Private Instance Variables
        double initialVelocity;
        double angle;
        double velocityx;
        double velocityy;
        double gravity;
        double specificTime;

        //--------------------------------------------------------------------------------------//

    public:
        //Constructors

        //Default constructor
        ParabolicShot(){
            initialVelocity = 0.0;
            angle = 0.0;
            velocityx = 0.0;
            velocityy = 0.0;
            gravity = -9.81;
            specificTime = 0.0;
        }

        //Constructor with parameters
        ParabolicShot(double iniV, double ang, double st){
            initialVelocity = iniV;
            angle = ang* (3.14159265359 / 180);
            velocityx = iniV * cos(angle);
            velocityy = iniV * sin(angle);
            gravity = -9.81;
            specificTime = st;
        }

        //--------------------------------------------------------------------------------------//
        //Getter Methods
        double getInitialVelocity(){
            return initialVelocity;
        }

        double getAngle(){
            return angle;
        }

        //getVelocity(char axis) is a getter method which receives a character that refers to the axis the user
        // is looking the velocity from. 
        double getVelocity(char axis){
            if(axis == 'x'){
                return velocityx;
            }
            else{
                return velocityy;
            }
        }

        double getSpecificTime(){
            return specificTime;
        }


        //--------------------------------------------------------------------------------------//
        //Setter Methods

        void setInitialVelocity(double iniV){
            initialVelocity = iniV;
        }

        void setAngle(double ang){
            angle = ang;
        }

        //setVelocity(char axis, double value) is a setter method which receives a character that refers to the axis the user
        // is looking to modify and afterwards the value is assigned as the new content of the desired velocity.
        void setVelocity(char axis, double value){
            if(axis == 'x'){
                velocityx = value;
            }
            else{
                velocityy = value;
            }
        }

        void setSpecificTime(double st){
            specificTime = st;
        }

        //--------------------------------------------------------------------------------------//
        //Methods of the Objects
        //--------------------------------------------------------------------------------------//
        //Get Positions and Velocity at Specific Time

        //getPositionInTime(char axis) uses a formula to get the position of the proyectile depending if the axis 'x' was
        //entered, otherwise calculates the position in axis y. Afterwards returned to the user as a double.
        double getPositionInTime(char axis){
            if(axis == 'x'){
                double positionX = (velocityx)*specificTime;
                return positionX;
            }
            else{
                double positionY = (velocityy)*specificTime + 0.5*gravity*pow(specificTime,2);
                return positionY;
            }
        }

        //getVelocityYinTime() calculates a specific velocity of the proyectile in the y axis depending on the 
        //specific time entered in the constructor Afterwards returned to the user as a double.
        double getVelocityYinTime(){
            double velY = velocityy + gravity*specificTime;
            return velY;
        }

        //--------------------------------------------------------------------------------------//
        //Get Maximum values of X and Y
        
        //getMaximum(char axis) uses a formula to calculate the maximum range of the parabola if the axis 'x' was
        //entered, otherwise calculates the maximum height of the proyectile in axis y. Then it is stored in its
        // variable and returned to the user as a double.
        double getMaximum(char axis){
            if(axis == 'x'){
                double maxX = (pow(initialVelocity,2) *sin(2*angle))/-gravity ;
                return maxX;
            }
            else{
                double maxY = pow(initialVelocity*sin(angle),2) / (2*-gravity);
                return maxY;
            }
        }

        //--------------------------------------------------------------------------------------//
        //Get Times of Maximum Values of X and Y

        //getTimeMax(cahr axis) uses a formula to get the time the proyectile reach the maximum range of the parabola if the 
        //axis 'x' was entered, otherwise calculates the time the proyectile reaches the maximum height. Then it is 
        // stored in its variable and returned to the user as a double.
        double getTimeMax(char axis){
            if(axis == 'x'){
                double timeMaxX= (2*initialVelocity*sin(angle))/(9.8);
                return timeMaxX;
            }
            else{
                double timeMaxY = (initialVelocity*sin(angle)) / (9.8);
                return timeMaxY;
            }
        }
        


};