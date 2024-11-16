/*

Author: Rodrigo Alejandro Hurtado Cortés - A01713854
Title: Class - MediumVAndA
Date last modification: November 14th, 2024.

Description: The present class calculate the medium velocity between two positions and if two displacements
are entered inside the constructor (four x positions, four y positions, 2 times between displacements and 
one intermediate time) it calculate the medium acceleration off both axis.

*/

//Import section
#include <iostream>
#include "Position.h"

using namespace std;

#pragma once

class MediumVAndA{
    private:

        //Private Instance Variables

        Position positions[4];
        double time1;
        double velocityx1;
        double velocityy1;

        double time2;
        double timeBtw;
        double velocityx2;
        double velocityy2;

        double accelerationX;
        double accelerationY;
    
    //--------------------------------------------------------------------------------------//

    public:
        //Constructors

        //Default constructor
        MediumVAndA(){
            Position pos1 = Position();
            positions[0] = pos1;
            Position pos2 = Position();
            positions[1] = pos2;
            Position pos3 = Position();
            positions[2] = pos3;
            Position pos4 = Position();
            positions[3] = pos4;

            time1 = 0.0;
            velocityx1 = 0.0;
            velocityy1 = 0.0;
            time2 = 0.0;
            timeBtw =0.0;
            velocityx2 = 0.0;
            velocityy2 = 0.0;
            accelerationX = 0.0;
            accelerationY = 0.0;
        }

        //Constructor with parameters to obtain one medium velocity.
        MediumVAndA(double posx1, double posy1, double posx2, double posy2, double t1){
            Position pos1 = Position(posx1,posy1);
            positions[0] = pos1;
            Position pos2 = Position(posx2,posy2);
            positions[1] = pos2;
            Position pos3 = Position();
            positions[2] = pos3;
            Position pos4 = Position();
            positions[3] = pos4;
            time1 = t1;
            velocityx1 = 0.0;
            velocityy1 = 0.0;
            time2 = 0.0;
            timeBtw = 0.0;
            velocityx2 = 0.0;
            velocityy2 = 0.0;
            accelerationX = 0.0;
            accelerationY = 0.0;
        }

        //Constructor with parameters to obtain two medium velocities and one acceleration.
        MediumVAndA(double posx1, double posy1, double posx2, double posy2, double t1,double posx3, double posy3, double posx4, double posy4, double t2, double tBtw){
            Position pos1 = Position(posx1,posy1);
            positions[0] = pos1;
            Position pos2 = Position(posx2,posy2);
            positions[1] = pos2;
            Position pos3 = Position(posx3,posy3);
            positions[2] = pos3;
            Position pos4 = Position(posx4,posy4);
            positions[3] = pos4;
            time1 = t1;
            velocityx1 = 0.0;
            velocityy1 = 0.0;
            time2 = t2;
            timeBtw = tBtw;
            velocityx2 = 0.0;
            velocityy2 = 0.0;
            accelerationX = 0.0;
            accelerationY = 0.0;
        }

        //--------------------------------------------------------------------------------------//
        //Getter methods
        double getPositionx1(){
            return positions[0].getPosX();
        }

        double getPositiony1(){
            return positions[0].getPosY();
        }       

        double getPositionx2(){
            return positions[1].getPosX();
        }

        double getPositiony2(){
            return positions[1].getPosY();
        }

        double getTime1(){
            return time1;
        }

        double getVelocityx1(){
            return velocityx1;
        }

        double getVelocityy1(){
            return velocityy1;
        }

        double getPositionx3(){
            return positions[2].getPosX();
        }

        double getPositiony3(){
            return positions[2].getPosY();
        }

        double getPositionx4(){
            return positions[3].getPosX();
        }

        double getPositiony4(){
            return positions[3].getPosY();
        }

        double getTime2(){
            return time2;
        }

        double getTimeBetween(){
            return timeBtw;
        }

        double getVelocityx2(){
            return velocityx2;
        }

        double getVelocityy2(){
            return velocityy2;
        }

        double getAccelerationX(){
            return accelerationX;
        }

        double getAccelerationY(){
            return accelerationY;
        }

        //--------------------------------------------------------------------------------------//
        //Setter Methods

        void setPositionx1(double posx1){
            positions[0].setPosX(posx1);
        }

        void setPositiony1(double posy1){
            positions[0].setPosY(posy1);
        }       

        void setPositionx2(double posx2){
            positions[1].setPosX(posx2);
        }

        void setPositiony2(double posy2){
            positions[1].setPosY(posy2);
        }

        void setTime1(double t1){
            time1 = t1;
        }

        void setVelocityx1(double velx1){
            velocityx1 = velx1;
        }

        void setVelocityy1(double vely1){
            velocityy1 = vely1;
        }

        void setPositionx3(double posx3){
            positions[2].setPosX(posx3);
        }

        void setPositiony3(double posy3){
            positions[2].setPosY(posy3);
        }

        void setPositionx4(double posx4){
            positions[3].setPosX(posx4);
        }

        void setPositiony4(double posy4){
            positions[3].setPosY(posy4);
        }

        void setTime2(double t2){
            time2 = t2;
        }

        void setTimeBetween(double tBtw){
            timeBtw = tBtw;
        }

        void setVelocityx2(double velx2){
            velocityx2 = velx2;
        }

        void setVelocityy2(double vely2){
            velocityy2 = vely2;
        }

        void setAccelerationX(double acc){
            accelerationX = acc;
        }

        void setAccelerationY(double acc){
            accelerationY = acc;
        }

        //--------------------------------------------------------------------------------------//
        //Methods of the Objects
        //Method to get Medium Velocity

        //1st Displacement methods
        
        // getMediumVelocity(int pos1, int pos2, char axis) calculates the medium velocity based on
        //the indexes entered representing the position desired and the axis regitered in char axis.
        //Finally it is stored in its variable and returned to the user as a double.
        double getMediumVelocity(int pos1, int pos2, char axis){
            if (axis == 'x' && pos1 == 0 && pos2 == 1){
                velocityx1 = (positions[pos2-1].getPosX()-positions[pos1-1].getPosX())/time1;
                return velocityx1;
            }
            else if(axis == 'x'){
                velocityx2 = (positions[pos2-1].getPosX()-positions[pos1-1].getPosX())/time2;
                return velocityx2;
            }
            else if(axis == 'y' && pos1 == 0 && pos2 == 1){
                velocityy1 = (positions[pos2-1].getPosY()-positions[pos1-1].getPosY())/time1;
                return velocityy1;
            }
            else{
                velocityy2 = (positions[pos2-1].getPosY()-positions[pos1-1].getPosY())/time2;
                return velocityy2;
            }
        }


        //--------------------------------------------------------------------------------------//
        //getAcceleration(char axis). If axis is 'x' it will save the acceleration in accelerationX and returned as a double, while if
        //another character is entered then the y acceleration will be saved and returned as a double.
        double getAcceleration(char axis){
            if(axis == 'x'){
                accelerationX = (velocityx2-velocityx1)/(time2+timeBtw+time1);
                return accelerationX;
            }
            else{
                accelerationY = (velocityy2-velocityy1)/(time2+timeBtw+time1);
                return accelerationY;
            }
        }



};