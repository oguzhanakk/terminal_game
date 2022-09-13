import random
import time

#Roulette-Game
def Roulette_Application(incoming_money):
    print("\nWelcome to the Roulette Game...")
    time.sleep(1)

    money_to_play = int(input("Enter how many cash you want to play: "))

    if (incoming_money < money_to_play):
        print("The money you want to play is more than your balance.")
        return incoming_money

    Remaining_money = incoming_money - money_to_play

    Incoming_top = random.randint(1, 36)

    action1 = int(input('If your income is between 1-18 (1), if you are between 18-36 if you are income (2), if you are between 1-12 with your income (3), if you are between 13-24 incomes (4) , if you are between 25-36 incomes (5): '))

    print("\nThe ball is drawn...\n")
    time.sleep(3)

    if (action1 == 1 and Incoming_top <= 18 and Incoming_top >= 1):
        print('Incoming ball =', Incoming_top, 'Congratulations, you won.')
        time.sleep(3)
        Remaining_money += (money_to_play * 2)
        print('Your remaining money: ', Remaining_money, "Tl")
        time.sleep(2)
        return Remaining_money

    elif (action1 == 2 and Incoming_top <= 36 and Incoming_top >= 18):
        print('Incoming ball =', Incoming_top, 'Congratulations, you won.\n')
        time.sleep(3)
        Remaining_money += (money_to_play * 2)
        print('Your remaining money: ', Remaining_money, "tl")
        time.sleep(2)
        return Remaining_money

    elif (action1 == 3 and Incoming_top <= 12 and Incoming_top >= 1):
        print('Incoming ball =', Incoming_top, 'Congratulations, you won.\n')
        time.sleep(3)
        Remaining_money += (money_to_play * 3)
        print('Your remaining money: ', Remaining_money, "tl")
        time.sleep(2)
        return Remaining_money

    elif (action1 == 4 and Incoming_top <= 24 and Incoming_top >= 13):
        print('Incoming ball =', Incoming_top, 'Congratulations, you won.\n')
        time.sleep(3)
        Remaining_money += (money_to_play * 3)
        print('Your remaining money: ', Remaining_money, "tl")
        time.sleep(2)
        return Remaining_money

    elif (action1 == 5 and Incoming_top <= 36 and Incoming_top >= 25):
        print('Incoming ball =', Incoming_top, 'Congratulations, you won.\n')
        time.sleep(3)
        Remaining_money += (money_to_play * 3)
        print('Your remaining money: ', Remaining_money, "tl")
        time.sleep(2)
        return Remaining_money

    else:
        print('Incoming ball =', Incoming_top, 'Unfortunately you didnt win.')
        time.sleep(3)
        print('Your remaining money: ', Remaining_money, "tl")
        time.sleep(2)
        return Remaining_money


#Blackjack game
def Blackjack_Application(Incoming_moneyy):
    Dealer_hand = []
    Player_hand = []

    print("\nWelcome to BlackJack Game...")
    time.sleep(3)

    Money_play = int(input("Enter how many cash you want to play: "))

    if (Incoming_moneyy < Money_play):
        print("The money you want to play is more than your balance.")
        return Incoming_moneyy

    Remaining_moneyy = Incoming_moneyy - Money_play

    time.sleep(1.3)

    print("The 1st card is drawn into the cashier.")
    time.sleep(2)
    Dealer_hand.append(random.randint(1, 11))
    print("First card drawn into the dealer: ", Dealer_hand[0], "\n")
    time.sleep(4)

    print("1st card is drawn to you.")
    time.sleep(2)
    Player_hand.append(random.randint(1, 11))
    print("The first card drawn to you: ", Player_hand[0], "\n")
    time.sleep(4)

    print("A second card is drawn to you.")
    time.sleep(2)
    Player_hand.append(random.randint(1, 10))
    print("The second card drawn to you: ", Player_hand[1], "\n")
    time.sleep(4)

    print("Total of your hands: ", sum(Player_hand))
    time.sleep(3)

    if ((Player_hand[0] + Player_hand[1]) == 21):
        print("Congratulations, you've made BlackJack.")
        Remaining_moneyy += (Money_play * (2.5))
        print("Your remaining money: ", Remaining_moneyy)
        return Remaining_moneyy

    i = 2
    a = 1

    while True:
        card_draw_answer = int(input("Would you like to draw a card? If yes, (1), if no (2): "))

        if (card_draw_answer == 1):

            print("\n{} to the user. card is drawn...".format(i + 1))
            time.sleep(3)

            Player_hand.append(random.randint(1, 10))

            print("{}. The card you have drawn is {} . Total of your hand : {} ".format(i + 1, Player_hand[i], sum(Player_hand)))
            time.sleep(2)

            i += 1

            if (sum(Player_hand) > 21):
                print("\ntotal of your hand", sum(Player_hand), "Unfortunately, you're screwed.\n")
                print("Your remaining money: ", Remaining_moneyy, "Tl")
                return Remaining_moneyy

        if (card_draw_answer == 2):
            print("\nThe first card drawn by the dealer",Dealer_hand[0])

            while True:

                print("To the vault {}. card is drawn...".format(a + 1))
                time.sleep(3)

                Dealer_hand.append(random.randint(1, 10))

                print("The case {}. drawn card {}. Dealer's hand total : {} \n".format(a + 1, Dealer_hand[a],
                                                                                       sum(Dealer_hand)))
                time.sleep(2)

                if (sum(Dealer_hand) > 21):
                    print("Dealer's hand total : {} \n".format(sum(Dealer_hand)))
                    time.sleep(3)
                    print("Congratulations, the safe has sunk.\n")

                    Remaining_moneyy += (Money_play * 2)
                    print("Your remaining money: ", Remaining_moneyy)
                    return Remaining_moneyy

                if (sum(Dealer_hand) <= 21 and sum(Dealer_hand) >= 17):

                    if (sum(Dealer_hand) > sum(Player_hand)):
                        print("The dealer's hand is {} , Your hand is {} Unfortunately, you lost.\n".format(sum(Dealer_hand),
                                                                                                            sum(Player_hand)))
                        print("Your remaining money: ", Remaining_moneyy)
                        return Remaining_moneyy

                    if (sum(Dealer_hand) < sum(Player_hand)):
                        print("Dealer's hand {} , Your hand {} Congratulations you won.\n".format(sum(Dealer_hand),
                                                                                                  sum(Player_hand)))
                        Remaining_moneyy += (Money_play * 2)
                        print("Your remaining money: ", Remaining_moneyy)
                        return Remaining_moneyy

                    if (sum(Dealer_hand) == sum(Player_hand)):
                        print("Dealer's hand is {} , Your hand is {} Tied.\n".format(sum(Dealer_hand),
                                                                                     sum(Player_hand)))
                        Remaining_moneyy += (Money_play)
                        print("Your remaining money: ", Remaining_moneyy)
                        return Remaining_moneyy

                a += 1