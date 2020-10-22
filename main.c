
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

#define ARG_LEN_HELP 14

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
////////////////////////
    void updator();
    void clear();
    void node_installer();
    void ohmyzsh_installer();
    void sys_update();
    void sys_upgrade();
    void sys_updgr();
    void sys_error();
    void sys_ok();
    void version();
    void wine_installer();
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
                sys_error();
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
                * read help (run : ./pck3r-help)
                */
                char read_help[ARG_LEN_HELP] = "./pck3r-";
                strcat(read_help, argv[1]);
                printf("%s", CYN);
                sys_ok();
                system("sleep 2");
                system(read_help);
                break;
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
                    sys_error();
                    printf("%s(no arg !!!!\nTry : $ pck3r install \"somthing else\"\nOr (if you run pck3r, localy) : $ ./pck3r install \"somthing else\"\n",RED);
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
                    
                    break;
                }
                else if(strcmp(argv[2], "wine")==0){

                    /*
                    * if argv[2] not null
                    * || like this ($ pck3r install ohmyzsh )
                    */
                    wine_installer();
                    
                    break;
                }

                else{
                    i=2;
                    char apter[1000] = "sudo apt install ";
                    char finally_do[1000] = {"\0"};
                    while (argv[i]!=NULL){
                        strcat(finally_do, argv[i]);
                        strcat(finally_do, " ");
                        i++;
                    }
                    strcat(apter, finally_do);
                    if((system(apter))!=0){
                        sys_error();
                    }
                    else{
                        sys_ok();
                        printf("%s installed \n",finally_do);
                    }

                    printf("packages : %s%s\n",CYN, finally_do);
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
                    if((system("sudo apt purge nodejs"))!=0){
                        sys_error();
                        break;
                    }
                    else{
                        sys_ok();
                        break;
                    }

                }


                /*
                 * if argv[2] not null , check it !
                 */

                else if(argv[2]!=NULL){
                    char finally_do[200] = "sudo apt purge ";
                    printf("%sremoving %s !\n",YEL, argv[2]);
                    strcat(finally_do, argv[2]);
                    system("echo \x1B[33m ");
                    system(finally_do);
                    break;
                }
            }



            /*
             *
             * if arg[1] == "sys"
             * wait for arg[2]
             * valid args after "sys" :
             * "update", "upgrade", "updgr(update and upgrade) "
             *
             */

            else if(strcmp(argv[1], "sys")==0){

                /*
                 * if arg[2] == "\0"
                 * like this => $ pck3r sys update
                 */

                if (argv[2]==NULL){
                    sys_error();
                    printf("%s\nAfter \"sys\" is empty !\n", RED);
                }

                /*
                 * if arg[2] == "update"
                 * like this => $ pck3r sys update
                 */

                else if (strcmp(argv[2], "update")==0){
                    sys_update();
                }

                /*
                 * if arg[2] == "upgrade"
                 * like this => $ pck3r sys upgrade
                 */

                else if (strcmp(argv[2], "upgrade")==0){
                    sys_upgrade();
                }

                /*
                 *
                 * if arg[2] == "updgr"
                 * like this => $ pck3r sys updgr
                 *
                 */

                else if (strcmp(argv[2], "updgr")==0){
                    sys_updgr();
                }

                /*
                 *
                 * if comamnd not valid after sys
                 * like this : $ pck3r sys {not valid}
                 *
                 */

                else{
                    sys_error();
                    printf("%s\nAfter \"sys\" is not valid !\n", RED);

                }
                break;
            }

            else if(strcmp(argv[1], "dwn")==0){
                if(argv[2]==NULL){
                    sys_error();
                    puts(RED);
                    puts("After \"dwn\" is empty " );
                }

                /*
                 *
                 * else if
                 * if after $ pck3r dwn "\0"
                 *
                 */

                else if (argv[2]!=NULL){
                    char link[2000] = "wget ";
                    strcat(link, argv[2]);
                    if(( system(link) )!=0){
                        sys_error();
                    }


                    else
                    {
                        sys_ok();
                        puts(GRN);
                        puts("downloaded ! (location : )");
                        system("pwd");
                    }

                }

                break;
            }

            /*
             * version 
             */

            else if(strcmp(argv[1], "version")==0){
                version();
                puts("");
                break;
                
            }

            /*
             *
             * if command after pck3r not valid
             *
             */

            else{
                sys_error();
                printf("%sCommand not found ! \n",RED);
                break;
            }

	}
    puts(NRM);
	return 0;
}



void clear(){system("clear");}

