#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>

struct student{
	char name[50];
    char dept[50];
    char roll[10];
    int route;
    int amount;
    int balance;
    char phone[20];
    char service[50];
    char passw[50];
	char email[50];
}std;
//structure for student

void menu();//fucntion to display menu
void std_menu(FILE *fp);//function to display student menu
void logout();//function to logout
void modify(FILE *fp);//fcuntion to modify student details
void regist(FILE * fp);//Function to register a student
void balance(FILE *fp);//Fucntion to pay remaining balance
void complain_box(FILE * fp);//Fucntion to open complain box 
void vcomp(FILE *fp);//fucntion to view complain resposnses
void notice(FILE * fp);//Fucntion to open notice board
void route(FILE *fp,char filename[]);//fucntion to open file consisting route Informations
void route_details(FILE *fp);//function to give route details selected by student
void displayinfo(FILE * fp);//fucntion to display all students
void search(FILE * fp);//fucntion to search a specific student
void login(FILE * fp);//fucntion for student login
void login_admin();//function for admin login
void admin_menu(FILE *fp);//fucntion to display admin menu
void view_complain(FILE *fp);//fucntion to view complains by admin
void wnotice(FILE *fp);//fucntion to write notice
void password(FILE *fp2);//fucntion to verify password
void remove_stds(FILE * fp);//function to delete students
void req_stop(FILE *fp);//fucntion to request a stop
int checkID(FILE *fp,char checkid[]);//function to check if an ID exists
void gotoxy(int,int);//function to shift the cursor position on Console
void fees();//function to view fees summary
void feesmng();//fucntion to pay fees at time of registration
void Jseatmng();//fucntion to allot seast in jadoon service
void Sseatmng();//fcuntion to allot seats in swvl service


int main(void){
	menu();
	return 0;
}

void menu(){
	SetConsoleTitle("FAST NU Point Management System");
    FILE * fp;
    int opt;
    system("color 9F");
    gotoxy(0,0);
    printf("________________________________________________________________________________________________________________________________________________________________________");
    printf("\n\n\t\t\t\t\t\t\t\t WELCOME TO FAST NU POINT MANAGEMENT SYSTEM.");
    printf("\n\n\n\n\t\t\t\t\t\t\t\t   CHOOSE ANY OF THE THREE OPTIONS!!\n\n");
    	printf("\n\t\t\t\t\t\t\t\t       ************************");
    	printf("\n\t\t\t\t\t\t\t\t       *                      *");
		printf("\n\t\t\t\t\t\t\t\t       *     1-Register       *");
		printf("\n\t\t\t\t\t\t\t\t       *                      *");
		printf("\n\t\t\t\t\t\t\t\t       *     2-Student Login  *");
		printf("\n\t\t\t\t\t\t\t\t       *                      *");
		printf("\n\t\t\t\t\t\t\t\t       *     3- Admin Login   *");
		printf("\n\t\t\t\t\t\t\t\t       *                      *");
		printf("\n\t\t\t\t\t\t\t\t       *                      *");
		printf("\n\t\t\t\t\t\t\t\t       ************************");
   gotoxy(0,25);
   printf("________________________________________________________________________________________________________________________________________________________________________");
   do{
   printf("\n\n\t\t\t\t\t\t\tEnter your choice: ");
   scanf("%d",&opt);
	
	switch(opt){
		case 1:
			printf("\n\n\t\t\t\t\t\t\tLoading please wait.......");
			sleep(1);
			system("cls");
			regist(fp);
			break;
		case 2:
			printf("\n\n\t\t\t\t\t\t\tLoading please wait.......");
			sleep(1);
			system("cls");
			login(fp);
			std_menu(fp);
			break;
		case 3:
			printf("\n\n\t\t\t\t\t\t\tLoading please wait.......");
			sleep(1);
			system("cls");
			login_admin();
			break;
		default:
			printf("Wrong input!");
		}
	}while(opt != 1 || opt != 2 || opt !=3);
}

void regist(FILE * fp){
    int flag = 0;
    char roll[50];
    char checkid[10];
    FILE *f2;
    int choice;
    fp = fopen("register.txt","a+");
	if(fp==NULL){
		printf("Error Opening Files!");
	}
	else{		
		do{
			printf("\n\t\tEnter Roll number e.g(22K4212)('K' in Capitals): ");
	        fflush(stdin);
	        gets(checkid);
	        if(checkID(fp,checkid)==1){
	        printf("\n\t\t\tID already exists. Please enter a new ID\n");
	        flag = 1;
	    	}
	        else{
			strcpy(std.roll,checkid);
			flag = 0;
			}
	    }while(flag == 1);
	    
        printf("\n\t\tEnter Full Name of Student: ");
        fflush(stdin);
        gets(std.name);

        printf("\n\t\tEnter Department Name: ");
        fflush(stdin);
        gets(std.dept);
        
        do{
		printf("\n\t\tEnter your Phone Number(w/out hyphen): ");
		fflush(stdin);
		gets(std.phone);
		if(strlen(std.phone)>11 || strlen(std.phone)<11 ){
			printf("\t\t\t\t Enter Number again");
			}
		}while(strlen(std.phone) != 11);
		
        system("CLS");
        printf("\t\t\t\t\t Fetching Jadoon details....");
        sleep(1);
        route(f2,"jadoon.txt");
        puts("\n====================================================================================================================================================================\n");
		printf("\t\t\t\t\t Fetching Swvl details....");
		sleep(1);
      	route(f2,"Swvl.txt");
    do{
        printf("\n\n\n\n\t\tSelect your Desired Service Provider from the two options(PRESS <1> Jadoon or <2> Swvl):");
      	scanf("%d",&choice);
      	switch(choice){
      	case 1:
      		strcpy(std.service,"Jadoon");
      		Jseatmng();
      		break;
      	case 2:
      		strcpy(std.service,"Swvl");
      		Sseatmng();
      		break;
        default:
      		printf("\t\t\tWrong Choice. Please Enter Again");
	  	}
	}while( choice != 1 && choice !=2);
	
		printf("\n\t\tYour email is: \n");
		strcpy(roll,std.roll);
		strcat(roll,"@123nu.edu.pk");//to add "salt" in email for security
		strcpy(std.email,roll);
		printf("\t\t\t\t%s\n",std.email);
		
		printf("\t\t\t\tUSE THIS FOR LOGIN\n\n");
		printf("\n\t\t\t\tPassword must have at least one:\n\t\t\t\t-Uppercase letter\n\t\t\t\t-Lowercase letter\n\t\t\t\t-Special character(!,@,#,$,%,*)\n\t\t\t\t-Number(0-9)\n");
		printf("\n\t\t\t\tEnter Password: ");
		fflush(stdin);
		gets(std.passw);
		password(fp);
		
		fwrite(&std,sizeof(struct student),1,fp);
    	}
    fclose(fp);
    printf("\n\t\t\t\t\tPress Enter To return to main menu!\n\n");
    getch();
    system("cls");
	menu();
	}	
	
