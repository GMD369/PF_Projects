#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
void gotoxy(int x,int y);
void printEnemy();
void printMaze();
void eraseEnemy();
void eraseE2();
void eraseE3();
void eraseE4();
void moveEnemy();
void moveE2();
void moveE3();
void moveE4();
void gameOver();
void LifesContainer();
string gameMenu();
void printPlayer();
void car();
void printE2();
void printE3();
void printE4();
void gameLogo();
void erasePlayer();
bool movePlayerRight();
bool movePlayerLeft();
bool movePlayerUp();
bool movePlayerDown();
void Print_PlayerFire();
void ScoreCount();
void Move_PlayerFire();
void Erase_PlayerFire();
bool Check_PlayerFire();
bool collisionDetection_Down();
bool collisionDetection_Left();
bool collisionDetection_Right();
bool collisionDetection_Up();
char getCharAtxy(short int x, short int y);
string changeDirection(string drirection);
string changeDirection2(string drirection);
int eX=2,eY=10;
int pX=50,pY=25;
int pX2=186,pY2=22;
int pX3=178,pY3=26;
int pX4=178,pY4=0;
int tx=30,ty=15;
int t1=70,t2=15;
int bX=2,bY=10;
int score=0;
int life=3;
int x=15,y=15;
int Fx = 0 , Fy = 0;
int EFx = 0, EFy = 0;
char maze[41][203]={"##########################################################################################################################################################################################################",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "## ***************************************************************************************************************************************************************************************************  ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "## ***************************************************************************************************************************************************************************************************  ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##                                                                                                                                                                                                      ##",
                    "##########################################################################################################################################################################################################"};
main()
{ 
     HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

  system("cls");
  gameLogo();
  getch();
   while(true)
  {  
  system("cls");
  string choice=gameMenu();
  if (choice=="1")
  {
  system("cls"); 
  printMaze();
  printEnemy();
  printE2();
  printE3();
  printPlayer();
  gotoxy(t1,t2);
 
  string enemyDirection="right";
  string direction1="down";
  
  
  while(true)
  {
    if (GetAsyncKeyState(VK_SPACE))
        {
            Fx = pX+16  ;
            Fy = pY+2;
            Print_PlayerFire();
        }
        Move_PlayerFire();
    if (GetAsyncKeyState(VK_LEFT))
    {
        if(movePlayerLeft())
        {
            if(life==0)
            break;
        }
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        if(movePlayerRight())
        {
         if(life==0)
            break;
        }
    }
    if (GetAsyncKeyState(VK_UP))
    {
        if(movePlayerUp())
        {
             if(life==0)
            break;
        }
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
       if( movePlayerDown())
       {
         if(life==0)
        break;
       }
    } 
    

    moveEnemy( );
    Sleep(100);
    moveE2();
    Sleep(100);
    moveE3();
    Sleep(100); 
    moveE4();
    Sleep(100); 
    ScoreCount();
    LifesContainer();
    
  }
  break;
  }
  if (choice=="2")
  {
    system("cls");
    break;
  }
  if(choice!="1"||choice!="2")
  {
    gotoxy(100,30);
    cout<<"Invalid!";
    Sleep(200);
    continue;
  }
 
 }
  
}
string changeDirection(string direction)
{
if (direction=="right"&& eX>=30)
{
    direction=="left";
}
if (direction=="left"&& eX<=2)
{
    direction=="right";
}
return direction;
}
void printE2()
{
      HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(h,6);  
gotoxy(pX2,pY2);
cout<<"   ,_o    "<<endl;
gotoxy(pX2,pY2+1);
cout<<".-/c-/,:: "<<endl;
gotoxy(pX2,pY2+2);
cout<<"(_)'==(_) "<<endl;
}
void eraseE2()
{
    gotoxy(pX2,pY2);
    cout<<"          ";
    gotoxy(pX2,pY2+1);
    cout<<"          ";
    gotoxy(pX2,pY2+2);
    cout<<"          ";
}
void printE3()
{
       HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(h,8);  
  gotoxy(pX3,pY3);
cout<<"   _____________ "<<endl;
  gotoxy(pX3,pY3+1);
cout<<" _/_|[][][][][] |"<<endl;
  gotoxy(pX3,pY3+2);
cout<<"(      City Bus |"<<endl;
  gotoxy(pX3,pY3+3);
cout<<"=--OO-------OO--=dwb "<<endl;
    
}
void eraseE3()
{
    gotoxy(pX3,pY3);
    cout<<"                    ";
    gotoxy(pX3,pY3+1);
    cout<<"                    ";
    gotoxy(pX3,pY3+2);
    cout<<"                    ";
    gotoxy(pX3,pY3+3);
    cout<<"                    ";
}

