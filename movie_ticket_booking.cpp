
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

typedef struct node
{
	char row_no;
	int seat_no, pin;
	char book;
	struct node *next, *prev;
} node;

class dcll
{
public:
	node *hn;
	dcll()
	{
		hn = NULL;
	}

public:
	void create()
	{
		node *nn, *cn;
		int j = 1;

		char c = 'A';

		do
		{
			int i = 1;
			do
			{
				srand(time(NULL));
				int k = rand() % 9000 + 1000;
				nn = new node();
				nn->next = nn->prev = NULL;
				nn->row_no = c;
				nn->seat_no = i;
				nn->pin = k;
				nn->book = 'a';
				if (hn == NULL)
				{
					hn = nn;
					nn->next = nn->prev = hn;
				}
				else
				{
					cn = hn;

					while (cn->next != hn)
						cn = cn->next;

					cn->next = nn;
					nn->prev = cn;
					nn->next = hn;
					hn->prev = nn;
				}
				i++;
			} while (i <= 7);
			j++;
			c++;
		} while (j <= 10);
	}

	void display()
	{
		node *cn;
		cn = hn;
		cout << "------------------------------------------------------------------\n";
		cout << "|                            Platinum                            |\n";
		while (cn->next != hn)
		{
			if ((cn->prev)->row_no != cn->row_no)
				cout << "| ";
			cout << cn->row_no;
			cout << cn->seat_no;
			if (cn->book == 'a')
				cout << " -> a  ";
			else
				cout << " -> b  ";

			if ((cn->next)->row_no != cn->row_no)
				cout
					<< "|\n";
			if (cn->row_no == 'C' && cn->seat_no == 7)
			{
				cout << "------------------------------------------------------------------\n";
				cout << "|                             gold                               |\n";
			}
			if (cn->row_no == 'H' && cn->seat_no == 7)
			{
				cout << "------------------------------------------------------------------\n";
				cout << "|                            Silver                              |\n";
			}
			cn = cn->next;
		}
		cout << cn->row_no;
		cout << cn->seat_no;
		if (cn->book == 'a')
			cout << " -> a  ";

		else
			cout << " -> b  ";
		cout << "|\n";

		cout << "------------------------------------------------------------------\n\n";
		cout << "PLATINUM-> 150              GOLD-> 100                  SILVER->60\n";
	}

