/*                     
Assignment : project4                                                           
Author: Ian Davidson                                                   
File: main.cpp
Date : Spring 2017                                                        
*/

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Lex.hpp"
#include "Token.hpp"
#include "DirectoryNode.hpp"
#include "DirectoryEntry.hpp"
#include "buildDirectoryEntry.cpp"
//DE means Directory Entry, DN means DirectoryNode instnace

using namespace std;




int main(int argc, char const * const argv [])
{
  if ( argc > 2 || argc < 2){
    cerr << "invalid arguments, need to pass 1 .json file as an argument" << endl;
    exit(1);
  }

  ifstream input(argv[1]);
  //open input using filename: argv[1]
  if(input.fail()){
    cerr << "input error from: " << argv[1] << endl;
    cerr << "Exiting now" << endl;
    exit(1);

  }

  string totalInputFile = "";
  
  //use tokenizer/lex with the input taken from ifstream
  for ( string line; getline(input, line); ){
    totalInputFile += line;
  }

  input.close();
  
  Lex *lex = new Lex(totalInputFile); //this is how to make an instance of lex
  // Token token = lex->getToken();

  //start parsing here...
  DirectoryEntry *wholeDir = buildDirEnt(lex);


  //int depth = wholeDir->depth();
  //cout << "depth when cwd is rootDir: " << depth << endl;

  
  //string pwd = wholeDir->pwd();
  //cout << "pwd: " << pwd << endl;


  //  vector<string> kids;
  //kids = wholeDir->find(".tar");
  
  //we needa test: move(), hasSubstructure()
  
  //cout << "here is kids of root: " << endl;
  //vector<string> kids;
  //kids = wholeDir->ls();

  //cout << "# of kiddies: " << kids.size() << endl;
  //for (uint k = 0; k < kids.size(); k++)
  //    cout << kids[k]  << endl;

  //  cout <<"u win" << endl;
  
  string path = "project1/RomanCalculatorStudentFiles";
  string path2 = "project3";
  //string shiz = wholeDir->cd(path);
  
  string pwd = wholeDir->pwd();
  cout << "pwd: " << pwd << endl;

  //shiz = wholeDir->cd();
  //pwd = wholeDir->pwd();
  //cout << "pwd: " << pwd << endl;


  int depth = wholeDir->depth();
  cout << "depth when cwd isn't rootDir: " << depth << endl;

  wholeDir->move(path,path2);

  vector <string> kids;
  kids = wholeDir->ls(path2);

  cout << "children of project1/RomanCalculatorStudentFiles" << endl;
  
  for (uint k = 0; k < kids.size(); k++)
    cout << kids[k]  << endl;


  kids = wholeDir->ls("project1");
  
  cout << "children of project1" << endl;
  
  /*
  DirectoryEntry *lameDirectory = wholeDir->duplicate(path);//();

  cout << "successfully duped" << endl;

  pwd = wholeDir->pwd();
  cout << "OG pwd: " << pwd << endl;

  pwd = lameDirectory->pwd();
  cout << "pwd: " << pwd << endl;
  
  bool same = wholeDir->hasSubstructure(lameDirectory);

  if(same)
    cout << "theyre the same names/structure" << endl;
  else
    cout << "not same structures" << endl;

  pwd = wholeDir->pwd();
  cout << "pwd: " << pwd << endl;
  */
  /*  
  vector<string> kids;

  kids = wholeDir->ls(path);
  
  */
  for (uint k = 0; k < kids.size(); k++)
    cout << kids[k]  << endl;
  
    
  wholeDir->destroy();
  
  return 0;

}
