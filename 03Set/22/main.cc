#include "main.ih"

int main(int argc, char **argv)
{   
    rSeed(argc, argv);                  //update seed
    
    size_t nSubjects = atoi(argv[1]);

    size_t line[maxLine]{};
    addSubjects(line, nSubjects);       //add subjects to ferry line
   
    displaySubjects(line, nSubjects);   //display subjects

    if (string(argv[1]) == "help")      //if help is the arguement 
        unencrypt();                    //display unencrypted text
}