void password(FILE *fp){
        int num=0,spec=0,uppercase=0,small=0,count= 0;
		int j;		
        for(j=0;std.passw[j]!='\0';j++){
            if(std.passw[j]>='0' && std.passw[j]<='9')
              		num++;
            if(std.passw[j]>='a' && std.passw[j]<='z')
            		small++;
            if(std.passw[j]>='A' && std.passw[j]<='Z')
            		uppercase++;
            if(std.passw[j]=='!' || std.passw[j]=='@' || std.passw[j]=='#' || std.passw[j]=='$' || std.passw[j]=='%' || std.passw[j]=='*')
            		spec++;
//            if(j>=13)
//            	count++;		
        	}
        if(num<1 || spec<1 || uppercase<1 || small<1){ //count<1
        	printf("\n\t\t\tInvalid Password!\n\n");
        	Beep(500,300);
        	printf("\t\t\t\tEnter password again: ");
        	fflush(stdin);
        	gets(std.passw);
			password(fp);
		}
        else{
        printf("\n\t\t\t\t\tRegistered Successfully\n\n");   
		}
	}
		
void gotoxy(int x,int y){
	COORD cord;
	cord.X = x;
	cord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cord);
}


void remove_stds(FILE *fp){
FILE *f2;
char roll_num[50];
int found=0;
printf("\t\t\t\t-------------------------------------DELETE RECORD-----------------------------------\n\n\n");
    fp=fopen("register.txt","r");
    f2=fopen("temp.txt","w");
    printf("\t\t\t\tEnter the roll no : ");
    fflush(stdin);
    gets(roll_num);
    if(fp==NULL){
        printf("Error oprning file!\n");
        exit(0);
      }

    while(fread(&std,sizeof(struct student),1,fp)){
        if(strcmp(std.roll,roll_num)==0){

            found=1;
		}
		else{
           fwrite(&std,sizeof(struct student),1,f2);
    	}
    }
    fclose(fp);
    fclose(f2);

    if(found == 0){
          printf("\n\t\t\t\tRecord not found\n");
        }    
    if(found == 1){
    remove("register.txt");
    rename("temp.txt","register.txt");
	printf("\n\t\t\t\tRecord deleted succesfully\n");
	}
	printf("\t\t\t\t\tPress Enter to return to admin menu :)");
	getch();
	system("cls");
	admin_menu(fp);
}


void login_admin(){
	FILE *fp;
    char user[50];
    char user_pass[50];
 	char option;
    int i, j,success = 0;

    printf("\n\n\t\t\t\t\t\t\t-------------------ADMIN ACCOUNT LOGIN------------------------- ");
    printf("\n***********************************************************************************************************************************************************************");
    gotoxy(35, 10);
    printf("\n\t\t\t\t\t\t\t\t\tEnter Username:");
    fflush(stdin);
    gets(user);
    static int count = 0;
    
    printf("\n\t\t\t\t\t\t\t\t\tEnter Password:");
    fflush(stdin);
    gets(user_pass);
    	while (1){
        if (strcmp("admin",user)==0 && strcmp("admin123",user_pass)==0){//preexisting password and username for admin
				success = 1;
				break;
				}
		else{
			break;
				}
        	}
        	if(success == 1){
        		printf("\n\t\t\t\t\t\t\t\t\t*Login successful!*");
        		admin_menu(fp);
			}
			else{
				printf("\n\t\t\t\t--------------------------------------------------------------------------------------------------");
				printf("\n\n\n\t\t\t\t\t\t\t\t\t  *Try Logging in again!*\n");
				for(i=0;i<3;i++){
					Beep(1500,400);
					}
				printf("\n\t\t\t\t\t\t\t\t   Please fetch correct login details!\n");
				printf("\n\t\t\t\t\t\t\t\t\t Press Enter to try again!");
				getch();
				system("cls");
				count++;
				if(count >= 4){
					system("cls");
					printf("You have reached the maximum number of tries Please Try again after restarting the software!");
					exit(0);
				}
				login_admin();
			}
		}

