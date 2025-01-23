/**
 * @file Card.cpp
 * @author Alim Aminev
 * @brief This is the definition file for a playing Card.
 * @version 0.1
 * @date 2024-10-4
 *
 * @copyright AlimTheSuperDeveloper
 *
 */
#include "../inc/Deck.h"
#include "../inc/Card.h"
#include <stdexcept>
#include <vector>
#include <ctime>
#include <iostream>

Deck::Deck() {
    BuildDeck();
    Shuffle(); // Build the deck when the Deck object is created
}

void Deck::BuildDeck(){
    /*
    /Nested loop creates 13 values for every of 4 suits and puts it in vector deck
    */
    for (int i = 1; i<=13; i++)
    {
        for (int j = 1; j<= 4; j++)
        {
            Card card(i,j,true);
            deck.push_back(card);
        }
    }
}

void Deck::Shuffle(){
    /*
    /seed based on time
    */
    srand(time(nullptr));
    /*
    /Is 100000 time of shuflles is enough? I hope it is
    */
    for(int i = 0; i <= 100000; i++)
    {
        /*
        /
        / Two random numbers generated that will present index of cards that beens switched
        */
        int rn1 = rand() % 53;
        int rn2 = rand() % 53;

        /*
        /temp made to hold value of card that will be replaced by other one to put it in place of itf
        */

        Card temp = deck[rn1];
        deck[rn1] = deck[rn2];
        deck[rn2] = temp;

    }
}
Card Deck::DealCards(){
    /*
/Loop func will print first four cards in the deck and eraise them
*/
{   
    Card card = deck[0];
    deck.erase(deck.begin());
    return card;

}
}
