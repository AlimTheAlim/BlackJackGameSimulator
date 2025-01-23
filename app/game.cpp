/** 
 * @file Card.cpp
 * @author Alim Aminev
 * @brief This is the definition file for a playing card game where players try to reach a certain threshold score without exceeding it.
 * @version 0.1
 * @date 2024-10-04
 *
 * @copyright AlimTheSuperDeveloper
 */

#include <iostream>
#include <vector>
#include "../inc/player.h"
#include "../inc/Deck.h"

using namespace chants;

/** 
 * @brief Main function to run the card game.
 * 
 * This function initiates a game by allowing users to specify the number of players and the threshold for winning. 
 * Each player is then dealt cards until they reach the threshold or "bust" (i.e., exceed a score of 21). 
 * The program determines the winner(s) based on the highest score under the threshold.
 */
int main() {
    // Prompt for the number of players in the game
    cout << "Enter number of Players: ";
    string number_player; ///< String to hold the input for number of players.
    cin >> number_player; ///< Input from user for number of players.
    
    int _number_player = stoi(number_player); ///< Convert string to integer for the number of players.
    
    vector <Player> players;   ///< Vector to hold the player objects.
    Deck deck; ///< The deck object for dealing cards.
    
    string threshold; ///< String to hold the threshold score input for each player.
    
    // Prompt for threshold score value
    cout << "Enter threshold for Players " << ": ";
    cin >> threshold; ///< Input from user for the threshold score.
    
    int _threshold = stoi(threshold); ///< Convert string threshold input to integer.

    /** 
     * @brief Loop to create each player and assign a name.
     * 
     * This loop iterates through the number of players and asks for each player's name.
     * The player object is then created with the provided name and threshold score.
     */
    for (int i = 0; i < _number_player; i++) {
        string name; ///< String variable to hold each player's name.

        // Prompt for player name
        cout << "Enter name for Player " << (i + 1) << ": ";
        cin >> name; ///< Input player's name.

        // Create a new Player object with name and threshold, then add to the players vector.
        Player player(name, _threshold);
        players.push_back(player);
    }

    /** 
     * @brief Deal cards to each player until their score meets or exceeds the threshold.
     * 
     * This loop iterates through each player, adding cards from the deck until their score
     * reaches the specified threshold.
     */
    for (int k = 0; k < _number_player; k++) {
        while (players[k].Score() < _threshold) {   
            players[k].AddCard(deck.DealCards()); ///< Add a card to the player's hand.
        }
    }

    /** 
     * @brief Check if any player has "busted".
     * 
     * A player is considered "busted" if their score exceeds 21. This loop checks each player
     * and sets their `isBusted` flag to true if their score is greater than 21.
     */
    for (int k = 0; k < _number_player; k++) {
        if (players[k].Score() > 21) {
            players[k].isBusted = true; ///< Set isBusted flag to true if score exceeds 21.
        }
    }

    /** 
     * @brief Find the maximum score among non-busted players.
     * 
     * This loop iterates through all players and tracks the highest score among players
     * who have not busted.
     */
    int maxScore = 0; ///< Variable to hold the highest score.
    for (int k = 0; k < _number_player; k++) {
        if (!players[k].isBusted) {
            if (players[k].Score() > maxScore) {
                maxScore = players[k].Score(); ///< Update maxScore if player's score is higher.
            }
        }
    }

    /** 
     * @brief Print player names, their scores, and their cards.
     * 
     * This section displays the names, scores, and the cards each player has in their hand.
     */
    for (int k = 0; k < _number_player; k++) {
        cout << "Player Name: " << players[k].GetName() << "    " << "Player Score: " << players[k].Score() << endl;
        cout << players[k].GetName() << "'s Cards:" << endl;

        // Loop through each player's cards and print them
        for (int i = 0; i < players[k].NumberCards(); i++) {
            cout << "   " << players[k].GetCard(i).ToString() << endl; ///< Print each card in player's hand.
        }
    }

    /** 
     * @brief Identify and print the winner(s).
     * 
     * This loop checks for players who have the maximum score and have not busted, then prints their name as the winner.
     */
    for (int k = 0; k < _number_player; k++) {
        if (!players[k].isBusted && players[k].Score() == maxScore) {
            cout << players[k].GetName() << " is the Winner!" << endl; ///< Declare the winner.
        }
    }

    /** 
     * @brief Print who is busted.
     * 
     * This loop prints out the names of players who have busted (i.e., exceeded a score of 21).
     */
    for (int k = 0; k < _number_player; k++) {
        if (players[k].isBusted == true) {
            cout << players[k].GetName() << " is Busted!" << endl; ///< Print busted player names.
        }
    }
}
