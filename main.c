#include<conio.h>
#include<stdio.h>
#include<string.h>
#include"../conio2.h"
#define ESC 27

#define F1 59

#define F2 60


void signup(void);

void login(void);

int i;

struct{
char password[20];

char username[20];
}s;


FILE *fp;


void main()

{
int ch;

while(1)

{
clrscr();

gotoxy(20,5);
textcolor(BLUE);
printf("  ______________MY FIRST PAGE________________");

gotoxy(28,7);
textcolor(YELLOW);
printf("WELCOME FOR COME HERE...........");

gotoxy(28,9);
printf("Press F1 For Login");

gotoxy(28,11);

printf("Press F2 For Signup");

gotoxy(28,13);

printf("Press ESC For Exit");
gotoxy(20,15);

printf("    _____________********______________\n");
getch();
ch=getch();

switch(ch)

{
case F1:
clrscr();

gotoxy(10,14);

for(int i=0;i<40;i++)

{
 printf("_");
 delay(40);
}

login();
break;

case F2:
clrscr();

gotoxy(10,14);

for(int i=0;i<40;i++)

{
 printf("_");
 delay(40);
}

signup();
break;

case ESC:
exit(0);

break;
}

}

getch();



}

void login()

  {

   int c;
   char username[20];
   char pass[20];
   int chkp,chku;

   clrscr();
   gotoxy(23,5);
   textcolor(LIGHTCYAN);
   printf("________________LOGIN PAGE__________________");
  gotoxy(23,7);

  fp=fopen("record.bin","rb");


  printf("Enter UserName         :");

  gets(username);

  gotoxy(23,9);

  printf("Enter PassWord         :");


  for(i=0;c=getch()!=13;i++)

{
  pass[i]=c;
  printf("*");
  }

  pass[i]='\0';

  while(!feof(fp))

 {
  fread(&s,sizeof(s),1,fp);

  chku=strcmp(username,s.username);

chkp=strcmp(pass,s.password);

  if(chku==0&&chkp!=0)

{

  printf("\nInvalid password!!!!!!!!!!!!");
  break;
  }

else if(chku!=0&&chkp==0)
  {
   printf("\n\tInvalid Username!!!!!!!!");

break;
  }

  else if(chku==0&&chkp==0)

  {
  clrscr();
  gotoxy(20,10);

  printf("_Hello %s Welcome Here_ ",s.username);

break;
  }

  }
    getch();
  }



 void signup(){
   char c;
int i;
  fp=fopen("record.bin","ab");

   clrscr();
  gotoxy(23,5);

 printf("        _________________SignUp Zone___________________");

gotoxy(23,7);
  printf("       Set UserName           :  ");

 gets(s.username);

  gotoxy(23,9);
  printf("Set Password:  ");
  for(i=0;c=getche()!=13;i++)
  {
  s.password[i]=c;
  }

  gotoxy(23,11);

  printf("Press Enter to continue.........");

 if(getch()==13)

{
   fwrite(&s,sizeof(s),1,fp);

     gotoxy(23,13);
   cprintf("\nSingUp Completed Ready to Login");
   }

  else
   return;

 fclose(fp);


getch();
  }
