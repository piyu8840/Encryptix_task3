#include <iostream>
using namespace std;

void board(char *num)       //function to draw grids 3 * 3
{
  cout << endl;
  cout << "\t\t      |     |     " << endl;
  cout << "\t\t   " << num[0] << "  |  " << num[1] << "  |  " << num[2] << "  " << endl;
  cout << "\t\t _____|_____|_____" << endl;
  cout << "\t\t      |     |     " << endl;
  cout << "\t\t   " << num[3] << "  |  " << num[4] << "  |  " << num[5] << "  " << endl;
  cout << "\t\t _____|_____|_____" << endl;
  cout << "\t\t      |     |     " << endl;
  cout << "\t\t   " << num[6] << "  |  " << num[7] << "  |  " << num[8] << "  " << endl;
  cout << "\t\t      |     |     " << endl;
  cout << endl;
}

void player1Move(char *num, char P1, string Player1)      //funcion which takes player1 input
{
  int spot;
  do
  {
    cout << Player1 << "'s  turn ! [X]" << endl;
    cout << "Enter the spot you want to occupy (1 - 9) : ";
    cin >> spot;
    spot--;
    if (spot < 0 || spot > 8)
    {
      cout << "Invalid spot. Please choose a spot between 1 and 9." << endl;
      continue;
    }
    if (num[spot] == ' ')
    {
      num[spot] = P1;
      break;
    }
    else
    {
      cout << "Spot already occupied. Please choose another spot." << endl;
    }
  } while (true);
}

void player2Move(char *num, char P2, string Player2)      //function which takes player2 input
{
  int spot;
  do
  {
    cout << Player2 << "'s  turn ! [O]" << endl;
    cout << "Enter the spot you want to occupy (1 - 9) : ";
    cin >> spot;
    spot--;
    if (spot < 0 || spot > 8)
    {
      cout << "Invalid spot. Please choose a spot between 1 and 9." << endl;
      continue;
    }
    if (num[spot] == ' ')
    {
      num[spot] = P2;
      break;
    }
    else
    {
      cout << "Spot already occupied. Please choose another spot." << endl;
    }
  } while (true);
}

bool checkwinner(char *num, char P1, char P2, string Player1, string Player2)   //function which checks the winner and loser
{
  if (num[0] != ' ' && num[0] == num[1] && num[1] == num[2])
  {
    if (num[0] == P1)
    {
      cout << "Congratulations ! " << Player1 << "  Win ! " << endl;
    }
    else
    {
      cout << "Congratulations ! " << Player2 << "  Win ! " << endl;
    }
  }

  else if (num[3] != ' ' && num[3] == num[4] && num[4] == num[5])
  {
    if (num[3] == P1)
    {
      cout << "Congratulations ! " << Player1 << "  Win ! " << endl;
    }
    else
    {
      cout << "Congratulations ! " << Player2 << "  Win ! " << endl;
    }
  }

  else if (num[6] != ' ' && num[6] == num[7] && num[7] == num[8])
  {
    if (num[6] == P1)
    {
      cout << "Congratulations ! " << Player1 << "  Win ! " << endl;
    }
    else
    {
      cout << "Congratulations ! " << Player2 << "  Win ! " << endl;
    }
  }

  else if (num[0] != ' ' && num[0] == num[3] && num[3] == num[6])
  {
    if (num[0] == P1)
    {
      cout << "Congratulations ! " << Player1 << "  Win ! " << endl;
    }
    else
    {
      cout << "Congratulations ! " << Player2 << "  Win ! " << endl;
    }
  }

  else if (num[1] != ' ' && num[1] == num[4] && num[4] == num[7])
  {
    if (num[1] == P1)
    {
      cout << "Congratulations ! " << Player1 << "  Win ! " << endl;
    }
    else
    {
      cout << "Congratulations ! " << Player2 << "  Win ! " << endl;
    }
  }

  else if (num[2] != ' ' && num[2] == num[5] && num[5] == num[8])
  {
    if (num[2] == P1)
    {
      cout << "Congratulations ! " << Player1 << "  Win ! " << endl;
    }
    else
    {
      cout << "Congratulations ! " << Player2 << "  Win ! " << endl;
    }
  }

  else if (num[0] != ' ' && num[0] == num[4] && num[4] == num[8])
  {
    if (num[0] == P1)
    {
      cout << "Congratulations ! " << Player1 << "  Win ! " << endl;
    }
    else
    {
      cout << "Congratulations ! " << Player2 << "  Win ! " << endl;
    }
  }

  else if (num[2] != ' ' && num[2] == num[4] && num[4] == num[6])
  {
    if (num[2] == P1)
    {
      cout << "Congratulations ! " << Player1 << "  Win ! " << endl;
    }
    else
    {
      cout << "Congratulations ! " << Player2 << "  Win ! " << endl;
    }
  }

  else
  {
    return false;
  }

  return true;
}

bool tie(char *num)  //function which checks whether its tie or not.
{
  for (int i = 0; i < 9; i++)
  {
    if (num[i] == ' ')
    {
      return false;
    }
  }

  cout << "Oops ! It's a Tie. Try Again ! !" << endl;
  return true;
}

int main()
{
  cout << endl;
  cout << "\t\t\t WELCOME TO TIC TAC TOE GAME  " << endl;
  cout << endl;

  string Player1, Player2;
  cout << "Enter name of the Player1 : ";
  cin >> Player1;
  cout << "Enter name of the Player2 : ";
  cin >> Player2;
  cout << endl;
  cout << "Player1 = " << Player1 << "\t[X]" << endl;
  cout << "Player2 = " << Player2 << "\t[O]" << endl;

  int again;
  char P1 = 'X';         //Assigning player1 with symbol 'X'
  char P2 = 'O';         //Assigning player2 with symbol 'O'
  bool PlayAgain = true;  //it helps user to repeat the game

  while (PlayAgain)
  {
    char num[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    bool gaming = true;
    board(num);

    while (gaming)
    {
      player1Move(num, P1, Player1);
      board(num);

      if (checkwinner(num, P1, P2, Player1, Player2) == true)
      {
        gaming = false;
        break;
      }
      else if (tie(num) == true)
      {
        gaming = false;
        break;
      }

      player2Move(num, P2, Player2);
      board(num);
      if (checkwinner(num, P1, P2, Player1, Player2) == true)
      {
        gaming = false;
        break;
      }
      else if (tie(num) == true)
      {
        gaming = false;
        break;
      }
    }
    cout << "Press 1 to play again (or) Press 0 to end the game : ";

    cin >> again;

    if (again == 1)
    {
      PlayAgain = true;
    }
    else
    {
      PlayAgain = false;
    }
  }

  return 0;
}