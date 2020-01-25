
#include <sstream>
#include "MyClientHandler.h"
#include "Matrix.h"
#define BUFFER_SIZE 1024

void MyClientHandler::handleClient(int input_stream, int output_stream) {
  char buffer[BUFFER_SIZE] = {0};
  int columns = 0;
  bool columnSet = false;
  int rows = 0;
  std::vector<int> start;
  std::vector<int> end;
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
    // Another day another row
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
    read(input_stream,buffer,BUFFER_SIZE);
    input = buffer;
    rmLinebreak(input);
  }
  close(input_stream);
  auto* init = new State<std::vector<int>>(&start,inputMatrix[start.at(0)][start.at(1)]);
  auto* goal = new State<std::vector<int>>(&end,inputMatrix[end.at(0)][end.at(1)]);
  auto* matrix = new Matrix(columns, init, goal);
  /* Inserts the states into our matrix */
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      std::vector<int> cell{rows,columns};
      matrix->addCell(new State<std::vector<int>>(&cell,inputMatrix[rows][columns]));
    }
  }
}

void MyClientHandler::rmLinebreak(std::string& str) {
  str.erase(std::remove(str.begin(),str.end(),'\n'),str.end());
  str.erase(std::remove(str.begin(),str.end(),'\r'),str.end());
}