void node_installer(){

    /*
     *
     * change color (forground color ) to yellow
     *
     */

    system("echo \x1B[33m");

    /*
     *
     * install curl, is require ...
     *
     */

    system("sudo apt install curl");

    if(( system("curl -sL https://deb.nodesource.com/setup_12.x | sudo -E bash -") )!=0){

        /*
         * if can not connect to https://deb.nodesource.com/ ,
         * print error
         * and break ...
         */

        sys_error();
    }
    else if(( system("sudo apt install nodejs") )!=0){

        /*
         * print error if node not installed ...
         */

        sys_error();
    }
    else{

        /*
         * clear, terminal
         */

        system("clear");

        /*
         * if node is ready for install
         * print sys_ok(); function,
         * and print node and nmp version
         *
         */

        sys_ok();
        system("echo \x1B[32m\"node version : \"");
        system("node -v");
        system("echo \x1B[32m\"npm version : \"");
        system("npm -v");
    }
}

void ohmyzsh_installer(){

    if(( system("echo \x1B[33m") )!=0){
            sys_error();
            return;
    }
    else if ((system("sudo apt install git") )!=0){
        sys_error();
        return;
    }
    else if(( system("sudo apt install zsh") )!=0){
        sys_error();
        return;
    }

    else if(( system("sh -c \"$(wget https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh -O -)\"") )!=0){
        sys_error();
        return;
    }
    else{
        sys_ok();
        printf("%sZSH installed \n", GRN);
        system("zsh -V");
    }
    

}



/*
 *
 * $ pck3r sys update
 * (update for UBUNTU )
 *
 */

void sys_update(){
     if((system("sudo apt update"))!=0){
        sys_error();
     }
     else{
        sys_ok();
        printf("%syour oprating system is upgrade", GRN);
     }

 }

/*
 *
 * $ pck3r sys upgrade
 * (upgrade for UBUNTU )
 *
 */

void sys_upgrade(){
     if((system("sudo apt full-upgrade"))!=0){
        sys_error();
     }
     else{
         sys_ok();
         printf("%syour oprating system is upgraded \n", GRN);
         system("lsb_release -a ");
         system("echo your oprating system information : ");
         system("uname -a ");
         system("echo your machine architecture : ");
         system("uname -p");


     }

 }


/*
 *
 * $ pck3r sys updgr
 * both with one command
 * (update & upgrade for UBUNTU )
 *
 */

void sys_updgr(){
     if(system("sudo apt update && sudo apt full-upgrade")!=0){
         sys_error();
     }
     else{
         sys_ok();
         printf("%syour oprating system is updated and upgraded \n", GRN);
         system("lsb_release -a ");
         system("echo your oprating system information : ");
         system("uname -a ");
         system("echo your machine architecture : ");
         system("uname -p");
         puts(WHT);
         system("sudo apt autoremove");         
     }

 }

 /*
  *
  * error function for error
  * anywhere
  *
  */

void sys_error(){

    /*
     * error
     */

     puts(RED);
     printf("尸⼕长㇌尺 : ERROR ! \n");
 }

/*
 *
 * ok function
 * when opration is done without problem.
 * call this function
 *
 */

void sys_ok(){

     /*
      * no error
      */

     puts(GRN);
     printf("尸⼕长㇌尺 : OK ! \n");
 }

void version(){
    puts(GRN);
    printf("version : 1.0"); 
}

/*
 * 
 * wine installer function for install wine 
 * and use wine and install it, 
 * for your oprating system 
 * use this function and you can change function name, 
 * if you want to rename function, 
 * and change this code for your self ... 
 * 
 */

void wine_installer(){

            if(( system("sudo dpkg --add-architecture i386 "))!=0){
                sys_error();
                return;
            }
            else if (( system("wget -nc https://dl.winehq.org/wine-builds/winehq.key"))!=0){
                sys_error();
                return;
            }
            
            else if(( system("sudo apt-key add winehq.key") )!=0){
                sys_error();
                return;
            }
            
            else if(( system("sudo apt update && sudo apt full-upgrade -y"))!=0){
                sys_error();
                return;
            }

            else if(( system("sudo apt install --install-recommends winehq-stable"))!=0){
                sys_error();
                return;
            }

            
            else if (( system("sudo add-apt-repository 'deb https://dl.winehq.org/wine-builds/ubuntu/ focal main'"))!=0){
                sys_error();
                return;
            }
            else if (( system("sudo add-apt-repository 'deb https://dl.winehq.org/wine-builds/ubuntu/ bionic main'"))!=0){
                sys_error();
                return;
            }
            
            else if(( system("sudo apt update && sudo apt full-upgrade - y"))!=0){
                sys_error();
                return;
            }

            else if(( system("sudo apt install --install-recommends winehq-stable"))!=0){
                sys_error();
                return;
            }
            
            else{
                sys_ok();
                printf("%sWine installed ! (18.04 and 20.04) ",GRN);

            }
}

