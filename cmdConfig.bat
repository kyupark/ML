rem launch.cmd

cd ./Google Drive/My Documents/GitHub/ML/

g++ -o NeuralNetwork main.cpp image.cpp neuralNetwork.cpp dataReader.cpp neuralNetworkTrainer.cpp

g++ -o NumberFind test.cpp neuralNetwork.cpp

pause