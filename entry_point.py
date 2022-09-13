from Rulet_Blackjackk import Roulette_Application,Blackjack_Application
import time
import random
import sqlite3

#sqlite link
con = sqlite3.connect("information.db")
cursor = con.cursor()

def money_control(kullanici_ismi):
    cursor.execute("Select para From Members where kullanici_adi = ?", (User_name,))
    list = cursor.fetchall()
    print('money in your account', list[0][0], "tl")

def add_money(User_name, money):
    cursor.execute("Select para From Members where kullanici_adi = ?", (User_name,))
    list = cursor.fetchall()
    cursor.execute("Update Members set para = {} WHERE kullanici_adi = '{}'".format(money + list[0][0], User_name))
    con.commit()

print("Welcome to our casino...")

cursor.execute("CREATE TABLE IF NOT EXISTS Members(kullanici_adi TEXT, sifre TEXT, para INT)")

#game loop
while (True):

    process = int(input("If you are going to be a member = (1), if you are going to log in to your membership = (2), to log out = (3) :  "))

    if (process == 1):
        while (True):
            name = str(input("Enter your username: "))
            password = str(input("Enter your password: "))

            cursor.execute("Select kullanici_adi From Members where kullanici_adi = ?", (name,))
            username_list = cursor.fetchall()
            try:
                if (name in username_list[0]):
                    print('\nSuch a username already exists. Try again.')
                    break
            except IndexError:
                pass

            if (len(name) < 5 or len(password) < 5):
                time.sleep(2)
                print('Your username and password must be more than 5 digits.')

            else:
                time.sleep(2)
                print('Congratulations, your subscription was successful.')
                cursor.execute("Insert into Members Values(?,?,?)", (name, password, 0))
                con.commit()
                break

    if (process == 2):
        User_name = str(input("Enter your username: "))
        User_password = str(input("Enter your password: "))

        cursor.execute("Select kullanici_adi,sifre From Members where kullanici_adi = ?", (User_name,))
        list2 = cursor.fetchall()
        if ((User_name in list2[0]) and (User_password in list2[0])):
            time.sleep(1)
            print('\nWelcome.', User_name)
            money_control(User_name)

            reply = int(input("If you want to add money to the account, type (5), if you don't, press any key: "))

            if (reply == 5):
                moneyy = int(input('Write how much money you want to add to your account: '))
                add_money(User_name, moneyy)
                print('{} TL added to your account'.format(moneyy))
                time.sleep(2)

                money_control(User_name)

            else:
                money_control(User_name)
                time.sleep(2)
                print("\ngood games.", User_name)

        else:
            time.sleep(2)
            print('Your username or password has been entered incorrectly.')
            continue

        while (True):
            game_option = int(input(
                "Press (1) to play roulette, (2) to play blackjack, (3) to exit and return to the main menu: "))

            cursor.execute("Select para From Members where kullanici_adi = ?", (User_name,))
            money = cursor.fetchall()
            if (money[0][0] == 0):
                time.sleep(2)
                print("Sorry, you don't have money, add money to your membership.")
                time.sleep(1)
                answer1 = int(input("If you want to add money to the account (5) write: "))

                if (answer1 == 5):
                    moneyy = int(input('Write how much money you want to add to your account: '))

                    add_money(User_name, moneyy)

                    money_control(User_name)
                    time.sleep(2)

                else:
                    time.sleep(1)
                    print('Unfortunately, you cant play because you dont have a cash.')
                    time.sleep(2)
                    break

            elif (game_option == 1):
                Returning_Money = Roulette_Application(money[0][0])
                cursor.execute(
                    "Update Members set para = {} WHERE kullanici_adi = '{}'".format(Returning_Money, User_name))
                con.commit()

            elif (game_option == 2):
                Returning_Money = Blackjack_Application(money[0][0])
                cursor.execute(
                    "Update Members set para = {} WHERE kullanici_adi = '{}'".format(Returning_Money, User_name))
                con.commit()

            if (game_option == 3):
                break

    if (process == 3):
        time.sleep(1)
        try:
            print("\nWe are waiting for you again", User_name,'...')
        except NameError:
            print("\nWe are waiting for you again.")
        time.sleep(2)
        con.close()
        quit()