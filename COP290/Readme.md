#ED Software Package:-

This repository holds the documentation and code for the assignment in the Course COP290 (Design Practices). The aim of this project is to develop a software package for Engineering Drawing.

# Project Specifications:-
Design and implementation a software package for Engineering drawing. The package will
have the following functionalities:
1. We should be able to interactively input or read from a file :-
i.) an isometric drawing
ii.) a 3D object model
iii.) projections on to any cross section.
2. Given a 3D model description we should be able to generate Orthographic Projections
on to any cross section or cutting plane.
3. Given three orthographic projections we should be able to recover the 3D description
of the object.

# Usage :-
git clone <url>
sudo apt-get install freeglut3 freeglut3-dev 
sudo apt-get install mesa-common-dev libgtkmm-3.0-dev
g++ -c -o Main.o Main.cpp
g++ -o Main Main.o -lglut -lGLU -lGL 
./Main