void login(FILE *fp){
    char u_email[50];
    char u_pass[50];
 	char option;
    int i=0,success = 0;
	char ch;
    
    fp = fopen("register.txt","r");
 
    if (fp == NULL){
    	puts(" ");
        printf("---------------------------------FILE NOT CREATED YET! PLEASE REGISTER FIRST!--------------------------------");
        exit(0);
    }
    else{
    printf("\n\n\t\t\t\t\t\t\t---------------------ACCOUNT LOGIN------------------------- ");
    printf("\n***********************************************************************************************************************************************************************");
	gotoxy(35, 10);
    printf("\n\t\t\t\t\t\t\t\t\tEnter Email:");
    fflush(stdin);
    gets(u_email);
    static int count = 0;
    
    printf("\n\t\t\t\t\t\t\t\t\tEnter Password:");
    fflush(stdin);
	gets(u_pass);
//    while (1){
//    	ch = getch();
//    	if(i > 13){
//    		u_pass[i]='\0';
//    		break;
//		}
//		else{
//			u_pass[i]=ch;
//			i++;
//			printf("*");
//		}
//	}//code to write password in "*" form but its problem was that it was taking backspace as a character as well which is not user friendly and the user cannot see what he wrote as well so we resorted to taking in string
	while (fread(&std, sizeof( struct student),1,fp)==1){
        if (strcmp(std.email,u_email)==0 && strcmp(std.passw,u_pass)==0){
				success = 1;
				break;
				}
        	}
        	if(success == 1){
        		printf("\n\t\t\t\t\t\t\t\t\t*Login successful!*");
        		fclose(fp);
        		std_menu(fp);
			}
			else{
				printf("\n\t\t\t\t--------------------------------------------------------------------------------------------------");
				printf("\n\n\n\t\t\t\t\t\t\t\t\t  *Try Logging in again!*\n");
				for(i=0;i<3;i++){
					Beep(2000,800);
					}
				printf("\n\t\t\t\t\t\t\t\t   Please fetch correct login details!\n");
				printf("\n\t\t\t\t\t\t\t     IF NOT REGISTERED THEN PLEASE REGISTER FIRST!\n");
				printf("\n\t\t\t\t\t\t\t\t\t Press Enter to try again!");
				getch();
				system("cls");
				count++;
				if(count >= 4){
					system("cls");
					printf("You have reached the maximum number of tries Please Try again after restarting the software!");
					exit(0);
				}
				login(fp);
				fclose(fp);
			}
		}
	}


void logout(){
	printf("\n\n\t\t\t\t\t\t\t Logging out......");
	sleep(1);
	printf("Logged Out! Thankyou for using our service :) ");
	Beep(850,400);
	usleep(200000000);
	system("cls");
	menu();
}

void complain_box(FILE *fp){
	char *comp;
	comp = (char*)calloc(1000,sizeof(char));
	char c;
	if(comp==NULL){
		printf("An unexpected error has occured!");
	}
	else{
	fp = fopen("complain.txt","w");
	if(fp == NULL){
		printf("\n\t\t\t\t\t\t\tError Opening Complain Box!");
		fclose(fp);
		exit(0);
	}
	else{
				system("cls");
				gotoxy(0,5);
				printf("------------------------------------");
				printf("---------------------------------------");
				gotoxy(75,5);
				printf("Complain");
				gotoxy(85,5);
				printf("Box");
				printf("--------------------------------------------------------------------------------\n");	
        printf("\n\n\n");
		printf("\n\t\t\t\t\t\t\t NOTE:MENTION YOUR ID AND FULL NAME BEFORE WRITING THE COMPLAIN! \n\n\n ");
		printf("\n\t\t\t\t\t\t\t Please write your message(Press Enter to submit the message):\n\n\n ");
		fflush(stdin);
		gets(comp);
		fprintf(fp,"%s",comp);
		printf("\n\n\n\t\t\t\t\tYour complain has been submitted!");
		fclose(fp);
		usleep(2000000);
		printf("Our admin will contact you soon! Thankyou for using our service :)\n\n");
		printf("\n\n\n\t\t\t\t\tPress Enter to return to Student Menu!");
		getch();
		system("cls");
		std_menu(fp);
		}
	}
}


void std_menu(FILE *fp){
int choice;
	system("cls");
				gotoxy(0,5);
				printf("------------------------------------");
				printf("------------------------------------");
				gotoxy(72,5);
				sleep(1);
				printf("Welcome");
				sleep(1);
				printf(" %s",std.name);
				sleep(1);
				printf("--------------------------------------------------------------------------\n");
				printf("\t\t\t\t\t\t\t\t\t\t\t\t-----------------Information Card------------------");
				printf("\n\t\t\t\t Press 1.View Fees Summary  \t\t\t\t\t\tRoll NO       : %s",std.roll);
				printf("\n\t\t\t\t Press 2.Request a stop \t\t\t\t\t\tStudent Name  : %s",std.name);
				printf("\n\t\t\t\t Press 3.Complain Box \t\t\t\t\t\t\tEmail Address : %s",std.email);
				printf("\n\t\t\t\t Press 4.Pay Balance\t\t\t\t\t\t\tPhone number  : %s",std.phone);
				printf("\n\t\t\t\t Press 5.Route Detail \t\t\t\t\t\t\tDepartment    : %s",std.dept);
				printf("\n\t\t\t\t Press 6.Noticeboard \t\t\t\t\t\t\tService       : %s",std.service);
				printf("\n\t\t\t\t Press 7.View Complain Responses\t\t\t\t\tRoute #       : %d",std.route);
				printf("\n\t\t\t\t Press 8.Logout");
				do{
				printf("\n\n\t\t\t\t Enter Your Desired Choice: ");
				scanf("%d",&choice);
				switch(choice){
					case 1:
						system("cls");
						fees();
						break;
					case 2:
						system("cls");
						req_stop(fp);
						break;
					case 3:
						complain_box(fp);
						break;
					case 4:
						system("cls");
						balance(fp);
						break;
					case 5:
						system("cls");
						route_details(fp);
						break;
					case 6:
						notice(fp);
						break;
					case 7:
						system("cls");
						vcomp(fp);
						break;
					case 8:
						logout();
						break;
					default:
						printf("Wrong Input!");
						Beep(850,400);
						printf("Enter again!");
						}
					}while(choice < 0 || choice > 8);
				}
