/*Function: main
*---------------------------------------------------
*Contains the main page and directs user to other pages
*
*Asks for initial choice input
*Choice 1: Shopkeeper login
*          function calls on loginpage
*Choice 2: Customer page
*          function calls on customerpage
*Choice 3: Exit program
*          returns 0; exits program
*if any other input is given, program will ask for another input
*/

/*Function: loginpage
*---------------------------------------------------
*Checks whether given login and password are valid
*
*Opens login.txt file and saves login and password information to several 2D arrays
*Asks for login and password from user
*if user input is valid (equal to at least one login and passsword information from the text file),
*then program will direct user to storemanagement page (function call on storemanagement page)
*otherwise, program will ask for login and password again
*if login and password is wrong 3 times, program will terminate
*/

/*Function: storemanagement
*---------------------------------------------------
*Storemanagement page: requests for choice from user and directs user accordingly
*
*Asks for initial choice input
Choice 1 - 6 will direct user to the accessproducts function (function call on accessproducts)
*Choice 7: Logout
*          Break out from current function and redirect user back to main page
*/

/*Function: accessproducts
*---------------------------------------------------
*Access the products file and provide user's demands given the choice from the previous function(storemanagement)
*
*Opens products.txt file and saves all products into a structure array named productslist
*Choice 1: Entire product list
*          Print out all the products of that shopkeeper
*Choice 2: Product list by expiration date
*          Sorts products by expiration date
*          Prints all products of that shopkeeper
*Choice 3: Product list with Discount
*          Prints products of shopkeeper that has any type of discount
*Choice 4: Add products
*          Request for product information
*          Add product to the product List
*          Print this product information to the text file
*Choice 5: Remove products
*          Request user for ID of product to be removed
*          Remove product from the product list
*          Remove this product information from the text file
*Choice 6: Edit products
*          Choose product to edit by choosing their IDs
*          Input new information of the product
*          Edit this information in the productslist array
*          Edit the products.txt file
*/

/*Function: customerpage
*---------------------------------------------------
*Customer page: requests for choice from user and directs user accordingly
*
*Asks for initial choice input
Choice 1 - 3 will direct user to the customersproductpage function (function call on customersproductpage)
*Choice 4: Go to start page
*          Break out from current function and redirect user back to main page
*/

/*Function: customersproductpage
*---------------------------------------------------
*Access the products file and provide user's demands given the choice from the previous function(customerpage)
*
*Opens login.txt file and saves Store name and shopkeeper name into their respective 2D arrays
*Opens products.txt file and saves all products into a structure array named productslist
*Choice 1: Show all products
*          Print out all the product information with the corresponding store and shopkeeper name as well
*Choice 2: Show Product list with Discount
*          Prints products of shopkeeper that has any type of discount
*Choice 3: Search for specific product
*          Ask for letter input from user
*          Compare letter input with first letter of all the products
*          Print out all the product information with the letter input as its first letter
*/

/*Text file format
*---------------------------------------------------
*login.txt:
*   [Store name]:[loginID/shopkeeper name] [password]
*products.txt:
*   [Store name]:[Item name],[Price],[Quantity],[Discount],[expiration year]-[expiration month]-[expiration day]
*
*There are no spaces in between the variables other than the space between the shopkeeper and password
*the square brackets ([]) are only there to emphasize the different parts, it is not used in the actual text file
*/

//header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//macro functions
#define MAX 100
#define CONTINUE\
    printf("\n\n\tPress any key and the Enter key to continue.\n\n");\
    scanf(" %[^\n]c", &ch);\
    system("cls");
#define WELCOME()\
    printf("*** Welcome to SKKU Stores Management ***\n");\
    printf("==============================================\n");\
    printf("\t1. Login as shopkeeper\n");\
    printf("\t2. Search products\n");\
    printf("\t3. Exit\n");\
    printf("==============================================\n");\
    printf("\tEnter Your Choice: ");
#define SHOPOWNERMENU(a, b)\
    printf("*** %s ***\n", a);\
    printf("Shopkeeper: %s\n", b);\
    printf("==============================================\n");\
    printf("\t1. Show my products\n");\
    printf("\t2. Sort products by expiration date\n");\
    printf("\t3. Show products with discounts\n");\
    printf("\t4. Add products\n");\
    printf("\t5. Remove products\n");\
    printf("\t6. Edit products\n");\
    printf("\t7. Log out\n");\
    printf("==============================================\n");\
    printf("\tEnter Your Choice: ");
#define CUSTOMERMENU\
    printf("*** CUSTOMER PAGE ***\n");\
    printf("==============================================\n");\
    printf("\t1. Show all products\n");\
    printf("\t2. Show products with discounts\n");\
    printf("\t3. Search for specific product\n");\
    printf("\t4. Go to start page\n");\
    printf("==============================================\n");\
    printf("\tEnter Your Choice: ");

//structure for all the products containing their information and their shopkeeper information
typedef struct
{
    char storename[MAX], item[MAX], discount[MAX], shopkeeper[MAX];
    int price, quantity, expireyear, expiremonth, expireday;
}product;

//declaration of all the functions
void loginpage();
void storemanagement(char store[MAX], char owner[MAX]);
void accessproducts(char name[MAX], char owner[MAX], int choice);
void customerpage();
void customersproductpage(int choice);

//main function
int main()
{
    //declaration of choice variable
    int choice = 0;

    //while loop for the main welcome page
    while(1)
    {
        //welcome message and request for choice input
        WELCOME();

        //if choice is not an integer, this while loop will be triggered
        while(scanf("%d", &choice) == 0 && getchar())
        {
            //request for input continuously until number is entered
            printf("\n\tError! Please try again!\n\n");
            WELCOME();
        }

        //switch case statement for the choice vaeiable
        switch(choice)
        {
            //case 1: shop login
            case 1:
            {
                //clear terminal
                system("cls");
                //function call on loginpage function
                loginpage();
                break;
            }
            //case 2: customer page
            case 2:
            {
                //clear terminal
                system("cls");
                //function call on customerpage function
                customerpage();
                break;
            }
            //case 3: exit
            case 3:
            {
                //return 0 to exit program
                printf("\n\tThank you so much! See you next time!\n");
                return 0;
            }
            //case if choice is a number other than 1,2,or 3
            default:
            {
                //go back to the initial loop
                printf("\n\tNot a valid choice! Please try again!\n\n");
                continue;
            }
        }
    }
}

