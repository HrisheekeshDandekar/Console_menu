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


int display_menu(struct menu_contents menu);
int horizontal_padding_values(int largest_length);
int print_the_frame(struct menu_contents menu, int title_len, int item1_len, int price1_len, int item2_len, int price2_len, int largest_length, int horizontal_padd_size);
int console_menu(struct item_contents item1, struct item_contents item2, struct item_contents item3, struct item_contents item4, struct item_contents item5,
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
		"FINAF Pizzeria"/*,"Margaretta Double Cheese with Cheese Burst","Rs.225/-","BlueBerry Cheese Cake","Rs.125/-"*/
		// Max values to fit the length of console
		//"a","a","a","a","aaaaaa321321321aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
		//Vales exceeding the max array sixe
		//"a","a","a","a","aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"


	};

	struct item_contents item1=
	{
		"Ryzen5 5600x","Clock Rate	3700 - 4600 MHz","65watt","Rs. 27,849"
	};
	struct item_contents item2 =
	{
		"GTX 3060ti","OC Mode - 1740","600W","Rs. 35,900"
	};
	struct item_contents item3 =
	{
		"AMD B550","PCIe 4.0/3.0 x4 M.2","Q-Flash Plus","Rs. 9,550"
	};
	struct item_contents item4 =
	{
		"Ryzen5 5600x","Clock Rate	3700 - 4600 MHz","65watt","Rs/-27,849"
	};
	struct item_contents item5 =
	{
		"Ryzen5 5600x","Clock Rate	3700 - 4600 MHz","65watt","Rs/-27,849"
	};
	struct item_contents item6 =
	{
		"Ryzen5 5600x","Clock Rate	3700 - 4600 MHz","65watt","Rs/-27,849"
	};
	struct item_contents item7 =
	{
		"Ryzen5 5600x","Clock Rate	3700 - 4600 MHz","65watt","Rs/-27,849"
	};
	struct item_contents item8 =
	{
		"Ryzen5 5600x","Clock Rate	3700 - 4600 MHz","65watt","Rs/-27,849"
	};
	struct item_contents item9 =
	{
		"Ryzen5 5600x","Clock Rate	3700 - 4600 MHz","65watt","Rs/-27,849"
	};
	struct item_contents item10 =
	{
		"Ryzen5 5600x","Clock Rate	3700 - 4600 MHz","65watt","Rs/-27,849"
	};
	display_menu(menu);		
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

	int largest_length, horizontal_padd_size;

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

}

int display_menu(struct menu_contents menu)
{
	int title_len, item1_len, price1_len, item2_len, price2_len, item1_full_length, item2_full_length, largest_length, horizontal_padd_size;

	//Assigning string lengths to variables
	title_len = strlen(menu.title);
	/*item1_len = strlen(menu.item1);
	price1_len = strlen(menu.price1);
	item2_len = strlen(menu.item2);
	price2_len = strlen(menu.price2);*/

	//Combining lengths for item name and price
	item1_full_length = item1_len + price1_len;
	item2_full_length = item2_len + price2_len;

	//Deciding which string is the longenst
	if ((title_len >= item1_full_length) && (title_len >= item2_full_length))
	{
		largest_length = title_len;
		//printf("\nLargest length is title");
	}
	else if ((item1_full_length >= title_len) && (item1_full_length >= item2_full_length))
	{
		largest_length = item1_full_length;
		//printf("\nLargest length is item 1 full");
	}
	else
	{
		largest_length = item2_full_length;
		//printf("\nLargest length is item2 full");
	}
	//printf("\nLength is  %d", largest_length);
	if ((title_len > MAX_BUFFER) || (item1_len > MAX_BUFFER) || (price1_len > MAX_BUFFER) || (item2_len > MAX_BUFFER) || (price2_len > MAX_BUFFER))
	{
		printf("The values trying to be entered in the arrays exceed the max value of 200\nTo make sure each character is displayed, ");
		printf("Please make sure the length of charaters does not exceed 200 in any element");
		printf("\n\n\n\n\n\n\n\n");
		exit();
	}
	if (largest_length > 113)						//Checking if user is okay with frames larger than the console
	{
		printf("The display_menu of the box to be displayed exceeds the Normal size of the console on Win10 16:9 screen.");
		printf("\nIf you wish to continue, enter 0");
		int error_accepted;
		scanf_s("%d", &error_accepted);
		if (error_accepted == 0)
		{
			horizontal_padd_size = horizontal_padding_values(largest_length);
			print_the_frame(menu, title_len, item1_len, price1_len, item2_len, price2_len, largest_length, horizontal_padd_size);
		}
		else
		{
			exit();
		}
	}

	horizontal_padd_size = horizontal_padding_values(largest_length);

	print_the_frame(menu, title_len, item1_len, price1_len, item2_len, price2_len, largest_length, horizontal_padd_size);
	return 0;
}

