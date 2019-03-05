/**************************************************************
Find Pi With Monte Carlo

Student Name: Bin (Quoc Dat Phung)           Ms. Lindsay Cullum
Grade       : 11                            ICS4U

                                            Due  :  March 05, 2019

OBJECTIVE
    Calculate the chance of the program generating a point
    inside a circle. The circle is inscribed in a square.
****************************************************************/

#include <iostream>
using namespace std;
#include <math.h>
#include <random>
#include <time.h>

#define Pi 3.14159265358979323846

int main () {
    ///INPUT
//Declaring Variables
    double counter = 0;     //counter to see how many times the point is in the circle.
    double r = 1;           //our radius is 1
    double circle;             //AREA OF CIRCLE
    double square;             //AREA OF SQUARE
    double x;               //coordinate of x
    double y;               //coordinate of y
    double side = 2 * r;    //a square's side is twice the circle's radius
    double total = 1000;    //the total points or number of times that the loop will run.

//Time Seed
    srand(time(0));

//Calculate the area of circle and square.
    circle = Pi * pow(r, 2);
    square = pow(side, 2);

    ///Calculation
//looping
    for (int i = 0; i < total; i++) {
        //rand()%6 + 1 means pick between 6 and 1.
        //the below means to pick a point within the radius of the SQUARE, NOT CIRCLE yet
        //later on you will see that the number is divided again by 100.
        //this is not redundant, r is 1. we don't want a random number between 1 and 0
        //we want a number as a decimal between 1 and 0.
        //later on we can use an algorithm to check if the point is in the square or circle.
        x = rand()% 100*r ;
        y = rand()% 100*r;
        x = x/100;
        y = y/100;

        //the square root of x^2 + y^2 gives us the hypotenuse (radius of circle). As long as
        //the hypotenuse is equal or smaller than the actual radius,...
        //then the point is generated within the circle.
        if (sqrt(x*x + y*y) < r) {
            counter++;
        }
    }

    ///OUTPUT
    cout << "The Circle's Area is " << circle << " units^2" << endl;
    cout << "The Square's Area is " << square << " units^2" << endl;
    cout << "Chances of point landing in the circle is " << counter*4/total << " %" << endl;

    return 0;
}
