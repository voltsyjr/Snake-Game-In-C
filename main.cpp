/*
                                        Snake Game -> (Snake Land)
                                NITD(National Institute of Technology Delhi)
        This is our snake game project developed by Vishal Singh and Shrey kumar prajapati
        all rights are reserved to Vishal Singh and Shrey Kumar Prajapati NITD(National Institute of Technology Delhi).

        Submitted by                    1. Name-> Vishal Singh
                                           Roll number-> 201210055
                                           Branch-> CSE
                                           year-> First Year, Semester first(Automn)

                                        2. Name-> Shrey Kumar Prajapati
                                           Roll number-> 201210041
                                           Branch-> CSE
                                           year-> First Year, Semester first(Automn)

        Submitted to                    Dr. Chandra Prakash.
*/

#include <graphics.h>                       //for using graphics
#include <time.h>                           //for generating each time random food
#include <stdio.h>                          //for standard input and output functions
#include <stdlib.h>                         //for gets() and some of its functions
int startSetupt(int *start);                                                            //function to welcome user/set initials
int setLevel(int *food, int *level,int x[], int y[], int *length,int *d, int *dir);     //function to set level
void theame(int level, int scoreValue,char score[], char levelShow[]);                  //function to set theame of level
void foodGenerate(int x[], int y[], int *rx, int *ry, int *length, int *food,int *scoreValue);  //function to generate food
void drawSnake(int x[], int y[],int length,int level);                                  //function to draw snake body
void levelSpeed(int level);                                                             //function to set speed of snake according to level
void input(int *d, int *dir);                                                           //function to take input from user
void directionLogic(int d,int x[],int y[],int *dir);                                    //function to give direction to snake
int diedCondition(int scoreValue,int level,int length,int *chk,int x[],int y[],char score[],char levelShow[]);  //function for snake to die
int endFunc(int scoreValue, int a, int level,char score[],char levelShow[]);            //function to end game
void winFunction();                                                                     //function for winning condition
int main()
{
    int rx=200,ry=200,x[200]={0},y[200]={0},d;
    int food=1, chk=700,dir=1,length=1,level=1,winCondition=0,scoreValue=0,start=0,play=0,initialExit=0,endGame=0;
    char score[50], levelShow[50],replaying[100];
    srand(time(0));
    play:
    initialExit=startSetupt(&start);
    if(start==1){
        replays:
        system("cls");
        printf("\n\t\t\t\t\t\t   Select Level!\n");                     //promt user to select user
        printf("\t\t\t\t\t\tPress 1 for level 1\n\t\t\t\t\t\tPress 2 for level 2\n\t\t\t\t\t\tPress 3 for level 3\n\t\t\t\t\t\tPress 4 for level 4\n\t\t\t\t\t\tPress 5 for level 5\n\t\t\t\t\t\t\t");
        fflush(stdin);
        scanf("%d",&level);
        fflush(stdin);
        while(level>5||level<1){                                        //if user entered wrong level value than to correct him
            system("cls");
            printf("\t\t\t\t\t***Please choose correct level***");
            printf("\n\t\t\t\t\t\tPress 1 for level 1\n\t\t\t\t\t\tPress 2 for level 2\n\t\t\t\t\t\tPress 3 for level 3\n\t\t\t\t\t\tPress 4 for level 4\n\t\t\t\t\t\tPress 5 for level 5\n\t\t\t\t\t\t\t");
            fflush(stdin);
            scanf("%d",&level);
            fflush(stdin);
        }
        system("cls");
        printf("\n\t\t\t\tPress 1 to start the game or 2 to return to main menu! ");
        fflush(stdin);
        scanf("%d",&play);
        fflush(stdin);
        if(play==2){goto play;}                                      //to take user to main menu
    int gd=DETECT,gm;                                                //graphics variables with auto detect Driver
    initgraph(&gd,&gm,NULL);                                         //opening graphics mode, graphics window and checking for bgi files
    x[0]=320;                                                        //set initial position of snake
    y[0]=240;
    d=1;
    while(1){
        winCondition= setLevel(&food, &level,x,y,&length,&d,&dir);   //setting level And winCondition
        if(winCondition==1){
            winFunction();                                           //call winfunction to show winning page
            break;
        }
        theame(level,scoreValue,score,levelShow);                    //setting theame
        foodGenerate(x,y,&rx,&ry,&length,&food,&scoreValue);         //generate food and add score
           setcolor(15);
        setfillstyle(1,2);
        input(&d, &dir);                                             //function to take input from user
        directionLogic(d,x,y,&dir);                                  //function to make logic to move snake
        drawSnake(x,y,length,level);                                 //function to draw snake body
        levelSpeed(level);                                           //function to set speed level Wise
        endGame=diedCondition(scoreValue,level,length,&chk,x,y,score,levelShow);    //Condition for ending the game
        if(endGame==1){break;}
        cleardevice();
    }
    }
    if(initialExit!=1){                                  //after died or winning game asking user to play agian or exit
        fflush(stdin);
        printf("\n\t\t\tPress 1 to replay or 2 to exit the game: ");
        gets(replaying);
        fflush(stdin);
        if(replaying[0]=='1'){
                food=1;scoreValue=0;length=1;d=1;dir=1;x[0]=320;y[0]=240;rx=200;ry=200;  //clearing last player data
            goto replays;
        }else{exit;}
    }
}
int startSetupt(int *start){                                //function to set starting initials
    char temp[10];
    system("cls");
    printf("\n\t\t\tWelcome to Snake Land!\n");             //Welcome note
    printf("\tWe all in childhood thinks like if I am a bird, lion or other animal.\n");
    printf("\tHere Your dream comes true, In this game you are a snake.\n\tYou have to survive and cross multiple stages and reunite with your family");
    fflush(stdin);
    printf("\n\t\t\tPress Enter to continue");
    gets(temp);
    fflush(stdin);
    label1:
    system("cls");                                          //main menu to explore game
    fflush(stdin);
    printf("\n\n\t\tPress 1 to start Game!\n\n\t\tPress 2 to view Controls and rules!\n\n\t\tPress 3 to Show Our Team Details\n\n\t\tPress 4 to exit!\n\n\t\t\t");
    scanf("%d",start);
    fflush(stdin);
    if(*start==2){
    system("cls");                                          //controls guide to play game
    printf("\n\t\t\tGuide to controls\n");
    printf("\tUse arrow keys to move Snake!\n");
    printf("\tFor moving snake in to left direction press:\t<\n");
    printf("\tFor moving snake in to right direction press:\t>\n");
    printf("\tFor moving snake in to up direction press:\t^\n");
    printf("\tFor moving snake in to down direction press:\tv\n");

    printf("\n\t\t\tConditions for dying\n");               //rules for diying
    printf("\tYou will die if you touch any boundary or touch yourself\n");
    fflush(stdin);
    printf("\n\t\t\tPress Enter to continue");
    gets(temp);
    fflush(stdin);
    goto label1;                                            //to goto main menu
    }
    else if(*start==3){
    system("cls");                                          //showing our team and project details
    printf("\n\tThis Project is Made by the team of Two Members:\n");
    printf("\t\t1. Vishal Singh\n\t\t2. Shrey prajapati Kumar\n");
    printf("\t\tThis is our first Game \n");
    printf("\t\tThis is our project for our first year automn semester\n");
    printf("\t\tSubmitted to Dr. Chandra Prakash Sir\n\n");
    printf("\t  ****Thanks For Playing Our game****\n");
    printf("\t  ****Hope You Enjoyed Our Game****");
    fflush(stdin);
    printf("\n\n\t\tPress Enter to continue");
    gets(temp);
    fflush(stdin);
    goto label1;                                            //goto main menu
    }
    else if(*start==4){return 1;}                           //to exit game from main menu
    return 0;
}
int setLevel(int *food, int *level,int x[], int y[], int *length,int *d, int *dir){
    char levelshowing[100], temp[100];                      //function to set level
    if(*food==11){                                          //when food crosses 10 increase the level by one
        if(*level!=5){                                      //if current level is not final level than promt user to press enter to continue when level is changed
        setfillstyle(1,5);
        setbkcolor(5);
        cleardevice();                                      //clear previous graphics objects and shapes
        fflush(stdin);
        sprintf(levelshowing,"Level %d Completed!",*level); //showing level up note
        outtextxy(140,30,levelshowing);
        outtextxy(140,50,"Press Enter to continue to Next level");
        gets(temp);
        fflush(stdin);
        setfillstyle(1,0);
        setbkcolor(0);
        }
        *level=*level + 1;                                  //increasing level by one
        *food=1;                                            //resetting food to 1
        for(int i=2;i<*length;i++){                         //for a new level resetting snakelength and cordinates to 0
            x[i]=0;
            y[i]=0;
        }
        *length=1;*d=1;x[0]=320;y[0]=240;*dir=1;            //setting snake length and position on each new level
    }
    if(*level>5){
        return 1;                                           //returning one so that we could call win function to congrats player for winning game
    }
    else{
        return 0;                                           //else return 0 for not to call win funtion
    }
}
void input(int *d, int *dir){                               //function to take snake direction from user
        if(GetAsyncKeyState(VK_RIGHT)){                     //for taking snake direction from player used getasynchronouskeystate()
            if(*dir!=2){*d=1;}                              //used if condition so that if snake is moving in left previously than player can't move it in right
            }
        else if(GetAsyncKeyState(VK_LEFT)){
            if(*dir!=1){*d=2;}                              //used if condition so that if snake is moving in right previously than player can't move it in left
        }
        else if(GetAsyncKeyState(VK_UP)){
            if(*dir!=4){*d=3;}                              //used if condition so that if snake is moving in down previously than player can't move it in up
        }
        else if(GetAsyncKeyState(VK_DOWN)){
            if(*dir!=3){*d=4;}                              //used if condition so that if snake is moving in up previously than player can't move it in down
        }
        else {*d=0;}
}
void directionLogic(int d,int x[],int y[],int *dir){        //function to give direction to snake according to input given by user
        switch(d){
            case 0:                                         //if press no key than continue in the direction in which snake was moving
                if(*dir==1){x[0]=x[0]+10;}
                else if(*dir==2){x[0]=x[0]-10;}
                else if(*dir==3){y[0]=y[0]-10;}
                else if(*dir==4){y[0]=y[0]+10;}
                else{*dir=0;}
                break;
            case 1:                                         //for moving snake in right direction
                x[0]=x[0]+10;
                *dir=1;
                break;
            case 2:                                         //for moving snake in left direction
                x[0]=x[0]-10;
                *dir=2;
                break;
            case 3:                                         //for moving snake inn up direction
                y[0]=y[0]-10;
                *dir=3;
                break;
            case 4:                                         //for moving snake in down direction
                y[0]=y[0]+10;
                *dir=4;
                break;
            }
}