//loginpage function
void loginpage()
{
    //declaration of variables
    FILE *fp;
    char id[MAX], pw[MAX];
    char ch;
    int i, j, lines = 0, count = 0;

    //open login.txt file using fp (file pointer)
    if((fp = fopen("login.txt", "r")) == NULL)
    {
        //print and exit if error opening login file
        fprintf(stdout, "Can't access login information.");
        exit(1);
    }

    //while loop to check number of login information (1 line = 1 login info)
    while((ch = fgetc(fp)) != EOF)
    {
        //if new line is found
        if(ch == '\n')
        {
            //increase line count
            lines++;
        }
    }
    //increase line count to consider EOF
    lines++;
    //rewind fp for future purposes
    rewind(fp);

    //create 2D arrays for login information: 1 row = 1 login information
    char storename[lines][MAX], idinfo[lines][MAX], pwinfo[lines][MAX];

    //for loop to save login information
    for(i = 0; i < lines; i++)
    {
        // until ':', characters will be saved to the storename array
        while((ch = getc(fp)) != ':')
        {
            //each letter will be saved to each index
            storename[i][count] = ch;
            count++;
        }
        //to prevent errors, last index will be set to '\0'
        storename[i][count] = '\0';
        //count = 0 to use in the next loop
        count = 0;

        // until a space(' '), characters will be saved to the idinfo array(shopkeeper name)
        while((ch = getc(fp)) != ' ')
        {
            //each letter will be saved to each index
            idinfo[i][count] = ch;
            count++;
        }
        //to prevent errors, last index will be set to '\0'
        idinfo[i][count] = '\0';
        //count = 0 to use in the next loop
        count = 0;

        // until a newline('\n'), characters will be saved to the pwinfo array(password)
        while((ch = getc(fp)) != '\n')
        {
            //each letter will be saved to each index
            pwinfo[i][count] = ch;
            count++;
            //if EOF is encountered
            if(ch == EOF)
            {
                //delete 1 count since last line does not have '\n'
                count--;
                //break from while loop to avoid crashing
                break;
            }
        }
        //to prevent errors, last index will be set to '\0'
        pwinfo[i][count] = '\0';
        //count = 0 to use in the next loop
        count = 0;
    }

    //shopkeeper page
    printf("*** SHOPKEEPER PAGE ***\n");
    printf("==============================================\n");
    //for loop to consider number of trials
    for(i = 0; i < 3; i++)
    {
        //request for id and password from user
        printf("\tLogin: ");
        scanf("%s", id);
        printf("\tPassword: ");
        scanf("%s", pw);
        
        //for loop to compare input with the stored idinfo and pwinfo arrays
        for(j = 0; j < lines; j++)
        {
            //using strcmp, check whether the user's login information is correct
            if(strcmp(id, idinfo[j]) == 0 && strcmp(pw, pwinfo[j]) == 0)
            {
                //if correct, clear terminal
                system("cls");
                //then function call on the storemanagement
                storemanagement(storename[j], idinfo[j]);
                break;
            }
        }
        // if j == lines, in other words, id and pw was compared with all the given information but none was identical
        if(j == lines)
        {
            //print if id or pw is wrong
            printf("\tYou have entered the wrong login or password (%d/3 trials)\n", i + 1);
        }
        //if j != lines, it means that id and pw was a success!
        else
        {
            //break out from for loop
            break;
        }
    }
    //if i == 3, meaning 3 trials attempted and all of them were wrong
    if(i == 3)
    {
        //print
        printf("\n\tAccess Denied. Shutting down the program.\n");
        //close fp
        if(fclose(fp) != 0)
        {
            //print if there is error in closing
            fprintf(stderr, "Error closing file\n");
        }
        //exit program
        exit(1);
    }
    //close fp
    if(fclose(fp) != 0)
    {
        //print if there is error in closing
        fprintf(stderr, "Error closing file\n");
    }
}

//storemanagement function
void storemanagement(char name[MAX], char owner[MAX])
{
    //declaration of variables
    int choice = 0;
    char ch;

    //while loop for the choices
    while(choice != 7)
    {
        //main menu for shopowner page and request for choice input
        SHOPOWNERMENU(name, owner);

        //if choice is not an integer, this while loop will be triggered
        while(scanf("%d", &choice) == 0 && getchar())
        {
            //print out the error message
            printf("\n\tError! Please try again!\n\n");
            //continuously request input until it is an integer
            SHOPOWNERMENU(name, owner);
        }

        //if choice is from 1 to 6
        if(choice > 0 && choice < 7)
        {
            //clear terminal
            system("cls");
            //print shopkeeper page template
            printf("*** %s ***\n", name);
            printf("Shopkeeper: %s\n", owner);
            printf("==============================================\n");
            //function call on accessproducts function 
            accessproducts(name, owner, choice);
            //CONTINUE macro function used for the "Press any key to continue"
            CONTINUE;
        }
        //if choice is 7
        else if(choice == 7)
        {
            //print logging out and clear screen
            printf("\tLogging Out...\n\n");
            system("cls");
            //break from current while loop and return to previous function (loginpage function)
            break;
        }
        //if choice is not from 1 to 7
        else
        {
            //ask for choice input again
            printf("\n\tNot a valid choice! Please try again!\n\n");
            continue;
        }
    }
}

