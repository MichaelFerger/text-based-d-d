#include <iostream>
using namespace std;

int main()
{
    //on load, we ask what class they are choosing
    std::cout << "What character class are you playng?\n"
                 "[R]ogue\n"
                 "[F]ighter\n"
                 "[C]leric\n";

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

    int playerHealth = 100;
    bool hasWeapon = false;
    char temp;
    char choice1;
    char choice2;
    char choice3;
    char choice4;

    std::cout << "You there! Adventurer! Welcome to my dungeon. As you look around, you are sitting in a filthy, dark, damp dungeon.\n"
                 "On either side of you, right and left, are doors. Your quick glance at the room affords you no other information.\n"
                 "[O]bserve your surroundings\n" //gives a description of surroundings again, with more info for a higher perception (possibly)
                 "Go [L]eft!\n"                  //enters the room to the left
                 "Go [R]ight\n"                  //enters the room to the right
                 "[G]ive up\n";                    //ends the game

    while(true){

        std::cin >> choice1;

        switch (toupper(choice1))
        {
        case 'O':
            if (toupper(charClass) == 'C')
            {
                std::cout << "You are in a filthy dungeon, with a door to either side. You also notice a secret door behind you!";
            }
            else
            {
                std::cout << "You are in a filthy dungeon, with a door to either side.";
            }
            break;
        case 'L':
            std::cout << "You enter the door to the left, revealing another dark room with no doors; however, you notice a small dagger on the ground.\n"
            "[P]ick up dagger\n";

            std::cin >> choice2;

            if (toupper(choice2) == 'P')
            {
                if (playerHealth == 100)
                {
                    std::cout << "This can definitely come in handy. Good find!\n\n";
                    hasWeapon = true;
                    std::cout << "As this is a dead end, the only other way is back in the main room in the door to the [R]ight\n\n";
                }
                else
                {
                    std::cout << "Would have helped if you found this earlier, eh?\n\n";
                    hasWeapon = true;
                    std::cout << "Now you can take on that goblin, head back to the door to the [R]ight\n\n";
                }
            }
            continue;
        case 'R':
            if (playerHealth == 100 && hasWeapon == true)
            {
                std::cout << "You return to the main room and go through the right door.\n"
                "You see a disgusting-looking goblin, hunched over, facing the other direction.\n"
                "You quickly decide on what to do: \n"
                "[I]nteract with the goblin and ask for help\n"
                "[A]ttack goblin";
                
                std::cin >> temp;
                if (toupper(temp) == 'I')
                {
                    std::cout << " 'Hello..?', you say cautiously. 'Do you know how to get out of here?' \n" // Add more dialogue from goblin
                    "The goblin slashes you, causing you to fall over. You lose 15 health\n";
                    playerHealth -= 15;
                    std::cout << "You quickly get up, leaving your only choice to fight back and defend yourself\n"
                    "You take the dagger and throw it at the goblin, nailing it right in the head!\n"
                    "'Damn, I'm good', you say with a smirk.\n"
                    "You go to pull the dagger out of the goblin; however, it breaks, leaving the blade still inside the goblin's skull.\n";
                    //Add next choice
                }
                if (toupper(temp) == 'A')
                {
                    std::cout << "You stab the goblin in the back, causing it to fall to the ground.\n"
                    "You pull the dagger out and stab it once again, this time in the head just to be sure.\n"
                    "When you pull the dagger out, only the handle remains; the blade is stuck in the goblins skull.\n"
                    "'Well at least the goblin is the dead one, not me', you say in relief.";
                    //Add next choice
                }
                break;
            }
            else if (playerHealth == 100 && hasWeapon == false)
            {
                std::cout << "You enter the right door and see a disgusting-looking goblin, hunched over, facing the other direction.\n"
                "With no other option, you decide to: \n"
                "[I]nteract with the goblin and ask for help\n";
                std::cin >> temp;
                if (toupper(temp) == 'I'){
                    std::cout << " 'Hello..?', you say cautiously. 'Do you know how to get out of here?' \n" // Add more dialogue from goblin
                    "The goblin slashes you, causing you to fall over. You lose 15 health\n"
                    "The goblin goes in for another strike but you quickly get up and run back to the main room\n";
                    playerHealth -= 15;
                    std::cout << "Player Health: " << playerHealth << "\n\n";
                    std::cout << "Now that you're back in the main room, try looking in the door to the [L]eft\n";
                }
                continue;
            }
            else
            {
                std::cout << "You return to the main room and go back through the right door.\n"
                "You approach the goblin, this time being better prepared. Again, it is hunched over, facing the other direction.\n"
                "Before the goblin turns around, you attack: \n"
                "[A]ttack goblin";
                std::cin >> temp;
                if (toupper(temp) == 'A')
                {
                    std::cout << "You stab the goblin in the back, causing it to fall to the ground.\n"
                    "You pull the dagger out and stab it once again, this time in the head just to be sure.\n"
                    "When you pull the dagger out, only the handle remains; the blade is stuck in the goblins skull.\n"
                    "'Well at least the goblin is the dead one, not me', you say in relief.";
                    //Add next choice
                }
                break;
            }
            
        
        }
        break;
    }
}