void levelSpeed(int level){                                 //set speed of snake according to the level
    if(level==1){
        delay(80);                                          //using delay() to change speed
    }
    else if(level==2){
        delay(65);
    }
    else if(level==3){
        delay(50);
    }
    else if(level==4){
        delay(45);
    }
    else if(level==5){
        delay(40);
    }
}
void theame(int level, int scoreValue,char score[], char levelShow[]){              //setting theame according to level
    if(level==1){             setfillstyle(INTERLEAVE_FILL,2);bar(0,0,640,480);     //background color
                            setfillstyle(CLOSE_DOT_FILL,12);}                           //for boundary style
    else if(level==2){        setfillstyle(INTERLEAVE_FILL,3);bar(0,0,640,480);     //background color
                            setfillstyle(CLOSE_DOT_FILL,9);}                            //for boundary style
    else if(level==3){        setfillstyle(INTERLEAVE_FILL,5);bar(0,0,640,480);     //background color
                            setfillstyle(CLOSE_DOT_FILL,7);}                            //for boundary style
    else if(level==4){        setfillstyle(INTERLEAVE_FILL,1);bar(0,0,640,480);     //background color
                            setfillstyle(CLOSE_DOT_FILL,9);}                            //for boundary style
    else if(level==5){        setfillstyle(INTERLEAVE_FILL,9);bar(0,0,640,480);     //background color
                            setfillstyle(CLOSE_DOT_FILL,11);}                           //for boundary style
        setbkcolor(3);                                                              //score and level background
        sprintf(score,"Score: %d",scoreValue);
        outtextxy(30,11,score);                                                     //display score
        sprintf(levelShow,"Level: %d",level);                                       //display level
        outtextxy(550,11,levelShow);
        setbkcolor(0);
        //for boundary
        bar(0,0,640,10);                                                            //top
        bar(0,0,20,480);                                                            //left
        bar(0,480,640,460);                                                         //bottom
        bar(620,10,640,480);                                                        //right
        line(20,30,620,30);
}
void foodGenerate(int x[], int y[], int *rx, int *ry, int *length, int *food,int *scoreValue){  //function to generate new food and add score
        if(x[0]==*rx && y[0]==*ry){                                         //condition to check if snake has eaten food or not
            *length +=1;                                                    //increase snake length by one
            *food +=1;                                                      //increase food by one
            *scoreValue+=1;                                                 //increase score by one
        do{
            *rx= (rand()%600);
            *ry= (rand()%440);
        }while(*rx<30 || *ry<40);                                           //condition to check if food is generated within the boundary
        //logic to make rx and ry integer and multiple of 10
        *rx=(*rx)/10;
        *rx=(*rx)*10;
        *ry=(*ry)/10;
        *ry=(*ry)*10;
        }
        setfillstyle(1,4);
        setcolor(4);
        fillellipse(*rx+5,*ry+5,6,6);                                        //draw food at new position
}
void drawSnake(int x[], int y[],int length,int level){                       //function to draw snake
        for(int i=0; i<=length;i++){
            if(i==0){                                                        //draw head
                setfillstyle(1,5);
                setcolor(4);
                fillellipse(x[i]+5,y[i]+5,7,7);
            }
            else{                                                            //draw body
                setfillstyle(1,9);
                setcolor(2);
                fillellipse(x[i]+5,y[i]+5,6,6);
            }

        }
        setcolor(15);
        for(int i=99;i>0;i--){                                                  //for moving snake, giving direction inheritation
            x[i]=x[i-1];
            y[i]=y[i-1];
        }
}

