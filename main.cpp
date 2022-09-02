#include <iostream>
#include <windows.h>
using namespace std;
int choice; //Global variable
int *root; //Global variable

void gotoxy(int x, int y) //This void sets position of cursor x,y, on the screen
{
  COORD c;
  c.X=x-1;
  c.Y=y-1;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
    int data[16]; //Variable array
    bool emptya[16]; //Variable array

void display_tree()
{
system("CLS");
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
//Rules of tree display
gotoxy(40,1); if (emptya[1]==true) cout<<"_"; else cout<<data[1];
gotoxy(20,4); if (emptya[2]==true) cout<<"_"; else cout<<data[2];
gotoxy(60,4); if (emptya[3]==true) cout<<"_"; else cout<<data[3];
gotoxy(10,6); if (emptya[4]==true) cout<<"_"; else cout<<data[4];
gotoxy(30,6); if (emptya[5]==true) cout<<"_"; else cout<<data[5];
gotoxy(50,6); if (emptya[6]==true) cout<<"_"; else cout<<data[6];
gotoxy(70,6); if (emptya[7]==true) cout<<"_"; else cout<<data[7];
gotoxy(5,10); if (emptya[8]==true) cout<<"_"; else cout<<data[8];
gotoxy(15,10); if (emptya[9]==true) cout<<"_"; else cout<<data[9];
gotoxy(25,10); if (emptya[10]==true) cout<<"_"; else cout<<data[10];
gotoxy(35,10); if (emptya[11]==true) cout<<"_"; else cout<<data[11];
gotoxy(45,10); if (emptya[12]==true) cout<<"_"; else cout<<data[12];
gotoxy(55,10); if (emptya[13]==true) cout<<"_"; else cout<<data[13];
gotoxy(65,10); if (emptya[14]==true) cout<<"_"; else cout<<data[14];
gotoxy(75,10); if (emptya[15]==true) cout<<"_"; else cout<<data[15];
cout<<endl<<endl<<endl;
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

void add()
{
    int number;
    cout<<"What number to add?: ";
    cin>>number;

    if (emptya[1]==true) //Tree is empty
    {
        root=&data[1];
        *root=number;
        emptya[1]=false;
    }
    else //Tree is not empty
    {
    bool found_space=false;
    int nod=1;

    while (found_space==false)
    {
        if (emptya[nod]==true)
        {
            found_space=true;
            data[nod]=number;
            emptya[nod]=false;

        }
        else if(number<data[nod])
        {
            //go left
            nod=2*nod;
        }
        else
        {
            //go rigt
            nod=2*nod+1;
        }
        if(nod>15)
        {
            cout<<"A bigger tree is needed!";
            Sleep(3000);
            found_space=true;
        }
    }
    }

}

void find()
{
int number;
cout<<"What number to find in the tree?: ";
cin>>number;

bool found=false;
int nod=1;

    while (found==false)
    {
        if(number==data[nod])
        {
            cout<<"Number found in nod number: "<<nod;
            Sleep(3000);

            found=true;
        }
        else if(number<data[nod])
        {
            //to the left
            nod=2*nod;
        }
        else
        {
            //to the right
            nod=2*nod+1;
        }
        if(nod>15)
        {
            cout<<"Number not found!";
            Sleep(3000);
            found=true;
        }
    }
}

int main()
{
    for (int i=1; i<=15; i++)
    {
        emptya[i]=true;
    }
    root=NULL;

    do
    {
    display_tree();

    cout<<"----------------------------------"<<endl;
    cout<<"   BINARY TREE "<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"1. ADD (add element to the tree)"<<endl;
    cout<<"2. FIND (find element within the tree)"<<endl;
    cout<<"3. EXIT (exit program)"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"   CHOOSE: ";
    cin>>choice;
    cout<<endl;

    switch(choice)
    {
        case 1: add(); break;
        case 2: find(); break;
    }

    }while (choice!=3);
    return 0;
}
