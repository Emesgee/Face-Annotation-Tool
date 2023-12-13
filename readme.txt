The compiled file with submission.exe was too large so please follow the instructions below to run the code.


############################################################
To run the code correctly please do the following steps.
############################################################
1) open cmd line and g to the \build folder 

2) type: cmake -G "Visual Studio 16 2019" ..
You can choose your own VS version in my case it was:  cmake -G "Visual Studio 17 2022" ..

3) cmake --build . --config Release

4) Now, to run the executable: \build\Release\submission.exe


###############################
Adjustments. 
###############################
1) cmakeChache.txt has been deleted from the build folder
2) submission.exe has also been deleted due to its large size. 
3)The sample image file is in the Release Folder. 
- So no need to change the image path in submission.cpp code.
4) You can save numerous cropped images.  
- Each time you create a bounding box, press the letter 's' .  



Cheers!