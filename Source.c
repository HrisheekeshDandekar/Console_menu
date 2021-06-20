/*
* A code to print a frame as a border for text
*
* PSUDO CODE
* 1)Assign strings for Title,item and its attributes.
* 2)Decide whiich string is of the largest length.
* 3)Accordingly decide the box display_menu.
* 4)print the whole table in one go.
*
* ASSUMPTIONS:
* 1)The format is followed correctly
*/

#include<stdio.h>

//Values used throughout the code. (Adding them before using the tool is necessary)
#define TOTAL_ITEMS 11
#define MAX_BUFFER 73
#define SINGLE_LEFT_UPPER 218
#define SINGLE_RIGHT_UPPER 191
#define SINGLE_LEFT_LOWER 192
#define SINGLE_RIGHT_LOWER 217
#define SINGLE_HORIZONTAL 196
#define SINGLE_VERTICAL 179
#define DOUBLE_LEFT_UPPER 201
#define DOUBLE_RIGHT_UPPER 187
#define DOUBLE_LEFT_LOWER 200
#define DOUBLE_RIGHT_LOWER 188
#define DOUBLE_HORIZONTAL 205
#define DOUBLE_VERTICAL 186

//functions which are necessary to be added
int horizontal_padding(int largest_length);
int title_printing(struct menu_contents menu, int largest_length);
int item_display_format(struct menu_contents menu, int largest_length, int item_number);
int display_console_menu(struct menu_contents menu);



//Structs to be copied as they are
struct item_contents
{
	char item[MAX_BUFFER];
	char attribute1[MAX_BUFFER];
	char attribute2[MAX_BUFFER];
	char attribute_rightmost[MAX_BUFFER];
};

struct menu_contents
{
	char title[MAX_BUFFER];
	struct item_contents item[TOTAL_ITEMS];
};

int main()
{

	/* TESTING IF THE CHARACTER CODES ARE CORRECT
	printf("%c",SINGLE_LEFT_UPPER );
	printf("%c\n",SINGLE_RIGHT_UPPER );
	printf("%c",SINGLE_LEFT_LOWER );
	printf("%c\n",SINGLE_RIGHT_LOWER );
	printf("%c",DOUBLE_LEFT_UPPER );
	printf("%c\n",DOUBLE_RIGHT_UPPER );
	printf("%c",DOUBLE_LEFT_LOWER );
	printf("%c",DOUBLE_RIGHT_LOWER );
	printf("\n%c",SINGLE_HORIZONTAL);
	printf("\n%c",SINGLE_VERTICAL );
	printf("\n%c",DOUBLE_HORIZONTAL );
	printf("\n%c",DOUBLE_VERTICAL );
	*/

	/*
	* (Dont forget to change the value of the number of items in the #define TOTAL_ITEMS secion)
	* 
	* Add in the struct menu_contents menu declaration
	* 
	* Format text to add more items 
	* .item[ITEM POSITION - 1].item = "NAME OF ITEM",.item[ITEM POSITION - 1].attribute1 = "ATTRIBUTE 1",.item[ITEM POSITION - 1].attribute2 = "ATTRIBUTE 2",.item[ITEM POSITION - 1].attribute_rightmost = "RIGHTMOST ATTRIBUTE"
	* 
	* Dont forge to add a comma after this if there is another item to be printed after this one, make sure there is a comma preceeding this item
	* In the format, Text in bold is to be altered according to your needs, 'ITEM POSITION - 1' is to be replaced by an integer
	* 
	* Format without guide text:
	* .item[].item = "Item",.item[].attribute1 = "Attribute1",.item[].attribute2 = "Attribute2",.item[].attribute_rightmost = ""
	* 
	*/
	struct menu_contents menu =
	{
		.title = "Title",

		.item[0].item = "Item 1",.item[0].attribute1 = "Attribute0.1",.item[0].attribute2 = "Attribute0.2",.item[0].attribute_rightmost = "0",		//Item 1

		.item[1].item = "Item 2",.item[1].attribute1 = "Attribute1.1",.item[1].attribute2 = "Attribute1.2",.item[1].attribute_rightmost = "1",		//Item 2

		.item[2].item = "Item 3",.item[2].attribute1 = "Attribute2.1",.item[2].attribute2 = "Attribute2.2",.item[2].attribute_rightmost = "2",		//Item 3

		.item[3].item = "Item 4",.item[3].attribute1 = "Attribute3.1",.item[3].attribute2 = "Attribute3.2",.item[3].attribute_rightmost = "3",		//Item 4
			
		.item[4].item = "Item 5",.item[4].attribute1 = "Attribute4.1",.item[4].attribute2 = "Attribute4.2",.item[4].attribute_rightmost = "4",		//Item 5

		.item[5].item = "Item 6",.item[5].attribute1 = "Attribute5.1",.item[5].attribute2 = "Attribute5.2",.item[5].attribute_rightmost = "5",		//Item 6

		.item[6].item = "Item 7",.item[6].attribute1 = "Attribute6.1",.item[6].attribute2 = "Attribute6.2",.item[6].attribute_rightmost = "6",		//Item 7

		.item[7].item = "Item 8",.item[7].attribute1 = "Attribute7.1",.item[7].attribute2 = "Attribute7.2",.item[7].attribute_rightmost = "7",		//Item 8
			
		.item[8].item = "Item 9",.item[8].attribute1 = "Attribute8.1",.item[8].attribute2 = "Attribute8.2",.item[8].attribute_rightmost = "8",		//Item 9

		.item[9].item = "Item 10",.item[9].attribute1 = "Attribute9.1",.item[9].attribute2 = "Attribute9.2",.item[9].attribute_rightmost = "9",		//Item 10

		.item[10].item = "",.item[10].attribute1 = "",.item[10].attribute2 = "",.item[10].attribute_rightmost = "" //Checking if an empty cell is being printed or not //Item 11
	};

	//Calling the function to print the contents in a tabular format 
	display_console_menu(menu);
	return 0;
	
}