	void display1(node *tmp[20], int n)
	{
		int price = 0;
		if (n != 1)
		{
			cout << "------------------------------------------------------------------\n";
			cout << "THANK YOU!\nYOU HAVE SUCCESFULLY BOOKED THE SEATS\n";
			for (int i = 1; i < n; i++)
			{
				if (tmp[i]->row_no == 'A' || tmp[i]->row_no == 'B' || tmp[i]->row_no == 'C')
					price += 150;
				else if (tmp[i]->row_no == 'D' || tmp[i]->row_no == 'E' || tmp[i]->row_no == 'F' || tmp[i]->row_no == 'G' || tmp[i]->row_no == 'H')
					price += 100;
				else
					price += 60;

				cout << tmp[i]->row_no << tmp[i]->seat_no << "    PIN : " << tmp[i]->pin << "\n";
			}
			printf("Total amount=%d\n", price);

			cout << "!!!!!!!!!!!!!!!!!!KEEP PIN SAFELY!!!!!!!!!!!!!!!!!!!\n";
			cout << "PINS ARE REQUIRED AT THE TIME OF CANCELLATION OF SEATS\n";
			cout << "------------------------------------------------------------------\n";
		}
	}
	void book_seat()
	{
		node *cn, *temp[20];
		int n, z;
		char row;
		int seat;
		char ch;
		do
		{
			z = 1;
			cout << "\nEnter No Of Tickets u Want To Buy: ";
			cin >> n;

			cout << "\nEnter Seat Number(s): \n";

			for (int i = 1; i <= n; i++)
			{
				cout << "NO " << i << " = ";
				cin >> row >> seat;
				cn = hn;
				if (row >= 'A' && row <= 'E')
				{
					while (cn->next != hn)
					{
						if (cn->row_no == row && cn->seat_no == seat)
						{
							if (cn->book == 'a')
							{
								cn->book = 'b';
								temp[z] = cn;
								z++;
							}
							else
							{
								cout << "INVALID CHOICE!\n";
								cout << cn->row_no << cn->seat_no << " Seat is already reserved \n";
							}
						}
						cn = cn->next;
					}
					if (cn->row_no == row && cn->seat_no == seat)
					{
						if (cn->book == 'a')
						{
							cn->book = 'b';
							temp[z] = cn;
							z++;
						}
						else
						{
							cout << "INVALID CHOICE!\n";
							cout << cn->row_no << cn->seat_no << " Seat is already reserved\n";
						}
					}
				}
				else //
				{
					while (cn->prev != hn)
					{
						if (cn->row_no == row && cn->seat_no == seat)
						{
							if (cn->book == 'a')
							{
								cn->book = 'b';
								temp[z] = cn;
								z++;
							}
							else
							{
								cout << "INVALID CHOICE!\n";
								cout << cn->row_no << cn->seat_no << " Seat is already reserved \n";
							}
						}
						cn = cn->prev;
					}
					if (cn->row_no == row && cn->seat_no == seat)
					{
						if (cn->book == 'a')
						{
							cn->book = 'b';
							temp[z] = cn;
							z++;
						}
						else
						{
							cout << "INVALID CHOICE!\n";
							cout << cn->row_no << cn->seat_no << " Seat is already reserved\n";
						}
					}
				}
			}

			display1(temp, z);
			cout << "\n\nPRESS 1 To check Seat Status\n";
			cout << "PRESS 2 To book other seat\n";
			cout << "PRESS 3 To Exit BOOKING PORTAL\n";
			cout << "\ninput: ";
			cin >> ch;
			if (ch == 1)
				display();
		} while (ch == '2');
	}

	void cancle()
	{
		char row, ch;
		int seat, pin;
		node *cn;
		cout << "SEAT CANCELLATION\n";
		do
		{
			ch = 'a';
			cn = hn;
			cout << "SEAT NUMBER :";
			cin >> row >> seat;
			cout << "PIN :";
			cin >> pin;
			if (row >= 'A' && row <= 'E')
			{
				while (cn->next != hn)
				{
					if (cn->row_no == row && cn->seat_no == seat && cn->pin == pin)
					{
						cout << "Are you sure u want to cancel the Seat (y/n) ";
						char c;
						cin >> c;
						if (c == 'y' || c == 'Y')
						{
							cout << "SEAT CANCELLED SUCCESFULLY!\n";
							cn->book = 'a';
						}
					}
					else if (cn->row_no == row && cn->seat_no == seat && cn->pin != pin)
					{
						cout << "invalid SEAT NUMBER && PIN combination!!!!\n";
					}
					cn = cn->next;
				}
				if (cn->row_no == row && cn->seat_no == seat && cn->pin == pin)
				{
					cout << "Are you sure u want to cancel (y/n) ";
					char c;
					cin >> c;
					if (c == 'y' || c == 'Y')
					{
						cout << "SEAT CANCELLED SUCCESFULLY!\n";
						cn->book = 'a';
					}
				}
				else if (cn->row_no == row && cn->seat_no == seat && cn->pin != pin)
				{
					cout << "invalid SEAT NUMBER && PIN combination!!!!\n";
				}
			}
			else
			{
				while (cn->next != hn)
				{
					if (cn->row_no == row && cn->seat_no == seat && cn->pin == pin)
					{
						cout << "Are you sure u want to cancel the Seat (y/n) ";
						char c;
						cin >> c;
						if (c == 'y' || c == 'Y')
						{
							cout << "SEAT CANCELLED SUCCESFULLY!\n";
							cn->book = 'a';
						}
					}
					else if (cn->row_no == row && cn->seat_no == seat && cn->pin != pin)
					{
						cout << "invalid SEAT NUMBER && PIN combination!!!!\n";
					}
					cn = cn->next;
				}
				if (cn->row_no == row && cn->seat_no == seat && cn->pin == pin)
				{
					cout << "Are you sure u want to cancel (y/n) ";
					char c;
					cin >> c;
					if (c == 'y' || c == 'Y')
					{
						cout << "SEAT CANCELLED SUCCESFULLY!\n";
						cn->book = 'a';
					}
				}
				else if (cn->row_no == row && cn->seat_no == seat && cn->pin != pin)
				{
					cout << "invalid SEAT NUMBER && PIN combination!!!!\n";
				}
			}
			cout << "\n\nPRESS 1 To Check Seat Status\n";
			cout << "PRESS 2 To Cancel More Tickets\n";
			cout << "PRESS 3 To Exit CANCELLATION PORTAL\n";
			cout << "\ninput: ";
			cin >> ch;
			if (ch == 1)
				display();
		} while (ch == '2');
	}
};
struct movie
{
	int movie_code;
	char movie_name[20];
	char release_date[20];
	struct movie *prev;
	struct movie *next;
} *first = NULL, *last = NULL, *temp = NULL;
void create_movienode()
{

	temp = (struct movie *)malloc(sizeof(struct movie));
	printf("Enter movie code,movie name and release date\n");
	scanf("%d%s%s", &temp->movie_code, temp->movie_name, temp->release_date);
	temp->prev = NULL;
	temp->next = NULL;
}

