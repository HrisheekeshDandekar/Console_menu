/*
* A code to print a frame as a border for text
*
* PSUDO CODE
* 1)Assign strings for Title,item1,Item2,Price1,Price2.
* 2)Decide whiich string is of the largest length.
* 3)Accordingly decide the box display_menu.
* 4)print the whole table in one go.
*
* ASSUMPTIONS:
* 1)For now the user can only add 2 items with one related info
*/

#include<stdio.h>
#define MAX_BUFFER 200
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

//int display_menu(struct menu_contents menu);
//int horizontal_padding_values(int largest_length);
//int print_the_frame(struct menu_contents menu, int title_len, int item1_len, int price1_len, int item2_len, int price2_len, int largest_length, int horizontal_padd_size);
int horizontal_padding(int largest_length);
int title_printing(struct menu_contents menu, int largest_length);
int item_display_format(struct item_contents item, int item_full_length, int largest_length);
int console_menu(struct menu_contents menu, struct item_contents item1, struct item_contents item2, struct item_contents item3, struct item_contents item4, struct item_contents item5,
	struct item_contents item6, struct item_contents item7, struct item_contents item8, struct item_contents item9, struct item_contents item10);



struct menu_contents
{
	char title[MAX_BUFFER];
	/*char item1[MAX_BUFFER];
	char price1[MAX_BUFFER];
	char item2[MAX_BUFFER];
	char price2[MAX_BUFFER];*/
};
struct item_contents
{
	char item[MAX_BUFFER];
	char attribute1[MAX_BUFFER];
	char attribute2[MAX_BUFFER];
	char attribute_rightmost[MAX_BUFFER];
};
struct all_items
{
	struct item_contents;
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

	struct menu_contents menu =               //Format{Title,Item1,Item2,}
	{
		//Normal output
		"FINAF Pizzeria abra ka dabra gili gili chuuuu"/*,"Margaretta Double Cheese with Cheese Burst","Rs.225/-","BlueBerry Cheese Cake","Rs.125/-"*/
		// Max values to fit the length of console
		//"a","a","a","a","aaaaaa321321321aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		//Vales exceeding the max array sixe
		//"a","a","a","a","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"


	};

	struct item_contents item1=
	{
		"Ryzen5 5600x","Clock Rate3700 -  4600 MHz","65watt","Rs. 27,849"
	};
	struct item_contents item2 =
	{
		//"GTX 3060ti","OC Mode - 1740","600W","Rs. 35,900"
		"","","",""
	};
	struct item_contents item3 =
	{
		"AMD B550","PCIe 4.0/3.0 x4 M.2","Q-Flash Plus","Rs. 9,550"
	};
	struct item_contents item4 =
	{
		"Ryzen5 5600x","Clock Rate 3700 - 4600 MHz","65watt","Rs/-27,849"
	};
	struct item_contents item5 =
	{
		"Ryzen5 5600x","Clock Rate 3700 - 4600 MHz","65watt","Rs/-27,849"
	};
	struct item_contents item6 =
	{
		"Ryzen5 5600x","Clock Rate 3700 - 4600 MHz","65watt","Rs/-27,849"
	};
	struct item_contents item7 =
	{
		"Ryzen5 5600x","Clock Rate 3700 - 4600 MHz","65watt","Rs/-27,849"
	};
	struct item_contents item8 =
	{
		"Ryzen5 5600x","Clock Rate 3700 - 4600 MHz","65watt","Rs/-27,849"
	};
	struct item_contents item9 =
	{
		"Ryzen5 5600x","Clock Rate	3700 - 4600 MHz","65watt","Rs/-27,849"
	};
	struct item_contents item10 =
	{
		"Ryzen5 5600x","Clock Rate	3700 - 4600 MHz","65watt","Rs/-27,849"
	};
	//display_menu(menu);		
	console_menu(menu, item1, item2, item3, item4, item5, item6, item7, item8, item9, item10);
	return 0;

}