int display_console_menu(struct menu_contents menu)
{
	int title_len, item_len, attribute1_len, attribute2_len, rightmost_attribute_len, item_full_len, largest_length, counter;

	title_len = strlen(menu.title);
	largest_length = title_len;

	for (counter = 0; counter < TOTAL_ITEMS; counter++)
	{
		item_len = strlen(menu.item[counter].item);
		attribute1_len = strlen(menu.item[counter].attribute1);
		attribute2_len = strlen(menu.item[counter].attribute2);
		rightmost_attribute_len = strlen(menu.item[counter].attribute_rightmost);
		item_full_len = item_len + attribute1_len + attribute2_len + rightmost_attribute_len;

		if (largest_length <= item_full_len)		//Deciding the largest length to be printed
		{
			largest_length = item_full_len;
		}

		//Making sure all the contests can be properly printed

		if ((title_len > (MAX_BUFFER-1))||(item_len > (MAX_BUFFER-1)) || (attribute1_len > (MAX_BUFFER-1)) || (attribute2_len > (MAX_BUFFER-1)) || 
			(rightmost_attribute_len > (MAX_BUFFER-1)))
		{
			printf("The values trying to be entered in the arrays exceed the max value of 72\nTo make sure each character is displayed, ");
			printf("Please make sure the length of charaters does not exceed 200 in any element");
			printf("\n\n\n");
			exit();
		}
		if (largest_length > 72)
		{
			printf("The contents are longer than the size of a console hence will result in a bad render of a box\n");
			printf("Please re-evaluate the contents and make them fit under 73 characters");
			exit();	
		}
	}



	//Starting to print the menu

	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_LEFT_UPPER);											//Upper boundry of Double frame
	for (counter = 0; counter < largest_length + 8; counter++)
	{
		printf("%c", DOUBLE_HORIZONTAL);
	}
	printf("%c\n", DOUBLE_RIGHT_UPPER);

	title_printing(menu, largest_length);				//Printing Title



	for(counter = 0; counter < TOTAL_ITEMS; counter++)			//Printing the item row/'s
	{	
		item_len = strlen(menu.item[counter].item);
		attribute1_len = strlen(menu.item[counter].attribute1);
		attribute2_len = strlen(menu.item[counter].attribute2);
		rightmost_attribute_len = strlen(menu.item[counter].attribute_rightmost);
		item_full_len = item_len + attribute1_len + attribute2_len + rightmost_attribute_len;

		if (item_full_len != 0)										//Checking if the cell is not empty
		{
			item_display_format(menu, largest_length, counter);
		}
	}



	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_LEFT_LOWER);									//Lower boundry of double frame
	for (counter = 0; counter < largest_length + 8; counter++)
	{
		printf("%c", DOUBLE_HORIZONTAL);
	}
	printf("%c\n", DOUBLE_RIGHT_LOWER);


	return 0;
}

