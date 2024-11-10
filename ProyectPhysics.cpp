/*

Author: Rodrigo Alejandro Hurtado Cortés - A01713854
Title: Proyect - Physics Problem Solver
Date last modification: November 9th, 2024.

Description: This proyect consist of four different classes integrated with formulas that help
solve different physics problems related to:

    1. Horizontal Cinematic.
    2. Vertical Cinematic.
    3. Medium Velocity and Acceleration.
    4. Parabolic shot.

All these being fulled by the data provided by the user.

The program in the present c++ file is composed of menus and switches which help to send the
problems to their proper formula established as methods in one of the four classes previously
mentioned.

A 5th option was added to the MainMenu() which helps the user to check the working of all the 
functions with predetermined established data.

*/

//Import Area

#include <iostream>

//Inclusion of the classes used in the present proyect.

#include "HorizontalKinematics.h"
#include "VerticalKinematics.h"
#include "MediumVAndA.h"
#include "ParabolicShot.h"

//--------------------------------------------------------------------------------------//

using namespace std;

//--------------------------------------------------------------------------------------//
//Funciones

//Function isBtwLimits(num, inf, sup, function) helps to check if a value (num) is between 
//the limits (inferior and superior) of its menu (function). If its not, creates a while 
//loop that makes the user enter a proper value to exit.
int isBtwLimits(int num, int inf, int sup, int(*function)(void)){
    if (num < inf || num > sup){
        while (num < inf || num > sup){
            cout <<"Invalid input, please enter a correct number" <<endl;
            num = function();
        }
        return num;
    }
    else{
        return num;
    }
    
}

//___________________________________________________________________________________________//

//Function MainMenu() is the decision that divides the four classes.
int MainMenu(){
    cout << "What type of problem are you trying to solve? Enter the number: "<<endl;
    cout << "1. Horizontal Cinematic." <<endl;
    cout << "2. Vertical Cinematic." <<endl;
    cout << "3. Medium Velocity and Acceleration" <<endl;
    cout << "4. Parabolic Shot" <<endl;
    cout << "5. Objects, Classes and Methods trial."<< endl;
    int answer;
    cin >> answer;
    return answer;
}

//___________________________________________________________________________________________//

//Function Menu1() is the menu of the class Horizontal Cinematic.
int Menu1(){
    cout << "1. Displacement." <<endl;
    cout << "2. Final Velocity." <<endl;
    cout << "3. Initial Velocity." <<endl;
    cout << "4. Acceleration." <<endl;
    cout << "5. Time." <<endl;
    int answer;
    cin >> answer;
    return answer;
}

//___________________________________________________________________________________________//

//Function Menu2() is the menu of the class Vertical Cinematic.
int Menu2(){
    cout << "1. Displacement." <<endl;
    cout << "2. Final Velocity." <<endl;
    cout << "3. Initial Velocity." <<endl;
    cout << "4. Time." <<endl;
    int answer;
    cin >> answer;
    return answer;
}

//___________________________________________________________________________________________//

//Function Menu3() is the menu of the class Medium Velocity and Acceleration.
int Menu3(){
    cout << "1. Medium Velocity of one position." <<endl;
    cout << "2. Medium Velocity of two positions and Acceleration" <<endl;
    int answer;
    cin >> answer;
    return answer;
}

//___________________________________________________________________________________________//

//Function Menu4() is the menu of the class Parabolic Shot.
int Menu4(){
    cout << "1. Position of X in a specific time." <<endl;
    cout << "2. Position of Y in a specific time." <<endl;
    cout << "3. Velocity of Y in a specific time." <<endl;
    cout << "4. Maximum X position." <<endl;
    cout << "5. Time of Maximum X position." <<endl;
    cout << "6. Maximum Y Position." <<endl;
    cout << "7. Time of Maximum Y position." <<endl;
    int answer;
    cin >> answer;
    return answer;
}


//---------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------
//Main Function

