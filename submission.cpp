#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <vector>
#include <iostream>

using namespace cv;
using namespace std;



// Counter for naming saved images
int imageCounter = 0;


// Points to store the top-left and bottom-right corners of the bounding box
Point topLeft, bottomRight;
// Source image
Mat source;

// Function which will be called on mouse input
void drawBoundingBox(int action, int x, int y, int flags, void* userdata)
{
    // Action to be taken when left mouse button is pressed
    if (action == EVENT_LBUTTONDOWN)
    {
        topLeft = Point(x, y);
    }
    // Action to be taken when left mouse button is released
    else if (action == EVENT_LBUTTONUP)
    {
        bottomRight = Point(x, y);
        // Draw the green bounding box  
        rectangle(source, topLeft, bottomRight, Scalar(0, 255, 0), 2);
        imshow("Window", source);
    }
}

int main()
{
    // Making the path vairibale for the 'sample.jpg' image.
    string imagePath = "sample.jpg";
    source = imread(imagePath, 1);
    // Make a dummy image, will be useful to clear the drawing
    Mat dummy = source.clone();
    namedWindow("Window");
    // highgui function called when mouse events occur
    setMouseCallback("Window", drawBoundingBox);
    int k = 0;
    // loop until escape character is pressed
    while (k != 27)
    {
        

        imshow("Window", source);
        putText(source, "Click and drag to draw a bounding box, Press ESC to exit", Point(2, 30), FONT_HERSHEY_SIMPLEX, 0.3, Scalar(255, 255, 255), 1);
        k = waitKey(20) & 0xFF;
        if (k == 99)
       
            // Clear the drawing
            dummy.copyTo(source);

        else if
            (k == 115) {

                Rect roi_rect(topLeft, bottomRight);
                // making a separate copy
                Mat cropped_image = source(roi_rect).clone();

                // Generate a unique filename for each saved image using the counter
                string filename = "cropped_image_" + to_string(imageCounter) + ".jpg";
                imwrite(filename, cropped_image);

                // Increment the counter for the next image
                imageCounter++;
            }


    }
    
    
    return 0;
}