void notice(FILE *fp){
	char c;
	fp = fopen("Notice.txt","r");
	if (fp == NULL){
		printf("Error opening file!");
	}
	else{
	system("cls");
	printf("\n\t\t\t\t\t\t\t------------------NOTICE BOARD-----------------------\n\n");
	 c = getc(fp);
        while (c != EOF)
        {
          printf("%c", c);
          c = getc(fp);
        }	
	}
	fclose(fp);
	printf("\n\t\t\t\t\t\t\t Press Enter to return to main menu!");
	getch();
	system("cls");
	std_menu(fp);
}

void search(FILE *fp){
	struct student std;
    char roll_no[50];
	int found=0;

    fp=fopen("register.txt","r");
    printf("\n\n\t\t\t\t--------------------SEARCH A STUDENT-----------------------");
    printf("\n\t\t\t\tEnter the roll no : ");
    fflush(stdin);
    gets(roll_no);

    while(fread(&std,sizeof(struct student),1,fp)==1){

        if(strcmp(std.roll,roll_no)==0){
        found=1;
        printf("\n\t\t\t\t Roll NO       			: %s",std.roll);
        printf("\n\t\t\t\t Student Name  			: %s",std.name);
        printf("\n\t\t\t\t Email Address 			: %s",std.email);
    	printf("\n\t\t\t\t Phone number  			: %s",std.phone);
		printf("\n\t\t\t\t Department    			: %s",std.dept);
		printf("\n\t\t\t\t Service       			: %s",std.service);
		printf("\n\t\t\t\t Route #       		        : %d",std.route);
	    printf("\n\t\t\t\t Amount Paid         		: %d",std.amount);
	    std.balance=30000-std.amount;
	    printf("\n\t\t\t\t Remaining Balance              : %d",std.balance);
        }
	}

    if(found == 0){
       printf("\n\t\t\tRecord not found\n");
    }

    fclose(fp);
	printf("\n\t\t\t\t Press Enter to return to Admin Menu!");
	getch();
	system("cls");
	admin_menu(fp);
}

void displayinfo(FILE *fp){
	system("cls");
	fp = fopen("register.txt","r");
	while(fread(&std,sizeof(struct student),1,fp)==1){
	printf("\n\t\t\t\t\t\t\t\t Roll NO       		: %s",std.roll);
    printf("\n\t\t\t\t\t\t\t\t Student Name  		: %s",std.name);
    printf("\n\t\t\t\t\t\t\t\t Email Address 		: %s",std.email);
    printf("\n\t\t\t\t\t\t\t\t Phone number  		: %s",std.phone);
	printf("\n\t\t\t\t\t\t\t\t Department    		: %s",std.dept);
	printf("\n\t\t\t\t\t\t\t\t Service       		: %s",std.service);
	printf("\n\t\t\t\t\t\t\t\t Route #       		: %d",std.route);
	printf("\n\t\t\t\t\t\t\t\t Amount Paid       	: %d",std.amount);
	std.balance=30000-std.amount;
	printf("\n\t\t\t\t\t\t\t\t Remaining Balance      : %d",std.balance);
	printf("\n\t\t\t\t\t\t-----------------------------------------------------------------\n\n");
	}
	fclose(fp);
	printf("\n\n\n\n\nPRESS ENTER TO RETURN TO ADMIN MENU :) ");
	getch();
	admin_menu(fp);
}



void route(FILE *fp,char filename[]){
	char c;
	printf("\n\t\t\t\t\t\t\t\t---------------Route Detail----------------\n");
	fp = fopen(filename,"r");
	c = getc(fp);
        while (c != EOF){
          printf("%c", c);
          c = getc(fp);
        }
    fclose(fp);
}

void Jseatmng(){
FILE *jp = NULL;
int seats;
char cha;

int i;
		jp = fopen("JadoonSeats.txt","r+");
		printf("\n\n\t\t\t Enter your desired Choice: ");
      	scanf("%d",&std.route);
		switch(std.route){
			case 1: 
			fscanf(jp,"%d",&seats);
			printf("\t\t\t\t The number of seats availaible are: %d",seats);
			rewind(jp);
			if(seats == 0){
			printf("\n\t\t\t\t Sorry! No seats Availaible on this Route.");
			printf("\n\t\t\t\t Continue Logging in and then file a complaint through the complain box!");
			}
			else {
			feesmng();
			seats--;
			printf("\t\t\t\t CONGRATULATIONS!! You have booked a seat for Jadoon Route %d\n",std.route);
			fprintf(jp,"%d",seats);
			}
			break;
			case 2:
			fseek(jp,3,SEEK_SET);
			fscanf(jp,"%d",&seats);
			printf("\t\t\t\t The number of seats availaible are: %d",seats);
			if(seats == 0){
			printf("\n\t\t\t\t Sorry! No seats Availaible on this Route.");
			printf("\n\t\t\t\t Continue Logging in and then file a complaint through the complain box!");
			}
			else {
			feesmng();
			seats--;
			printf("\t\t\t\t CONGRATULATIONS!! You have booked a seat for Jadoon Route %d\n",std.route);
			fseek(jp,3,SEEK_SET);
			fprintf(jp,"%d",seats);
			}
			break;
			
			case 3:
			fseek(jp,6,SEEK_SET);
			fscanf(jp,"%d",&seats);
			printf("\t\t\t\t The number of seats availaible are: %d",seats);
			if(seats == 0){
			printf("\n\t\t\t\t Sorry! No seats Availaible on this Route.");
				printf("\n\t\t\t\t Continue Logging in and then file a complaint through the complain box!");
			}
			else {
			feesmng();
			seats--;
			printf("\t\t\t\t CONGRATULATIONS!! You have booked a seat for Jadoon Route %d\n",std.route);
			fseek(jp,6,SEEK_SET);
			fprintf(jp,"%d",seats);
			}
			break;
			
			case 4:
			fseek(jp,9,SEEK_SET);
			fscanf(jp,"%d",&seats);
			printf("\t\t\t\t The number of seats availaible are: %d",seats);
			if(seats == 0){
			printf("\n\t\t\t\t Sorry! No seats Availaible on this Route.");
			printf("\n\t\t\t\t Continue Logging in and then file a complaint through the complain box!");
			}
			else {
			feesmng();
			seats--;
			printf("\t\t\t\t CONGRATULATIONS!! You have booked a seat for Jadoon Route %d\n",std.route);
			fseek(jp,9,SEEK_SET);
			fprintf(jp,"%d",seats);
			}
			break;
			
			case 5:
			fseek(jp,12,SEEK_SET);
			fscanf(jp,"%d",&seats);
			printf("\t\t\t\t The number of seats availaible are: %d",seats);
			if(seats == 0){
			printf("\n\t\t\t\t Sorry! No seats Availaible on this Route.");
			printf("\n\t\t\t\t Continue Logging in and then file a complaint through the complain box!");
			}
			else {
			feesmng();
			seats--;
			printf("\t\t\t\t CONGRATULATIONS!! You have booked a seat for Jadoon Route %d\n",std.route);
			fseek(jp,12,SEEK_SET);
			fprintf(jp,"%d",seats);
			}
			break;
			default:
			printf("\n\n\n The route you are trying to select is a swvl route! ");
			printf("Would you like to Select a Swvl route?(Y/N)");
			scanf(" %c",&cha);
			if(cha == 'Y' ||cha == 'y'){
				Sseatmng();
			}
			else{
				Jseatmng();
			}
		}
		fclose(jp);
	}


