#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <random>

// Declare variables
char usr[32];
char host[64];
//bool is64 = Environment.Is64BitOperatingSystem;
//char architecture[];
int installedDirectories;
int randGetDependencies = false;
int selectedDependency;
std::string dependency;
std::string fakePackage;
int archiveSize;
int diskSpace;
int extractSize = 9999;
int downloadTime;
int archiveSize2;
int downloadTime2;
int totalDownSize;
int totalDownTime;
std::string dependencySuffix;
int v1;
int v2;
int v3;
int v4;
// Start code
void getRand(int *var,int maxNum){ //the C code works in C++ so...  I just changed it to void since it doesn't return anything
    // Get the random number, seed is taken from the time
    srand(time(0));
    *var = rand() % maxNum;
}
void clrScrn() { //This also works in C++, changed to void too
    // Screen clear function, checks OS first for compatibility:tm:
    #ifdef unix
        system("clear");
    #endif
    #ifdef __APPLE__
        system( "clear" );
    #endif
}
int main(void){
    // Get all variables and random numbers set
    // Hostname and Username
    getlogin_r(usr,32);
    gethostname(host,64);
    // Number of installed directories (I'm honestly not even sure what that means)
    getRand(&installedDirectories,8000000);
    // "Coin flip" to see if we're going to get a dependency or not
    getRand(&randGetDependencies,2);
    if(randGetDependencies){
        // Choose what dependency suffix to use if the coin flip was a 1
        getRand(&selectedDependency,8);
        switch(selectedDependency){
            case 1:
                dependencySuffix += "-runtime";
                break;
            case 2:
                dependencySuffix += "-man";
                break;
            case 3:
                dependencySuffix += "-headers";
                break;
            case 4:
                dependencySuffix += "-config";
                break;
            case 5:
                dependencySuffix += "-utils";
                break;
            case 6:
                dependencySuffix += "-dev";
                break;
            case 7:
                dependencySuffix += "-data";
                break;}
        getRand(&archiveSize2,84);} //get archive size of dependancy
    getRand(&archiveSize,96);//get archive size of package
    // Combine sizes if there's going to be a dependency, if there's not then don't
    if(randGetDependencies)totalDownSize=archiveSize+archiveSize2;
    else totalDownSize=archiveSize;
    // Get total disk space needed
    while (totalDownSize <= extractSize)getRand(&extractSize, 96);
    diskSpace=totalDownSize+extractSize;
    // Get download time
    getRand(&downloadTime,8);
    getRand(&downloadTime2,6);
    // Combine them for the displayed download time
    totalDownTime=downloadTime+downloadTime2;
    // Get all the various version numbers
    getRand(&v1,25);
    getRand(&v2,50);
    getRand(&v3,9);
    getRand(&v4,9);
    std::string version = std::to_string(v1)+":"+std::to_string(v2)+"."+std::to_string(v3)+"."+std::to_string(v4);
    // Start actually doing stuff
    clrScrn();
    #ifdef _WIN32
    #endif
    #ifdef unix
        // If unix, use unix color scheme
        printf("\e[1;32m%s@%s\e[0m:\e[1;34m~\e[0m$ sudo apt install ",usr,host);
    #endif
    #ifdef __APPLE__
        std::cout << usr << ":~" << host << "$ sudo apt install ";
    #endif
    std::cin >> fakePackage;
    // Now that we have the package, we can assemble the dependency using the pre-generated suffix
    if (randGetDependencies)dependency = fakePackage + dependencySuffix;
    else dependency = "";
    // Fake password prompt
    printf("[sudo] password for %s: ",usr);
    // Just using a getchar() so you can enter whatever as the password and I don't have to store it
    getchar();
    getchar();
    std::cout << "Reading package lists... ";
    usleep(850000);
    std::cout << "Done\n";
    std::cout << "Building dependency tree\n";
    usleep(900000);
    std::cout << "Reading state information... ";
    usleep(900000);
    std::cout << "Done\n";
    // List packages, no need to check if there's a dependency because you won't notice anything if there isn't
    std::cout << "The following NEW packages will be installed:\n";
    std::cout << "  " << fakePackage << "  " << dependency << std::endl;
    // If there's a dependency say 2 new packages, if not say 1
    std::cout << "0 upgraded, " << std::to_string(1+randGetDependencies) << " newly installed, 0 to remove and 0 not upgraded.\n";
    usleep(750000);
    // Get that nice pre-generated archive size and then output how much space it will use
    std::cout << "Need to get "<< totalDownSize <<" mB of archives.\n";
    usleep(250000);
    std::cout << "After this operation, " << diskSpace << " mB of additional disk space will be used.\nGet:1 http://archive.ubuntu.com/ubuntu focal-updates/universe amd64 "<< fakePackage <<" amd64 "<< version <<" [" <<archiveSize << " mB]\n";
    sleep(downloadTime);
    // If there's a dependency, download that too
    if(randGetDependencies){
        std::cout << "Get:2 http://archive.ubuntu.com/ubuntu focal-updates/universe amd64 "<< dependency <<" amd64 ["<< archiveSize2 <<" mB]\n";
        sleep(downloadTime2);}
    std::cout << "Fetched " << totalDownSize << " mB in " << totalDownTime << "s\n";
    usleep(850000);
    std::cout << "Selecting previously unselected package " << fakePackage << ".\n";
    usleep(850000);
    std::cout << "(Reading database ... " << installedDirectories << " files and directories currently installed.)\n";
    // Use those nice version numbers
    std::cout << "Preparing to unpack .../" << fakePackage << "_" << version << "-amd64.deb ...\n";
    usleep(750000);
    std::cout << "Unpacking " << fakePackage << " (" << version << ") ...\n";
    sleep(2);
    std::cout << "Setting up " << fakePackage << " (" << version << ") ...\n";
    sleep(2);
    // In theory I will update this number if I notice that man-db has had an update
    std::cout << "Processing triggers for man-db (2.9.1-1) ...\n\n";
    sleep(2);
    return(0);
}
