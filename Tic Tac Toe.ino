#include <SoftwareSerial.h>

char gameboard[]={' ',' ',' ',' ',' ',' ',' ',' ',' '};

void setup()
{
Serial.begin(9600);
}

void loop() 
{ 

  Serial.println("Tic Tac Toe");
  Serial.println("Let's play");
   delay(500);
  Serial.println("This is the gameboard:");
   delay(500);
  Serial.println("_________ _________ _________");
 Serial.println("|         |         |         |");
 Serial.println("|    1    |    2    |    3    |");
 Serial.println("|         |         |         |");
  Serial.println("_________ _________ _________");
 Serial.println("|         |         |         |");
 Serial.println("|    4    |    5    |    6    |");
 Serial.println("|         |         |         |");
  Serial.println("_________ _________ _________");
 Serial.println("|         |         |         |");
 Serial.println("|    7    |    8    |    9    |");
 Serial.println("|         |         |         |");
  Serial.println("_________ _________ _________");
   delay(1000);
  
do 
{
yourturn();
if (winner()) break;
Arduino();
game();
} while (!winner());
delay(5000);
for (int i=0; i<100; i++) Serial.println();
for (int i=0; i<9; i++) gameboard[i]=' ';  
  
}
void game()
{
 Serial.println("_________ _________ _________");
 Serial.println("|         |         |         |");
 Serial.print("|    ");Serial.print(gameboard[0]);Serial.print("    |    ");Serial.print(gameboard[1]);Serial.print("    |    ");Serial.print(gameboard[2]);Serial.print("    |\n");
 Serial.println("|         |         |         |");
  Serial.println("_________ _________ _________");
 Serial.println("|         |         |         |");
 Serial.print("|    ");Serial.print(gameboard[3]);Serial.print("    |    ");Serial.print(gameboard[4]);Serial.print("    |    ");Serial.print(gameboard[5]);Serial.print("    |\n");
 Serial.println("|         |         |         |");
  Serial.println("_________ _________ _________");
 Serial.println("|         |         |         |");
 Serial.print("|    ");Serial.print(gameboard[6]);Serial.print("    |    ");Serial.print(gameboard[7]);Serial.print("    |    ");Serial.print(gameboard[8]);Serial.print("    |\n");
 Serial.println("|         |         |         |");
  Serial.println("_________ _________ _________");
}
boolean winner ()
{
  char winner =' ';
  int i;
  if(gameboard[0]==gameboard[1] && gameboard[1]==gameboard[2]) winner=gameboard[0];
  if(gameboard[0]==gameboard[3] && gameboard[3]==gameboard[6]) winner=gameboard[0];
  if(gameboard[0]==gameboard[4] && gameboard[4]==gameboard[8]) winner=gameboard[0];
  if(gameboard[1]==gameboard[4] && gameboard[4]==gameboard[7]) winner=gameboard[1];
  if(gameboard[2]==gameboard[5] && gameboard[5]==gameboard[8]) winner=gameboard[2];
  if(gameboard[2]==gameboard[4] && gameboard[4]==gameboard[6]) winner=gameboard[2];
  if(gameboard[3]==gameboard[4] && gameboard[4]==gameboard[5]) winner=gameboard[3];
  if(gameboard[6]==gameboard[7] && gameboard[7]==gameboard[8]) winner=gameboard[6];
  if(winner==' ') 
  {
  winner='*';
  for(i=0; i<9; i++)
   if(gameboard[i]==' ')   winner=' ';
  }
   if(winner==' ') return false;
  else
   if(winner=='X') 
   {
    game();
    Serial.println("Brilliant ! You won!");
   }
   if(winner=='0')
   Serial.println("Ups, it seams that Arduino is smarter than you...Try again!");
   if(winner=='*') 
   Serial.println("What a shameful draw! That was realy boring");
}
void yourturn() 
{
boolean valid = false;
int you = 0;

while (!valid) 
{
Serial.println("Choose a number between 1 and 9");
while (you<'1' || you>'9') 
{
you = Serial.read();
delay(1000);
}
you = you - 48;
Serial.println();
if (gameboard[you-1]!=' ')
Serial.println("Wrong position!");
else 
{
gameboard[you-1]='X';
valid = true;
   }
 }
}
void Arduino() 
{
int i=-1;
while (i==-1) 
{
i = random(0,9);
if (gameboard[i]==' ') 
{
gameboard[i]='0';
Serial.println();
break;
}
else i=-1;
   }
}

