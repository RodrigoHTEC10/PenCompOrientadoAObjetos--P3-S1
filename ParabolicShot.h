/*

Author: Rodrigo Alejandro Hurtado Cortés - A01713854
Title: Class - ParabolicShot
Date last modification: November 9th, 2024.

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
        double maxY;
        double timeMaxY;
        double maxX;
        double timeMaxX;

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
            maxY = 0.0;
            timeMaxY = 0.0;
            maxX = 0.0;
            timeMaxX = 0.0;
        }

        //Constructor with parameters
        ParabolicShot(double iniV, double ang, double st){
            initialVelocity = iniV;
            angle = ang* (3.14159265359 / 180);
            velocityx = iniV * cos(angle);
            velocityy = iniV * sin(angle);
            gravity = -9.81;
            specificTime = st;
            maxY = 0.0;
            timeMaxY = 0.0;
            maxX = 0.0;
            timeMaxX = 0.0;
        }

        //--------------------------------------------------------------------------------------//
        //Getter Methods
        double getInitialVelocity(){
            return initialVelocity;
        }

        double getAngle(){
            return angle;
        }

        double getVelocityX(){
            return velocityx;
        }

        double getVelocityY(){
            return velocityy;
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

        void setVelocityX(double velx){
            velocityx = velx;
        }

        void setVelocityY(double vely){
            velocityy = vely;
        }

        void setSpecificTime(double st){
            specificTime = st;
        }

        void setMaximumY(double mxY){
            maxY = mxY;
        }

        void setTimeMaximunY(double tMxY){
            timeMaxY = tMxY;
        }

        void setMaximumX(double mxX){
            maxX = mxX;
        }

        void setTimeMaximumX(double tMxX){
            timeMaxX = tMxX;
        }

        //--------------------------------------------------------------------------------------//
        //Methods of the Objects
        //--------------------------------------------------------------------------------------//
        //Get Positions and Velocity at Specific Time

        double getPositionXInTime(){
            double positionX = (velocityx)*specificTime;
            return positionX;
        }

        double getPositionYInTime(){
            double positionY = (velocityy)*specificTime + 0.5*gravity*pow(specificTime,2);
            return positionY;
        }

        double getVelocityYinTime(){
            double velY = velocityy + gravity*specificTime;
            return velY;
        }

        //--------------------------------------------------------------------------------------//
        //Get Maximum values of X and Y

        double getMaximumX(){
            maxX = (pow(initialVelocity,2) *sin(2*angle))/-gravity ;
            return maxX;
        }

        double getMaximumY(){
            maxY = pow(initialVelocity*sin(angle),2) / (2*-gravity);
            return maxY;
        }

        //--------------------------------------------------------------------------------------//
        //Get Times of Maximum Values of X and Y

        double getTimeMaxX(){
            timeMaxX= (2*initialVelocity*sin(angle))/(9.8);
            return timeMaxX;
        }
        
        double getTimeMaxY(){
            timeMaxY = (initialVelocity*sin(angle)) / (9.8);
            return timeMaxY;
        }
        


};