int diedCondition(int scoreValue,int level,int length,int *chk,int x[],int y[],char score[],char levelShow[]){  //function to check snake died condition
        if(x[0]>=620||x[0]<=15||y[0]>=455||y[0]<=25){
            endFunc(scoreValue,0,level,score,levelShow);        //if snake crosses boundary than call endFunc()
            return 1;
        }
        for(int i=2;i<length;i++){
            if(x[0]==x[i] && y[0]==y[i]){
                *chk=i;
            }
        }
        if(x[0]==x[*chk] && y[0]==y[*chk]){                     //if snake touches itself than call endFunc()
            endFunc(scoreValue,1,level,score,levelShow);
            return 1;
        }
}
int endFunc(int scoreValue, int a, int level,char score[],char levelShow[]){        //function to show player that he/she has died
    char ends[100];
    setfillstyle(1,5);
    setbkcolor(5);
    bar(0,0,640,480);
    fflush(stdin);
    closegraph();
    system("cls");
    if(a==0){
        printf("\n\n\t\t\tYou died outside the boundary\n");                        //if snake touch boyndary
    }
    else if(a==1){
        printf("\n\n\t\t\tYou died into Your self\n");                              //if snake touch itself
    }
    printf("\n\t\t\t\tYour score is: %d \n",scoreValue);
    printf("\n\t\t\t\tYou Reached Level: %d \n",level);
    fflush(stdin);
    printf("\n\t\t\t\tPress Enter to continue!");
    gets(ends);
    fflush(stdin);
    system("cls");
    return 0;
}

void winFunction(){                                                     //function to congrats player that he has won
    char temp[100];
    setfillstyle(1,3);
    setbkcolor(3);
    setcolor(0);
    bar(0,0,640,480);
    outtextxy(180,50,"\t\t*******  Congratulations!!  ********\n\n");
    outtextxy(190,70,"\t\t    You survived All the Stages\n");
    setfillstyle(1,4);
    fillellipse(280,140,30,30);                                         //drawing smily face
    setfillstyle(1,5);
    fillellipse(292,130,5,5);
    fillellipse(268,130,5,5);
    sector(281,145,180,360,15,15);
    fflush(stdin);
    outtextxy(200,200,"Press Enter to continue");
    gets(temp);
    fflush(stdin);
    system("cls");
    closegraph();
}

//The End, This is all our game consist of