int console_menu(struct menu_contents menu ,struct item_contents item1, struct item_contents item2, struct item_contents item3, struct item_contents item4, struct item_contents item5,
	struct item_contents item6, struct item_contents item7, struct item_contents item8, struct item_contents item9, struct item_contents item10)
{
	int title_len;
	int item1_len, attribute1_1_len, attribute1_2_len, attribute_rightmost1_len, item2_len, attribute2_1_len, attribute2_2_len, attribute_rightmost2_len, item3_len, attribute3_1_len, attribute3_2_len, attribute_rightmost3_len;
	int item4_len, attribute4_1_len, attribute4_2_len, attribute_rightmost4_len, item5_len, attribute5_1_len, attribute5_2_len, attribute_rightmost5_len, item6_len, attribute6_1_len, attribute6_2_len, attribute_rightmost6_len;
	int item7_len, attribute7_1_len, attribute7_2_len, attribute_rightmost7_len, item8_len, attribute8_1_len, attribute8_2_len, attribute_rightmost8_len, item9_len, attribute9_1_len, attribute9_2_len, attribute_rightmost9_len;
	int item10_len, attribute10_1_len, attribute10_2_len, attribute_rightmost10_len;

	int item1_full_length, item2_full_length, item3_full_length, item4_full_length, item5_full_length, item6_full_length, item7_full_length, item8_full_length, item9_full_length, item10_full_length;

	int largest_length;// horizontal_padd_size;

	int counter;

	//To decide the dimentions of the box,string lengths are taken and compared

	title_len = strlen(menu.title);

	item1_len = strlen(item1.item);
	attribute1_1_len = strlen(item1.attribute1);
	attribute1_2_len = strlen(item1.attribute2);
	attribute_rightmost1_len = strlen(item1.attribute_rightmost);

	item1_full_length = item1_len + attribute1_1_len + attribute1_2_len + attribute_rightmost1_len;


	item2_len = strlen(item2.item);
	attribute2_1_len = strlen(item2.attribute1);
	attribute2_2_len = strlen(item2.attribute2);
	attribute_rightmost2_len = strlen(item2.attribute_rightmost);

	item2_full_length = item2_len + attribute2_1_len + attribute2_2_len + attribute_rightmost2_len;


	item3_len = strlen(item3.item);
	attribute3_1_len = strlen(item3.attribute1);
	attribute3_2_len = strlen(item3.attribute2);
	attribute_rightmost3_len = strlen(item3.attribute_rightmost);

	item3_full_length = item3_len + attribute3_1_len + attribute3_2_len + attribute_rightmost3_len;


	item4_len = strlen(item5.item);
	attribute4_1_len = strlen(item4.attribute1);
	attribute4_2_len = strlen(item4.attribute2);
	attribute_rightmost4_len = strlen(item4.attribute_rightmost);

	item4_full_length = item4_len + attribute4_1_len + attribute4_2_len + attribute_rightmost4_len;


	item5_len = strlen(item5.item);
	attribute5_1_len = strlen(item5.attribute1);
	attribute5_2_len = strlen(item5.attribute2);
	attribute_rightmost5_len = strlen(item5.attribute_rightmost);

	item5_full_length = item5_len + attribute5_1_len + attribute5_2_len + attribute_rightmost5_len;


	item6_len = strlen(item6.item);
	attribute6_1_len = strlen(item6.attribute1);
	attribute6_2_len = strlen(item6.attribute2);
	attribute_rightmost6_len = strlen(item6.attribute_rightmost);

	item6_full_length = item6_len + attribute6_1_len + attribute6_2_len + attribute_rightmost6_len;


	item7_len = strlen(item7.item);
	attribute7_1_len = strlen(item7.attribute1);
	attribute7_2_len = strlen(item7.attribute2);
	attribute_rightmost7_len = strlen(item7.attribute_rightmost);

	item7_full_length = item7_len + attribute7_1_len + attribute7_2_len + attribute_rightmost7_len;


	item8_len = strlen(item8.item);
	attribute8_1_len = strlen(item8.attribute1);
	attribute8_2_len = strlen(item8.attribute2);
	attribute_rightmost8_len = strlen(item8.attribute_rightmost);

