
/*
 * this program created for novice in linux
 * and this program, can handle almost things in ubuntu and ...
 * and all distributions  based on  debian  ...
 * this program , create by amzy0(M.Amin azimi.K)
 * this program , can change under GPL3 license ...
 * you can send me a pull request in github :
 * https"//github.com/amzy-0/pck3r
 * good luck
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/unistd.h>
#include <string.h>

/*
 *define zone (length of arrays)
 * 1-define ARG_LEN_HELP length for help
 * 2-define color
 */

#define ARG_LEN_HELP 17

////////////////////////
    //color zone
////////////////////////

#define NRM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"

////////////////////////
    //color zone ended
////////////////////////

////////////////////////
    //functions
    void updator();
    void clear();
    void node_installer();
    void ohmyzsh_installer();
///////////////////////
int main ( int argc , char *argv[]){

    /*
     * int i ; (i variable in for loop (for argv[index number(i)]))
     */

    int i;

    /*
     * for loop for getting args
     */

	for ( i = 0 ; i < argc ; i++ ){

            /*
             * if after pck3r is empty (no args)
             * argc N.(1) is pck3r
             */

            if(argc == 1){
                printf("%splease enter a command(after \"pck3r\").\nfor see the all command : $ pck3r help\n",RED);
            }

            /*
             * if first arg == clear
             */

			else if(strcmp(argv[1], "clear")==0){
                clear();
			}

            /*
             * if argv[i] is "help" ($ pck3r help)
             */

			else if(strcmp(argv[1], "help")==0){
                /*
                * read help (run : less pck3r-help)
                */
                char read_help[ARG_LEN_HELP] = "less pck3r-";
                strcat(read_help, argv[i]);
                printf("%s", CYN);
                system(read_help);
            }

            /*
             * if argv[i] is "install" ($ pck3r install)
             */

            else if (strcmp(argv[1], "install")==0){

                /*
                 * if after "install" is NULL
                 * like this : $ pck3r install "\0"
                 */

               if(argv[2] == NULL){
                    printf("%sERROR !!(no arg )\nTry : $ pck3r install \"somthing else\"\nOr (if you run pck3r, localy) : $ ./pck3r install \"somthing else\"\n",RED);
                    break;
                }

                /*
                 * if argv[i++] (after "install" arg) is empty
                 */

                else if(strcmp(argv[2], "nodejs")==0){
                    node_installer();
                    break;
                }

                else if(strcmp(argv[2], "python3pip")==0){

                    /*
                    * if argv[2] not null
                    * || like this ($ pck3r install  python3pip )
                    */

                    system("sudo apt install python3-pip");
                    break;
                }
                else if(strcmp(argv[2], "ohmyzsh")==0){

                    /*
                    * if argv[2] not null
                    * || like this ($ pck3r install ohmyzsh )
                    */
                    ohmyzsh_installer();
                    printf("%sZSH installed \n", GRN);
                    break;
                }

                else{
                    i=2;
                    char apter[1000] = "sudo apt install ";
                    char finaly_do[1000] = {"\0"}; 
                    while (argv[i]!=NULL){
                        strcat(finaly_do, argv[i]);
                        strcat(finaly_do, " ");
                        i++;
                    }
                    strcat(apter, finaly_do);
                    system(apter);
                    printf("packages : %s%s\n",CYN, finaly_do);
                    break;
                    
                }

            }

            /*
             * if user want uninstall a program or tools or ...
             * like this ($ pck3r uninstall somthing )
             */

            else if(strcmp(argv[1], "uninstall")==0){

                /*
                 * if argv[2] is null
                 * like this ($ pck3r uninstall "\0")
                 */

                if (argv[2] == NULL){
                    printf("%s", RED);
                    printf("uninstall called for remove  \"\\0(NULL)\" \n");
                    printf("after \"uninstall\" is empty ! \n");
                    break;

                }

                /*
                 * if user want uninstall,
                 * a programm ($ pck3r uninstall nodejs)
                 */

                else if(strcmp(argv[2], "nodejs")==0){
                    system("echo \x1B[33m ");
                    system("sudo apt purge nodejs");
                    break;
                }


                /*
                 * if argv[2] not null , check it !
                 */

                else if(argv[2]!=NULL){
                    char finaly_do[200] = "sudo apt purge ";
                    printf("%sremoving %s !\n",YEL, argv[2]);
                    strcat(finaly_do, argv[2]);
                    system("echo \x1B[33m ");
                    system(finaly_do);
                    break;
                }
            }

            /*
             * if user want update a program or tools or ...
             * like this ($ pck3r update)
             */

            else if(strcmp(argv[1], "update")==0){

                /*
                 * if argv[2] is null
                 * like this ($ pck3r update )
                 */

               updator();
               break;
            }

            else{
                printf("%sCommand not found ! \n",RED);
                break;
            }

	}
	return 0;
}



void clear(){system("clear");}

void node_installer(){


    system("echo \x1B[33m");
    system("sudo apt install curl");
    system("curl -sL https://deb.nodesource.com/setup_12.x | sudo -E bash -");
    system("sudo apt install nodejs");
    system("clear");

    system("echo \x1B[32m\"node version : \"");
    system("node -v");
    system("echo \x1B[32m\"npm version : \"");
    system("npm -v");

}

void ohmyzsh_installer(){

    system("echo \x1B[33m");
    system("sudo apt install git");
    system("sudo apt install zsh");
    system("sh -c \"$(wget https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O -)\"");

}
/*
 * updator for install update form 
 * github.com/amzy-0/pck3r
 * and then update source and 
 * automatic install pck3r into the /bin DIRECTORY
 * pck3r clone to  : ~/pck3r 
 */
void updator(){

    system("echo \x1B[33m");
    system("sudo apt install git");
    char* home = getenv("HOME");
    chdir(home);
    system("pwd");
    system("git clone https://github.com/amzy-0/pck3r");
    system("sudo mv pck3r .pck3r");
    chdir(".pck3r");
    system("pwd");
    system("ls");
    system("git remote add pck3r  https://github.com/amzy-0/pck3r");
    system("git fetch pck3r");
    system("git merge pck3r/master master");

    system("sudo cp -r pck3r /bin/");
    system("echo pck3r copied ...");
    system("sudo cp -r pck3r-help /bin/");
    system("echo pak3r-help copied ...");
    system("echo pck3r dependences ...");
    system("sudo apt install wget");
    system("sudo apt install curl");
    system("sudo apt install libgtk-3-dev");
    system("sleep 5");
    printf("%spck3r updated \n",GRN);
 
}