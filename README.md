# Physics Problem Solver - Proyect - Object Oriented Computational Thinking 

Author: Rodrigo Alejandro Hurtado Cortés - A01713854 

## General Description
In the proyect exposed below I present the Physics Problem Solver.
This program help the user solve physics ecuations looking for specific values between the four classes that contain the mathematical formulas that help obtain the desired value.
These classes and values they help the user obtain are:



## Classes

The UML diagram of the relationship between the proyect's classes can be appreciated below:

<img src="https://github.com/user-attachments/assets/80fb1830-9c53-4f48-8447-2de6af64a024" style="width:70%; height:auto;">


### - **Kinematics** ("Kinematics.h")


Parent abstract class that constains all the attributes of Horizontal and Vertical Kinematics as well as their common formulas to obtain displacement in x and y, initial velocity, final velocity, and time; excluding acceleration.

The similarity between their respective formulas can be found in the images below.


![Kinematics](https://github.com/user-attachments/assets/85ca9ae0-3798-4a7b-bd8c-8c97792184ff)



### - **Horizontal Kinematics** ("HorizontalCinematic.h")


Class that focuses on obtaining displacement in x and y, initial velocity, final velocity, and time in the absence of acceleration, as well as acceleration using the five formulas of horizontal kinematics and the inheritance from Kinematics.h.

<img src="https://study.com/cimages/videopreview/wceuhfpfz2.jpg" width=50% height=50%>

The value that the user desires to obtain and the value the user does not have is specified by him/her in the menus.


<img src="https://github.com/user-attachments/assets/badc04a0-79e2-4518-88fe-b20c4584927d" style="width:30%; height:auto;">


### - **Vertical Kinematics** ("VerticalCinematic.h")


This class uses inheritance from Kinematics.h keeping only its constructors due to the acceleration that will remain constant as the value of gravity acceleration 9.81, therefore entering it as a fixed parameter inside the constructor of Kinematics.


<img src="https://github.com/user-attachments/assets/6985ae1f-962c-47b4-b005-4c6ea8c16b66" style="width:30%; height:auto;">


### - **Medium Velocity and Medium Acceleration** ("MediumVAndA.h")


Simple class where the user can choose to obtain the medium velocity of one displacement, or obtain the medium velocity of two displacement in the same system and therefore the acceleration between them based on the formulas:

<img src="https://assets.ltkcontent.com/images/6490/difference-velocity-acceleration_27c5571306.jpg" width=50% height=50%>


Both the velocity and acceleration are divided into Y and X axis due to their posible vectorial influence.


![MEDIUMA](https://github.com/user-attachments/assets/6c619fa2-fd80-4616-9c22-3f68d45d5961)


### - **Position** ("Position.h")

Class responsible for holding position objects that contain an element in the "x" axis as well as the "y" axis; which are used to calculate Medium Velocity and Acceleration in their independent axis.


<img src="https://github.com/user-attachments/assets/e36732ce-703e-4978-808a-031f7847f847" style="width:30%; height:auto;">



### - **Parabolic Shot** ("ParabolicShot.h")

Through the present class the user will enter the inivial velocity and angle at which a proyectile was shot and can be able to know a specific position in the X and Y axis at a specific time, velocity in the Y axis at a specific time, maximum values of height and range of the parabola as well as the moments the proyectile arrived at these points. All this functionality based on the following formulas:

<img src="https://physicsqanda.com/wp-content/uploads/2023/01/SmartSelect_20230119_111554_Samsung-Notes-1024x641.jpg" width=50% height=50%>


![ParabolicShot](https://github.com/user-attachments/assets/ac970a58-3331-4f74-aa61-8a884da3d033)



## ProyectPhysics.cpp

The main program that generates an executable (.exe) file is called ProyectPhysics.cpp.
This program is divided into menus that guide the user inside the different classes and solutions they may be looking for through switches, following the specifications of each class previously explained.
Inside these menus the user must type a number between the limits of the menu and follow any specification typed by the program until finally obtain the result to their problem based on their input data.

A 5th option was added to the Main menu which helps the user to check the working of all the functions with predetermined established data.


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
