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

#include "../inc/player.h"
#include "../inc/Card.h"
#include "../inc/Deck.h"
#include <iostream>
#include <vector>



using namespace chants;


Player::Player(std::string playerName, int playerThreshold)
    : name(playerName), threshold(playerThreshold) {

}


int Player::GetThreshold(){
        return threshold;
}

std::string Player::GetName() const {
    return name;  // Return the player's name
}




void Player::AddCard(Card card)
{
    _hand.push_back(card);
}


string Player::ShowHand()
{
    for(int i = 0; i <= _hand.size(); i++)
    {
        _hand[i].isFaceUp = true;
    }
    return 0;
}

void Player::EmptyHand(){
    if(_hand.size()==0)
    {
            cout << "emptyhand" << endl;
    }
}


int Player::CountCards(){
        int AmountOfCards;
        AmountOfCards = _hand.size();
        return AmountOfCards;
}
    
int Player::Score(){
    int TotalScore = 0;
    for(Card card:_hand)
    {           
        int _Score;
        _Score = card.GetValue();
        TotalScore = TotalScore + _Score;
        }
    if (TotalScore > 21){
        for (int i = 0; i < _hand.size(); i++)
        {
            if(_hand[i].GetValue()==11)
            {
                TotalScore -= 10;
            }
        }
    }
    return TotalScore;
    }

void Player::FlipCard(int)
{

    int i;
    cin >> i;
    _hand[i].isFaceUp = !_hand[i].isFaceUp;  
}

void Player::FlipAllCards(bool faceUp)
{
    for (int i =0; i <= _hand.size(); i++)
    {
        _hand[i].isFaceUp = !_hand[i].isFaceUp;

    }
            
}

Card Player::GetCard(int i)
{
    return _hand[i];
}

int Player::NumberCards(){
    return _hand.size();
}