void Sseatmng(){
FILE *sp = NULL;
int seats;
char ch;
sp = fopen("SWVLSeats.txt","r+");

int i;
		printf("\n\n\t\t\t Enter your desired Choice: ");
      	scanf("%d",&std.route);
		sp = fopen("SWVLSeats.txt","r+");
		switch(std.route){
			case 6: 
			fscanf(sp,"%d",&seats);
			printf("\t\t\t\t The number of seats availaible are: %d",seats);
			rewind(sp);
			if(seats == 0){
			printf("\n\t\t\t\t Sorry! No seats Availaible on this Route.");
			printf("\n\t\t\t\t Continue Logging in and then file a complaint through the complain box!");
			}
			else {
			feesmng();
			seats--;
			printf("\t\t\t\t CONGRATULATIONS!! You have booked a seat for SWVL Route %d\n",std.route);
			fprintf(sp,"%d",seats);
			}
			break;
			case 7:
			fseek(sp,3,SEEK_SET);
			fscanf(sp,"%d",&seats);
			printf("\t\t\t\t The number of seats availaible are: %d",seats);
			if(seats == 0){
			printf("\n\t\t\t\t Sorry! No seats Availaible on this Route.");
			printf("\n\t\t\t\t Continue Logging in and then file a complaint through the complain box!");
			}
			else {
			feesmng();
			seats--;
			printf("\t\t\t\t CONGRATULATIONS!! You have booked a seat for SWVL Route %d\n",std.route);
			fseek(sp,3,SEEK_SET);
			fprintf(sp,"%d",seats);
			}
			break;
			
			case 8:
			fseek(sp,6,SEEK_SET);
			fscanf(sp,"%d",&seats);
			printf("\t\t\t\t The number of seats availaible are: %d\n",seats);
			if(seats == 0){
			printf("\n\t\t\t\t Sorry! No seats Availaible on this Route.");
			printf("\n\t\t\t\t Continue Logging in and then file a complaint through the complain box!");
			}			
			else {
			feesmng();
			seats--;
			printf("\t\t\t\t CONGRATULATIONS!! You have booked a seat for SWVL Route %d\n",std.route);
			fseek(sp,6,SEEK_SET);
			fprintf(sp,"%d",seats);
			}
			break;
			
			case 9:
			fseek(sp,9,SEEK_SET);
			fscanf(sp,"%d",&seats);
			printf("The number of seats availaible are: %d",seats);
			if(seats == 0){
			printf("\n\t\t\t\t Sorry! No seats Availaible on this Route.");
			printf("\n\t\t\t\t Continue Logging in and then file a complaint through the complain box!");
			}
			else {
			feesmng();
			seats--;
			printf("\t\t\t\t CONGRATULATIONS!! You have booked a seat for SWVL Route %d\n",std.route);
			fseek(sp,9,SEEK_SET);
			fprintf(sp,"%d",seats);
			}
			break;
			
			case 10:
			fseek(sp,12,SEEK_SET);
			fscanf(sp,"%d",&seats);
			printf("\t\t\t\t The number of seats availaible are: %d",seats);
			if(seats == 0){
			printf("\n\t\t\t\t Sorry! No seats Availaible on this Route.");
			printf("\n\t\t\t\t Continue Logging in and then file a complaint through the complain box!");
			}
			else {
			feesmng();	
			seats--;
			printf("\t\t\t\t CONGRATULATIONS!! You have booked a seat for SWVL Route %d\n",std.route);
			fseek(sp,12,SEEK_SET);
			fprintf(sp,"%d",seats);
			}
			break;
		    default:
			printf("\n\n\n The route you are trying to select is a Jadoon route! ");
			printf("Would you like to Select a Jadoon route?(Y/N): ");
			scanf(" %c",&ch);
			if(ch == 'Y' ||ch == 'y'){
				Jseatmng();
			}
			else{
				Sseatmng();
			}
		}
		fclose(sp);
	}