void moveEnemy()
{
    eraseEnemy();
    eX=eX+4;
    if (eX==158)
    {  
        eX=2;
    }
      printEnemy();
      
   
}
string changeDirection2(string direction)
{
     if (direction=="down" && pY2>=35)
     {
        direction="up";
     }
     if (direction=="up" && pY2<=4)
     {
        direction="down";
     }
     return direction;
}
void moveE2()
{
    eraseE2();
    pX2=pX2-8;
    if(pX2==2)
    {
        pX2=186;
    }
    printE2();
}
void moveE3()
{
    eraseE3();
    pX3=pX3-1;
    if (pX3==2)
    {
        pX3=178;
    }
    printE3();
}
void eraseEnemy()
{
    gotoxy(eX,eY); 
    cout<<"               ";
    gotoxy(eX,eY+1);
    cout<<"               ";
    gotoxy(eX,eY+2);
    cout<<"               ";
    gotoxy(eX,eY+3);
    cout<<"               ";
    gotoxy(eX,eY+4);
    cout<<"               ";
    
}
void printEnemy()
{
      HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(h,3);
    gotoxy(eX,eY);
  cout<<"  ______"<<endl;
   gotoxy(eX,eY+1);
  cout<<" /|_||_\\`.__"<<endl;
   gotoxy(eX,eY+2);
  cout<<"(   _Police _\\"<<endl;
   gotoxy(eX,eY+3);
  cout<<"=`-(_)--(_)-' "<<endl;
    
}
void printMaze()
{
 for(int i=0;i<41;i++)
 {
    for(int j=0;j<202;j++)
    {
        cout<<maze[i][j];
    }
    cout<<endl;
 }
}
void gotoxy(int x,int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void printPlayer()
{
     HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(h,4);
   gotoxy(pX,pY);
  cout<<"  _____"<<endl;
   gotoxy(pX,pY+1);
  cout<<" /|_||_\\`.__"<<endl;
  gotoxy(pX,pY+2);
  cout<<"(   _USER _ _\\"<<endl;
   gotoxy(pX,pY+3);
  cout<<"=`-(_)--(_)-' "<<endl;
    
}  
bool movePlayerUp()
{
    if (getCharAtxy(pX, pY-1) == ' ')
    {
    erasePlayer();
    pY=pY-1;
    printPlayer();
    }
     else
    {
       
        system("cls");
        life=life-1;
        pX=50;
        pY=25;
        printMaze();
        if(life==0)
        {
        system("cls");
         gameOver();
        Sleep(200);
        return 1;   
        }
        
    }
    return 0;
} 
bool movePlayerDown()
{
    if (getCharAtxy(pX, pY+5) == ' ')
    {
    erasePlayer();
    pY=pY+1;
    printPlayer();
    }
    else
    {
        
        system("cls");
        life=life-1;
        pX=50;
        pY=25;
        printMaze();
        if(life==0)
        {
             system("cls");
         gameOver();
        Sleep(200);
        return 1;   
        }
        
    }
    return 0;
}
void erasePlayer()
{
    gotoxy(pX,pY);
    cout<<"              ";
    gotoxy(pX,pY+1);
    cout<<"              ";
    gotoxy(pX,pY+2);
    cout<<"              ";
    gotoxy(pX,pY+3);
    cout<<"              ";
    
    
}
bool movePlayerRight()
{   
    if (getCharAtxy(pX+14, pY) == ' ')
    {
        erasePlayer();
        pX=pX+2;
        printPlayer();
    }
     else
    {
       
        system("cls");
        life=life-1;
        pX=50;
        pY=25;
        printMaze();
        if(life==0)
        {
             system("cls");
         gameOver();
        Sleep(200);
        return 1;   
        }
        
    }
    return 0;
}
    bool movePlayerLeft()
    {
        if (getCharAtxy(pX - 1, pY) == ' ')
        {
        erasePlayer();
        pX=pX-2;
        printPlayer();
    }
     else
    {
        system("cls");
        life=life-1;
        pX=50;
        pY=20;
        printMaze();
        if(life==0)
        {
            system("cls");
         gameOver();
        Sleep(200);
        return 1;   
        }
        
    }
    return 0;
    }


char getCharAtxy(short int x, short int y)
{
CHAR_INFO ci;
COORD xy = {0, 0};
SMALL_RECT rect = {x, y, x, y};
COORD coordBufSize;
coordBufSize.X = 1;
coordBufSize.Y = 1;
return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar
: ' ';
}
void gameLogo()
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(h,1);  
gotoxy(x+5,y);
cout<<".----------------.  .----------------.  .----------------.       .----------------.  .----------------.  .----------------.  .----------------."<<endl; 
gotoxy(x+5,y);
cout<<"| .--------------. || .--------------. || .--------------. |     | .--------------. || .--------------. || .--------------. || .--------------. |"<<endl;
gotoxy(x+5,y+1);
cout<<"| |     ______   | || |      __      | || |  _______     | |     | |    ______    | || |      __      | || | ____    ____ | || |  _________   | |"<<endl;
gotoxy(x+5,y+2);
cout<<"| |   .' ___  |  | || |     /  \\     | || | |_   __ \\    | |     | |  .' ___  |   | || |     /  \\     | || ||_   \\  /   _|| || | |_   ___  |  | |"<<endl;
gotoxy(x+5,y+3);
cout<<"| |  / .'   \\_|  | || |    / /\\ \\    | || |   | |__) |   | |     | | / .'   \\_|   | || |    / /\\ \\    | || |  |   \\/   |  | || |   | |_  \\_|  | |"<<endl;
gotoxy(x+5,y+4);
cout<<"| |  | |         | || |   / ____ \\   | || |   |  __ /    | |     | | | |    ____  | || |   / ____ \\   | || |  | |\\  /| |  | || |   |  _|  _   | |"<<endl;
gotoxy(x+5,y+5);
cout<<"| |  \\ `.___.'\\  | || | _/ /    \\ \\_ | || |  _| |  \\ \\_  | |     | | \\ `.___]  _| | || | _/ /    \\ \\_ | || | _| |_\\/_| |_ | || |  _| |___/ |  | |"<<endl;
gotoxy(x+5,y+6);
cout<<"| |   `._____.'  | || ||____|  |____|| || | |____| |___| | |     | |  `._____.'   | || ||____|  |____|| || ||_____||_____|| || | |_________|  | |"<<endl;
gotoxy(x+5,y+7);
cout<<"| |              | || |              | || |              | |     | |              | || |              | || |              | || |              | |"<<endl;
gotoxy(x+5,y+8);
cout<<"| '--------------' || '--------------' || '--------------' |     | '--------------' || '--------------' || '--------------' || '--------------' |"<<endl;
SetConsoleTextAttribute(h,8);
gotoxy(x+75,y+13);
cout<<"--------------------------------";
SetConsoleTextAttribute(h,2);
gotoxy(x+75,y+15);
cout<<"           LOADING.......";
SetConsoleTextAttribute(h,8);
gotoxy(x+75,y+17);
cout<<"--------------------------------";
Sleep(1000);
gotoxy(x+75,y+13);
cout<<"                                ";
gotoxy(x+75,y+15);
cout<<"                         ";
gotoxy(x+75,y+17);
cout<<"                                ";
gotoxy(x+75,y+17);
cout<<"Press Any Key To Continue..";
}
void printE4()
{
     HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(h,14);
gotoxy(pX4,pY4+18);
cout<<"   ,_oo   ";
gotoxy(pX4,pY4+19);
cout<<".-/c-//:: ";
gotoxy(pX4,pY4+20);
cout<<"(_)'==(_) ";
}
void eraseE4()
{
    gotoxy(pX4,pY4+18);
    cout<<"             ";
    gotoxy(pX4,pY4+19);
    cout<<"             ";
    gotoxy(pX4,pY4+20);
    cout<<"             ";
}
void moveE4()
{
    eraseE4();
    pX4=pX4-4;
    
    if (pX4==2)
    {
        pX4=178;
    }
    printE4();
}




