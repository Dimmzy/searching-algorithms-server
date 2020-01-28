#include <sstream>
#include "MyClientHandler.h"
#include "Matrix.h"
#include "ObjectAdapter.h"

/* Maximal amount of information we're ready to receive */
#define BUFFER_SIZE 1024

/**
 * The handleClient receives information through the input_stream, translates it into a problem using ObjectAdapter,
 * and solves it through it. It then sends the solution through output_stream to the requesting client.
 * @param input_stream the input stream we'll receive our problem from
 * @param output_stream the output stream we'll send our problem to
 */
void MyClientHandler::handleClient(int input_stream, int output_stream) {
  char buffer[BUFFER_SIZE] = {0};
  int columns = 0;
  bool columnSet = false;
  int rows = 0;
  /* We'll append to this string all of the information received so we can have a hash of the problem to save as name */
  std::string stringToHash;
  std::vector<int> start;
  std::vector<int> end;
  read(input_stream, buffer,BUFFER_SIZE);
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
        stringToHash.append(cell);
        start.push_back(stod(cell));
      }
      /* Reads and gets the ending cell */
      read(input_stream,buffer,BUFFER_SIZE);
      input = buffer;
      rmLinebreak(input);
      std::stringstream lineStreamEnd(input);
      while(std::getline(lineStreamEnd,cell,',')) {
        stringToHash.append(cell);
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
      /*TODO: the hash I comment the line below*/
      //stringtoHash.append(cell);
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
      std::vector<int> cell{i,j};
      matrix->addCell(new State<std::vector<int>>(&cell,inputMatrix[i][j]));
    }
  }

}

/**
 * Removes linebreaks from passed string.
 * @param str the string we'll remove LB from/
 */
void MyClientHandler::rmLinebreak(std::string& str) {
  str.erase(std::remove(str.begin(),str.end(),'\n'),str.end());
  str.erase(std::remove(str.begin(),str.end(),'\r'),str.end());
}