	item8_full_length = item8_len + attribute8_1_len + attribute8_2_len + attribute_rightmost8_len;


	item9_len = strlen(item9.item);
	attribute9_1_len = strlen(item9.attribute1);
	attribute9_2_len = strlen(item9.attribute2);
	attribute_rightmost9_len = strlen(item9.attribute_rightmost);

	item9_full_length = item9_len + attribute9_1_len + attribute9_2_len + attribute_rightmost9_len;


	item10_len = strlen(item10.item);
	attribute10_1_len = strlen(item10.attribute1);
	attribute10_2_len = strlen(item10.attribute2);
	attribute_rightmost10_len = strlen(item10.attribute_rightmost);

	item10_full_length = item10_len + attribute10_1_len + attribute10_2_len + attribute_rightmost10_len;

	// Decideing the largest string length of the 10 items.
	largest_length = title_len;
	if (largest_length <= item1_full_length)
	{
		largest_length = item1_full_length;
	}
	if (largest_length <= item2_full_length)
	{
		largest_length = item2_full_length;
	}
	if (largest_length <= item3_full_length)
	{
		largest_length = item3_full_length;
	}
	if (largest_length <= item4_full_length)
	{
		largest_length = item4_full_length;
	}
	if (largest_length <= item5_full_length)
	{
		largest_length = item5_full_length;
	}
	if (largest_length <= item6_full_length)
	{
		largest_length = item6_full_length;
	}
	if (largest_length <= item7_full_length)
	{
		largest_length = item7_full_length;
	}
	if (largest_length <= item8_full_length)
	{
		largest_length = item8_full_length;
	}
	if (largest_length <= item9_full_length)
	{
		largest_length = item9_full_length;
	}
	if (largest_length <= item10_full_length)
	{
		largest_length = item10_full_length;
	}

	//checking if any of the items have string length greater than maximum allowed
	if ((title_len > MAX_BUFFER) || (item1_len > MAX_BUFFER) || (attribute1_1_len > MAX_BUFFER) || (attribute1_2_len > MAX_BUFFER) || (attribute_rightmost1_len > MAX_BUFFER) ||
		(item2_len > MAX_BUFFER) || (attribute2_1_len > MAX_BUFFER) || (attribute2_2_len > MAX_BUFFER) || (attribute_rightmost2_len > MAX_BUFFER) || (item3_len > MAX_BUFFER) ||
		(attribute3_1_len > MAX_BUFFER) || (attribute3_2_len > MAX_BUFFER) || (attribute_rightmost3_len > MAX_BUFFER) || (item4_len > MAX_BUFFER) || (attribute4_1_len > MAX_BUFFER) ||
		(attribute4_2_len > MAX_BUFFER) || (attribute_rightmost4_len > MAX_BUFFER) || (item5_len > MAX_BUFFER) || (attribute5_1_len > MAX_BUFFER) || (attribute5_2_len > MAX_BUFFER) ||
		(attribute_rightmost5_len > MAX_BUFFER) || (item6_len > MAX_BUFFER) || (attribute6_1_len > MAX_BUFFER) || (attribute6_2_len > MAX_BUFFER) || (attribute_rightmost6_len > MAX_BUFFER) ||
		(item7_len > MAX_BUFFER) || (attribute7_1_len > MAX_BUFFER) || (attribute7_2_len > MAX_BUFFER) || (attribute_rightmost7_len > MAX_BUFFER) || (item8_len > MAX_BUFFER) ||
		(attribute8_1_len > MAX_BUFFER) || (attribute8_2_len > MAX_BUFFER) || (attribute_rightmost8_len > MAX_BUFFER) || (item9_len > MAX_BUFFER) || (attribute9_1_len > MAX_BUFFER) ||
		(attribute9_2_len > MAX_BUFFER) || (attribute_rightmost9_len > MAX_BUFFER) || (item10_len > MAX_BUFFER) || (attribute10_1_len > MAX_BUFFER) || (attribute10_2_len > MAX_BUFFER) ||
		(attribute_rightmost10_len > MAX_BUFFER))
	{
		printf("The values trying to be entered in the arrays exceed the max value of 200\nTo make sure each character is displayed, ");
		printf("Please make sure the length of charaters does not exceed 200 in any element");
		printf("\n\n\n");
		exit();
	}

