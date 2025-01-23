/** 
 * @file Card.cpp
 * @author Alim Aminev
 * @brief This is the definition file for the `Deck` class, representing a deck of cards.
 * @version 0.1
 * @date 2024-10-04
 * 
 * @copyright AlimTheSuperDeveloper
 */

#pragma once

#include "Card.h"
#include <string>
#include <vector>

using namespace std;

/**
 * @class Deck
 * @brief Represents a deck of playing cards.
 *
 * The `Deck` class handles the creation, shuffling, and dealing of a standard deck of playing cards.
 * It contains a collection of `Card` objects and provides functionality to build a deck, shuffle it, and deal cards.
 */
class Deck {
private:
    std::vector<Card> deck; ///< A vector holding the `Card` objects that make up the deck.
    
    /** 
     * @brief Build the deck by adding 52 cards (standard deck).
     * 
     * This private method is used to initialize the deck with 52 cards, one for each combination of rank and suit.
     */
    void BuildDeck();

    /** 
     * @brief Shuffle the deck to randomize the order of cards.
     * 
     * This private method shuffles the cards in the deck using a randomization algorithm, ensuring that
     * the order of the cards is random for fair gameplay.
     */
    void Shuffle();

public:
    /** 
     * @brief Construct a new Deck object.
     * 
     * The constructor initializes the deck by building and shuffling the cards. When a `Deck` object is created,
     * the deck will automatically contain 52 shuffled cards, ready for dealing.
     */
    Deck();

    /** 
     * @brief Deal one card from the deck.
     * 
     * This method returns a single `Card` object from the deck and removes it from the deck.
     * 
     * @return Card The card dealt from the deck.
     */
    Card DealCards();
};
