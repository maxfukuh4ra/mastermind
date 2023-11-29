//
//  main.cpp
//  Mastermind
//
//  Created by Howard Stahl on 9/21/22.
//

#include <iostream>
#include "Random.h"
#include "Piece.h"
#include "Board.h"
#include "Score.h"
#include "Settings.h"
#include "Enums.h"
#include "Mastermind.h"


int main( ) {
    using namespace cs31;
    using namespace std;

//  Choose a random answer...
    Mastermind game;
    bool forceEnd = false;
    std::string action, turn, message = "(p)lay (q)uit: ";
    cout << game.display( message ) << endl;

    do
    {
        getline( cin, action );
        while (action.size() == 0)
        {
            getline( cin, action );  // no blank entries allowed....
        }
        switch (action[0])
        {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                forceEnd = true;
                break;
            case 'p':
            case 'P':
                if (game.determineGameOutcome() == GAMENOTOVER)
                {
                    getline( cin, turn );
                    Move m = game.play( turn );

                    if (m.isValid())
                    {
                        Score s = game.endRound(m);
                        s.isExactMatch();  // just to avoid warning...
                    }
                    else
                    {
                        // turn was not a valid word
                        cout << turn << " was not a Mastermind game entry!" << endl;
                    }
                }
                break;
        }
        if (!game.gameIsOver())
        {
            cout << game.display( message ) << endl;
        }
        else
        {
            cout << game.display( game.gameOutcomeAsString() ) << endl;
            cout << "The winning Mastermind game entry was: " << game.answer() << endl;
        }
    } while( !game.gameIsOver() && !forceEnd );

    return( 0 );
}
//
//
//#include "Board.h"
//#include "Mastermind.h"
//#include "Piece.h"
//#include "Move.h"
//#include "Score.h"
//#include "Random.h"
//#include <iostream>
//#include <string>
//#include <cassert>
//using namespace std;
//using namespace cs31;
//
//
//void testone(int n)
//{
//
//    Random r;
//    Piece p;
//    Move m;
//    Move playedMove;
//    Move theAnswer;
//    bool good;
//    Score s;
//    Board b;
//    Mastermind game;
//
//    switch (n)
//    {
//        // test code for Random
//        case  1:
//          for (int i = 1; i <= 100; i++ )
//          {
//             r.random();
//             int value = r.getValue();
//             assert( value >=0 && value <= 25 );
//          }
//          break;
//
//        // test code for Piece
//        case  2:
//          p = Piece( 'b' );
//          assert( p.getColor() == BLUE );
//          assert( p.getColorAsString() == "B" );
//          break;
//
//        case  3:
//          p = Piece( "YELLOW" );
//          assert( p.getColor() == YELLOW );
//          assert( p.getColorAsString() == "Y" );
//          break;
//
//        case  4:
//          p = Piece( GREEN );
//          assert( p.getColor() == GREEN );
//          assert( p.getColorAsString() == "G" );
//          break;
//
//        case  5:
//          assert( p.getColor() == NOTVALID );
//          assert( p.getColorAsString() == " " );
//          break;
//
//        // test code for Move
//        case  6:
//          // by default, pieces are invalid
//          p = m.getPiece( 0 );
//          assert(p.getColor() == NOTVALID );
//          p = m.getPiece( 1 );
//          assert(p.getColor() == NOTVALID );
//          p = m.getPiece( 2 );
//          assert(p.getColor() == NOTVALID );
//          p = m.getPiece( 3 );
//          assert(p.getColor() == NOTVALID );
//          break;
//
//        case  7:
//          good = true;
//          // when out of range, throw logic error
//          try {
//              p = m.getPiece( -10 );
//              good = false;
//          } catch( std::logic_error ) {
//
//          }
//          try {
//              p = m.getPiece( 10 );
//              good = false;
//          } catch( std::logic_error ) {
//
//          }
//          assert( good );
//          break;
//
//        case  8:
//          m.setPieces( "grby" );
//          p = m.getPiece( 0 );
//          assert(p.getColor() == GREEN );
//          p = m.getPiece( 1 );
//          assert(p.getColor() == RED );
//          p = m.getPiece( 2 );
//          assert(p.getColor() == BLUE );
//          p = m.getPiece( 3 );
//          assert(p.getColor() == YELLOW );
//          assert( m.to_string() == "GRBY" );
//          break;
//
//        case  9:
//          m.setPiece( 0, 'p' );
//          m.setPiece( 1, 'o' );
//          m.setPiece( 2, 'y' );
//          m.setPiece( 3, 'g' );
//
//          p = m.getPiece( 0 );
//          assert(p.getColor() == PURPLE );
//          p = m.getPiece( 1 );
//          assert(p.getColor() == ORANGE );
//          p = m.getPiece( 2 );
//          assert(p.getColor() == YELLOW );
//          p = m.getPiece( 3 );
//          assert(p.getColor() == GREEN );
//          assert( m.to_string() == "POYG" );
//          break;
//
//        case  10:
//          m.setPiece( 0, "O" );
//          m.setPiece( 1, "O" );
//          m.setPiece( 2, "P" );
//          m.setPiece( 3, "P" );
//
//          p = m.getPiece( 0 );
//          assert(p.getColor() == ORANGE );
//          p = m.getPiece( 1 );
//          assert(p.getColor() == ORANGE );
//          p = m.getPiece( 2 );
//          assert(p.getColor() == PURPLE );
//          p = m.getPiece( 3 );
//          assert(p.getColor() == PURPLE );
//          assert( m.to_string() == "OOPP" );
//          break;
//
//        case 11:
//          p = Piece( 'b' );
//          m.setPiece( 0, p );
//          p = Piece( 'r' );
//          m.setPiece( 1, p );
//          m.setPiece( 2, p );
//          p = Piece( 'g' );
//          m.setPiece( 3, p );
//
//          p = m.getPiece( 0 );
//          assert(p.getColor() == BLUE );
//          p = m.getPiece( 1 );
//          assert(p.getColor() == RED );
//          p = m.getPiece( 2 );
//          assert(p.getColor() == RED );
//          p = m.getPiece( 3 );
//          assert(p.getColor() == GREEN );
//          assert( m.to_string() == "BRRG" );
//          break;
//
//        case 12:
//          // by default, score is wrong
//          assert( s.isExactMatch() == false );
//          assert( s.getAnswer( 0 ) == WRONG );
//          assert( s.getAnswer( 1 ) == WRONG );
//          assert( s.getAnswer( 2 ) == WRONG );
//          assert( s.getAnswer( 3 ) == WRONG );
//          break;
//
//        case 13:
//          good = true;
//          // when out of range, throw logic error
//          try {
//              s.getAnswer( -10 );
//              good = false;
//          } catch( std::logic_error ) {
//
//          }
//
//          try {
//              s.getAnswer( 10 );
//              good = false;
//          } catch( std::logic_error ) {
//
//          }
//          assert( good );
//          break;
//
//        case 14:
//          playedMove.setPieces( "GRBY" );
//          theAnswer.setPieces( "grby" );
//          s = Score( playedMove, theAnswer );
//          assert( s.isExactMatch() == true );
//          assert( s.to_string() == "RRRR" );
//          assert( s.getAnswer( 0 ) == RIGHT );
//          assert( s.getAnswer( 1 ) == RIGHT );
//          assert( s.getAnswer( 2 ) == RIGHT );
//          assert( s.getAnswer( 3 ) == RIGHT );
//          break;
//
//        case 15:
//          playedMove.setPieces( "grby" );
//          theAnswer.setPieces( "opop" );
//          s = Score( playedMove, theAnswer );
//          assert( s.isExactMatch() == false );
//          assert( s.to_string() == "____" );
//          assert( s.getAnswer( 0 ) == WRONG );
//          assert( s.getAnswer( 1 ) == WRONG );
//          assert( s.getAnswer( 2 ) == WRONG );
//          assert( s.getAnswer( 3 ) == WRONG );
//          break;
//
//        case 16:
//          playedMove.setPieces( "grpo" );
//          theAnswer.setPieces( "rgrg" );
//          s = Score( playedMove, theAnswer );
//          assert( s.isExactMatch() == false );
//          assert( s.to_string() == "MM__" );
//          assert( s.getAnswer( 0 ) == MAYBE );
//          assert( s.getAnswer( 1 ) == MAYBE );
//          assert( s.getAnswer( 2 ) == WRONG );
//          assert( s.getAnswer( 3 ) == WRONG );
//          break;
//
//        case 17:
//          assert( b.getCurrentRound() == 0 );
//          break;
//
//        case 18:
//          good = true;
//          // when out of range, throw logic error
//          try {
//              b.getMoveForRound( -10 );
//              good = false;
//          } catch( std::logic_error ) {
//
//          }
//          try {
//              b.getMoveForRound( 10 );
//              good = false;
//          } catch( std::logic_error ) {
//
//          }
//          assert( good );
//          break;
//
//        case 19:
//          good = true;
//          // when out of range, throw logic error
//          try {
//              b.getScoreForRound( -10 );
//              good = false;
//          } catch( std::logic_error ) {
//
//          }
//          try {
//              b.getScoreForRound( 10 );
//              good = false;
//          } catch( std::logic_error ) {
//
//          }
//          assert( good );
//          break;
//
//        case 20:
//          m.setPieces( "grby" );
//          theAnswer.setPieces( "opop" );
//          s = Score( m, theAnswer );
//          b.endRound( m, s );
//          assert( b.getCurrentRound() == 1 );
//          assert( b.getMoveForRound( 0 ).to_string() == "GRBY" );
//          assert( b.getScoreForRound( 0 ).to_string() == "____" );
//          break;
//
//        case 21:
//          m.setPieces( "rgyp" );
//          playedMove.setPieces( "rgyp" );
//          theAnswer.setPieces( "bobo" );
//          s = Score( playedMove, theAnswer );
//          b.endRound( m, s );
//          assert( b.getCurrentRound() == 1 );
//          assert( b.getMoveForRound( 0 ).to_string() == "RGYP" );
//          assert( b.getScoreForRound( 0 ).to_string() == "____" );
//          break;
//
//        case 22:
//          m.setPieces( "gypo" );
//          playedMove.setPieces( "gypo" );
//          theAnswer.setPieces( "oygp" );
//          s = Score( playedMove, theAnswer );
//          b.endRound( m, s );
//          assert( b.getCurrentRound() == 1 );
//          assert( b.getMoveForRound( 0 ).to_string() == "GYPO" );
//          assert( b.getScoreForRound( 0 ).to_string() == "MRMM" );
//          break;
//
//        case 23:
//          m.setPieces( "gypo" );
//          playedMove.setPieces( "gypo" );
//          theAnswer.setPieces( "ggpy" );
//          s = Score( playedMove, theAnswer );
//          b.endRound( m, s );
//          assert( b.getCurrentRound() == 1 );
//          assert( b.getMoveForRound( 0 ).to_string() == "GYPO" );
//          assert( b.getScoreForRound( 0 ).to_string() == "RMR_" );
//          break;
//
//        case 24:
//          game = Mastermind( "gypp" );
//          assert( game.answer() == "GYPP" );
//          assert( game.gameIsOver() == false );
//          break;
//
//        case 25:
//          game = Mastermind( "popo" );
//          assert( game.answer() == "POPO" );
//          assert( game.gameIsOver() == false );
//          m = game.play( "rgbp" );
//          s = game.endRound(m);
//          assert( s.isExactMatch() == false );
//          assert( s.to_string() == "___M" );
//          assert( game.gameIsOver() == false );
//          break;
//
//        case 26:
//          game = Mastermind( "ypoy" );
//          assert( game.answer() == "YPOY" );
//          assert( game.gameIsOver() == false );
//          m = game.play( "rbrb" );
//          s = game.endRound(m);
//          assert( s.isExactMatch() == false );
//          assert( s.to_string() == "____" );
//          assert( game.gameIsOver() == false );
//          m = game.play( "gpgp" );
//          s = game.endRound(m);
//          assert( s.isExactMatch() == false );
//          assert( s.to_string() == "_R__" );
//          assert( game.gameIsOver() == false );
//          m = game.play( "ypoy" );
//          s = game.endRound(m);
//          assert( s.isExactMatch() == true );
//          assert( s.to_string() == "RRRR" );
//          assert( game.gameIsOver() == true );
//          break;
//
//        case 27:
//          game = Mastermind( "ypyp" );
//          assert( game.answer() == "YPYP" );
//          assert( game.gameIsOver() == false );
//          m = game.play( "rbgr" );
//          s = game.endRound(m);
//          assert( s.isExactMatch() == false );
//          assert( s.to_string() == "____" );
//          assert( game.gameIsOver() == false );
//          m = game.play( "oooo" );
//          s = game.endRound(m);
//          assert( s.isExactMatch() == false );
//          assert( s.to_string() == "____" );
//          assert( game.gameIsOver() == false );
//          m = game.play( "ybpo" );
//          s = game.endRound(m);
//          assert( s.isExactMatch() == false );
//          assert( s.to_string() == "R_M_" );
//          assert( game.gameIsOver() == false );
//          m = game.play( "pypo" );
//          s = game.endRound(m);
//          assert( s.isExactMatch() == false );
//          //assert( s.to_string() == "MMM_" );
//          assert( game.gameIsOver() == true );
//          break;
//
//        case 28:
//          game = Mastermind( "ggbb" );
//          assert( game.answer() == "GGBB" );
//          assert( game.gameIsOver() == false );
//          m = game.play( "rbgr" );
//          s = game.endRound(m);
//          assert( s.isExactMatch() == false );
//          assert( s.to_string() == "_MM_" );
//          assert( game.gameIsOver() == false );
//          m = game.play( "bbbg" );
//          s = game.endRound(m);
//          assert( s.isExactMatch() == false );
//          assert( s.to_string() == "M_RM" );
//          assert( game.gameIsOver() == false );
//          m = game.play( "gbgb" );
//          s = game.endRound(m);
//          assert( s.isExactMatch() == false );
//          assert( s.to_string() == "RMMR" );
//          assert( game.gameIsOver() == false );
//          m = game.play( "bbbb" );
//          s = game.endRound(m);
//          assert( s.isExactMatch() == false );
//          assert( s.to_string() == "__RR" );
//          assert( game.gameIsOver() == true );
//          break;
//
//        default:
//          cout << "Bad argument" << endl;
//          break;
//     }
//}
//
//
//int main()
//{
//     cout << "Enter test number: ";
//     int n;
//     cin >> n;
//     testone(n);
//     cout << "Passed!" << endl;
//     return( 0 );
//}
