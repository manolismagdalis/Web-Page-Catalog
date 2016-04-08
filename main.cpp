/**
    @author: Emmanouil Magdalis

    @version: 1.0.0

    The following program reads web page links from an input txt and builds a catalog
    with the following features:

    -All the different page IDs are stored in an AVL tree. IDs are positive integers

    -The neighbours of each link in the AVL tree are organized using a doubly linked list which features
     insertion of a new link as well as deletion of an existing link.

    -The neighbours are stored in increasing order

    The program reads every command from a commands txt file which will include the
    following commands (capital letters) : READ_DATA, END, INSERT_LINK, DELETE_LINK
    and prints the complete list of all the links in the command prompt.

    An example of the commands txt is given:

        READ_DATA
        INSERT_LINK 5 3
        INSERT_LINK 15 3
        INSERT_LINK 9 8
        INSERT_LINK 5 7
        DELETE_LINK 9 8
        INSERT_LINK 5 9
        DELETE_LINK 5 7
        INSERT_LINK 15 3
        INSERT_LINK 9 2
        INSERT_LINK 9 8
        INSERT_LINK 18 4
        END

    READ_DATA exists only once in the beginning of the txt and the END once in the
    end. If during INSERT_LINK the link already exists, then nothing is inserted. Also,
    if the link that is commanded to be deleted using DELETE_LINK does not exist, then
    nothing happens and the program continues.
*/


#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Tree.h"



int main()
{
    Tree MyTree;
    std::string command;
    std::string data1;
    std::string data2;
    int ddata1;
    int ddata2;
    std::ifstream myfile;
    myfile.open ("example.txt");
    if (myfile.is_open())
    {
        while (command!="READ_DATA")  //This while loop is used to make sure the program does not read junk
        {                             //before actually reaching the first command of the code
            myfile >> command;
        }
        while ( myfile >>  command >> data1 )
        {
            if (command=="INSERT_LINK")
            {
                myfile >> data2;
                ddata1=atoi(data1.c_str()); //convert string data1 to int ddata1
                ddata2=atoi(data2.c_str()); //convert string data2 to int ddata2
                RootOfAvl=MyTree.insertion(RootOfAvl, ddata1, ddata2);
            }
            else if (command=="DELETE_LINK")
            {
                myfile >> data2;
                ddata1=atoi(data1.c_str()); //convert string data1 to int ddata1
                ddata2=atoi(data2.c_str()); //convert string data2 to int ddata2
                MyTree.removelink(ddata1, ddata2);
            }
            else if (command=="END") break;
            else
            {
                std::cout << "Unable to read the txt file!" << std::endl;
                return 0;
            }
        }
        myfile.close();
    }
    else std::cout << "Unable to open file!";

    std::cout << "\nThe catalogue is the following: \n" << std::endl;
    MyTree.print(RootOfAvl);
    std::cout << std::endl;
    system("pause");
    return 0;
}
