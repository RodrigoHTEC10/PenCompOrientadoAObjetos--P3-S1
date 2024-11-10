/*

Author: Rodrigo Alejandro Hurtado Cortés - A01713854
Title: Class - VerticalCinematic
Date last modification: November 9th, 2024.

Description: Class that inherits its methods and constructor from the HorizontalCinematic.h
class due to the use of the same formulas for both physics problems changing a posible acceleration
for the acceleration of gravity (9.81).

*/

//Include section

#include <iostream>
#include "HorizontalKinematics.h"

using namespace std;

#pragma once



class VerticalCinematic: public HorizontalCinematic{
    
    //--------------------------------------------------------------------------------------//

    public:

        // In case of the value its being looked for, add a 0 in that parameter
        //Constructors
        
        VerticalCinematic(double position, double ini_v, double fin_v, double t):HorizontalCinematic(position, ini_v,fin_v,-9.81,t){
        }

        //--------------------------------------------------------------------------------------//        

        //Getter Methods
        double getDisplacementY(){
            return getDisplacement();
        }

        double getInitialVelocity(){
            return getInitialVelocityHC();
        }

        double getFinalVelocity(){
            return getFinalVelocityHC();
        }

        double getTime(){
            return getTimeHC();
        }
        
        //--------------------------------------------------------------------------------------//
        //Setter Methods
        void setDisplacementY(double posy){
            setDisplacement(posy);
        }

        void setInitialVelocity(double ini_v){
            setInitialVelocityHC(ini_v);
        }

        void setFinalVelocity(double fin_v){
            setFinalVelocityHC(fin_v);
        }

        void setTime(double t){
            setTimeHC(t);
        }

        //--------------------------------------------------------------------------------------//
        //Methods of the Objects
        //--------------------------------------------------------------------------------------//
        //Methods to get Position


        //Lack Final Velocity
        double getDisplacementYNoVf(){
            return getDisplacementNoVf();
        }

        //Lack Initial Velocity
        double getDisplacementYNoVi(){
            return getDisplacementNoVi();
        }

        //Lack Displacement in Y
        double getDisplacementYNoT(){
            return getDisplacementNoT();
        }

        //--------------------------------------------------------------------------------------//
        //Methods to get Final Velocity


        //Lack Displacement in Y
        double getFinalVelocityNoY(){
            return getFinalVelocityNoX();
        }

        //Lack Initial Velocity
        double getFinalVelocityNoViVC(){
            return getFinalVelocityNoVi();
        }

        //Lack Time
        double getFinalVelocityNoTVC(){
            return getFinalVelocityNoT();
        }

        //--------------------------------------------------------------------------------------//
        //Methods to get Initial Velocity


        //Lack Displacement in Y
        double getInitialVelocityNoY(){
            return getInitialVelocityNoX();
        }

        //Lack Final Velocity
        double getInitialVelocityNoVfVC(){
            return getInitialVelocityNoVf();  
        }

        //Lack Time
        double getInitialVelocityNoTVC(){
            return getInitialVelocityNoT();
            
        }

        //--------------------------------------------------------------------------------------//
        //Methods to get Time


        //Lack Displacement in Y
        double getTimeNoY(){
            double time = getTimeNoX();
            if (time < 0){
                return time*-1;
            }
            else {
                return time;
            }

        }

        //Lack Final Velocity
        double getTimeNoVfVC(){
            double time = getTimeNoVf();
            if (time < 0){
                return time*-1;
            }
            else {
                return time;
            }
        }

        //Lack Initial Velocity
        double getTimeNoViVC(){
            double time = getTimeNoVi();
            if (time < 0){
                return time*-1;
            }
            else {
                return time;
            }
        }


        

};