//accessproducts function
void accessproducts(char name[MAX], char owner[MAX], int choice)
{
    //declaration of variables
    FILE *fp;
    product *productslist, products;
    char ch, str[MAX], temp[MAX];
    int lines = 0, count = 0, i = 0, index = 0, j, editindex, removeindex;

    //open products.txt file using fp
    if((fp = fopen("products.txt", "r")) == NULL)
    {
        //print if error in opening
        fprintf(stdout, "Can't access products.");
        //exit program if error in opening file
        exit(1);
    }

    //while loop to check number of products (1 line = 1 product)
    while((ch = fgetc(fp)) != EOF)
    {
        //if new line is found
        if(ch == '\n')
        {
            //increase line count
            lines += 1;
        }
    }
    //increase line count by 1 to consider EOF (last line does not have \n)
    lines += 1;
    //dynamically allocate memory to the product structure using number of products
    if((productslist = (product *)malloc(lines * sizeof(product))) == NULL)
    {
        //print if error allocating memory
        printf("Memory allocation error !\n");
        //exit program
		exit(1);
    }
    //rewind fp
    rewind(fp);

    //fgets to read line by line
    //while loop to continuously use fgets until the EOF is reached
    while(fgets(str, MAX, fp) != NULL)
    {
        // until ':', characters of the str string will be stored to the storename variable of the productslist array
        while(str[count] != ':')
        {
            //each letter will be saved to each index
            productslist[i].storename[index] = str[count];
            count++;
            index++;
        }
        //set last index to the '\0' to avoid errors
        productslist[i].storename[index] = '\0';
        //increase count (index of str) to skip ':'
        count++;
        //index = 0 for next loop index
        index = 0;

        // until ',', characters of the str string will be stored to the item variable (item name) of the productslist array
        while(str[count] != ',')
        {
            //each letter will be saved to each index
            productslist[i].item[index] = str[count];
            count++;
            index++;
        }
        //set last index to the '\0' to avoid errors
        productslist[i].item[index] = '\0';
        //increase count (index of str) to skip ','
        count++;
        //index = 0 for next loop index
        index = 0;

        // until the next ',', characters of the str string will be stored in a temp variable
        while(str[count] != ',')
        {
            //each letter will be saved to each index
            temp[index] = str[count];
            count++;
            index++;
        }
        //increase count (index of str) to skip ','
        count++;
        //set last index to the '\0' to avoid errors
        temp[index] = '\0';
        //use atoi and save to the price variable to get the integer from the string
        productslist[i].price = atoi(temp);
        //index = 0 for next loop index
        index = 0;

        // until the next ',', characters of the str string will be stored in a temp variable
        while(str[count] != ',')
        {
            //each letter will be saved to each index
            temp[index] = str[count];
            count++;
            index++;
        }
        //increase count (index of str) to skip ','
        count++;
        //set last index to the '\0' to avoid errors
        temp[index] = '\0';
        //use atoi and save to the quantity variable to get the integer from the string
        productslist[i].quantity = atoi(temp);
        //index = 0 for next loop index
        index = 0;

        // until the next ',', characters of the str string will be stored to the discount variable
        while(str[count] != ',')
        {
            //each letter will be saved to each index
            productslist[i].discount[index] = str[count];
            count++;
            index++;
        }
        //set last index to the '\0' to avoid errors
        productslist[i].discount[index] = '\0';
        //increase count (index of str) to skip ','
        count++;
        //index = 0 for next loop index
        index = 0;

        // until the '-', characters of the str string will be stored in a temp variable
        while(str[count] != '-')
        {
            //each letter will be saved to each index
            temp[index] = str[count];
            count++;
            index++;
        }
        //increase count (index of str) to skip ','
        count++;
        //set last index to the '\0' to avoid errors
        temp[index] = '\0';
        //use atoi and save to the expireyear variable to get the integer from the string
        productslist[i].expireyear = atoi(temp);
        //index = 0 for next loop index
        index = 0;

        // until the next '-', characters of the str string will be stored in a temp variable
        while(str[count] != '-')
        {
            //each letter will be saved to each index
            temp[index] = str[count];
            count++;
            index++;
        }
        //increase count (index of str) to skip ','
        count++;
        //set last index to the '\0' to avoid errors
        temp[index] = '\0';
        //use atoi and save to the expiremonth variable to get the integer from the string
        productslist[i].expiremonth = atoi(temp);
        //index = 0 for next loop index
        index = 0;

        // until the next '-', characters of the str string will be stored in a temp variable
        while(str[count] != '\0')
        {
            //each letter will be saved to each index
            temp[index] = str[count];
            count++;
            index++;
        }
        //set last index to the '\0' to avoid errors
        temp[index] = '\0';
        //use atoi and save to the expireday variable to get the integer from the string
        productslist[i].expireday = atoi(temp);
        //reset index and count variables for the next product information
        index = 0;
        count = 0;
        //increase i count to consider next index in the structure variable
        i++;
    }

    //close fp file pointer
    if(fclose(fp) != 0)
    {
        //print if there is error in closing
        fprintf(stderr, "Error closing file\n");
    }

    //if else statements for the choice variable from previous function (storemanagement)
    //choice 1: print all products
    if(choice == 1)
    {
        //print out all products of the current store
        printf("\tProducts List: \n");
        printf("\tProduct Name\tPrice\tQuantity\tDiscount\tExpiration Date\n");
        for(i = 0; i < lines; i++)
        {
            //if store of product is the same as the current shopkeeper's storename
            if(strcmp(productslist[i].storename, name) == 0)
            {
                //print product information
                printf("\t%s", productslist[i].item);
                printf("\t%d", productslist[i].price);
                printf("\t%d\t", productslist[i].quantity);
                printf("\t%s\t", productslist[i].discount);
                if(productslist[i].expiremonth > 9 && productslist[i].expireday > 9)
                {
                    printf("\t%d-%d-%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else if(productslist[i].expiremonth <= 9 && productslist[i].expireday > 9)
                {
                    printf("\t%d-0%d-%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else if(productslist[i].expiremonth > 9 && productslist[i].expireday <= 9)
                {
                    printf("\t%d-%d-0%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else
                {
                    printf("\t%d-0%d-0%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
            }
        }
    }
    //choice 2: print products by expiration date
    else if(choice == 2)
    {
        //declaration of local product variable
        product tempproduct;

        //for loop to sort products
        for(i = 0; i < lines - 1; i++)
        {
            for(j = i + 1; j < lines; j++)
            {
                //if expiration year of the left product is greater than any of the right products 
                if(productslist[i].expireyear > productslist[j].expireyear)
                {
                    //store the right product(faster expiration date) to tempproduct variable
                    tempproduct = productslist[i];
                    //swap left product to the right product position
                    productslist[i] = productslist[j];
                    //place right product info to the original left product position
                    productslist[j] = tempproduct;
                }
                //if expiration year of the left product is equal to any of the right products 
                else if(productslist[i].expireyear == productslist[j].expireyear)
                {
                    //if expiration month of the left product is greater than any of the right products (year is equal)
                    if(productslist[i].expiremonth > productslist[j].expiremonth)
                    {
                        //store the right product(faster expiration date) to tempproduct variable
                        tempproduct = productslist[i];
                        //swap left product to the right product position
                        productslist[i] = productslist[j];
                        //place right product info to the original left product position
                        productslist[j] = tempproduct;
                    }
                    //if expiration month of the left product is equal to any of the right products 
                    else if(productslist[i].expiremonth == productslist[j].expiremonth)
                    {
                        //if expiration day of the left product is greater than any of the right products (year and month are equal)
                        if(productslist[i].expireday > productslist[j].expireday)
                        {
                            //store the right product(faster expiration date) to tempproduct variable
                            tempproduct = productslist[i];
                            //swap left product to the right product position
                            productslist[i] = productslist[j];
                            //place right product info to the original left product position
                            productslist[j] = tempproduct;
                        }
                    }
                }
            }
        }
        //print out productslist after sorting by expiration date
        printf("\tProducts List by Expiration Date: \n");
        printf("\tProduct Name\tPrice\tQuantity\tDiscount\tExpiration Date\n");
        for(i = 0; i < lines; i++)
        {
            //if store of product is the same as the current shopkeeper's storename
            if(strcmp(productslist[i].storename, name) == 0)
            {
                //print product information
                printf("\t%s", productslist[i].item);
                printf("\t%d", productslist[i].price);
                printf("\t%d\t", productslist[i].quantity);
                printf("\t%s\t", productslist[i].discount);
                if(productslist[i].expiremonth > 9 && productslist[i].expireday > 9)
                {
                    printf("\t%d-%d-%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else if(productslist[i].expiremonth <= 9 && productslist[i].expireday > 9)
                {
                    printf("\t%d-0%d-%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else if(productslist[i].expiremonth > 9 && productslist[i].expireday <= 9)
                {
                    printf("\t%d-%d-0%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else
                {
                    printf("\t%d-0%d-0%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
            }
        }
    }
    //choice 3: Products with Discount
    else if(choice == 3)
    {
        //print out products with discount
        printf("\tProducts List with Discounts: \n");
        printf("\tProduct Name\tPrice\tQuantity\tDiscount\tExpiration Date\n");
        for(i = 0; i < lines; i++)
        {
            //if store of product is the same as the current shopkeeper's storename
            //also if discount variable is not equal to "None", meaning it has discount
            if(strcmp(productslist[i].storename, name) == 0 && strcmp(productslist[i].discount,"None") != 0)
            {
                //print product information
                printf("\t%s", productslist[i].item);
                printf("\t%d", productslist[i].price);
                printf("\t%d\t", productslist[i].quantity);
                printf("\t%s\t", productslist[i].discount);
                if(productslist[i].expiremonth > 9 && productslist[i].expireday > 9)
                {
                    printf("\t%d-%d-%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else if(productslist[i].expiremonth <= 9 && productslist[i].expireday > 9)
                {
                    printf("\t%d-0%d-%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else if(productslist[i].expiremonth > 9 && productslist[i].expireday <= 9)
                {
                    printf("\t%d-%d-0%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else
                {
                    printf("\t%d-0%d-0%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
            }
        }
    }
    //Choice 4: add products
    else if(choice == 4)
    {
        //open products.txt with fp using "a" (append or add additional product)
        if((fp = fopen("products.txt", "a")) == NULL)
        {
            //print if error opening file
            fprintf(stdout, "Can't access products.");
            //exit program
            exit(1);
        }
        //request for new product information
        //store in products variable
        printf("\tAdd New Product:\n");
        printf("\tProduct Name: ");
        scanf(" %[^\n]s", products.item);
        printf("\tPrice (per item): ");
        scanf("%d", &products.price);
        printf("\tQuantity: ");
        scanf("%d", &products.quantity);
        printf("\tDiscount: ");
        scanf(" %[^\n]s", products.discount);
        printf("\tExpire Date: ");
        scanf("%d-%d-%d", &products.expireyear, &products.expiremonth, &products.expireday);

        //print information to the file with the product format "\n%s:%s,%d,%d,%s,%d-%d-%d"
        if(products.expiremonth > 9 && products.expireday > 9)
        {
            fprintf(fp, "\n%s:%s,%d,%d,%s,%d-%d-%d", name, products.item, products.price, products.quantity, products.discount, products.expireyear, products.expiremonth, products.expireday);
        }
        else if(products.expiremonth <= 9 && products.expireday > 9)
        {
            fprintf(fp, "\n%s:%s,%d,%d,%s,%d-0%d-%d", name, products.item, products.price, products.quantity, products.discount, products.expireyear, products.expiremonth, products.expireday);
        }
        else if(products.expiremonth > 9 && products.expireday <= 9)
        {
            fprintf(fp, "\n%s:%s,%d,%d,%s,%d-%d-0%d", name, products.item, products.price, products.quantity, products.discount, products.expireyear, products.expiremonth, products.expireday);
        }
        else
        {
            fprintf(fp, "\n%s:%s,%d,%d,%s,%d-0%d-0%d", name, products.item, products.price, products.quantity, products.discount, products.expireyear, products.expiremonth, products.expireday);
        }

        //close f
        if(fclose(fp) != 0)
        {
            //print if there is error in closing
            fprintf(stderr, "Error closing file\n");
        }

        printf("\n\tSuccessfully added the product!");
    }
    //Choice 5: Remove products
    else if(choice == 5)
    {
        //count = 0 used for momentary product ID
        count = 0;
        //print out product name and their ID
        printf("\tProducts List: \n");
        printf("\tProduct ID\tProduct Name\n");
        for(i = 0; i < lines; i++)
        {
            //if store of product is the same as the current shopkeeper's storename
            if(strcmp(productslist[i].storename, name) == 0)
            {
                //increase count (product count)
                count++;
                //print product information
                printf("\t%d\t", count);
                printf("\t%s\n", productslist[i].item);
            }
        }
        //request for input regarding which product to remove
        printf("==============================================\n");
        printf("Enter ID of removing product: ");
        scanf("%d", &removeindex);

        count = 0;
        //for loop to find the product's index in structure array
        for(i = 0; i < lines; i++)
        {
            //if product is in the current store
            if(strcmp(productslist[i].storename, name) == 0)
            {
                //increase count
                count++;
                //if count == removeindex (corresponding ID of removing product)
                if(count == removeindex)
                {
                    //break out from loop since we now know the index (i)
                    break;
                }
            }
        }
        //update removeindex
        removeindex = i;
        //for loop to delete the product
        for(i = removeindex; i < (lines - 1); i++)
        {
            //reduce the index of all the products to the right (right of the removing product) by 1
            productslist[i] = productslist[i + 1];
        }

        //reallocate memory or structure (lines - 1 since we deleted 1 product)
        productslist = realloc(productslist, (lines - 1) * sizeof(product));

        //open file
        if((fp = fopen("products.txt", "w")) == NULL)
        {
            //print if error accessing file
            fprintf(stdout, "Can't access products list.");
            //exit program
            exit(1);
        }

        //print first product information from structre since it has a different format (no '\n' at the start)
        if(productslist[0].expiremonth > 9 && productslist[0].expireday > 9)
        {
            fprintf(fp, "%s:%s,%d,%d,%s,%d-%d-%d", productslist[0].storename, productslist[0].item, productslist[0].price, productslist[0].quantity, productslist[0].discount, productslist[0].expireyear, productslist[0].expiremonth, productslist[0].expireday);
        }
        else if(productslist[0].expiremonth <= 9 && productslist[0].expireday > 9)
        {
            fprintf(fp, "%s:%s,%d,%d,%s,%d-0%d-%d", productslist[0].storename, productslist[0].item, productslist[0].price, productslist[0].quantity, productslist[0].discount, productslist[0].expireyear, productslist[0].expiremonth, productslist[0].expireday);
        }
        else if(productslist[0].expiremonth > 9 && productslist[0].expireday <= 9)
        {
            fprintf(fp, "%s:%s,%d,%d,%s,%d-%d-0%d", productslist[0].storename, productslist[0].item, productslist[0].price, productslist[0].quantity, productslist[0].discount, productslist[0].expireyear, productslist[0].expiremonth, productslist[0].expireday);
        }
        else
        {
            fprintf(fp, "%s:%s,%d,%d,%s,%d-0%d-0%d", productslist[0].storename, productslist[0].item, productslist[0].price, productslist[0].quantity, productslist[0].discount, productslist[0].expireyear, productslist[0].expiremonth, productslist[0].expireday);
        }

        //for the remaining products
        for(i = 1; i < (lines - 1); i++)
        {
            //print all the information to the products.txt file
            if(productslist[i].expiremonth > 9 && productslist[i].expireday > 9)
            {
                fprintf(fp, "\n%s:%s,%d,%d,%s,%d-%d-%d", productslist[i].storename, productslist[i].item, productslist[i].price, productslist[i].quantity, productslist[i].discount, productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
            }
            else if(productslist[i].expiremonth <= 9 && productslist[i].expireday > 9)
            {
                fprintf(fp, "\n%s:%s,%d,%d,%s,%d-0%d-%d", productslist[i].storename, productslist[i].item, productslist[i].price, productslist[i].quantity, productslist[i].discount, productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
            }
            else if(productslist[i].expiremonth > 9 && productslist[i].expireday <= 9)
            {
                fprintf(fp, "\n%s:%s,%d,%d,%s,%d-%d-0%d", productslist[i].storename, productslist[i].item, productslist[i].price, productslist[i].quantity, productslist[i].discount, productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
            }
            else
            {
                fprintf(fp, "\n%s:%s,%d,%d,%s,%d-0%d-0%d", productslist[i].storename, productslist[i].item, productslist[i].price, productslist[i].quantity, productslist[i].discount, productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
            }
        }

        //close file
        if(fclose(fp) != 0)
        {
            //print if there is error in closing
            fprintf(stderr, "Error closing file\n");
        }

        printf("\n\tSuccessfully removed product!");
    }
    //choice 6: edit product
    else
    {
        count = 0;
        //print product information
        printf("\tProducts List: \n");
        printf("\tProduct ID\tProduct Name\tPrice\tQuantity\tDiscount\tExpiration Date\n");
        for(i = 0; i < lines; i++)
        {
            //if store of the product is the same as the shopkeeper's store
            if(strcmp(productslist[i].storename, name) == 0)
            {
                //count used for temporary product ID
                count++;
                printf("\t%d\t", count);
                //print product information
                printf("\t%s", productslist[i].item);
                printf("\t%d", productslist[i].price);
                printf("\t%d\t", productslist[i].quantity);
                printf("\t%s\t", productslist[i].discount);
                if(productslist[i].expiremonth > 9 && productslist[i].expireday > 9)
                {
                    printf("\t%d-%d-%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else if(productslist[i].expiremonth <= 9 && productslist[i].expireday > 9)
                {
                    printf("\t%d-0%d-%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else if(productslist[i].expiremonth > 9 && productslist[i].expireday <= 9)
                {
                    printf("\t%d-%d-0%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else
                {
                    printf("\t%d-0%d-0%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
            }
        }
        //request for editindex input
        printf("==============================================\n");
        printf("Enter ID of editing product: ");
        scanf("%d", &editindex);

        count = 0;
        //for loop to find the product's index in structure array
        for(i = 0; i < lines; i++)
        {
            //if product is in current store
            if(strcmp(productslist[i].storename, name) == 0)
            {
                //increase count
                count++;
                //if count == removeindex (corresponding ID of removing product)
                if(count == editindex)
                {
                    //break out from loop
                    break;
                }
            }
        }
        //i = index of product to edit

        //clear terminal
        //request for new input and save to the index
        system("cls");
        printf("*** %s ***\n", name);
        printf("Shopkeeper: %s\n", owner);
        printf("==============================================\n"); 
        printf("\tEditing Product\n");
        printf("\tProduct ID: %d\n", editindex);
        printf("\tProduct Name: ");
        scanf(" %[^\n]s", productslist[i].item);
        printf("\tPrice (per item): ");
        scanf("%d", &productslist[i].price);
        printf("\tQuantity: ");
        scanf("%d", &productslist[i].quantity);
        printf("\tDiscount: ");
        scanf(" %[^\n]s", productslist[i].discount);
        printf("\tExpire Date: ");
        scanf("%d-%d-%d", &productslist[i].expireyear, &productslist[i].expiremonth, &productslist[i].expireday);

        //open products.txt file
        if((fp = fopen("products.txt", "w")) == NULL)
        {
            //print if error opening
            fprintf(stdout, "Can't access products list.");
            //exit program
            exit(1);
        }

        //print first product information from structre since it has a different format (no '\n' at the start)
        if(productslist[0].expiremonth > 9 && productslist[0].expireday > 9)
        {
            fprintf(fp, "%s:%s,%d,%d,%s,%d-%d-%d", productslist[0].storename, productslist[0].item, productslist[0].price, productslist[0].quantity, productslist[0].discount, productslist[0].expireyear, productslist[0].expiremonth, productslist[0].expireday);
        }
        else if(productslist[0].expiremonth <= 9 && productslist[0].expireday > 9)
        {
            fprintf(fp, "%s:%s,%d,%d,%s,%d-0%d-%d", productslist[0].storename, productslist[0].item, productslist[0].price, productslist[0].quantity, productslist[0].discount, productslist[0].expireyear, productslist[0].expiremonth, productslist[0].expireday);
        }
        else if(productslist[0].expiremonth > 9 && productslist[0].expireday <= 9)
        {
            fprintf(fp, "%s:%s,%d,%d,%s,%d-%d-0%d", productslist[0].storename, productslist[0].item, productslist[0].price, productslist[0].quantity, productslist[0].discount, productslist[0].expireyear, productslist[0].expiremonth, productslist[0].expireday);
        }
        else
        {
            fprintf(fp, "%s:%s,%d,%d,%s,%d-0%d-0%d", productslist[0].storename, productslist[0].item, productslist[0].price, productslist[0].quantity, productslist[0].discount, productslist[0].expireyear, productslist[0].expiremonth, productslist[0].expireday);
        }

        //for the remaining products
        for(i = 1; i < lines; i++)
        {
            //print all the information to the products.txt file
            if(productslist[i].expiremonth > 9 && productslist[i].expireday > 9)
            {
                fprintf(fp, "\n%s:%s,%d,%d,%s,%d-%d-%d", productslist[i].storename, productslist[i].item, productslist[i].price, productslist[i].quantity, productslist[i].discount, productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
            }
            else if(productslist[i].expiremonth <= 9 && productslist[i].expireday > 9)
            {
                fprintf(fp, "\n%s:%s,%d,%d,%s,%d-0%d-%d", productslist[i].storename, productslist[i].item, productslist[i].price, productslist[i].quantity, productslist[i].discount, productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
            }
            else if(productslist[i].expiremonth > 9 && productslist[i].expireday <= 9)
            {
                fprintf(fp, "\n%s:%s,%d,%d,%s,%d-%d-0%d", productslist[i].storename, productslist[i].item, productslist[i].price, productslist[i].quantity, productslist[i].discount, productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
            }
            else
            {
                fprintf(fp, "\n%s:%s,%d,%d,%s,%d-0%d-0%d", productslist[i].storename, productslist[i].item, productslist[i].price, productslist[i].quantity, productslist[i].discount, productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
            }
        }

        //close file
        if(fclose(fp) != 0)
        {
            //print if there is error in closing
            fprintf(stderr, "Error closing file\n");
        }

        //clear terminal
        //print out the new products list after editing
        count = 0;
        system("cls");
        printf("*** %s ***\n", name);
        printf("Shopkeeper: %s\n", owner);
        printf("==============================================\n");
        for(i = 0; i < lines; i++)
        {
            //if product is in current store
            if(strcmp(productslist[i].storename, name) == 0)
            {
                //print product information
                count++;
                printf("\t%d\t", count);
                printf("\t%s", productslist[i].item);
                printf("\t%d", productslist[i].price);
                printf("\t%d\t", productslist[i].quantity);
                printf("\t%s\t", productslist[i].discount);
                if(productslist[i].expiremonth > 9 && productslist[i].expireday > 9)
                {
                    printf("\t%d-%d-%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else if(productslist[i].expiremonth <= 9 && productslist[i].expireday > 9)
                {
                    printf("\t%d-0%d-%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else if(productslist[i].expiremonth > 9 && productslist[i].expireday <= 9)
                {
                    printf("\t%d-%d-0%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else
                {
                    printf("\t%d-0%d-0%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
            }
        }
    }

    //free the memory allocation of productslist
    free(productslist);
}

//customerpage function
void customerpage()
{
    //declaration of variable
    int choice = 0;
    char ch;

    //while loop until 4 is inputted
    while(choice != 4)
    {
        //macro function asking for input
        CUSTOMERMENU;

        //while input is not an integer
        while(scanf("%d", &choice) == 0 && getchar())
        {
            //print error and request for input again
            printf("\n\tError! Please try again!\n\n");
            CUSTOMERMENU;
        }

        //switch case for choice
        switch(choice)
        {
            //case 1: print all products
            case 1:
            {
                //clear terminal
                system("cls");
                printf("*** CUSTOMER PAGE ***\n");
                printf("==============================================\n");
                //function call on customersproductpage
                customersproductpage(choice);
                CONTINUE;
                break;
            }
            //case 2: print products with discount
            case 2:
            {
                //clear terminal
                system("cls");
                printf("*** CUSTOMER PAGE ***\n");
                printf("==============================================\n");
                //function call on customersproductpage
                customersproductpage(choice);
                CONTINUE;
                break;
            }
            //case 3: search product using first letter
            case 3:
            {
                //clear terminal
                system("cls");
                printf("*** CUSTOMER PAGE ***\n");
                printf("==============================================\n");
                //function call on customersproductpage
                customersproductpage(choice);
                CONTINUE;
                break;
            }
            //case 4: exit
            case 4:
            {
                //clear screen
                system("cls");
                //break from current function and go back to main menu
                break;
            }
            //if choice is not from 1 to 4
            default:
            {
                //ask for input again
                printf("\n\tNot a valid choice! Please try again!\n\n");
                continue;
            }
        }
    }
    
}

//customersproductpage function
void customersproductpage(int choice)
{
    //declaration of variables
    FILE *fp, *storeinfo;
    product *productslist;
    char ch, productletter, str[MAX], temp[MAX];
    int storenum = 0, lines = 0, count = 0, i = 0, index = 0, j;

    //open login.txt file as storeinfo
    if((storeinfo = fopen("login.txt", "r")) == NULL)
    {
        //print if error
        fprintf(stdout, "Can't access login information.");
        //exit
        exit(1);
    }

    //while loop to check number of stores (1 line = 1 store)
    while((ch = fgetc(storeinfo)) != EOF)
    {
        //if newline is found
        if(ch == '\n')
        {
            //increase storenum count
            storenum++;
        }
    }
    //increase storenum count to consider EOF
    storenum++;
    //rewind file pointer
    rewind(storeinfo);

    //create 2D arrays for store name and shopkeeper information
    char storename[storenum][MAX], shopkeeper[storenum][MAX];

    //for loop to find store name and shopkeeper info
    for(i = 0; i < storenum; i++)
    {
        // until ':', characters will be saved to the storename array
        while((ch = getc(storeinfo)) != ':')
        {
            //each letter will be saved to each index
            storename[i][count] = ch;
            count++;
        }
        //to prevent errors, last index will be set to '\0'
        storename[i][count] = '\0';
        //count = 0 to use in the next loop
        count = 0;

        // until a space(' '), characters will be saved to the shopkeeper array
        while((ch = getc(storeinfo)) != ' ')
        {
            //each letter will be saved to each index
            shopkeeper[i][count] = ch;
            count++;
        }
        //to prevent errors, last index will be set to '\0'
        shopkeeper[i][count] = '\0';
        //count = 0 to use in the next loop
        count = 0;

        //while loop to skip the password information
        while((ch = getc(storeinfo)) != '\n')
        {
            //if EOF is found, break from loop
            if(ch == EOF)
            {
                break;
            }
        }
    }
    //restart variables for future use
    i = 0;
    count = 0;

    //close login.txt file
    if(fclose(storeinfo) != 0)
    {
        //print if there is error in closing
        fprintf(stderr, "Error closing file\n");
    }

    //open products.txt file
    if((fp = fopen("products.txt", "r")) == NULL)
    {
        //print error and exit if cannot open
        fprintf(stdout, "Can't access products.");
        exit(1);
    }

    //while loop to check number of products (1 line = 1 product)
    while((ch = fgetc(fp)) != EOF)
    {
        //if new line is found
        if(ch == '\n')
        {
            //increase line count
            lines++;
        }
    }
    //increase line count by 1 to consider EOF (last line does not have \n)
    lines++;
    //dynamically allocate memory to the product structure using number of products
    if((productslist = (product *)malloc(lines * sizeof(product))) == NULL)
    {
        //print if error allocating memory
        printf("Memory allocation error !\n");
        //exit program
		exit(1);
    }
    //rewind fp
    rewind(fp);

    //fgets to read line by line
    //while loop to continuously use fgets until the EOF is reached
    while(fgets(str, MAX, fp) != NULL)
    {
        // until ':', characters of the str string will be stored to the storename variable of the productslist array
        while(str[count] != ':')
        {
            //each letter will be saved to each index
            productslist[i].storename[index] = str[count];
            count++;
            index++;
        }
        //set last index to the '\0' to avoid errors
        productslist[i].storename[index] = '\0';
        //increase count (index of str) to skip ':'
        count++;
        //index = 0 for next loop index
        index = 0;

        // until ',', characters of the str string will be stored to the item variable (item name) of the productslist array
        while(str[count] != ',')
        {
            //each letter will be saved to each index
            productslist[i].item[index] = str[count];
            count++;
            index++;
        }
        //set last index to the '\0' to avoid errors
        productslist[i].item[index] = '\0';
        //increase count (index of str) to skip ','
        count++;
        //index = 0 for next loop index
        index = 0;

        // until the next ',', characters of the str string will be stored in a temp variable
        while(str[count] != ',')
        {
            //each letter will be saved to each index
            temp[index] = str[count];
            count++;
            index++;
        }
        //increase count (index of str) to skip ','
        count++;
        //set last index to the '\0' to avoid errors
        temp[index] = '\0';
        //use atoi and save to the price variable to get the integer from the string
        productslist[i].price = atoi(temp);
        //index = 0 for next loop index
        index = 0;

        // until the next ',', characters of the str string will be stored in a temp variable
        while(str[count] != ',')
        {
            //each letter will be saved to each index
            temp[index] = str[count];
            count++;
            index++;
        }
        //increase count (index of str) to skip ','
        count++;
        //set last index to the '\0' to avoid errors
        temp[index] = '\0';
        //use atoi and save to the quantity variable to get the integer from the string
        productslist[i].quantity = atoi(temp);
        //index = 0 for next loop index
        index = 0;

        // until the next ',', characters of the str string will be stored to the discount variable
        while(str[count] != ',')
        {
            //each letter will be saved to each index
            productslist[i].discount[index] = str[count];
            count++;
            index++;
        }
        //set last index to the '\0' to avoid errors
        productslist[i].discount[index] = '\0';
        //increase count (index of str) to skip ','
        count++;
        //index = 0 for next loop index
        index = 0;

        // until the '-', characters of the str string will be stored in a temp variable
        while(str[count] != '-')
        {
            //each letter will be saved to each index
            temp[index] = str[count];
            count++;
            index++;
        }
        //increase count (index of str) to skip ','
        count++;
        //set last index to the '\0' to avoid errors
        temp[index] = '\0';
        //use atoi and save to the expireyear variable to get the integer from the string
        productslist[i].expireyear = atoi(temp);
        //index = 0 for next loop index
        index = 0;

        // until the next '-', characters of the str string will be stored in a temp variable
        while(str[count] != '-')
        {
            //each letter will be saved to each index
            temp[index] = str[count];
            count++;
            index++;
        }
        //increase count (index of str) to skip ','
        count++;
        //set last index to the '\0' to avoid errors
        temp[index] = '\0';
        //use atoi and save to the expiremonth variable to get the integer from the string
        productslist[i].expiremonth = atoi(temp);
        //index = 0 for next loop index
        index = 0;

        // until the next '-', characters of the str string will be stored in a temp variable
        while(str[count] != '\0')
        {
            //each letter will be saved to each index
            temp[index] = str[count];
            count++;
            index++;
        }
        //set last index to the '\0' to avoid errors
        temp[index] = '\0';
        //use atoi and save to the expireday variable to get the integer from the string
        productslist[i].expireday = atoi(temp);
        //reset index and count variables for the next product information
        index = 0;
        count = 0;
        //increase i count to consider next index in the structure variable
        i++;
    }

    //for loop to save the shopkeeper names
    //i loop will go through the 2D array information
    for(i = 0; i < storenum; i++)
    {
        //j loop will go through each and every product
        for(j = 0; j < lines; j++)
        {
            //if storename of product is the same as a certain index in the 2D array
            if(strcmp(productslist[j].storename, storename[i]) == 0)
            {
                //save the shopkeeper info with the same index to the structure
                strncpy(productslist[j].shopkeeper,shopkeeper[i], MAX);
            }
        }
    }

    //close fp file pointer
    if(fclose(fp) != 0)
    {
        //print if there is error in closing
        fprintf(stderr, "Error closing file\n");
    }

    //choice 1: All products
    if(choice == 1)
    {
        //print all products
        printf("\tProducts List: \n");
        printf("\tProduct Name\tStore\tShopkeeper\tPrice\tQuantity\tDiscount\tExpiration Date\n");
        //go through each product using for loop
        for(i = 0; i < lines; i++)
        {
            //print product information
            printf("\t%s", productslist[i].item);
            printf("\t%s", productslist[i].storename);
            printf("\t%s\t", productslist[i].shopkeeper);
            printf("\t%d", productslist[i].price);
            printf("\t%d\t", productslist[i].quantity);
            printf("\t%s\t", productslist[i].discount);
            if(productslist[i].expiremonth > 9 && productslist[i].expireday > 9)
            {
                printf("\t%d-%d-%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
            }
            else if(productslist[i].expiremonth <= 9 && productslist[i].expireday > 9)
            {
                printf("\t%d-0%d-%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
            }
            else if(productslist[i].expiremonth > 9 && productslist[i].expireday <= 9)
            {
                printf("\t%d-%d-0%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
            }
            else
            {
                printf("\t%d-0%d-0%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
            }
        }
    }
    //choice 2: Products with discount
    else if(choice == 2)
    {
        //print out products with discount
        printf("\tProducts List with Discounts: \n");
        printf("\tProduct Name\tStore\tShopkeeper\tPrice\tQuantity\tDiscount\tExpiration Date\n");
        for(i = 0; i < lines; i++)
        {
            //if discount variable is not equal to "None", meaning it has discount
            if(strcmp(productslist[i].discount,"None") != 0)
            {
                //print product information
                printf("\t%s", productslist[i].item);
                printf("\t%s", productslist[i].storename);
                printf("\t%s\t", productslist[i].shopkeeper);
                printf("\t%d", productslist[i].price);
                printf("\t%d\t", productslist[i].quantity);
                printf("\t%s\t", productslist[i].discount);
                if(productslist[i].expiremonth > 9 && productslist[i].expireday > 9)
                {
                    printf("\t%d-%d-%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else if(productslist[i].expiremonth <= 9 && productslist[i].expireday > 9)
                {
                    printf("\t%d-0%d-%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else if(productslist[i].expiremonth > 9 && productslist[i].expireday <= 9)
                {
                    printf("\t%d-%d-0%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else
                {
                    printf("\t%d-0%d-0%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
            }
        }
    }
    //choice 3: Search product using first letter
    else
    {
        //request for first letter input
        printf("Search Product (Enter first letter): ");
        scanf(" %c", &productletter);
        //search for product
        printf("\tResults: \n");
        printf("\tProduct Name\tStore\tShopkeeper\tPrice\tQuantity\tDiscount\tExpiration Date\n");
        //for loop to go through all the products
        for(i = 0; i < lines; i++)
        {
            //if productletter input is the same as the first letter of a certain product
            if(productslist[i].item[0] == productletter)
            {
                //print its information
                printf("\t%s", productslist[i].item);
                printf("\t%s", productslist[i].storename);
                printf("\t%s\t", productslist[i].shopkeeper);
                printf("\t%d", productslist[i].price);
                printf("\t%d\t", productslist[i].quantity);
                printf("\t%s\t", productslist[i].discount);
                if(productslist[i].expiremonth > 9 && productslist[i].expireday > 9)
                {
                    printf("\t%d-%d-%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else if(productslist[i].expiremonth <= 9 && productslist[i].expireday > 9)
                {
                    printf("\t%d-0%d-%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else if(productslist[i].expiremonth > 9 && productslist[i].expireday <= 9)
                {
                    printf("\t%d-%d-0%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
                else
                {
                    printf("\t%d-0%d-0%d\n", productslist[i].expireyear, productslist[i].expiremonth, productslist[i].expireday);
                }
            }
        }
    }

    //free the memory allocation of productslist
    free(productslist);
}