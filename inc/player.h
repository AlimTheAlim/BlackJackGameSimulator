/** 
 * @file Card.cpp
 * @author Alim Aminev
 * @brief This is the header file for the Player class, representing a player in the card game.
 * @version 0.1
 * @date 2024-10-04
 * 
 * @copyright AlimTheSuperDeveloper
 */

#pragma once

#include <vector>
#include <string>
#include "../inc/Card.h"

using namespace std;

namespace chants {

/**
 * @class Player
 * @brief This class represents a player in the card game, including their hand of cards, score, and win/loss status.
 *
 * A Player object keeps track of the player's name, score, threshold (winning score), hand of cards, and their current status
 * (whether they are a winner or have busted). The class includes methods to manage the player's hand, calculate their score,
 * and determine if they have won or busted.
 */
class Player {
private:
    std::string name;  ///< Player's name
    int threshold;     ///< A score threshold for the player, the target to win the game
    std::vector<Card> _hand;  ///< A collection of the cards the player holds

    /**
     * @brief Calculate the total score based on the cards in the player's hand.
     * 
     * This private method is responsible for calculating the player's score based on the values of the cards in their hand.
     * It is typically used in methods like `Score()` to determine the current score of the player.
     *
     * @return int The calculated score.
     */
    int calculateScore();

public:
    bool isBusted;  ///< Flag indicating if the player has busted (score exceeds 21).
    bool isWinner;  ///< Flag indicating if the player is a winner.

    /** 
     * @brief Construct a new Player object
     * 
     * This constructor initializes a new player with a given name and score threshold. The player's hand is empty at the time of creation.
     * 
     * @param playerName The name of the player.
     * @param playerThreshold The score threshold that the player needs to reach or exceed to win.
     */
    Player(std::string playerName, int playerThreshold);

    /** 
     * @brief Get the name of the player.
     * 
     * This method returns the name of the player.
     * 
     * @return std::string The name of the player.
     */
    std::string GetName() const;

    /** 
     * @brief Get the score threshold for the player.
     * 
     * This method returns the threshold value which is the target score a player needs to reach to win the game.
     * 
     * @return int The threshold score.
     */
    int GetThreshold();

    /** 
     * @brief Add a card to the player's hand.
     * 
     * This method allows adding a `Card` object to the player's hand. It is used during gameplay to deal cards to the player.
     * 
     * @param card The `Card` object to be added to the player's hand.
     */
    void AddCard(Card card);

    /** 
     * @brief Show the cards in the player's hand as a string.
     * 
     * This method returns a string representation of the cards in the player's hand. It is typically used for displaying the hand
     * in the game.
     * 
     * @return string A string representation of the player's hand.
     */
    string ShowHand();

    /** 
     * @brief Empty the player's hand.
     * 
     * This method clears all cards from the player's hand, essentially resetting the player's state.
     */
    void EmptyHand();

    /** 
     * @brief Count the number of cards in the player's hand.
     * 
     * This method returns the number of cards currently held in the player's hand.
     * 
     * @return int The number of cards in the player's hand.
     */
    int CountCards();

    /** 
     * @brief Calculate and return the player's score.
     * 
     * This method calculates the score based on the cards in the player's hand, which is used for determining if the player has won
     * or busted.
     * 
     * @return int The player's current score.
     */
    int Score();

    /** 
     * @brief Flip a specific card in the player's hand.
     * 
     * This method allows flipping a card in the player's hand (e.g., revealing the card's face).
     * 
     * @param index The index of the card to be flipped.
     */
    void FlipCard(int index);

    /** 
     * @brief Flip all cards in the player's hand.
     * 
     * This method flips all the cards in the player's hand (e.g., revealing all cards).
     * 
     * @param faceUp A boolean value to specify whether to flip the cards face-up or face-down.
     */
    void FlipAllCards(bool faceUp);

    /** 
     * @brief Return the suit of a specific card in the player's hand.
     * 
     * This method returns the suit of a card at the given index in the player's hand.
     * 
     * @param i The index of the card in the player's hand.
     * @return string The suit of the card.
     */
    string returnSuit(int i);

    /** 
     * @brief Get a specific card from the player's hand.
     * 
     * This method allows retrieving a specific card from the player's hand by its index.
     * 
     * @param i The index of the card.
     * @return Card The `Card` object at the specified index.
     */
    Card GetCard(int i);

    /** 
     * @brief Change the value of a specific card in the player's hand.
     * 
     * This method allows changing the value of a specific card in the player's hand, useful for games like blackjack.
     * 
     * @param i The index of the card to modify.
     */
    void ChangeValue(int i);

    /** 
     * @brief Return a specific card in the player's hand as a string.
     * 
     * This method returns the string representation of a card at the given index.
     * 
     * @param i The index of the card.
     * @return string A string representing the card at the specified index.
     */
    string ReturnHand(int i);

    /** 
     * @brief Get the number of cards in the player's hand.
     * 
     * This method returns the total number of cards the player has in their hand.
     * 
     * @return int The number of cards in the player's hand.
     */
    int NumberCards();

    /** 
     * @brief Decrease the player's score by a certain amount.
     * 
     * This method is used to decrease the player's score, useful in scenarios where penalties are applied.
     */
    void DecreaseScore();
};

} // namespace chants
