#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QPushButton>

#include "Parameter.h"
#include "Card.h"
#include "Player.h"
#include "Combination.h"

class Game : public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent = 0);

    // objects of queue
    QGraphicsScene *scene = nullptr;
    Player *player = nullptr;
    std::vector<Player *> players;
    std::vector<Card *> cards;

    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    // void keyReleaseEvent(QKeyEvent *event);
    void ShowMsg();

public slots:
    void updating();
    void del();
    void cardButtonEvent(int);

protected:
private:
    void createScene();
    void reset();
    void setButton();
    void shuffleAndDealCard();
    void showNowPlayerOwnCards();
    void showOtherPlayersOwnCard();
    void player_turn(int);
    void gameFlow();
    void showCombination();

    QPushButton *btnSF; // 同花順
    QPushButton *btnFK; // 鐵支
    QPushButton *btnFH; // 葫蘆
    QPushButton *btnS;  // 順子
    QPushButton *btnP;  // 一對
    QPushButton *btnPass;  // Pass
    QPushButton *btnDeal;  // 出牌

    Combination *Straight_Flush;
    Combination *Four_of_a_Kind;
    Combination *Full_House;
    Combination *Straight;
    Combination *Pair;

    //
    Player *now_player;
    std::vector<Player *> other_players;
    std::vector<QPushButton *> nowcardsBTNs;
    std::vector<QGraphicsPixmapItem *> cardBacks;

    // int time
    int timerID;
};

#endif // GAME_H
