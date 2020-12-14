#include <iostream>
using namespace std;

int main()
{
    //on load, we ask what class they are choosing
    std::cout << "When playing this game, enter the capital letter in brackets of the corresponding choice you would like to make.\n"
                 "What character class are you playng?\n"
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

    bool hasPotion = false;
    char temp;
    char choice1;
    char choice2;
    char choice3;
    char choice4;

    std::cout << "You there! Adventurer! Welcome to my dungeon. As you look around, you are sitting in a filthy, dark, damp dungeon.\n"
                 "On either side of you, right and left, are doors. Your quick glance at the room affords you no other information.\n"

                 "[O]bserve your surroundings\n" //gives a description of surroundings again, with more info for a higher perception (possibly)
                 "Go [L]eft!\n"                  //enters the room to the left
                 "Go [R]ight!\n";                 //enters the room to the right

    while (true)
    {

        std::cin >> choice1;

        switch (toupper(choice1))
        {
        case 'O':
            if (toupper(charClass) == 'C')
            {
                std::cout << "You are in a filthy dungeon, with a door to either side. You also notice a secret door behind you!\n"
                             "Go [L]eft.\n"
                             "Go [R]ight.\n"
                             "[I]nvestigate the secret door\n";
            }
            else
            {
                std::cout << "You are in a filthy dungeon, with a door to either side.\n"
                             "Go [L]eft.\n"
                             "Go [R]ight.\n";
            }
            continue;
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
                    std::cout << "As this is a dead end, the only other way is back in the main room in the door to the [R]ight\n";
                }
                else
                {
                    std::cout << "Would have helped if you found this earlier, eh?\n\n";
                    hasWeapon = true;
                    std::cout << "Now you can take on that goblin, head back to the door to the [R]ight\n";
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
                             "[A]ttack goblin\n";

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
                    hasWeapon = false;
                    //Add next choice
                }
                if (toupper(temp) == 'A')
                {
                    std::cout << "You stab the goblin in the back, causing it to fall to the ground.\n"
                                 "You pull the dagger out and stab it once again, this time in the head just to be sure.\n"
                                 "When you pull the dagger out, only the handle remains; the blade is stuck in the goblins skull.\n"
                                 "'Well at least the goblin is the dead one, not me', you say in relief.\n";
                    hasWeapon = false;
                    std::cout << "You notice a door across the room. You approach it, stepping over the goblin's body on the ground.\n"
                                 "[O]pen the door.\n";

                    std::cin >> temp;
                    if (toupper(temp) == 'O')
                    {
                        if (charClass == 'R')
                        {
                            std::cout << "Your danger-sense allows you to nimbly dodge out of the way, as arrows fly out from the wall at you.\n"
                                         "That was close, you think to yourself. Eyeing the room for more traps, you enter, to notice a short sword in the corner.\n"
                                         "[P]ick up the shortsword.\n";
                            std::cin >> temp;
                        }
                        else
                        {
                            std::cout << "As you open the door, arrows fly out of the wall from across the next room.\n"
                                         "One catches you on the shoulder, and you shrug off the pain.\n";
                                         playerHealth -= 25;
                                         std::cout << "Player Health: " << playerHealth << "\n\n"
                                         "Checking for more traps as you enter, you notice a shortsword in the corner of this room.\n"
                                         "[P]ick up the shortsword.\n";
                            
                            std::cin >> temp;
                        }
                        hasWeapon = true;

                        std::cout << "You see only one door ahead of you, and the glow of a fire shines from beneath the oak door.\n"
                                     "You can hear someone whistling from the other side.\n"
                                     "[K]nock on the door\n"
                                     "[O]pen the door\n";

                        std::cin >> temp;

                        if (toupper(temp) == 'K')
                        {
                            std::cout << "'Huh? Hello? Hang on just a minute I'm coming.' A gruff voice calls out from the other side of the door.\n"
                                         "The door opens to reveal a very muscular looking orc, and a fire with a spit over it, roasting some unidentifiable creature.\n"
                                         "'I am the keeper of the door to this dungeon. You cannot escape without first challenging and defeating me.'\n"
                                         "Challenge him to [C]ombat\n"
                                         "Challenge him to an [A]rm wrestling constest\n"
                                         "Challenge him to a [D]ance-Off.\n";
                            std::cin >> temp;
                        }
                        else
                        {
                            std::cout << "The door opens to reveal a very muscular looking orc, and a fire with a spit over it, roasting some unidentifiable creature.\n"
                                         "'I am the keeper of the door to this dungeon. You cannot escape without first challenging and defeating me.'\n"
                                         "Challenge him to [C]ombat\n"
                                         "Challenge him to an [A]rm wrestling constest\n"
                                         "Challenge him to a [D]ance-Off.\n";
                            std::cin >> temp;
                        }

                        if (toupper(temp) == 'C')
                        {
                            std::cout << "You arm yourself with the shortsword, and he snarls, bearing his misshapen, gnarly teeth and brandishing a very large axe.\n"
                                         "After a long, and arduous battle, the orc falls to the ground, dead. You've won your freedom.\n"
                                         "You notice the key around his neck, and take it. You insert it into the door, and turn the key. It opens.\n"
                                         "You're free.";
                        }
                        else if (toupper(temp) == 'A')
                        {
                            std::cout << "You size up the large orc, and smile. You could take him, but why fight him? You know how to beat him."
                                         "'I challenge you to an arm wrestling contest.' You declare, a little boasty. He laughs heartily.\n"
                                         "'You've got moxy, puny human. I will accept this challenge of strength.' he says, gesturing to his dining table off to the side of the room.";
                            if (charClass == 'F')
                            {
                                std::cout << "You sit down at the table, and ready yourself. You've trained your whole life for this, feats of strength are your thing.\n"
                                             "It's a longer fight than you're used to, you both teeter and waver as you strain to keep your hand up. You can see his strength waiver.\n"
                                             "You muster all of your strength, and finally, you slam the back of his meaty fist onto the tabletop. You've won.\n"
                                             "'I suppose you'll be needing this, not-so-puny human.' He hands you a key from around his neck. You insert it into the door, and turn the key. It opens.\n"
                                             "You're free.";
                            }
                            else
                            {
                                std::cout << "You sit down at the table, and the orc flexes his massive forearm. You ready yourself, and within 5 seconds of starting, the back of your hand hits the table.\n"
                                             "You realize what this means. You lost. Unsure what he will do next, you don't wait to find out. You unsheath your sword, and plunge it into the orc's chest.\n"
                                             "He recoils, screaming. The orc snarls, bearing his misshapen, gnarly teeth and brandishing a very large axe.\n"
                                             "After a long, and arduous battle, the orc falls to the ground, dead. You've won your freedom.\n"
                                             "You notice the key around his neck, and take it. You insert it into the door, and turn the key. It opens.\n"
                                             "You're free.";
                            }
                        }
                        else
                        {
                            std::cout << "'I challenge you... to a dance-off!' you announce. The orc looks at you, puzzled. ";
                        }
                    }
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
                if (toupper(temp) == 'I')
                {
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
                             "[A]ttack goblin\n";

                std::cin >> temp;
                if (toupper(temp) == 'A')
                {
                    std::cout << "You stab the goblin in the back, causing it to fall to the ground.\n"
                                 "You pull the dagger out and stab it once again, this time in the head just to be sure.\n"
                                 "When you pull the dagger out, only the handle remains; the blade is stuck in the goblins skull.\n"
                                 "'Well at least the goblin is the dead one, not me', you say in relief.\n";

                    //Add next choice
                }
                break;
            }
        case 'I':
            if (playerHealth == 100)
            {
                cout << "You discover a dimly lit room behind the secret door, with shelves upon shelves of potions.\n"
                        "You grab the only labeled one, a health potion. Should come in handy. You return to the previous room.\n"
                        "Go [L]eft.\n"
                        "Go [R]ight.\n";
                hasPotion = true;
            }
            else if (playerHealth != 100)
            {
                cout << "You discover a dimly lit room behind the secret door, with shelves upon shelves of potions.\n"
                        "You grab the only labeled one, a health potion. Bottoms up! You return to the previous room, healed and ready.\n"
                        "Go [L]eft.\n"
                        "Go [R]ight.\n";
                playerHealth += 20;
            }
            continue;
        }
        break;
    }
}