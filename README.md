# Web-Page-Catalog


# author: Emmanouil Magdalis

# version: 1.0.0

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