int main(){
    cout << "Welcome to the physics problem solver" << endl;
    int answer = MainMenu();
    int check = isBtwLimits(answer,1,5,MainMenu);
    
    //---------------------------------------------------------------------------------------------------------
    //---------------------------------------------------------------------------------------------------------
    //Use of the class HorizontalCinematic

    switch(check){
        case 1:{

        cout << "What value do you desire to obtain? Enter the number: "<<endl;
        int lookFor1 = Menu1();
        int lookFor1Check = isBtwLimits(lookFor1, 1, 5, Menu1);

        cout << "What value you don't have? Enter the number: (Don't choose the same number as last response)"<<endl;
        int dontHave1 = Menu1();
        int dontHave1Check = isBtwLimits(dontHave1, 1, 5, Menu1);

        switch(lookFor1Check){

            //User is looking for position
            case 1:{
                switch(dontHave1Check){
                    
                    //Lack Final Velocity
                    case 2:{
                        double vi;
                        double a;
                        double t;

                        cout <<"Enter the initial velocity: " <<endl;
                        cin >> vi;
                        cout <<"Enter the acceleration: " <<endl;
                        cin >> a;
                        cout <<"Enter the time: " <<endl;
                        cin >> t;

                        HorizontalCinematic casoX1 = HorizontalCinematic(0,vi,0,a,t);
                        double final = casoX1.getDisplacementNoVf();
                        cout <<"Your displacement is: "<< final <<endl;

                    }break;

                    //Lack Initial Velocity
                    case 3:{
                        double vf;
                        double a;
                        double t;

                        cout <<"Enter the final velocity: " <<endl;
                        cin >> vf;
                        cout <<"Enter the acceleration: " <<endl;
                        cin >> a;
                        cout <<"Enter the time: " <<endl;
                        cin >> t;

                        HorizontalCinematic casoX1 = HorizontalCinematic(0,0,vf,a,t);
                        double final = casoX1.getDisplacementNoVi();
                        cout <<"Your displacement is: "<< final <<endl;

                    }break;

                    //Lack Acceleration
                    case 4:{
                        double vf;
                        double vi;
                        double t;

                        cout <<"Enter the final velocity: " <<endl;
                        cin >> vf;
                        cout <<"Enter the initial velocity: " <<endl;
                        cin >> vi;
                        cout <<"Enter the time: " <<endl;
                        cin >> t;

                        HorizontalCinematic casoX1 = HorizontalCinematic(0.0,vi,vf,0.0,t);
                        double final = casoX1.getDisplacementNoA();
                        cout <<"Your displacement is: "<< final <<endl;

                    }break;

                    //Lack Time
                    case 5:{
                        double vf;
                        double vi;
                        double a;

                        cout <<"Enter the final velocity: " <<endl;
                        cin >> vf;
                        cout <<"Enter the initial velocity: " <<endl;
                        cin >> vi;
                        cout <<"Enter the acceleration: " <<endl;
                        cin >> a;

                        HorizontalCinematic casoX1 = HorizontalCinematic(0.0,vi,vf,a,0.0);
                        double final = casoX1.getDisplacementNoT();
                        cout <<"Your displacement is: "<< final <<endl;

                    }break;

                    default:{
                        cout << "Same number entered.\nRestart the program." << endl;
                    }
                }

            }break;

            //User is looking for the Final Velocity
            case 2:{
                switch(dontHave1Check){

                    //Lack Position
                    case 1:{
                        double vi;
                        double a;
                        double t;

                        cout <<"Enter the initial velocity: " <<endl;
                        cin >> vi;
                        cout <<"Enter the acceleration: " <<endl;
                        cin >> a;
                        cout <<"Enter the time: " <<endl;
                        cin >> t;

                        HorizontalCinematic casoX1 = HorizontalCinematic(0.0,vi,0.0,a,t);
                        double final = casoX1.getFinalVelocityNoX();
                        cout <<"Your final velocity is: "<< final <<endl;

                    }break;

                    //Lack Initial Velocity
                    case 3:{
                        double x;
                        double a;
                        double t;

                        cout <<"Enter the displacement: " <<endl;
                        cin >> x;
                        cout <<"Enter the acceleration: " <<endl;
                        cin >> a;
                        cout <<"Enter the time: " <<endl;
                        cin >> t;

                        HorizontalCinematic casoX1 = HorizontalCinematic(x,0.0,0.0,a,t);
                        double final = casoX1.getFinalVelocityNoVi();
                        cout <<"Your final velocity is: "<< final <<endl;

                    }break;

                    //Lack the accelerarion
                    case 4:{
                        double x;
                        double vi;
                        double t;

                        cout <<"Enter the displacement: " <<endl;
                        cin >> x;
                        cout <<"Enter the initial velocity: " <<endl;
                        cin >> vi;
                        cout <<"Enter the time: " <<endl;
                        cin >> t;

                        HorizontalCinematic casoX1 = HorizontalCinematic(x,vi,0.0,0.0,t);
                        double final = casoX1.getFinalVelocityNoA();
                        cout <<"Your final velocity is: "<< final <<endl;

                    }break;

                    //Lack the Time
                    case 5:{
                        double x;
                        double vi;
                        double a;

                        cout <<"Enter the displacement: " <<endl;
                        cin >> x;
                        cout <<"Enter the initial velocity: " <<endl;
                        cin >> vi;
                        cout <<"Enter the acceleration: " <<endl;
                        cin >> a;

                        HorizontalCinematic casoX1 = HorizontalCinematic(x,vi,0.0,a,0.0);
                        double final = casoX1.getFinalVelocityNoT();
                        cout <<"Your final velocity is: "<< final <<endl;

                    }break;

                    default:{
                        cout << "Same number entered.\nRestart the program" << endl;
                    }
                }


            }break;

            //User is looking for the Initial Velocity
            case 3:{
                switch(dontHave1Check){
                    //Lack Position
                    case 1:{
                        double vf;
                        double a;
                        double t;

                        cout <<"Enter the final velocity: " <<endl;
                        cin >> vf;
                        cout <<"Enter the acceleration: " <<endl;
                        cin >> a;
                        cout <<"Enter the time: " <<endl;
                        cin >> t;

                        HorizontalCinematic casoX1 = HorizontalCinematic(0.0,0.0,vf,a,t);
                        double final = casoX1.getInitialVelocityNoX();
                        cout <<"Your initial velocity is: "<< final <<endl;

                    }break;

                    //Lack Final Velocity
                    case 2:{
                        double x;
                        double a;
                        double t;

                        cout <<"Enter the displacement: " <<endl;
                        cin >> x;
                        cout <<"Enter the acceleration: " <<endl;
                        cin >> a;
                        cout <<"Enter the time: " <<endl;
                        cin >> t;

                        HorizontalCinematic casoX1 = HorizontalCinematic(x,0.0,0.0,a,t);
                        double final = casoX1.getInitialVelocityNoVf();
                        cout <<"Your initial velocity is: "<< final <<endl;

                    }break;

                    //Lack the accelerarion
                    case 4:{
                        double x;
                        double vf;
                        double t;

                        cout <<"Enter the displacement: " <<endl;
                        cin >> x;
                        cout <<"Enter the final velocity: " <<endl;
                        cin >> vf;
                        cout <<"Enter the time: " <<endl;
                        cin >> t;

                        HorizontalCinematic casoX1 = HorizontalCinematic(x,0.0,vf,0.0,t);
                        double final = casoX1.getInitialVelocityNoA();
                        cout <<"Your initial velocity is: "<< final <<endl;

                    }break;

                    //Lack the Time
                    case 5:{
                        double x;
                        double vf;
                        double a;

                        cout <<"Enter the displacement: " <<endl;
                        cin >> x;
                        cout <<"Enter the final velocity: " <<endl;
                        cin >> vf;
                        cout <<"Enter the acceleration: " <<endl;
                        cin >> a;

                        HorizontalCinematic casoX1 = HorizontalCinematic(x,0.0,vf,a,0.0);
                        double final = casoX1.getInitialVelocityNoT();
                        cout <<"Your initial velocity is: "<< final <<endl;

                    }break;

                    default:{
                        cout << "Same number entered.\nRestart the program" << endl;
                    }
                }

            }break;

            //User is looking for the Acceleration
            case 4:{
                switch(dontHave1Check){
                    //Lack Position
                    case 1:{
                        double vf;
                        double vi;
                        double t;

                        cout <<"Enter the final velocity: " <<endl;
                        cin >> vf;
                        cout <<"Enter the initial velocity: " <<endl;
                        cin >> vi;
                        cout <<"Enter the time: " <<endl;
                        cin >> t;

                        HorizontalCinematic casoX1 = HorizontalCinematic(0.0,vi,vf,0.0,t);
                        double final = casoX1.getAccelerationNoX();
                        cout <<"Your acceleration is: "<< final <<endl;

                    }break;

                    //Lack Final Velocity
                    case 2:{
                        double x;
                        double vi;
                        double t;

                        cout <<"Enter the displacement: " <<endl;
                        cin >> x;
                        cout <<"Enter the initial velocity: " <<endl;
                        cin >> vi;
                        cout <<"Enter the time: " <<endl;
                        cin >> t;

                        HorizontalCinematic casoX1 = HorizontalCinematic(x,vi,0.0,0.0,t);
                        double final = casoX1.getAccelerationNoVf();
                        cout <<"Your acceleration is: "<< final <<endl;

                    }break;

                    //Lack the Initial Velocity
                    case 3:{
                        double x;
                        double vf;
                        double t;

                        cout <<"Enter the displacement: " <<endl;
                        cin >> x;
                        cout <<"Enter the final velocity: " <<endl;
                        cin >> vf;
                        cout <<"Enter the time: " <<endl;
                        cin >> t;

                        HorizontalCinematic casoX1 = HorizontalCinematic(x,0.0,vf,0.0,t);
                        double final = casoX1.getAccelerationNoVi();
                        cout <<"Your acceleration is: "<< final <<endl;

                    }break;

                    //Lack the Time
                    case 5:{
                        double x;
                        double vf;
                        double vi;

                        cout <<"Enter the displacement: " <<endl;
                        cin >> x;
                        cout <<"Enter the final velocity: " <<endl;
                        cin >> vf;
                        cout <<"Enter the initial velocity: " <<endl;
                        cin >> vi;

                        HorizontalCinematic casoX1 = HorizontalCinematic(x,vi,vf,0.0,0.0);
                        double final = casoX1.getAccelerationNoT();
                        cout <<"Your acceleration is: "<< final <<endl;

                    }break;

                    default:{
                        cout << "Same number entered.\nRestart the program" << endl;
                    }
                }

            }break;

            //User is looking for Time
            case 5:{
                switch(dontHave1Check){
                    //Lack Position
                    case 1:{
                        double vf;
                        double vi;
                        double a;

                        cout <<"Enter the final velocity: " <<endl;
                        cin >> vf;
                        cout <<"Enter the initial velocity: " <<endl;
                        cin >> vi;
                        cout <<"Enter the acceleration: " <<endl;
                        cin >> a;

                        HorizontalCinematic casoX1 = HorizontalCinematic(0.0,vi,vf,a,0.0);
                        double final = casoX1.getTimeNoX();
                        cout <<"Your time is: "<< final <<endl;

                    }break;

                    //Lack Final Velocity
                    case 2:{
                        double x;
                        double vi;
                        double a;

                        cout <<"Enter the displacement: " <<endl;
                        cin >> x;
                        cout <<"Enter the initial velocity: " <<endl;
                        cin >> vi;
                        cout <<"Enter the acceleration: " <<endl;
                        cin >> a;

                        HorizontalCinematic casoX1 = HorizontalCinematic(x,vi,0.0,a,0.0);
                        double final = casoX1.getTimeNoVf();
                        cout <<"Your time is: "<< final <<endl;

                    }break;

                    //Lack the Initial Velocity
                    case 3:{
                        double x;
                        double vf;
                        double a;

                        cout <<"Enter the displacement: " <<endl;
                        cin >> x;
                        cout <<"Enter the final velocity: " <<endl;
                        cin >> vf;
                        cout <<"Enter the acceleration: " <<endl;
                        cin >> a;

                        HorizontalCinematic casoX1 = HorizontalCinematic(x,0.0,vf,a,0.0);
                        double final = casoX1.getTimeNoVi();
                        cout <<"Your time is: "<< final <<endl;

                    }break;

                    //Lack the Acceleration
                    case 4:{
                        double x;
                        double vf;
                        double vi;

                        cout <<"Enter the displacement: " <<endl;
                        cin >> x;
                        cout <<"Enter the final velocity: " <<endl;
                        cin >> vf;
                        cout <<"Enter the initial velocity: " <<endl;
                        cin >> vi;

                        HorizontalCinematic casoX1 = HorizontalCinematic(x,vi,vf,0.0,0.0);
                        double final = casoX1.getTimeNoA();
                        cout <<"Your time is: "<< final <<endl;

                    }break;

                    default:{
                        cout << "Same number entered.\nRestart the program" << endl;
                    }
                }

            }break;

        }


        }break;


        //---------------------------------------------------------------------------------------------------------
        //---------------------------------------------------------------------------------------------------------
        //Use of the class VerticalCinematic

        case 2:{
        cout << "What value do you desire to obtain? Enter the number: "<<endl;
        int lookFor1 = Menu2();
        int lookFor1Check = isBtwLimits(lookFor1, 1, 4, Menu2);

        cout << "What value you don't have? Enter the number: (Don't choose the same number as last response)"<<endl;
        int dontHave1 = Menu2();
        int dontHave1Check = isBtwLimits(dontHave1, 1, 4, Menu2);

        switch(lookFor1Check){

            //User is looking for Position Y
            case 1:{
                switch(dontHave1Check){
                    //Lack Final Velocity
                    case 2:{
                        double vi;
                        double t;

                        cout <<"Enter the initial velocity: " <<endl;
                        cin >> vi;
                        cout <<"Enter the time: " <<endl;
                        cin >> t;

                        VerticalCinematic Case1 = VerticalCinematic(0.0,vi,0.0,t);
                        double result = Case1.getDisplacementYNoVf();
                        cout <<"Your displacement is: "<< result <<endl;


                    }break;

                    //Lack Initial Velocity
                    case 3:{
                        double vf;
                        double t;

                        cout <<"Enter the final velocity: " <<endl;
                        cin >> vf;
                        cout <<"Enter the time: " <<endl;
                        cin >> t;

                        VerticalCinematic Case1 = VerticalCinematic(0.0,0.0,vf,t);
                        double result = Case1.getDisplacementYNoVi();
                        cout <<"Your displacement is: "<< result <<endl;


                    }break;

                    //Lack Time
                    case 4:{
                        double vi;
                        double vf;

                        cout <<"Enter the initial velocity: " <<endl;
                        cin >> vi;
                        cout <<"Enter the final velocity: " <<endl;
                        cin >> vf;

                        VerticalCinematic Case1 = VerticalCinematic(0.0,vi,vf,0.0);
                        double result = Case1.getDisplacementYNoT();
                        cout <<"Your displacement is: "<< result <<endl;

                    }break;
                }

            }break;

            //User is looking for Final Velocity
            case 2: {
                switch(dontHave1Check){
                    //Lack Position Y
                    case 1:{
                        double vi;
                        double t;

                        cout <<"Enter the initial velocity: " <<endl;
                        cin >> vi;
                        cout <<"Enter the time: " <<endl;
                        cin >> t;

                        VerticalCinematic Case1 = VerticalCinematic(0.0,vi,0.0,t);
                        double result = Case1.getFinalVelocityNoY();
                        cout <<"Your final velocity is: "<< result <<endl;

                    }break;

                    //Lack Initial Velocity
                    case 3:{
                        double posy;
                        double t;

                        cout <<"Enter the displacement in Y: " <<endl;
                        cin >> posy;
                        cout <<"Enter the time: " <<endl;
                        cin >> t;

                        VerticalCinematic Case1 = VerticalCinematic(posy,0.0,0.0,t);
                        double result = Case1.getFinalVelocityNoViVC();
                        cout <<"Your final velocity is: "<< result <<endl;

                    }break;

                    //Lack Time
                    case 4:{
                        double vi;
                        double posy;

                        cout <<"Enter the initial velocity: " <<endl;
                        cin >> vi;
                        cout <<"Enter displacement in Y: " <<endl;
                        cin >> posy;

                        VerticalCinematic Case1 = VerticalCinematic(posy,vi,0.0,0.0);
                        double result = Case1.getFinalVelocityNoTVC();
                        cout <<"Your final velocity is: "<< result <<endl;

                    }break;
                }

            }break;

            //User is looking for Initial Velocity
            case 3: {
                switch(dontHave1Check){
                    //Lack Position Y
                    case 1:{
                        double vf;
                        double t;

                        cout <<"Enter the final velocity: " <<endl;
                        cin >> vf;
                        cout <<"Enter the time: " <<endl;
                        cin >> t;

                        VerticalCinematic Case1 = VerticalCinematic(0.0,0.0,vf,t);
                        double result = Case1.getInitialVelocityNoY();
                        cout <<"Your initial velocity is: "<< result <<endl;

                    }break;

                    //Lack Final Velocity
                    case 2:{
                        double posy;
                        double t;

                        cout <<"Enter the displacement in Y: " <<endl;
                        cin >> posy;
                        cout <<"Enter the time: " <<endl;
                        cin >> t;

                        VerticalCinematic Case1 = VerticalCinematic(posy,0.0,0.0,t);
                        double result = Case1.getInitialVelocityNoVfVC();
                        cout <<"Your initial velocity is: "<< result <<endl;

                    }break;

                    //Lack Time
                    case 4:{
                        double vf;
                        double posy;

                        cout <<"Enter the final velocity: " <<endl;
                        cin >> vf;
                        cout <<"Enter the displacement in Y: " <<endl;
                        cin >> posy;

                        VerticalCinematic Case1 = VerticalCinematic(posy,0.0,vf,0.0);
                        double result = Case1.getInitialVelocityNoTVC();
                        cout <<"Your initial velocity is: "<< result <<endl;

                    }break;
                }

            }break;

            //User is looking for Time
            case 4: {
                switch(dontHave1Check){
                    //Lack Position Y
                    case 1:{
                        double vf;
                        double vi;

                        cout <<"Enter the final velocity: " <<endl;
                        cin >> vf;
                        cout <<"Enter the initial velocity:: " <<endl;
                        cin >> vi;

                        VerticalCinematic Case1 = VerticalCinematic(0.0,vi,vf,0.0);
                        double result = Case1.getTimeNoY();
                        cout <<"Your time is: "<< result <<endl;

                    }break;

                    //Lack Final Velocity
                    case 2:{
                        double posy;
                        double vi;

                        cout <<"Enter the displacement in Y: " <<endl;
                        cin >> posy;
                        cout <<"Enter the initial velocity:: " <<endl;
                        cin >> vi;

                        VerticalCinematic Case1 = VerticalCinematic(posy,vi,0.0,0.0);
                        double result = Case1.getTimeNoVfVC();
                        cout <<"Your time is: "<< result <<endl;

                    }break;

                    //Lack Initial Velocity
                    case 3:{
                        double posy;
                        double vf;

                        cout <<"Enter the displacement in Y: " <<endl;
                        cin >> posy;
                        cout <<"Enter the final velocity:: " <<endl;
                        cin >> vf;

                        VerticalCinematic Case1 = VerticalCinematic(posy,0.0,vf,0.0);
                        double result = Case1.getTimeNoViVC();
                        cout <<"Your time is: "<< result <<endl;

                    }break;
                }

            }break;
        }


        }break;


        //---------------------------------------------------------------------------------------------------------
        //---------------------------------------------------------------------------------------------------------
        //Use of the class MediumVAndA

        case 3:{
        cout << "What do you desire to obtain? Enter the number: "<<endl;
        int lookFor1 = Menu3();
        int lookFor1Check = isBtwLimits(lookFor1, 1, 2, Menu3);

        
        switch(lookFor1Check){
            //Getting the Medium Velocity of One Position
            case 1:{
                double posx1;
                double posx2;
                double posy1;
                double posy2;
                double time;

                cout <<"Enter the position in X No. 1: " <<endl;
                cin >> posx1;
                cout <<"Enter the position in X No. 2: " <<endl;
                cin >> posx2;
                cout <<"Enter the position in Y No. 1: " <<endl;
                cin >> posy1;
                cout <<"Enter the position in Y No. 2: " <<endl;
                cin >> posy2;
                cout <<"Enter the time between movement: " <<endl;
                cin >> time;

                MediumVAndA Case3 = MediumVAndA(posx1,posy1,posx2,posy2,time);
                double velocityX = Case3.getMediumVelocityx1();
                double velocityY = Case3.getMediumVelocityy1();
                cout << "The medium velocity in the x axis is: "<<velocityX <<" and in the y axis is: "<<velocityY<<endl;

            }break;


            //Getting the Medium Velocity of Two Positions
            case 2:{
                double posx1;
                double posx2;
                double posy1;
                double posy2;
                double time;
                double posx3;
                double posx4;
                double posy3;
                double posy4;
                double time2;
                double timeBtw;

                cout <<"Enter the position in X No. 1 of your 1st displacement: " <<endl;
                cin >> posx1;
                cout <<"Enter the position in X No. 2 of your 1st displacement: " <<endl;
                cin >> posx2;
                cout <<"Enter the position in Y No. 1 of your 1st displacement:  " <<endl;
                cin >> posy1;
                cout <<"Enter the position in Y No. 2 of your 1st displacement: " <<endl;
                cin >> posy2;
                cout <<"Enter the time between of your 1st displacement: : " <<endl;
                cin >> time;
                cout <<"Enter the position in X No. 1 of your 2nd displacement: " <<endl;
                cin >> posx3;
                cout <<"Enter the position in X No. 2 of your 2nd displacement: " <<endl;
                cin >> posx4;
                cout <<"Enter the position in Y No. 1 of your 2nd displacement:  " <<endl;
                cin >> posy3;
                cout <<"Enter the position in Y No. 2 of your 2nd displacement: " <<endl;
                cin >> posy4;
                cout <<"Enter the time between of your 2nd displacement: : " <<endl;
                cin >> time2;
                cout <<"Enter the time between your two displacements: "<<endl;
                cin >> timeBtw;

                MediumVAndA Case3 = MediumVAndA(posx1,posy1,posx2,posy2,time,posx3,posy3,posx4,posy4,time2,timeBtw);
                double velocityX = Case3.getMediumVelocityx1();
                double velocityY = Case3.getMediumVelocityy1();
                double velocityX1 = Case3.getMediumVelocityx2();
                double velocityY1 = Case3.getMediumVelocityy2();
                double AccelerationX = Case3.getAccelerationX();
                double AccelerationY = Case3.getAccelerationY();

                cout << "The medium velocity in the x axis  of your 1st displacement is: "<<velocityX <<endl;
                cout <<" And in the y axis is: "<<velocityY<<endl;
                cout << "The medium velocity in the x axis  of your 2nd displacement is: "<<velocityX1 <<endl;
                cout <<" And in the y axis is: "<<velocityY1<<endl;
                cout <<" Acceleration in X: "<<AccelerationX<<endl;
                cout <<" Acceleration in Y: "<<AccelerationY<<endl;


            }break;

        }

        }break;


        //---------------------------------------------------------------------------------------------------------
        //---------------------------------------------------------------------------------------------------------
        //Use of the class ParabolicShot

        case 4:{
        cout << "What do you desire to obtain? Enter the number: "<<endl;
        int lookFor1 = Menu4();
        int lookFor1Check = isBtwLimits(lookFor1, 1, 7, Menu4);

        double iniV;
        double ang;
        double st;

        cout <<"Enter the inicial velocity: " <<endl;
        cin >> iniV;
        cout <<"Enter the angle of inclination : " <<endl;
        cin >> ang;
        cout <<"Enter the specific time to analize (if there is none type 0): "<<endl;
        cin >> st;

        ParabolicShot Case4 = ParabolicShot(iniV,ang,st);


        switch(lookFor1Check){
            case 1:{
                double result = Case4.getPositionXInTime();
                cout<<"Your position in X in time "<<Case4.getSpecificTime()<<" is: "<<result;

            }break;

            case 2:{
                double result = Case4.getPositionYInTime();
                cout<<"Your position in Y in time "<<Case4.getSpecificTime()<<" is: "<<result<<endl<<endl;

            }break;

            case 3:{
                double result = Case4.getVelocityYinTime();
                cout<<"Your velocity in Y in time "<<Case4.getSpecificTime()<<" is: "<<result<<endl;

            }break;

            case 4:{
                double result = Case4.getMaximumX();
                cout<<"Your Maximum X Position is: "<<result <<endl;

            }break;

            case 5:{
                double result = Case4.getTimeMaxX();
                cout<<"The time of the Maximum X Position is: "<<result <<endl;

            }break;

            case 6:{
                double result = Case4.getMaximumY();
                cout<<"Your Maximum Y Position is: "<<result <<endl;

            }break;

            case 7:{
                double result = Case4.getTimeMaxY();
                cout<<"The time of the Maximum Y Position is: "<<result <<endl;

            }break;

        }

        }break;

        //---------------------------------------------------------------------------------------------------------
        //---------------------------------------------------------------------------------------------------------
        //Use of all the methods of each class for demostration purposes

        case 5: {

            //---------------------------------------------------------------------------------------------------------
            //Class HorizontalKinematics.h
            cout<<"Class No. 1 Horizontal Kinematics"<<endl;
            cout<<" "<<endl;

            HorizontalCinematic Case1 = HorizontalCinematic(20,0,40,2,20);

            cout<<"Displacement: No Acceleration            "<<Case1.getDisplacementNoA()<<endl;
            cout<<"Displacement: No Time                    "<<Case1.getDisplacementNoT()<<endl;
            cout<<"Displacement: No Final Velocity          "<<Case1.getDisplacementNoVf()<<endl;
            cout<<"Displacement: No Initial Velocity        "<<Case1.getDisplacementNoVi()<<endl;

            cout<<"Final Velocity: No Acceleration          "<<Case1.getFinalVelocityNoA()<<endl;
            cout<<"Final Velocity: No Time                  "<<Case1.getFinalVelocityNoT()<<endl;
            cout<<"Final Velocity: No Initial Velocity      "<<Case1.getFinalVelocityNoVi()<<endl;
            cout<<"Final Velocity: No Displacement in X     "<<Case1.getFinalVelocityNoX()<<endl;

            cout<<"Initial Velocity: No Acceleration        "<<Case1.getInitialVelocityNoA()<<endl;
            cout<<"Initial Velocity: No Time                "<<Case1.getInitialVelocityNoT()<<endl;
            cout<<"Initial Velocity: No Final Velocity      "<<Case1.getInitialVelocityNoVf()<<endl;
            cout<<"Initial Velocity: No Displacement in X   "<<Case1.getInitialVelocityNoX()<<endl;

            cout<<"Acceleration: No Time                    "<<Case1.getAccelerationNoT()<<endl;
            cout<<"Acceleration: No Final Velocity          "<<Case1.getAccelerationNoVf()<<endl;
            cout<<"Acceleration: No Initial Velocity        "<<Case1.getAccelerationNoVi()<<endl;
            cout<<"Acceleration: No Displacement in X       "<<Case1.getAccelerationNoX()<<endl;

            cout<<"Time: No Acceleration                    "<<Case1.getTimeNoA()<<endl;
            cout<<"Time: No Final Velocity                  "<<Case1.getTimeNoVf()<<endl;
            cout<<"Time: No Initial Velocity                "<<Case1.getTimeNoVi()<<endl;
            cout<<"Time: No Displacement in X               "<<Case1.getTimeNoX()<<endl;
            cout<<" "<<endl;

            //---------------------------------------------------------------------------------------------------------
            //Class VerticalKinematics.h
            cout<<"Class No. 2 Vertical Kinematics"<<endl;
            cout<<" "<<endl;

            VerticalCinematic Case2 = VerticalCinematic(0,0,-50,5.09684);

            cout<<"Displacement: No Time                    "<<Case2.getDisplacementYNoT()<<endl;
            cout<<"Displacement: No Final Velocity          "<<Case2.getDisplacementYNoVf()<<endl;
            cout<<"Displacement: No Initial Velocity        "<<Case2.getDisplacementYNoVi()<<endl;

            cout<<"Final Velocity: No Time                  "<<Case2.getFinalVelocityNoTVC() <<endl;
            cout<<"Final Velocity: No Initial Velocity      "<<Case2.getFinalVelocityNoViVC()<<endl;
            cout<<"Final Velocity: No Displacement in Y     "<<Case2.getFinalVelocityNoY()<<endl;

            cout<<"Initial Velocity: No Time                "<<Case2.getInitialVelocityNoTVC()<<endl;
            cout<<"Initial Velocity: No Final Velocity      "<<Case2.getInitialVelocityNoVfVC()<<endl;
            cout<<"Initial Velocity: No Displacement in Y   "<<Case2.getInitialVelocityNoY()<<endl;

            cout<<"Time: No Final Velocity                  "<<Case2.getTimeNoVfVC()<<endl;
            cout<<"Time: No Initial Velocity                "<<Case2.getTimeNoViVC()<<endl;
            cout<<"Time: No Displacement in Y               "<<Case2.getTimeNoY()<<endl;
            cout<<" "<<endl;


            //---------------------------------------------------------------------------------------------------------
            //Class MediumVAndA.h
            cout<<"Class No. 3 Medium Velocity and Acceleration"<<endl;
            cout<<" "<<endl;

            MediumVAndA Case3 = MediumVAndA(1.0,1.0,10.0,2.0,2.0,15.0,3.0,20.0,4.0,2.0,2.0);

            cout<<"Medium Velocity in X of the 1st Position "<<Case3.getMediumVelocityx1()<<endl;
            cout<<"Medium Velocity in Y of the 1st Position "<<Case3.getMediumVelocityy1()<<endl;
            cout<<"Medium Velocity in X of the 2st Position "<<Case3.getMediumVelocityx2()<<endl;
            cout<<"Medium Velocity in Y of the 2st Position "<<Case3.getMediumVelocityy2()<<endl;
            cout<<"Medium Acceleration in X:                "<<Case3.getAccelerationX()<<endl;
            cout<<"Medium Acceleration in Y:                "<<Case3.getAccelerationY()<<endl;
            cout<<" "<<endl;


            //---------------------------------------------------------------------------------------------------------
            //Class ParabolicShot.h
            cout<<"Class No. 4 Parabolic Shot"<<endl;
            cout<<" "<<endl;

            ParabolicShot Case4 = ParabolicShot(65.0,30,5);

            cout<<"Position of the proyectile in X at a specific time:  "<<Case4.getPositionXInTime()<<endl;
            cout<<"Position of the proyectile in Y at a specific time:  "<<Case4.getPositionYInTime()<<endl;
            cout<<"Velocity of the proyectile in X at a specific time:  "<<Case4.getVelocityYinTime()<<endl;
            cout<<"Range of the Parabole:                               "<<Case4.getMaximumX()<<endl;
            cout<<"Time when the proyectile reach the range:            "<<Case4.getTimeMaxX()<<endl;
            cout<<"Maximum height of the parabole:                      "<<Case4.getMaximumY()<<endl;
            cout<<"Time when the proyectile reach the maximum height:   "<<Case4.getTimeMaxY()<<endl;
            cout<<" "<<endl;

            

        }break;
    }

    return 0;
}