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
#define CARDBACK_LEFT_Y_LENGTH 450

#define CARDBACK_RIGHT_X 923
#define CARDBACK_RIGHT_Y 600
#define CARDBACK_RIGHT_Y_LENGTH 450

#define CARDBACK_UP_X_LEFT 300
#define CARDBACK_UP_X_LENGTH 450
#define CARDBACK_UP_Y 50



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
    C3,
    C4,
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
    C2
    // top
};

#endif // PARAMETER_H