void car() {
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(h,3);
    gotoxy(3,15);
         cout << "                ___..................____\n"
                 "           _..--''~_______   _____...----~~~\\\\\n"
                 "       __.'    .-'~       \\\\~      [_`.7     \\\\\n"
                 " .---~~      .'            \\\\           __..--\\\\_\n"
                 "/             `-._          \\\\   _...~~~_..---~  ~~~~~~~~~~~~--.._\n"
                 "\\              /  ~~~~~~----_\\`-~_-~~__          ~~~~~~~---.._    ~--.__\n"
                 " \\     _       |==            |   ~--___--------...__          `-   _.--\"\"\"|\n"
                 "  \\ __/.-._\\   |              |            ~~~~--.  `-._ ___...--~~~_.'|_Y |\n"
                 "   `--'|/~_\\\\  |              |     _____           _.~~~__..--~~_.-~~~.-~/\n"
                 "     | ||| |\\\\_|__            |.../.----.._.        | Y |__...--~~_.-~  _/\n"
                 "      ~\\\\\\ || ~|..__---____   |||||  .'~-. \\\\       |_..-----~~~~   _.~~\n"
                 "        `\\`-'/ /     ~~~----...|'''|  |/\"_\"\\ \\\\   |~~'           __.~\n"
                 "         `~~~'                 ~~-:  ||| ~| |\\\\  |        __..~~\n"
                 "                                   ~~|||  | | \\/  _.---~~\n"
                 "                                     \\\\\\  //  | ~~~\n"
                 "                                      `\\`-'/  / \n"
                 "                                       `~~~~'\n";

    
}
string gameMenu()
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
 
    car();
    gotoxy(100,35);
    cout<<"NOTE:"<<endl;
       gotoxy(100,37);
    cout<<"     \"  Avoid the obstacles like cars,bikes and wall and otherwise game will be over!\"";
        SetConsoleTextAttribute(h,2);
    gotoxy(100,20);
       SetConsoleTextAttribute(h,1);
    cout<<"==> 1.  START GAME";
    gotoxy(100,22);
       SetConsoleTextAttribute(h,4);
    cout<<"==> 2.  EXIT";
    string choice;
  gotoxy(100,25);
  SetConsoleTextAttribute(h,8);
  cout<<"Choose Option: ";
   gotoxy(120,25);
  cin>>choice;
  return choice;


}
void Print_PlayerFire()
{
    gotoxy(Fx, Fy);
    cout << ">";
}
void Erase_PlayerFire()
{
    gotoxy(Fx, Fy);
    cout << " ";
}
void Move_PlayerFire()
{

    for (int i = 0; i < 202; i++)
    {
        for (int j = 0; j < 41; j++)
        {

            if (getCharAtxy(i, j) == '>')
            {
                Fx = i;
                Fy = j;

                Erase_PlayerFire();
                 
                gotoxy(Fx+1, Fy);

                Fx++;
                if (Check_PlayerFire())
                {
                    Print_PlayerFire();
                }
            }
        }
    }
}
bool Check_PlayerFire()
{
    if (getCharAtxy(Fx, Fy) == ' ')
    {
        return true;
    }
    else
    {
        if (getCharAtxy(Fx, Fy) != '#')
        {
         score=score+2;
        }
        return false;
       
    }
}