int horizontal_padding(int largest_length)
{
	//Horizontal length of the console is 120 characters
	//Vertical length of the console is 30 characters

	int doubleframe_horizontal_length, horizontal_padd_size, vertical_padd_size, counter;

	doubleframe_horizontal_length = largest_length + 8;
	horizontal_padd_size = ((120 - doubleframe_horizontal_length) / 2);


	for (counter = 0; counter < horizontal_padd_size; counter++)//Horizontal Padding for each line
	{
		printf(" ");
	}
	return 0;
}

int item_display_format(struct menu_contents menu,int largest_length,int item_number)
{
	int item_len = strlen(menu.item[item_number].item);
	int attribute1_len = strlen(menu.item[item_number].attribute1);
	int attribute2_len = strlen(menu.item[item_number].attribute2);
	int attribute_rightmost_len = strlen(menu.item[item_number].attribute_rightmost);
	int item_full_length = item_len + attribute1_len + attribute2_len + attribute_rightmost_len;
	int counter;

	horizontal_padding(largest_length);   //Padding to get the table at the centre
																//LINE 1 (Upper parts of single borders)
	printf("%c", DOUBLE_VERTICAL);


	if (item_len != 0)
	{
		printf("%c", SINGLE_LEFT_UPPER);							//Start of item name single frame
	}
	else
	{
		printf("  ");
	}

	for (counter = 0; counter < item_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	if (item_len != 0)
	{
		printf("%c", SINGLE_RIGHT_UPPER);
	}

	if (attribute1_len != 0)
	{
		printf("%c", SINGLE_LEFT_UPPER);							//Start of attribute1 single frame
	}
	else
	{
		printf("  ");
	}

	for (counter = 0; counter < attribute1_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	if (attribute1_len != 0)
	{
		printf("%c", SINGLE_RIGHT_UPPER);
	}


	if (attribute2_len != 0)
	{
		printf("%c", SINGLE_LEFT_UPPER);							//Start of attribute2 single frame 
	}
	else
	{
		printf("  ");
	}


	for (counter = 0; counter < attribute2_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	if (attribute2_len != 0)
	{
		printf("%c", SINGLE_RIGHT_UPPER);
	}


	if (item_full_length != largest_length)						//Padding betwwen right most value and attribute 2 in case if this is not the largest string
	{
		for (counter = 0; counter < largest_length - item_full_length; counter++)
		{
			printf(" ");
		}
	}


	if (attribute_rightmost_len != 0)
	{
		printf("%c", SINGLE_LEFT_UPPER);							//Start of rightmost attribute single frame 
	}
	else
	{
		printf("  ");
	}
	for (counter = 0; counter < attribute_rightmost_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	if (attribute_rightmost_len != 0)
	{
		printf("%c", SINGLE_RIGHT_UPPER);
	}

	printf("%c\n", DOUBLE_VERTICAL);


	//LINE 2 (Printing strings)
	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_VERTICAL);

	if (item_len != 0)
	{
		printf("%c", SINGLE_VERTICAL);
		printf("%s", menu.item[item_number].item);		//Item name
		printf("%c", SINGLE_VERTICAL);
	}
	else
	{
		printf("  ");
	}

	if (attribute1_len != 0)
	{
		printf("%c", SINGLE_VERTICAL);
		printf("%s", menu.item[item_number].attribute1);		//Attribute1
		printf("%c", SINGLE_VERTICAL);
	}
	else
	{
		printf("  ");
	}

	if (attribute2_len != 0)
	{
		printf("%c", SINGLE_VERTICAL);
		printf("%s", menu.item[item_number].attribute2);		//Attribute2
		printf("%c", SINGLE_VERTICAL);
	}
	else
	{
		printf("  ");
	}

	if (item_full_length != largest_length)						//Padding betwwen right most value and attribute 2 in case if this is not the largest string
	{
		for (counter = 0; counter < largest_length - item_full_length; counter++)
		{
			printf(" ");
		}
	}

	if (attribute_rightmost_len != 0)
	{
		printf("%c", SINGLE_VERTICAL);
		printf("%s", menu.item[item_number].attribute_rightmost);		//Attribute_rightmost
		printf("%c", SINGLE_VERTICAL);
	}
	else
	{
		printf("  ");
	}

	printf("%c\n", DOUBLE_VERTICAL);

	//LINE 3 (Closing of all the single borders)
	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_VERTICAL);


	if (item_len != 0)
	{
		printf("%c", SINGLE_LEFT_LOWER);							//End of item name single frame
	}
	else
	{
		printf("  ");
	}

	for (counter = 0; counter < item_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	if (item_len != 0)
	{
		printf("%c", SINGLE_RIGHT_LOWER);
	}

	if (attribute1_len != 0)
	{
		printf("%c", SINGLE_LEFT_LOWER);							//End of attribute1 single frame
	}
	else
	{
		printf("  ");
	}

	for (counter = 0; counter < attribute1_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	if (attribute1_len != 0)
	{
		printf("%c", SINGLE_RIGHT_LOWER);
	}


	if (attribute2_len != 0)
	{
		printf("%c", SINGLE_LEFT_LOWER);							//End of attribute2 single frame 
	}
	else
	{
		printf("  ");
	}


	for (counter = 0; counter < attribute2_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	if (attribute2_len != 0)
	{
		printf("%c", SINGLE_RIGHT_LOWER);
	}


	if (item_full_length != largest_length)						//Padding betwwen right most value and attribute 2 in case if this is not the largest string
	{
		for (counter = 0; counter < largest_length - item_full_length; counter++)
		{
			printf(" ");
		}
	}


	if (attribute_rightmost_len != 0)
	{
		printf("%c", SINGLE_LEFT_LOWER);							//End of rightmost attribute single frame 
	}
	else
	{
		printf("  ");
	}
	for (counter = 0; counter < attribute_rightmost_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	if (attribute_rightmost_len != 0)
	{
		printf("%c", SINGLE_RIGHT_LOWER);
	}

	printf("%c\n", DOUBLE_VERTICAL);

	return 0;
}

int title_printing(struct menu_contents menu, int largest_length)
{
	int counter, title_padding, title_len;

	title_len = strlen(menu.title);
	title_padding = ((largest_length + 4) - title_len) / 2;

	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_VERTICAL);									//Blank Line
	for (counter = 0; counter < (largest_length + 8); counter++)
	{
		printf(" ");
	}
	printf("%c", DOUBLE_VERTICAL);
	printf("\n");


	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_VERTICAL);									//Upper start of Title frame  (LINE 1)
	printf(" ");
	printf("%c", DOUBLE_LEFT_UPPER);
	for (counter = 0; counter < (largest_length + 4); counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", DOUBLE_RIGHT_UPPER);
	printf(" ");
	printf("%c\n", DOUBLE_VERTICAL);


	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_VERTICAL);                                  //Printing title (LINE 2)
	printf(" ");
	printf("%c", SINGLE_VERTICAL);
	for (counter = 0; counter < title_padding; counter++)
	{
		printf(" ");
	}
	printf("%s", menu.title);
	for (counter = 0; counter < title_padding; counter++)
	{
		printf(" ");
	}
	//Making sure padding is correct (Total length of the line has to be padded with space. If title.len is odd, one space is given less as lower bound is taken during divition)
	if ((title_len % 2) != ((largest_length + 4) % 2))
	{
		printf(" ");
	}
	printf("%c", SINGLE_VERTICAL);
	printf(" ");
	printf("%c\n", DOUBLE_VERTICAL);


	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_VERTICAL);									//Lower Start of  Title frame (LINE 3)
	printf(" ");
	printf("%c", DOUBLE_LEFT_LOWER);
	for (counter = 0; counter < (largest_length + 4); counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", DOUBLE_RIGHT_LOWER);
	printf(" ");
	printf("%c\n", DOUBLE_VERTICAL);

	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_VERTICAL);									//Blank Line
	for (counter = 0; counter < (largest_length + 8); counter++)
	{
		printf(" ");
	}
	printf("%c", DOUBLE_VERTICAL);
	printf("\n");

	return 0;
}