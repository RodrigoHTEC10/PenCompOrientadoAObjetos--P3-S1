# Physics Problem Solver - Proyect - Object Oriented Computational Thinking 

Author: Rodrigo Alejandro Hurtado Cortés - A01713854 

## General Description
In the proyect exposed below I present the Physics Problem Solver.
This program help the user solve physics ecuations looking for specific values between the four classes that contain the mathematical formulas that help obtain the desired value.
These classes and values they help the user obtain are:


## Classes
### - **Horizontal Kinematics** ("HorizontalCinematic.h")


Using the following formulas and isolating the values to obtain, there are a total of 4 ways of obtain each value (displacement in x, initial velocity, final velocity, acceleration, and time) , each one with the abscense of another, therefore each formula uses only three values entered by the user.

<img src="https://study.com/cimages/videopreview/wceuhfpfz2.jpg" width=50% height=50%>

The value that the user desires to obtain and the value the user does not have is specified by him/her in the menus.

### - **Vertical Kinematics** ("VerticalCinematic.h")


Similarly to the class Horizontal Kinematics, using inheritance due to the similarity between their formulas, the user who desires to use this class will specify the value its looking for as well as the value he does not have through menus. Following this, him/her will enter the initial data of the remaining variables to receive the result based on the function that ended up using.

Differently to the Horizontal Kinematics class, the acceleration will remain constant as the value of gravity acceleration 9.81, therefore there are a total of 3 ways to obtain the remaining four values participant in Kinematics (Displacement in y, initial velocity, final velocity, and time).


### - **Medium Velocity and Medium Acceleration** ("MediumVAndA.h")


Simple class where the user can choose to obtain the medium velocity of one displacement, or obtain the medium velocity of two displacement in the same system and therefore the acceleration between them based on the formulas:

<img src="https://assets.ltkcontent.com/images/6490/difference-velocity-acceleration_27c5571306.jpg" width=50% height=50%>


Both the velocity and acceleration are divided into Y and X axis due to their posible vectorial influence.


### - **Parabolic Shot** ("ParabolicShot.h")

Through the present class the user will enter the inivial velocity and angle at which a proyectile was shot and can be able to know a specific position in the X and Y axis at a specific time, velocity in the Y axis at a specific time, maximum values of height and range of the parabola as well as the moments the proyectile arrived at these points. All this functionality based on the following formulas:

<img src="https://physicsqanda.com/wp-content/uploads/2023/01/SmartSelect_20230119_111554_Samsung-Notes-1024x641.jpg" width=50% height=50%>


## ProyectPhysics.cpp

The main program that generates an executable (.exe) file is called ProyectPhysics.cpp.
This program is divided into menus that guide the user inside the different classes and solutions they may be looking for through switches, following the specifications of each class previously explained.
Inside these menus the user must type a number between the limits of the menu and follow any specification typed by the program until finally obtain the result to their problem based on their input data.


## Considerations: Units to Use
The units accepted for this program must follow the next conventions in order to receive a correct result.

- Distance: meters (m).
- Velocity: meters / second (m/s).
- Accelerations: meters/second ^2 (m/s^2).
- Angles: degrees (°).
- Time: seconds (s).
- Positions: any point in the x or y axis measured in meters (m).

Depending on the result obtained, it can be interpreted as given in one of the previous units.

Example: The user looking for acceleration without having a displacement. Obtained 10.2 in the X axis and 2.5 in the Y axis.
Therefore these results can be interpreted as 10.2 m/s^2 and 2.5 m/s^2 respectively.

## Recommendations
The menus of the proyect only accept integers, therefore only type the simple number.
Enjoy the program.
