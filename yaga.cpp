#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

const int BUFFER_ON=0, BUFFER_OFF=1;
int counter = 0;

string strcatch_global="";

bool tag_cmp(const char* cmd, const char* cmd2, const char* cmd_cmp, const char* cmd_cmp2);

void yaga_main(bool TAG__COMMAND, string COMMAND, string ARG_COMPLETE, string ARG_X[], char* ARG_V[], int ARG_C, int enter_times, string OUTPUT_TXT);


int main(int argc, char* argv[]){
  
  string argx[10];
  string arg_cmpl;
  
  if(argc > 1){
    
    yaga_main(tag_cmp(argv[0],argv[1],argv[0],"-v"), "g++ -v","", argx, argv, argc, BUFFER_OFF, "");
    
    yaga_main(tag_cmp(argv[1],argv[2],"github","-n"), "mkdir ", "-code/", argx, argv, argc, BUFFER_ON, "Project has been created! - fist step!");
    
    yaga_main(tag_cmp(argv[1],argv[2],"github","-n"), "mv -v", "* ", argx, argv, argc, BUFFER_OFF, "");
   
    yaga_main(tag_cmp(argv[1],argv[2],"-r",argv[2]), "rm -rf ", "-code/", argx, argv, argc, BUFFER_OFF,  "Project has been removed!");
   
    yaga_main(tag_cmp(argv[1],argv[2],"-o",argv[2]), "g++ -o ",
    " *.cpp", argx, argv, argc, BUFFER_OFF, "Project has builded ok..");
    
    if(!strcmp(argv[1],"matrix")){
  
      yaga_main(tag_cmp(argv[0], argv[1], argv[0], "matrix"), "stty cbreak & pkg install --assume-yes cmatrix", "", argx, argv, argc, BUFFER_OFF, " ");
      
      yaga_main(tag_cmp(argv[0], argv[1], argv[0], argv[1]), "timeout 5 cmatrix & stty -cbreak", " & clear", argx, argv, argc, BUFFER_ON,"");
   
      yaga_main(tag_cmp(argv[0], argv[1], argv[0], argv[1]), "pkg remove --assume-yes cmatrix", "", argx, argv, argc, BUFFER_OFF,"");
    }
  }
  else{
    cout << "ERROR!\nSintax: yaga [TYPE] -[FLAG] [NAME]\n" ;
  } 
  
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

void yaga_main(bool TAG__COMMAND, string COMMAND, string ARG_COMPLETE, string ARG_X[], char* ARG_V[], int ARG_C, int enter_times, string OUTPUT_TXT){
  
  const char* cmd_stream;
  
  if(TAG__COMMAND && ARG_C>1){
   
    ARG_X[0]=COMMAND;
    
    switch(ARG_C){
      case 2: //POINT OF ERROR - SOLVED
            ARG_X[1]=ARG_COMPLETE;
            break;
      case 3:
            ARG_X[1]=ARG_V[2]+ARG_COMPLETE;
            break;
      case 4:
            ARG_X[1]=ARG_V[3]+ARG_COMPLETE;
            break;
    }
    
    ARG_X[2]=ARG_X[0]+ARG_X[1]+strcatch_global;
    cmd_stream = ARG_X[2].c_str();
    system(cmd_stream);
    
    if(enter_times==0){
      strcatch_global = ARG_X[1];
    }
    
    cout << OUTPUT_TXT << "\n";
  }
  else if(not TAG__COMMAND && ARG_C>=1 && counter<1){
    cout << "ERROR - it needs the project's name...\nSintax: yaga [TYPE] -[FLAG] [NAME]\n" ;
      
  }
  counter++; //future implementation ?
}