	//Starting to print the menu

	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_LEFT_UPPER);											//Upper boundry of Double frame
	for (counter = 0; counter < largest_length + 8; counter++)
	{
		printf("%c", DOUBLE_HORIZONTAL);
	}
	printf("%c\n", DOUBLE_RIGHT_UPPER);

	title_printing(menu,largest_length);				//Printing Title

	if (item1_full_length != 0)
	{
		item_display_format(item1, item1_full_length, largest_length);
	}
	if (item2_full_length != 0)
	{
		item_display_format(item2, item2_full_length, largest_length);
	}
	if (item3_full_length != 0)
	{
		item_display_format(item3, item3_full_length, largest_length);
	}
	if (item4_full_length != 0)
	{
		item_display_format(item4, item4_full_length, largest_length);
	}
	if (item5_full_length != 0)
	{
		item_display_format(item5, item5_full_length, largest_length);
	}
	if (item6_full_length != 0)
	{
		item_display_format(item6, item6_full_length, largest_length);
	}
	if (item7_full_length != 0)
	{
		item_display_format(item7, item7_full_length, largest_length);
	}
	if (item8_full_length != 0)
	{
		item_display_format(item8, item8_full_length, largest_length);
	}
	if (item9_full_length != 0)
	{
		item_display_format(item9, item9_full_length, largest_length);
	}
	if (item10_full_length != 0)
	{
		item_display_format(item10, item10_full_length, largest_length);
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
/*int item_display_format(int title_len,int item1_len, int attribute1_1_len, int attribute1_2_len, int attribute_rightmost1_len, int item2_len, int attribute2_1_len,
	int attribute2_2_len, int attribute_rightmost2_len, int item3_len, int attribute3_1_len, int attribute3_2_len, int attribute_rightmost3_len,int item4_len, int attribute4_1_len, 
	int attribute4_2_len,int attribute_rightmost4_len, int item5_len, int attribute5_1_len, int attribute5_2_len, int attribute_rightmost5_len, int item6_len, int attribute6_1_len, 
	int attribute6_2_len, int attribute_rightmost6_len,int item7_len, int attribute7_1_len, int attribute7_2_len, int attribute_rightmost7_len, int item8_len, int attribute8_1_len, 
	int attribute8_2_len, int attribute_rightmost8_len, int item9_len, int attribute9_1_len, int attribute9_2_len, int attribute_rightmost9_len,int item10_len, int attribute10_1_len, 
	int attribute10_2_len, int attribute_rightmost10_len,
	int item1_full_length, int item2_full_length, int item3_full_length, int item4_full_length, int item5_full_length, int item6_full_length, int item7_full_length, int item8_full_length, 
	int item9_full_length, int item10_full_length,int largest_length,
	struct menu_contents menu, struct item_contents item1, struct item_contents item2, struct item_contents item3, struct item_contents item4, struct item_contents item5,
	struct item_contents item6, struct item_contents item7, struct item_contents item8, struct item_contents item9, struct item_contents item10)
{
	return 0;
}*/
int horizontal_padding(int largest_length)
{
	//Horizontal length of the console is 120 characters
	//Vertical length of the console is 30 characters

	int doubleframe_horizontal_length, horizontal_padd_size, vertical_padd_size,counter;

	doubleframe_horizontal_length = largest_length + 8;
	horizontal_padd_size = ((120 - doubleframe_horizontal_length) / 2);


	for (counter = 0; counter < horizontal_padd_size; counter++)//Horizontal Padding for each line
	{
		printf(" ");
	}
}

int item_display_format(struct item_contents item, int item_full_length, int largest_length)
{
	int item_len = strlen(item.item);
	int attribute1_len = strlen(item.attribute1);
	int attribute2_len = strlen(item.attribute2);
	int attribute_rightmost_len = strlen(item.attribute_rightmost);
	int counter;

	horizontal_padding(largest_length);   //Padding to get the table at the centre
																//LINE 1 (Upper parts of single borders)
	printf("%c", DOUBLE_VERTICAL);


	printf("%c", SINGLE_LEFT_UPPER);							//Start of item name single frame
	for (counter = 0; counter < item_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", SINGLE_RIGHT_UPPER);


	printf("%c", SINGLE_LEFT_UPPER);							//Start of attribute1 single frame
	for (counter = 0; counter < attribute1_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", SINGLE_RIGHT_UPPER);


	printf("%c", SINGLE_LEFT_UPPER);							//Start of attribute2 single frame 
	for (counter = 0; counter < attribute2_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", SINGLE_RIGHT_UPPER);


	if (item_full_length != largest_length)						//Padding betwwen right most value and attribute 2 in case if this is not the largest string
	{
		for (counter = 0; counter < largest_length - item_full_length; counter++)
		{
			printf(" ");
		}
	}



	printf("%c", SINGLE_LEFT_UPPER);							//Start of rightmost attribute single frame 
	for (counter = 0; counter < attribute_rightmost_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", SINGLE_RIGHT_UPPER);

	printf("%c\n", DOUBLE_VERTICAL);
	
																	//LINE 2 (Printing strings)
	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_VERTICAL);

	printf("%c", SINGLE_VERTICAL);
	printf("%s", item.item);		//Item name
	printf("%c", SINGLE_VERTICAL);

	printf("%c", SINGLE_VERTICAL);
	printf("%s", item.attribute1);		//Attribute1
	printf("%c", SINGLE_VERTICAL);

	printf("%c", SINGLE_VERTICAL);
	printf("%s", item.attribute2);		//Attribute2
	printf("%c", SINGLE_VERTICAL);

	if (item_full_length != largest_length)						//Padding betwwen right most value and attribute 2 in case if this is not the largest string
	{
		for (counter = 0; counter < largest_length - item_full_length; counter++)
		{
			printf(" ");
		}
	}

	printf("%c", SINGLE_VERTICAL);
	printf("%s", item.attribute_rightmost);		//Attribute_rightmost
	printf("%c", SINGLE_VERTICAL);

	printf("%c\n", DOUBLE_VERTICAL);

																//LINE 3 (Closing of all the single borders)
	horizontal_padding(largest_length);   //Padding to get the table at the centre
	printf("%c", DOUBLE_VERTICAL);


	printf("%c", SINGLE_LEFT_LOWER);							//End of item name single frame
	for (counter = 0; counter < item_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", SINGLE_RIGHT_LOWER);


	printf("%c", SINGLE_LEFT_LOWER);							//End of attribute1 single frame
	for (counter = 0; counter < attribute1_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", SINGLE_RIGHT_LOWER);


	printf("%c", SINGLE_LEFT_LOWER);							//End of attribute2 single frame 
	for (counter = 0; counter < attribute2_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", SINGLE_RIGHT_LOWER);


	if (item_full_length != largest_length)						//Padding betwwen right most value and attribute 2 in case if this is not the largest string
	{
		for (counter = 0; counter < largest_length - item_full_length; counter++)
		{
			printf(" ");
		}
	}



	printf("%c", SINGLE_LEFT_LOWER);							//End of rightmost attribute single frame 
	for (counter = 0; counter < attribute_rightmost_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", SINGLE_RIGHT_LOWER);

	printf("%c\n", DOUBLE_VERTICAL);

}

int title_printing(struct menu_contents menu, int largest_length)
{
	int counter, title_padding, title_len;

	title_len = strlen(menu.title);
	title_padding = ((largest_length+4) - title_len) / 2;

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
	for (counter = 0; counter < (largest_length+4); counter++)
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
	if ((title_len % 2) != ((largest_length+4) % 2))
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
	for (counter = 0; counter < (largest_length+4); counter++)
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