void feesmng(){
		printf("\n\t\tYour Transport Fees is Rs30,000. The Minimum Amount payable is 15,000\n");
		do{
      	printf("\t\tEnter Amount to Pay: ");
      	scanf("%d",&std.amount);
      	if(std.amount<15000 || std.amount>30000){
      		printf("\n\t\t\t\tEnter Amount in limit please!\n");
		  }
      	}while(std.amount<15000 || std.amount>30000);
	std.balance = 30000-std.amount;
}

void fees(){
	FILE *fp;
	printf("\n\n\n\n\n\t\t\t\t\t\t\t---------------------------Fees detail--------------------------------\n\n");
	printf("\t\t\t      Amount Paid :  %d",std.amount);
	std.balance = 30000-std.amount;
    printf("\t\tBalance Remaining :  %d",std.balance);
    printf("\t\t\t\t\t Press enter to return to student menu");
    getch();
    std_menu(fp);
}


void admin_menu(FILE *fp){
	int choice;
	system("cls");
				gotoxy(0,5);
				printf("------------------------------------");
				printf("------------------------------------");
				gotoxy(72,5);
				sleep(1);
				printf("Welcome");
				sleep(1);
				printf(" Admin");
				sleep(1);
				printf("------------------------------------------------------------------------------------\n");
				printf("\n\t\t\t\t Press 1.Display all Students");
				printf("\n\t\t\t\t Press 2.Quick Search");
				printf("\n\t\t\t\t Press 3.Notice board");
				printf("\n\t\t\t\t Press 4.Complain Box");
				printf("\n\t\t\t\t Press 5.Remove Students");
				printf("\n\t\t\t\t Press 6.Modify Student Details");
				printf("\n\t\t\t\t Press 7.Logout");
				do{
				printf("\n\n\t\t\t\t Enter Your Desired Choice: ");
				scanf("%d",&choice);
				switch(choice){
					case 1:
						system("cls");
						displayinfo(fp);
						break;
					case 2:
						system("cls");
						search(fp);
						break;
					case 3:
						system("cls");
						wnotice(fp);
						break;
					case 4:
						system("cls");
						view_complain(fp);
						break;
					case 5:
						system("cls");
						remove_stds(fp);
						break;
					case 6:
						system("cls");
						modify(fp);
						break;
					case 7:
						logout();
						break;
					default:
						printf("Wrong Input!");
						Beep(850,400);
						}
					}while(choice<1 || choice >7);
				}

void wnotice(FILE *fp){
	char *notice;
	notice = (char *)calloc(1000,sizeof(char));
	fp = fopen("notice.txt","w");
	printf("\t\t\t\t----------------------------------------NoticeBoard------------------------------------\n\n");
	printf("\t\t\t\t\t Please Enter Your Message: ");
	fflush(stdin);
	gets(notice);
	fprintf(fp,"%s",notice);
	printf("\t\t\t\t\t Enter to save your message and return to admin menu ;)");
	getch();
	fclose(fp);
	system("cls");
	admin_menu(fp);
}


void view_complain(FILE *fp){
	int i,j;
	char c;
	char reply[1000];
	fp = fopen("complain.txt","r");
	if(fp == NULL){
		printf("An Unexpected Error occured in opening file!");
		fclose(fp);
		exit(0);
	}
	else{
		c = getc(fp);
        while (c != EOF){
          printf("%c", c);
          c = getc(fp);
        }
    fclose(fp);
    
    fp = fopen("complain.txt","a");
		printf("\n\n\t\t\t\t\t Press Enter to Reply to the message!");
		printf("Your Reply: ");
		fflush(stdin);
		gets(reply);
		fprintf(fp,"\n\n %s %s","ADMIN REPLY: ",reply);
		printf("\n\t\t\t\t\t Press Enter to save the message and return to admin menu :)");
		getch();
		sleep(1);
		printf("\n\t\t\t\t\t Your Response has been recorded!");
		system("cls");
		fclose(fp);
		admin_menu(fp);
	}
}


