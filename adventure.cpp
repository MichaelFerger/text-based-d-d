//this is a comment so I can make sure when I commit, you guys receive this as well

#include <iostream>

using namespace std;

int main()
{
    //on load, we ask what class they are choosing
    cout << "What character class are you playng?\n"
            "[R]ogue\n"
            "[F]ighter\n"
            "[C]leric";

    char class;
    cin >> class;

    switch (toupper(class))
    {
    case 'R':
        cout << "Ah, a sneaky bastard I see.";
        break;
    case 'F':
        cout << "Fancy yourself a strong man, eh?";
        break;
    case 'C':
        cout << "Oh, so now you're all high-and-mighty, mister magic man.";
        break;
    default:
        cout << "You did not input a capital letter representing your chosen class. TRY AGAIN.";
        break;
    }
}