/*

Author: Rodrigo Alejandro Hurtado Cortés - A01713854
Title: Class - MediumVAndA
Date last modification: November 22nd, 2024.

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
        double time2;
        double timeBtw;
    
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
            time2 = 0.0;
            timeBtw =0.0;
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
            time2 = 0.0;
            timeBtw = 0.0;
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
            time2 = t2;
            timeBtw = tBtw;
        }

        //--------------------------------------------------------------------------------------//
        //Getter methods

        //getPosition(char axis, int num) is a getter method which returns the desired value on the
        //  axis written as a char either 'x' or' y' of the position identified with the integer num 
        // (1-4).
        double getPosition(char axis, int num){
            if (axis == 'x'){
                return positions[num-1].getPosX();
            }
            else{
                return positions[num-1].getPosY();
            }
        }

        //getTime(int num) is a getter method that returns different times depending on the integer 
        // introduced as a parameter, being time1 (time between positions 1-2) if num == 1, time2 
        //(time between positions 3-4) if num == 2 and either number above or under those will return
        // the time between time1 and time2.
        double getTime(int num){
            if (num == 1){
                return time1;
            }
            else if (num == 2){
                return time2;
            }
            else{
                return timeBtw;
            }
        }


        //--------------------------------------------------------------------------------------//
        //Setter Methods
        
        //setPosition(char axis, int num, double value) is a setter method which will modify the 
        // desired value on the axis written as a char either 'x' or' y' of the position identified
        // with the integer num (1-4) for the double entered in value.
        void setPosition(char axis, int num, double value){
            if (axis == 'x'){
                positions[num-1].setPosX(value);
            }
            else{
                positions[num-1].setPosX(value);
            }
        }


        //setTime(int num, double value) is a getter method that modifies different times depending 
        //on the integer introduced as a parameter, being time1 (time between positions 1-2) if num == 1,
        // time2 (time between positions 3-4) if num == 2 and either number above or under those will 
        // the time between time1 and time2 changing the selection for the double value.
        void setTime(int num, double value){
            if (num == 1){
                time1 = value;
            }
            else if (num == 2){
                time2 = value;
            }
            else{
                timeBtw = value;
            }
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
                double velocityx1 = (positions[pos2-1].getPosX()-positions[pos1-1].getPosX())/time1;
                return velocityx1;
            }
            else if(axis == 'x'){
                double velocityx2 = (positions[pos2-1].getPosX()-positions[pos1-1].getPosX())/time2;
                return velocityx2;
            }
            else if(axis == 'y' && pos1 == 0 && pos2 == 1){
                double velocityy1 = (positions[pos2-1].getPosY()-positions[pos1-1].getPosY())/time1;
                return velocityy1;
            }
            else{
                double velocityy2 = (positions[pos2-1].getPosY()-positions[pos1-1].getPosY())/time2;
                return velocityy2;
            }
        }


        //--------------------------------------------------------------------------------------//
        //getAcceleration(char axis). If axis is 'x' it will save the acceleration in accelerationX 
        //and returned as a double, while if another character is entered then the y acceleration will
        //be saved and returned as a double.
        double getAcceleration(char axis){
            double velocityx1 = (positions[1].getPosX()-positions[0].getPosX())/time1;
            double velocityx2 = (positions[3].getPosX()-positions[2].getPosX())/time2;
            double velocityy1 = (positions[1].getPosY()-positions[0].getPosY())/time1;
            double velocityy2 = (positions[3].getPosY()-positions[2].getPosY())/time2;

            if(axis == 'x'){
                double accelerationX = (velocityx2-velocityx1)/(time2+timeBtw+time1);
                return accelerationX;
            }
            else{
                double accelerationY = (velocityy2-velocityy1)/(time2+timeBtw+time1);
                return accelerationY;
            }
        }



};