void modify(FILE *fp){
FILE *fp1;
int found=0;
char id[25];
int option,opt;

fp=fopen("register.txt","r+");

printf("\n\t\t\tEnter student roll no you want to Modify:");
fflush(stdin);
gets(id);

while((fread(&std,sizeof(struct student),1,fp))==1){
	if(strcmp(std.roll,id)==0){
		found=1;	
		break;
	}
}
if(found == 1){
		printf("\n\t\t\t\t\t\t PLEASE SELECT WHICH FIELD TO EDIT");
		printf("\n\t\t\t\t\t\t PRESS<1> Name");
		printf("\n\t\t\t\t\t\t PRESS<2> Roll Number");
		printf("\n\t\t\t\t\t\t PRESS<3> Email");
		printf("\n\t\t\t\t\t\t PRESS<4> Department");
		printf("\n\t\t\t\t\t\t PRESS<5> Phone Number");
		printf("\n\t\t\t\t\t\t PRESS<6> Route No.");
		printf("\n\t\t\t\t\t\t PRESS<7> Service");
		printf("\n\t\t\t\t\t\t PRESS<8> Password");
		printf("\n\t\t\t\t\t\t PRESS<9> Amount Paid");
		do{
		printf("\n\n\t\t\t\t\t\t Select your desired choice: ");
		scanf("%d",&option);
	switch(option){
		case 1:
	    printf("\n\t\t\tEnter Full Name: ");
	    fflush(stdin);
        gets(std.name);
        fseek(fp,-(long)sizeof(struct student),SEEK_CUR);
        fwrite(&std,sizeof(struct student),1,fp);
         printf("\t\t\tModified Succesfully!");
        break;
        case 2: 
        printf("\n\t\t\tEnter ROLL #: ");
        fflush(stdin);
        gets(std.roll);
        fseek(fp,-(long)sizeof(struct student),SEEK_CUR);
        fwrite(&std,sizeof(struct student),1,fp);
         printf("\t\t\tModified Succesfully!");
        break;
        case 3:
        printf("\n\t\tEnter Email Address: ");
        fflush(stdin);
        gets(std.email);
        fseek(fp,-(long)sizeof(struct student),SEEK_CUR);
        fwrite(&std,sizeof(struct student),1,fp);
         printf("\t\t\tModified Succesfully!");
        break;
        case 4:
        printf("\n\t\t\tEnter Department: ");
        fflush(stdin);
        gets(std.dept);
        fseek(fp,-(long)sizeof(struct student),SEEK_CUR);
        fwrite(&std,sizeof(struct student),1,fp);
         printf("\t\t\tModified Succesfully!");
        break;
        case 5:
        printf("\n\t\tEnter Phone number: ");
        fflush(stdin);
        gets(std.phone);
        fseek(fp,-(long)sizeof(struct student),SEEK_CUR);
        fwrite(&std,sizeof(struct student),1,fp);
         printf("\t\t\tModified Succesfully!");
        break;
        case 6:
        printf("\n\t\t\tEnter New Route# : ");
        scanf("%d",&std.route);
        fseek(fp,-(long)sizeof(struct student),SEEK_CUR);
        fwrite(&std,sizeof(struct student),1,fp);
         printf("\t\t\tModified Succesfully!");
        break;
        case 7:
        do{
    	printf("\n\t\t\tSelect New Service Provider press<1> Jadoon or <2> Swvl: ");
    	scanf("%d",&opt);
    		switch(opt){
    			case 1:
    				strcpy(std.service,"Jadoon");
    				break;
    			case 2:
    				strcpy(std.service,"Swvl");
    				break;
    			default:
    				printf("Wrong input! Select again");
				}
		}while(opt != 1 || opt !=2);
		fseek(fp,-(long)sizeof(struct student),SEEK_CUR);
		fwrite(&std,sizeof(struct student),1,fp);
		 printf("\t\t\tModified Succesfully!");
        break;
        case 8:
        printf("\n\t\t\tEnter New Password: ");
        fflush(stdin);
        gets(std.passw);
        password(fp);
        fseek(fp,-(long)sizeof(struct student),SEEK_CUR);
        fwrite(&std,sizeof(struct student),1,fp);
         printf("\t\t\tModified Succesfully!");
        break;
        case 9:
    	printf("\n\t\t\tEnter Full Amount Paid: ");
        scanf("%d",&std.amount);
        fseek(fp,-(long)sizeof(struct student),SEEK_CUR);
        fwrite(&std,sizeof(struct student),1,fp);
         printf("\t\t\tModified Succesfully!");
        break;
        default:
        printf("Wrong input! Try again!");
    		}
    	}while(option < 1 || option > 9);
}
else if(found==0){
	printf("Sorry No Record Found\n\n");
}

fclose(fp);
printf("\n\n\t\t\t\t\t\t Press Enter to return to admin menu ;)");
getch();
admin_menu(fp);
}

