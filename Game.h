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
    void Pass();
    void Deal();
    void switchCombinationalType(int);

protected:
private:
    void createScene();
    void reset();
    void setButton();
    void shuffleAndDealCard();
    void showNowPlayerOwnCards();
    void showOtherPlayersOwnCard();
    void showDealCards(bool show = true);
    void player_turn(int);
    void gameStart();
    void showCombination();
    void nextPlayer();

    QPushButton *btnSF;   // 同花順
    QPushButton *btnFK;   // 鐵支
    QPushButton *btnFH;   // 葫蘆
    QPushButton *btnS;    // 順子
    QPushButton *btnP;    // 一對
    QPushButton *btnPass; // Pass
    QPushButton *btnDeal; // 出牌

    //
    Player *now_player;                      // 現在玩家
    std::vector<Player *> other_players;     // 其他玩家
    std::vector<QPushButton *> nowcardsBTNs; // 現在玩家手牌
    std::vector<QGraphicsProxyWidget *> pro;
    std::vector<QGraphicsPixmapItem *> cardBacks; // 其他玩家手牌牌背
    std::vector<Combination *> combination_types; // 出牌組合
    std::vector<QGraphicsPixmapItem *> hasDealCards; // 上次出的牌

    //
    std::vector<Card *> last_combination; // 上位玩家出的牌
    std::vector<Card *> selected_cards;   // 點案選中的牌
    CombinationType last_type;            // 上次出牌牌型
    CombinationType selected_type;        // 目前選中牌型
    bool first_one_deal=true;

    // int time
    int timerID;
};

#endif // GAME_H
