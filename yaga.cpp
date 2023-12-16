#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

bool tag_cmp(const char* cmd, const char* cmd2, const char* cmd_cmp, const char* cmd_cmp2);

void yaga_main(bool TAG__COMMAND, string COMMAND, string ARG_COMPLETE, string ARG_X[], char* ARG_V[], int ARG_C, string OUTPUT_TXT);


int main(int argc, char* argv[]){
  
  string argx[10];
  string arg_cmpl;
  const char* cmd_stream;
  
  if(!strcmp(argv[1],"-v")){
    system("g++ -v");
  }
 
  if((!strcmp(argv[1],"github")) && (!strcmp(argv[2], "-n")))
  {
 
    cout << "Creating new local project and uploading to github\n";
    
    //Making dir project 
    
    arg_cmpl = "-code/";
    argx[0] = "mkdir "; 
    argx[1] = argv[3]+arg_cmpl;
    argx[2] = argx[0]+argx[1];
    
    //Copying files to dir's project
    
    argx[3] = "cp --remove-destination ";
    argx[4] = argv[3];
    argx[5] = "* ";
    argx[6] = argx[1];
    argx[7] = argx[3]+argx[4]+argx[5]+argx[6];
    
    //Sending command's stream to system function
    
    cmd_stream = argx[2].c_str();
    system(cmd_stream);
    cmd_stream = argx[7].c_str();
    system(cmd_stream);
    
    cout << "Project " << argx[1] << "has been created!\n";
  }
  
  yaga_main(tag_cmp(argv[1],argv[2],"-r",argv[2]), "rm -rf ", "-code/",argx, argv, argc, "Project has been removed!");
 
  yaga_main(tag_cmp(argv[1],argv[2],"-o",argv[2]), "g++ -o ",
  " *.cpp", argx, argv, argc, "Project has builded ok..");
  
  
  return 0;
}

bool tag_cmp(const char* cmd, const char* cmd2, const char* cmd_cmp, const char* cmd_cmp2){
 
  if((!strcmp(cmd, cmd_cmp)) && (!strcmp(cmd2, cmd_cmp2))){
    return 1;
  }
  else{
    return 0;
  }

}

void yaga_main(bool TAG__COMMAND, string COMMAND, string ARG_COMPLETE, string ARG_X[], char* ARG_V[], int ARG_C, string OUTPUT_TXT){
  
  const char* cmd_stream;
  
  if(TAG__COMMAND && ARG_C>1){
    
    ARG_X[0]=COMMAND;
    
    switch(ARG_C){
      case 3:
            ARG_X[1]=ARG_V[2]+ARG_COMPLETE;
            break;
      case 4:
            ARG_X[1]=ARG_V[3]+ARG_COMPLETE;
            break;
    }
   
    ARG_X[2]=ARG_X[0]+ARG_X[1];
    cmd_stream = ARG_X[2].c_str();
    system(cmd_stream);
    
    cout << OUTPUT_TXT << "\n";
  }
  else if(ARG_C==0){
    cout << "ERROR - it needs the project's name...\nSintax: yaga [TYPE] -[FLAG] [NAME]\n" ;
  }
  
}