int horizontal_padding_values(int largest_length)
{
	//Horizontal length of the console is 120 characters
	//Vertical length of the console is 30 characters

	int doubleframe_horizontal_length, horizontal_padd_size, vertical_padd_size;

	doubleframe_horizontal_length = largest_length + 6;
	horizontal_padd_size = ((120 - doubleframe_horizontal_length) / 2);

	//As the vertical length of table and console is fixed, we know the horizonal padding value is 8

	return horizontal_padd_size;
}
int single_element_row(struct menu_contents menu, int title_len, int item1_len, int price1_len, int item2_len, int price2_len, int largest_length, int horizontal_padd_size)
{
	printf("%c", DOUBLE_VERTICAL);

}
//Block to print the Table
int print_the_frame(struct menu_contents menu, int title_len, int item1_len, int price1_len, int item2_len, int price2_len, int largest_length, int horizontal_padd_size)
{
	int counter, title_padding;

	title_padding = (largest_length - title_len) / 2;
	/*printf("%d\n", largest_length);
	printf("%d\n", title_len);
	printf("%d\n", title_padding);*/
	for (counter = 0; counter < 8; counter++) //Vertical Padding
	{
		printf("\n");
	}
	//Outer frame, upper line
	for (counter = 0; counter < horizontal_padd_size; counter++)//Horizontal Padding for each line
	{
		printf(" ");
	}
	printf("%c", DOUBLE_LEFT_UPPER);
	for (counter = 0; counter < largest_length + 4; counter++)
	{
		printf("%c", DOUBLE_HORIZONTAL);
	}
	printf("%c\n", DOUBLE_RIGHT_UPPER);
	//Upper line blank
	for (counter = 0; counter < horizontal_padd_size; counter++)//Horizontal Padding for each line
	{
		printf(" ");
	}
	printf("%c", DOUBLE_VERTICAL);
	for (counter = 0; counter < largest_length + 4; counter++)
	{
		printf(" ");
	}
	printf("%c\n", DOUBLE_VERTICAL);
	//Start of title frame
	for (counter = 0; counter < horizontal_padd_size; counter++)//Horizontal Padding for each line
	{
		printf(" ");
	}
	printf("%c", DOUBLE_VERTICAL);
	printf(" ");
	printf("%c", DOUBLE_LEFT_UPPER);
	for (counter = 0; counter < largest_length; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", DOUBLE_RIGHT_UPPER);
	printf(" ");
	printf("%c\n", DOUBLE_VERTICAL);
	//Print for title frame
	for (counter = 0; counter < horizontal_padd_size; counter++)//Horizontal Padding for each line
	{
		printf(" ");
	}
	printf("%c", DOUBLE_VERTICAL);
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
	if ((title_len % 2) != (largest_length % 2))
	{
		printf(" ");
	}
	printf("%c", SINGLE_VERTICAL);
	printf(" ");
	printf("%c\n", DOUBLE_VERTICAL);
	//End of title frame
	for (counter = 0; counter < horizontal_padd_size; counter++)//Horizontal Padding for each line
	{
		printf(" ");
	}
	printf("%c", DOUBLE_VERTICAL);
	printf(" ");
	printf("%c", DOUBLE_LEFT_LOWER);
	for (counter = 0; counter < largest_length; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", DOUBLE_RIGHT_LOWER);
	printf(" ");
	printf("%c\n", DOUBLE_VERTICAL);
	//Another blank line
	for (counter = 0; counter < horizontal_padd_size; counter++)//Horizontal Padding for each line
	{
		printf(" ");
	}
	printf("%c", DOUBLE_VERTICAL);
	for (counter = 0; counter < largest_length + 4; counter++)
	{
		printf(" ");
	}
	printf("%c\n", DOUBLE_VERTICAL);
	//Item1 frame start
	for (counter = 0; counter < horizontal_padd_size; counter++)//Horizontal Padding for each line
	{
		printf(" ");
	}
	printf("%c", DOUBLE_VERTICAL);
	printf("%c", SINGLE_LEFT_UPPER);
	for (counter = 0; counter < item1_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", SINGLE_RIGHT_UPPER);
	//start for price 1 frame
	printf("%c", SINGLE_LEFT_UPPER);
	for (counter = 0; counter < price1_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", SINGLE_RIGHT_UPPER);
	if ((item1_len + price1_len) != (largest_length))  //Necessary padding at the end of both the frames to compensate for the diff in string lengths
	{
		for (counter = 0; counter < (largest_length - (item1_len + price1_len)); counter++)
		{
			printf(" ");
		}
	}
	printf("%c\n", DOUBLE_VERTICAL);
	//Printing item1, price1
	for (counter = 0; counter < horizontal_padd_size; counter++)//Horizontal Padding for each line
	{
		printf(" ");
	}
	printf("%c", DOUBLE_VERTICAL);
	printf("%c", SINGLE_VERTICAL);
	printf("%s", menu.item1);
	printf("%c", SINGLE_VERTICAL);
	printf("%c", SINGLE_VERTICAL);
	printf("%s", menu.price1);
	printf("%c", SINGLE_VERTICAL);
	if ((item1_len + price1_len) != (largest_length))  //Necessary padding at the end of both the frames to compensate for the diff in string lengths
	{
		for (counter = 0; counter < (largest_length - (item1_len + price1_len)); counter++)
		{
			printf(" ");
		}
	}
	printf("%c\n", DOUBLE_VERTICAL);
	//Closing the item 1, price1 frames
	for (counter = 0; counter < horizontal_padd_size; counter++)//Horizontal Padding for each line
	{
		printf(" ");
	}
	printf("%c", DOUBLE_VERTICAL);
	printf("%c", SINGLE_LEFT_LOWER);
	for (counter = 0; counter < item1_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", SINGLE_RIGHT_LOWER);
	printf("%c", SINGLE_LEFT_LOWER);
	for (counter = 0; counter < price1_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", SINGLE_RIGHT_LOWER);
	if ((item1_len + price1_len) != (largest_length))  //Necessary padding at the end of both the frames to compensate for the diff in string lengths
	{
		for (counter = 0; counter < (largest_length - (item1_len + price1_len)); counter++)
		{
			printf(" ");
		}
	}
	printf("%c\n", DOUBLE_VERTICAL);

	//Item2 frame start
	for (counter = 0; counter < horizontal_padd_size; counter++)//Horizontal Padding for each line
	{
		printf(" ");
	}
	printf("%c", DOUBLE_VERTICAL);
	printf("%c", SINGLE_LEFT_UPPER);
	for (counter = 0; counter < item2_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", SINGLE_RIGHT_UPPER);
	//start for price 2 frame
	printf("%c", SINGLE_LEFT_UPPER);
	for (counter = 0; counter < price2_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	//starting frames for item2,price2
	printf("%c", SINGLE_RIGHT_UPPER);
	if ((item2_len + price2_len) != (largest_length))  //Necessary padding at the end of both the frames to compensate for the diff in string lengths
	{
		for (counter = 0; counter < (largest_length - (item2_len + price2_len)); counter++)
		{
			printf(" ");
		}
	}
	printf("%c\n", DOUBLE_VERTICAL);
	//Printing item1, price1
	for (counter = 0; counter < horizontal_padd_size; counter++)//Horizontal Padding for each line
	{
		printf(" ");
	}
	printf("%c", DOUBLE_VERTICAL);
	printf("%c", SINGLE_VERTICAL);
	printf("%s", menu.item2);
	printf("%c", SINGLE_VERTICAL);
	printf("%c", SINGLE_VERTICAL);
	printf("%s", menu.price2);
	printf("%c", SINGLE_VERTICAL);
	if ((item2_len + price2_len) != (largest_length))  //Necessary padding at the end of both the frames to compensate for the diff in string lengths
	{
		for (counter = 0; counter < (largest_length - (item2_len + price2_len)); counter++)
		{
			printf(" ");
		}
	}
	printf("%c\n", DOUBLE_VERTICAL);
	//Closing the item 2, price2 frames
	for (counter = 0; counter < horizontal_padd_size; counter++)//Horizontal Padding for each line
	{
		printf(" ");
	}
	printf("%c", DOUBLE_VERTICAL);
	printf("%c", SINGLE_LEFT_LOWER);
	for (counter = 0; counter < item2_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", SINGLE_RIGHT_LOWER);
	printf("%c", SINGLE_LEFT_LOWER);
	for (counter = 0; counter < price2_len; counter++)
	{
		printf("%c", SINGLE_HORIZONTAL);
	}
	printf("%c", SINGLE_RIGHT_LOWER);
	if ((item2_len + price2_len) != (largest_length))  //Necessary padding at the end of both the frames to compensate for the diff in string lengths
	{
		for (counter = 0; counter < (largest_length - (item2_len + price2_len)); counter++)
		{
			printf(" ");
		}
	}
	printf("%c\n", DOUBLE_VERTICAL);
	//Closing the main double frame
	for (counter = 0; counter < horizontal_padd_size; counter++)//Horizontal Padding for each line
	{
		printf(" ");
	}
	printf("%c", DOUBLE_LEFT_LOWER);
	for (counter = 0; counter < largest_length + 4; counter++)
	{
		printf("%c", DOUBLE_HORIZONTAL);
	}
	printf("%c\n", DOUBLE_RIGHT_LOWER);
	//Vertical Padding
	for (counter = 0; counter < 8; counter++)
	{
		printf("\n");
	}
}
