/*

Author: Rodrigo Alejandro Hurtado Cortés - A01713854
Title: Class - MediumVAndA
Date last modification: November 9th, 2024.

Description: The present class calculate the medium velocity between two positions and if two displacements
are entered inside the constructor (four x positions, four y positions, 2 times between displacements and 
one intermediate time) it calculate the medium acceleration off both axis.

*/

#include <iostream>
using namespace std;

#pragma once

class MediumVAndA{
    private:

        //Private Instance Variables
        double positionx1;
        double positiony1;
        double positionx2;
        double positiony2;
        double time1;
        double velocityx1;
        double velocityy1;

        double positionx3;
        double positiony3;
        double positionx4;
        double positiony4;
        double time2;
        double timeBtw;
        double velocityx2;
        double velocityy2;

        double acceleration;
    
    //--------------------------------------------------------------------------------------//

    public:
        //Constructors

        //Default constructor
        MediumVAndA(){
            positionx1 = 0.0;
            positiony1 = 0.0;
            positionx2 = 0.0;
            positiony2 = 0.0;
            time1 = 0.0;
            velocityx1 = 0.0;
            velocityy1 = 0.0;
            positionx3 = 0.0;
            positiony3 = 0.0;
            positionx4 = 0.0;
            positiony4 = 0.0;
            time2 = 0.0;
            timeBtw =0.0;
            velocityx2 = 0.0;
            velocityy2 = 0.0;
            acceleration = 0.0;
        }

        //Constructor with parameters to obtain one medium velocity.
        MediumVAndA(double posx1, double posy1, double posx2, double posy2, double t1){
            positionx1 = posx1;
            positiony1 = posy1;
            positionx2 = posx2;
            positiony2 = posy2;
            time1 = t1;
            velocityx1 = 0.0;
            velocityy1 = 0.0;
            positionx3 = 0.0;
            positiony3 = 0.0;
            positionx4 = 0.0;
            positiony4 = 0.0;
            time2 = 0.0;
            timeBtw = 0.0;
            velocityx2 = 0.0;
            velocityy2 = 0.0;
            acceleration = 0.0;
        }

        //Constructor with parameters to obtain two medium velocities and one acceleration.
        MediumVAndA(double posx1, double posy1, double posx2, double posy2, double t1,double posx3, double posy3, double posx4, double posy4, double t2, double tBtw){
            positionx1 = posx1;
            positiony1 = posy1;
            positionx2 = posx2;
            positiony2 = posy2;
            time1 = t1;
            velocityx1 = 0.0;
            velocityy1 = 0.0;
            positionx3 = posx3;
            positiony3 = posy3;
            positionx4 = posx4;
            positiony4 = posy4;
            time2 = t2;
            timeBtw = tBtw;
            velocityx2 = 0.0;
            velocityy2 = 0.0;
            acceleration = 0.0;
        }

        //--------------------------------------------------------------------------------------//
        //Getter methods
        double getPositionx1(){
            return positionx1;
        }

        double getPositiony1(){
            return positiony1;
        }       

        double getPositionx2(){
            return positionx2;
        }

        double getPositiony2(){
            return positiony2;
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
            return positionx3;
        }

        double getPositiony3(){
            return positiony3;
        }

        double getPositionx4(){
            return positionx4;
        }

        double getPositiony4(){
            return positiony4;
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

        double getAcceleration(){
            return acceleration;
        }

        //--------------------------------------------------------------------------------------//
        //Setter Methods

        void setPositionx1(double posx1){
            positionx1 = posx1;
        }

        void setPositiony1(double posy1){
            positiony1 = posy1;
        }       

        void setPositionx2(double posx2){
            positionx2 = posx2;
        }

        void setPositiony2(double posy2){
            positiony2 = posy2;
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
            positionx3 = posx3;
        }

        void setPositiony3(double posy3){
            positiony3 = posy3;
        }

        void setPositionx4(double posx4){
            positionx4 = posx4;
        }

        void setPositiony4(double posy4){
            positiony4 = posy4;
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

        void setAcceleration(double acc){
            acceleration = acc;
        }

        //--------------------------------------------------------------------------------------//
        //Methods of the Objects
        //Method to get Medium Velocity

        //1st Displacement methods
        double getMediumVelocityx1(){
            velocityx1 = (positionx2-positionx1)/time1;
            return velocityx1;
        }

        double getMediumVelocityy1(){
            velocityy1 = (positiony2-positiony1)/time1;
            return velocityy1;
        }

        //2nd Displacement methods
        double getMediumVelocityx2(){
            velocityx2 = (positionx4-positionx3)/time2;
            return velocityx2;
        }

        double getMediumVelocityy2(){
            velocityy2 = (positiony4-positiony3)/time2;;
            return velocityy2;
        }

        //--------------------------------------------------------------------------------------//
        //Method to get Acceleration
        double getAccelerationX(){
            acceleration = (velocityx2-velocityx1)/(time2+timeBtw+time1);
            return acceleration;
        }

        double getAccelerationY(){
            acceleration = (velocityy2-velocityy1)/(time2+timeBtw+time1);
            return acceleration;
        }

};