void insert_details()
{
	create_movienode();
	FILE *fp;
	fp = fopen("G:\\data.txt", "a");

	if (first == NULL)
	{

		first = temp;
		last = first;
	}
	else
	{
		first->prev = temp;
		temp->next = first;
		first = temp;
	}
	if (fp == NULL)
	{
		printf("File not found\n");
		exit(1);
	}
	else
	{
		fprintf(fp, "%d%s%s\n", temp->movie_code, temp->movie_name, temp->release_date);
		printf("Record inserted successfully\n");
	}

	fclose(fp);
}
void view_movies()
{
	char ch;
	FILE *fp;
	fp = fopen("G:\\data.txt", "r");
	if (fp == NULL)
	{
		printf("File not found\n");
		exit(1);
	}
	else
	{
		system("cls");
		while ((ch = fgetc(fp)) != EOF)
			printf("%c", ch);
	}
	fclose(fp);
}

int main()
{
	int ch, n;
	do
	{
		printf("\n====================================================================");
		printf("\n");
		printf("\t Movie Ticket booking ");
		printf("\n");
		printf("\n====================================================================");

		printf("\nPress <1> Insert Movie");
		printf("\nPress <2> View All Movie");

		printf("\nPress <3> Book Ticket");

		printf("\nPress <0> Exit ");

		printf("\nEnter your Choice ::");
		scanf("%d", &ch);
		dcll o;
		switch (ch)
		{
		case 1:

			printf("How many movies do you want to enter?\n");
			scanf("%d", &n);
			for (int i = 0; i < n; i++)
				insert_details();
			break;
		case 2:
			view_movies();
			break;
		case 3:
			char c;
			cout << "\n\n\n";
			cout << "                 @@@@@@   Cinemax  @@@@@@\n";
			cout << "                vvvvvv ARRANGEMENT vvvvvv\n\n";
			o.create();
			o.display();
			do
			{
				cout << "\n\n\n";
				cout << "PRESS 1-> BOOK TICKETS\n";
				cout << "PRESS 2-> CANCEL TICKETS\n";
				cout << "PRESS 3-> EXIT\n";
				cout << "\ninput: ";
				cin >> ch;
				switch (ch)
				{
				case 1:
					o.book_seat();
					o.display();
					break;
				case 2:
					o.cancle();
					o.display();
					break;
				}
				if (ch != 3)
				{
					cout << "\n\nPRESS 1 To Main Menu\n";
					cout << "PRESS 2 To Exit CINEMAX PORTAL\n";
					cout << "\ninput: ";
					cin >> c;
				}
			} while (c == '1');
			break;
		case 0:
			exit(1);

		default:
			printf("Invalid choice");
		}

	} while (ch != 0);
	cout << "\n\n\n";
	return 0;
}