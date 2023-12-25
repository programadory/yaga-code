#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

/*Constants required for yaga_main() and checkDirectives()*/

const int BUFFER_ON=0, BUFFER_OFF=1; 
int counter = 0;
string strcatch_global="";
string directives[5]={"github", "-o", "-r", "-v", "matrix"};
//string getSintax="";
/*--------------------------------*/
bool tag_cmp(const char* cmd, const char* cmd2, const char* cmd_cmp, const char* cmd_cmp2);

void yaga_main(bool TAG__COMMAND, string COMMAND, string ARG_COMPLETE, string ARG_X[], char* ARG_V[], int ARG_C, int enter_times, string OUTPUT_TXT);

bool checkDirectives(const char* ARG_V);

int main(int argc, char* argv[]){
  
  string argx[10]; //array to get data into yaga_main()
  
  if(argc > 1){ //Check in to avoid strcmp() errors 
      
      if(checkDirectives(argv[1])){ //Second check to predict inexistent[FLAG]
        
          yaga_main(tag_cmp(argv[0],argv[1],argv[0],"-v"), "g++ -v","", argx, argv, argc, BUFFER_OFF, "");
          
          yaga_main(tag_cmp(argv[1],argv[2],"github","-n"), "mkdir ", "-code/", argx, argv, argc, BUFFER_ON, "Project has been created! - fist step!");
          
          yaga_main(tag_cmp(argv[1],argv[2],"github","-n"), "mv -v", "* ", argx, argv, argc, BUFFER_OFF, "");
         
          yaga_main(tag_cmp(argv[1],argv[2],"-r",argv[2]), "rm -rf ", "-code/", argx, argv, argc, BUFFER_OFF,  "Project has been removed!");
         
          yaga_main(tag_cmp(argv[1],argv[2],"-o",argv[2]), "g++ -o ",
          " *.cpp", argx, argv, argc, BUFFER_OFF, "Project has builded ok..");
          
          /*Nothing special, just arragement*/
          if(!strcmp(argv[1],"matrix")){
        
              yaga_main(tag_cmp(argv[0], argv[1], argv[0], "matrix"), "stty cbreak & pkg install --assume-yes cmatrix", "", argx, argv, argc, BUFFER_OFF, " ");
              
              yaga_main(tag_cmp(argv[0], argv[1], argv[0], argv[1]), "timeout 5 cmatrix & stty -cbreak", " & clear", argx, argv, argc, BUFFER_ON,"");
           
              yaga_main(tag_cmp(argv[0], argv[1], argv[0], argv[1]), "pkg remove --assume-yes cmatrix", "", argx, argv, argc, BUFFER_OFF,"");
          }
      }else{ cout << "Sintax error: yaga [TYPE*UNREGONIZED##]\n"; }
  }
  else{ cout << "ERROR!\nSintax: yaga [TYPE] -[FLAG] [FILE/DIR]\n";} 
  
  return 0;
}

/*Check a couple of strcmp() and return true or false*/
bool tag_cmp(const char* cmd, const char* cmd2, const char* cmd_cmp, const char* cmd_cmp2){
 
  if((!strcmp(cmd, cmd_cmp)) && (!strcmp(cmd2, cmd_cmp2))){
    return 1;
  }
  else{
    return 0;
  }
}

void yaga_main(bool TAG__COMMAND, string COMMAND, string ARG_COMPLETE, string ARG_X[], char* ARG_V[], int ARG_C, int enter_times, string OUTPUT_TXT){
  
  const char* cmd_stream; //to save command stream and use it in system()
  
  if(TAG__COMMAND && ARG_C>1){ //Check if tag_cmp() equals TRUE and argv[2] exists.
   
    ARG_X[0]=COMMAND; //copying main command to argx[0]
    
    switch(ARG_C){ /*locatting file/dir to treat based on number of argumments and adding complement if necessary*/
      case 2:
            ARG_X[1]=ARG_COMPLETE;
            break;
      case 3:
            ARG_X[1]=ARG_V[2]+ARG_COMPLETE;  
            break;
      case 4:
            ARG_X[1]=ARG_V[3]+ARG_COMPLETE; 
            break;
    }
    /*[command] [file/dir+complement] [cached complement]*/
    ARG_X[2]=ARG_X[0]+ARG_X[1]+strcatch_global; 
    cmd_stream = ARG_X[2].c_str(); //c_str() convert string to char*[]
    system(cmd_stream);
    
    /*Check if TAG__COMMAND is true again and copying the complement in argx[1] to strcatch_global to use as second complement if necessary.*/
    if(enter_times==0){ 
      strcatch_global = ARG_X[1];
    }
    
    cout << OUTPUT_TXT << "\n";
  } /*using counter to prevent ERROR message everytime yaga_main is called as false*/
}

bool checkDirectives(const char* ARG_V){
  
  bool check = false;
  for(int i=0; i<5; i++){
    if(!strcmp(ARG_V, directives[i].c_str())){
        check = true;
        break;
    }else{
      check = false;
    }
  }
  return check;
}