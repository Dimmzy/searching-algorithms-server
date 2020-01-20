
#include <sstream>
#include "MyClientHandler.h"
#define BUFFER_SIZE 1024

void MyClientHandler::handleClient(int input_stream, int output_stream) {
  char buffer[BUFFER_SIZE] = {0};
  int columns = 0;
  bool columnSet = false;
  int rows = 0;
  std::vector<double> start;
  std::vector<double> end;
  int valread = read(input_stream, buffer,BUFFER_SIZE);
  std::string line, input(buffer);
  std::vector<std::vector<double>> inputMatrix;
  rmLinebreak(input);
  while (input != "end") {
    std::stringstream lineStream(input);
    std::string cell;
    /* End of matrix input, time to receive enter and exit cell */
    if (rows == columns && columns != 0) {
      /* Gets the starting cell */
      while(std::getline(lineStream,cell,',')) {
        start.push_back(stod(cell));
      }
      /* Reads and gets the ending cell */
      read(input_stream,buffer,BUFFER_SIZE);
      input = buffer;
      rmLinebreak(input);
      std::stringstream lineStreamEnd(input);
      while(std::getline(lineStreamEnd,cell,',')) {
        end.push_back(stod(cell));
      }
      /* We got start cell and end cell, finished reading! */
      break;
    }
    rows++;
    std::vector<double> row;
    while(std::getline(lineStream,cell,',')) {
      if(!columnSet)
        columns++;
      row.push_back(stod(cell));
    }
    columnSet = true;
    inputMatrix.push_back(row);
    bzero(buffer,BUFFER_SIZE);
    valread = read(input_stream,buffer,BUFFER_SIZE);
    input = buffer;
    rmLinebreak(input);
  }
  close(input_stream);
  /* TESTER: Prints the Matrix */
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      std::cout << inputMatrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void MyClientHandler::rmLinebreak(std::string& str) {
  str.erase(std::remove(str.begin(),str.end(),'\n'),str.end());
  str.erase(std::remove(str.begin(),str.end(),'\r'),str.end());
}