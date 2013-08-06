ML
==
This is a neural network implementation that reads in handwritten values from the MNIST database,
then trains the system to be able to read images of hand written digets and recognize what number it is

The NeuralNetwork.exe file trains the weights, then the interface.py provides a canvas for the user to draw digets
and runs the NumberFind.exe to run that image through the trained weights and display what number it is(Not functional yet)

The image data is read from the 'data0, data1...' files in the data folder which contain 1000 images of the number after
data in their name(ex: data0 would be 0s)