bool collisionDetection_Right()
{
    if (getCharAtxy(pX+1, pY) != ' ')
    {
        return 0;
    }
    return 1;
}
bool collisionDetection_Left()
{
    if (getCharAtxy(pX-1, pY) != ' ')
    {
        return 0;
    }
    return 1;
}
bool collisionDetection_Up()
{
    if (getCharAtxy(pX, pY-1) != ' ')
    {
        return 0;
    }
    return 1;
}
bool collisionDetection_Down()
{
    if (getCharAtxy(pX, pY+1) != ' ')
    {
        return 0;
    }
    return 1;
}
void gameOver()
{ HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(h,4);
         cout << " $$$$$$\\   $$$$$$\\  $$\\      $$\\ $$$$$$$$\\              $$$$$$\\  $$\\    $$\\ $$$$$$$$\\ $$$$$$$\\              $$\\ \n"
                 "$$  __$$\\ $$  __$$\\ $$$\\    $$$ |$$  _____|            $$  __$$\\ $$ |   $$ |$$  _____|$$  __$$\\             $$ |\n"
                 "$$ /  \\__|$$ /  $$ |$$$$\\  $$$$ |$$ |                  $$ /  $$ |$$ |   $$ |$$ |      $$ |  $$ |            $$ |\n"
                 "$$ |$$$$\\ $$$$$$$$ |$$\\$$\\$$ $$ |$$$$$\\                $$ |  $$ |\\$$\\  $$  |$$$$$\\    $$$$$$$  |            $$ |\n"
                 "$$ |\\_$$ |$$  __$$ |$$ \\$$$  $$ |$$  __|               $$ |  $$ | \\$$\\$$  / $$  __|   $$  __$$<             \\__|\n"
                 "$$ |  $$ |$$ |  $$ |$$ |\\$  /$$ |$$ |                  $$ |  $$ |  \\$$$  /  $$ |      $$ |  $$ |                \n"
                 "\\$$$$$$  |$$ |  $$ |$$ | \\_/ $$ |$$$$$$$$\\              $$$$$$  |   \\$  /   $$$$$$$$\\ $$ |  $$ |            $$\\ \n"
                 " \\______/ \\__|  \\__|\\__|     \\__|\\________|             \\______/     \\_/    \\________|\\__|  \\__|            \\__|\n";
}
void ScoreCount()
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(h,4);
    gotoxy(3,2);
    cout<<"--------------------"<<endl;
     gotoxy(3,3);
    cout<<"SCORE:     "<<score  <<endl;
     gotoxy(3,4);
    cout<<"-_-_-_-_-_-_-_-_-_-_"<<endl;
}
void LifesContainer()
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(h,7);
    gotoxy(30,2);
    cout<<"~~~~~~~~~~~~~~";
    gotoxy(30,3);
    cout<<"LIFES:  "<<life;
    gotoxy(30,4);
    cout<<"..............";

}