void route_details(FILE *fp){
	printf("\t\t\t\t\t--------------------------------------Route Details----------------------------------");
	printf("\n\t\t\t\t\t Route#: %d ",std.route);
	printf("\t\t\t Service Provider: %s ",std.service);
	
	printf("\n\n\t\t\t\t\t\t Press Enter to return to student menu ");
	getch();
	sleep(1);
	std_menu(fp);
}
void req_stop(FILE *fp){
	FILE *fp2,*jp,*sp;
	int choose,seats;
	char c;
	
	fp = fopen("Swvl.txt","r");
	fp2 = fopen("jadoon.txt","r");
	route(fp,"jadoon.txt");
	route(fp2,"Swvl.txt");
	
	fclose(fp);
	fclose(fp2);
	jp = fopen("Jadoonseats.txt","r");
	sp = fopen("SWVLseats.txt","r");
	do{
	printf("\n\n\n\t\t\t\t PLEASE SELECT YOUR DESIRED STOP: ");
	scanf("%d",&choose);
	switch(choose){
			case 1: 
			fscanf(jp,"%d",&seats);
			rewind(jp);
				printf("\n\t\t\t\t Please wait for confirmation from the point driver!");
				sleep(2);
			if(seats != 0){
				printf("\n\t\t\t\t Your Request has been accepted....Route# %d will pick you up after a few mins",choose);
				sleep(1);
			}
			else{
				printf("\n\t\t\t\t Your request has been declined..All the seats are full!");
				sleep(2);
			}
			break;
			
			case 2:
			fseek(jp,3,SEEK_SET);
			fscanf(jp,"%d",&seats);
				printf("\n\t\t\t\t Please wait for confirmation from the point driver!");
				sleep(2);
			if(seats != 0){
				printf("\n\t\t\t\t Your Request has been accepted....Route# %d will pick you up after a few mins",choose);
				sleep(1);
			}
			else{
				printf("\n\t\t\t\t Your request has been declined..All the seats are full!");
				sleep(2);
			}
			fseek(jp,3,SEEK_SET);
			break;
			
			case 3:
			fseek(jp,6,SEEK_SET);
			fscanf(jp,"%d",&seats);
				printf("\n\t\t\t\t Please wait for confirmation from the point driver!");
				sleep(2);
			if(seats != 0){
				printf("\n\t\t\t\t Your Request has been accepted....Route# %d will pick you up after a few mins",choose);
				sleep(1);
			}
			else{
				printf("\n\t\t\t\t Your request has been declined..All the seats are full!");
				sleep(2);
			}	
			fseek(jp,6,SEEK_SET);
			break;
			
			case 4: 
			fseek(jp,9,SEEK_SET);
			fscanf(jp,"%d",&seats);
				printf("\n\t\t\t\t Please wait for confirmation from the point driver!");
				sleep(2);
			if(seats != 0){
				printf("\n\t\t\t\t Your Request has been accepted....Route# %d will pick you up after a few mins",choose);
				sleep(1);
			}
			else{
				printf("\n\t\t\t\t Your request has been declined..All the seats are full!");
				sleep(2);
			}
			fseek(jp,9,SEEK_SET);
			break;
			
			case 5:
			fseek(jp,12,SEEK_SET);
			fscanf(jp,"%d",&seats);
				printf("\n\t\t\t\t Please wait for confirmation from the point driver!");
				sleep(2);
			if(seats != 0){
				printf("\n\t\t\t\t Your Request has been accepted....Route# %d will pick you up after a few mins",choose);
				sleep(1);
			}
			else{
				printf("\n\t\t\t\t Your request has been declined..All the seats are full!");
				sleep(2);
			}
			fseek(jp,12,SEEK_SET);
			break;
			
			case 6: 
			fscanf(sp,"%d",&seats);
			printf("\n\t\t\t\t Please wait for confirmation from the point driver!");
				sleep(2);
			if(seats != 0){
				printf("\n\t\t\t\t Your Request has been accepted....Route# %d will pick you up after a few mins",choose);
				sleep(1);
			}
			else{
				printf("\n\t\t\t\t Your request has been declined..All the seats are full!");
				sleep(2);
			}
			break;
			case 7:
			fseek(sp,3,SEEK_SET);
				fscanf(sp,"%d",&seats);
			printf("\n\t\t\t\t Please wait for confirmation from the point driver!");
				sleep(2);
			if(seats != 0){
				printf("\n\t\t\t\t Your Request has been accepted....Route# %d will pick you up after a few mins",choose);
				sleep(1);
			}
			else{
				printf("\n\t\t\t\t Your request has been declined..All the seats are full.");
				sleep(2);
			}
			fseek(sp,3,SEEK_SET);
			break;
			
			case 8:
			fseek(sp,6,SEEK_SET);
				fscanf(sp,"%d",&seats);
			printf("\n\t\t\t\t Please wait for confirmation from the point driver!");
				sleep(2);
			if(seats != 0){
				printf("\n\t\t\t\t Your Request has been accepted....Route# %d will pick you up after a few mins",choose);
				sleep(1);
			}
			else{
				printf("\n\t\t\t\t Your request has been declined..All the seats are full!");
				sleep(2);
			}
			
			fseek(sp,6,SEEK_SET);
			break;
			
			case 9:
			fseek(sp,9,SEEK_SET);
				fscanf(sp,"%d",&seats);
			
				printf("\n\t\t\t\t Please wait for confirmation from the point driver!");
				sleep(2);
			if(seats != 0){
				printf("\n\t\t\t\t Your Request has been accepted....Route# %d will pick you up after a few mins",choose);
				sleep(1);
			}
			else{
				printf("\n\t\t\t\t Your request has been declined..All the seats are full!");
				sleep(2);
			}
			fseek(sp,9,SEEK_SET);
			break;
			
			case 10:
			fseek(sp,12,SEEK_SET);
			fscanf(sp,"%d",&seats);
			printf("\n\t\t\t\t Please wait for confirmation from the point driver!");
				sleep(2);
			if(seats != 0){
				printf("\n\t\t\t\t Your Request has been accepted....Route# %d will pick you up after a few mins",choose);
				sleep(1);
			}
			else{
				printf("\n\t\t\t\t Your request has been declined..All the seats are full!");
				sleep(2);
			}
			fseek(sp,12,SEEK_SET);
			break;
		    default:
			printf("Invalid Route Entered");
		}
}while(choose<1 || choose >10);
	fclose(jp);
	fclose(sp);
	
	printf("\n\n\n\t\t\t\t Press Enter to return to student menu;) ");
	getch();
	system("cls");
	std_menu(fp);
}

void balance(FILE *fp){
	int bal,flag = 0;
	fp = fopen("register.txt","r+");
	printf("\t\t\t\t ------------------------------POINT PAYMENT SYSTEM----------------------------");
	printf("\n\t\t\t\tRemaining amount to pay is %d",std.balance);
	do{
	printf("\n\t\t\t\tEnter the amount you would like to pay: ");
	scanf("%d",&bal);
	printf("\t\t\t\tPlease wait.....");
	sleep(1);
	printf("\r");
	if(bal > std.balance){
		printf("\t\t\t\tPlease Pay the amount within limit\n");
		flag = 0;
	}
	else{
	std.amount+=bal;
	std.balance-=bal;
	printf("\t\t\t\tAmount Paid Succesfully!");
	flag = 1;
		}
	}while(flag == 0);
    fseek(fp,-(long)sizeof(struct student),SEEK_CUR);
	fwrite(&std,sizeof(struct student),1,fp);
	fclose(fp);
	printf("Press Enter to return to Student menu");
	getch();
	std_menu(fp);
}

void vcomp(FILE *fp){//make it specific to student
	int i;
	char c;
	fp = fopen("complain.txt","r");
	printf("\t\t\t\t\t\t\t\t Fetching Admin Responses");
	for(i=0;i<2;i++){
	printf(".");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".");
	}
	puts(" ");
	puts(" ");
	c = getc(fp);
        while (c != EOF){
          printf("%c", c);
          c = getc(fp);
        }
    printf("\n\n\t\t\t\t Press Enter to Return to Student menu ;)");
    getch();
    fclose(fp);
    system("cls");
    std_menu(fp);
}

int checkID(FILE *fp,char checkid[]){
	int flag=0;
	fp = fopen("register.txt","r");
	while(fread(&std, sizeof(struct student), 1,fp)){
    if(strcmp(std.roll,checkid) == 0){
    flag=1;
	}
}		
return flag;	
}
