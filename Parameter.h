#ifndef PARAMETER_H
#define PARAMETER_H

#define FRAME_DELAY 30

// background size
#define SCREEN_WIDTH 1080
#define SCREEN_HEIGHT 960

// Game Setting
#define PLAYER_NUM 4
// #define

// Button Size&Position
#define BTN_WIDTH 150
#define BTN_HEIGHT 50
#define BTN_Y 850
#define BTN_X1 140 - 75
#define BTN_X2 340 - 75
#define BTN_X3 540 - 75
#define BTN_X4 740 - 75
#define BTN_X5 940 - 75

// Card button Size&Position
#define CARD_BUTTON_WIDTH 100
#define CARD_BUTTON_HEIGHT 146
#define CARD_BTN_X_LEFT 180
#define CARD_BTN_X_LENGTH 720
#define CARD_BTN_Y 650
#define CARD_BTN_Y_clicked 600

#define CARDBACK_WIDTH 75
#define CARDBACK_HEIGHT 110

#define CARDBACK_LEFT_X 80
#define CARDBACK_LEFT_Y 100

#define CARDBACK_RIGHT_X 923
#define CARDBACK_RIGHT_Y 500

#define CARDBACK_UP_X_RIGHT 700
#define CARDBACK_UP_Y 50

#define CARDBACK_Y_UNIT 30
#define CARDBACK_X_UNIT 35



#define PLAYER1_X 100
#define PLAYER1_Y 650
#define PLAYER2_X 923
#define PLAYER2_Y 570
#define PLAYER3_X 800
#define PLAYER3_Y 5
#define PLAYER4_X 75
#define PLAYER4_Y 5
#define LABEL_X 100
#define LABEL_Y 60


// Card
enum ITEM_ORDER
{
    // buttom
    BACKGROUND,
    CARD,
    BUTTON,
    // top
};

enum Suit
{
    // buttom
    Clubs,    // 0
    Diamonds, // 1
    Hearts,   // 2
    Spades,   // 3
              // top
};
enum Number
{
    // buttom
    C3,//0
    C4,//1
    C5,
    C6,
    C7,
    C8,
    C9,
    C10,
    J,
    Q,
    K,
    A,
    C2//12
    // top
};

enum CombinationType
{
    // buttom
    Straight_Flush, // 0
    Four_of_a_Kind, // 1
    Full_House,     // 2
    Straight,       // 3
    Pair,           // 4
    Single,         // 5
    None
    // buttom
};

#endif // PARAMETER_H
