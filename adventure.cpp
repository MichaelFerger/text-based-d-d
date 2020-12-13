//this is a comment so I can make sure when I commit, you guys receive this as well

#include <iostream>
using namespace std;

int main()
{
    //on load, we ask what class they are choosing
    std::cout << "What character class are you playng?\n"
                 "[R]ogue\n"
                 "[F]ighter\n"
                 "[C]leric";

    char charClass;
    std::cin >> charClass;

    switch (toupper(charClass))
    {
    case 'R':
        std::cout << "Ah, a sneaky bastard I see.";
        break;
    case 'F':
        std::cout << "Fancy yourself a strong man, eh?";
        break;
    case 'C':
        std::cout << "Oh, so now you're all high-and-mighty, mister magic man.";
        break;
    default:
        std::cout << "You did not input a capital letter representing your chosen class. TRY AGAIN.";
        break;
    }

    char choice1;
    char choice2;
    char choice3;
    char choice4;

    std::cout << "You there! Adventurer! Welcome to my dungeon. As you look around, you are sitting in a filthy, dark, damp dungeon.\n"
                 "On either side of you, right and left, are doors. Your quick glance at the room affords you no other information."
                 "[O]bserve your surroundings\n" //gives a description of surroundings again
                 "Go [L]eft!\n"                  //enters the room to the left
                 "Go [R]ight\n"                  //enters the room to the right
                 "[G]ive up";                    //ends the game

    std::cin >> choice1;

    switch (toupper(choice1))
    {
    case 'O':
        if (toupper(charClass) == C)
        {
            std::cout << "You are in a filthy dungeon, with a door to either side. You also notice a secret door behind you!";
        }
        else
        {
            std::cout << "You are in a filthy dungeon, with a door to either side.";
        }
        break;
    }

    // it is here i realized either i would have to nest all of the switch statements, with each path having every option until
    // the player either escaped the maze/dungeon or gave up. Looking for another alternative
}