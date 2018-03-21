# ED Software Package:-

This repository holds the documentation and code for the assignment in the Course COP290 (Design Practices). The aim of this project is to develop a software package for Engineering Drawing.

# Project Specifications:-
Design and implementation a software package for Engineering drawing. The package will
have the following functionalities:
1. We should be able to interactively input or read from a file :-
i.) an isometric drawing
ii.) a 3D object model
iii.) projections on to any cross section plane.
2. Given a 3D model description we should be able to generate Orthographic Projections
on to any cross section or cutting plane.
3. Given three orthographic projections we should be able to recover the 3D description
of the object.

# Directions to Use :-
1. compile using make command 
2. change directory to build by using cd build
3. use ./main to run the executable file
4. write the input file name on command prompt (text file)
5. Enjoy the rotation functionality if using the 2D to 3D.

# Assumptions:-
1. if the plane of projection is above the origin then its considered to be top view else bottom view.
2. 3D objects are represented as wire-frame model.

# Changes after last submission:-
Have removed some files like AuxilliaryFunc2D.h, AuxilliaryFunc3D.h, Recreate2D.h, Recreate3D.h, Reduce2D.h and Recreate3D.h due to following reasons
1. The input taken is already in a reduced form.
2. Recreate part is incorporated in 3Dto2D.cpp.
3. Auxilliary functions(Rotate) is used only in only one case so didn't make much sense to create a seperate file for that.
4. corresponding .cpp files for the .h files are made and the directory is restructure so that it become same as Proff. SuBan directed in the session just after submission of last part.  	 


