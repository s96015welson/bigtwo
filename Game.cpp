#include "Game.h"

#include <cstdlib>
#include <iostream>

#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QTimer>
#include <QDebug>
#include <QObject>
#include <QSound>
#include <QMessageBox>
#include <QPushButton>
#include <QSignalMapper>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <ctime>
#include <cstdlib>
#include "unistd.h"
#include <string>
#include "Parameter.h"

using namespace std;
Game::Game(QWidget *parent)

{

    setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    setMouseTracking(true);
    srand(time(NULL));
    createScene();

    // reset
    reset();
    // game flow
    gameFlow();

    show();
}

void Game::ShowMsg()
{
    /*
    QMessageBox msgBox;
    // QString final_score = ;

    msgBox.setStyleSheet("QLabel{"
                         "min-width:180px;"
                         "min-height:100px;"
                         "font-size:16px;"
                         "}");
    QString qStr1 = "Game Over!\nFinal Score:";
    QString qStr2 = QString::number(score->getScore());
    msgBox.setText(qStr1 + qStr2);
    msgBox.exec();
    */
}

void Game::createScene()
{

    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    // ADD BACKGROUND
    /*

        QGraphicsPixmapItem *pic = new QGraphicsPixmapItem();
        pic->setPixmap(QPixmap("./dataset/images/background.png").scaled(SCREEN_WIDTH,SCREEN_HEIGHT));
        scene->addItem(pic);
        pic->setPos(0, 0);
       */
}

void Game::reset()
{
    // clear vectors
    players.clear();
    cards.clear();

    while (!nowcardsBTNs.empty())
    {
        delete nowcardsBTNs.back();
        nowcardsBTNs.pop_back();
    }
    while (!cardBacks.empty())
    {
        scene->removeItem(cardBacks.back());
        delete cardBacks.back();
        cardBacks.pop_back();
    }

    // initial button
    setButton();
    // generate player

    for (int i = 0; i < PLAYER_NUM; i++)
    {
        Player *new_player = new Player();
        players.push_back(new_player);
    }
    // deliver card
    shuffleAndDealCard();
}

void Game::keyPressEvent(QKeyEvent *event)
{
}
void Game::mousePressEvent(QMouseEvent *event)
{
}

void Game::updating()
{
}
void Game::setButton()
{

    // imageA->setIconSize(pic.size());
    //

    QPushButton *btnPP = new QPushButton;
    btnPP->setParent(this);
    btnPP->setText("delete");
    QObject::connect(btnPP, SIGNAL(clicked()), this, SLOT(del()));

    btnSF = new QPushButton;
    btnSF->setParent(this);
    btnSF->setText("同花順");
    btnSF->move(BTN_X1, BTN_Y);
    btnSF->resize(BTN_WIDTH, BTN_HEIGHT);
    btnSF->setFont(QFont("Courier", 18, QFont::Bold));
    // btnSF->setEnabled(false);

    btnFK = new QPushButton;
    btnFK->setParent(this);
    btnFK->setText("鐵支");
    btnFK->move(BTN_X2, BTN_Y);
    btnFK->resize(BTN_WIDTH, BTN_HEIGHT);
    btnFK->setFont(QFont("Courier", 18, QFont::Bold));

    btnFH = new QPushButton;
    btnFH->setParent(this);
    btnFH->setText("葫蘆");
    btnFH->move(BTN_X3, BTN_Y);
    btnFH->resize(BTN_WIDTH, BTN_HEIGHT);
    btnFH->setFont(QFont("Courier", 18, QFont::Bold));

    btnS = new QPushButton;
    btnS->setParent(this);
    btnS->setText("順子");
    btnS->move(BTN_X4, BTN_Y);
    btnS->resize(BTN_WIDTH, BTN_HEIGHT);
    btnS->setFont(QFont("Courier", 18, QFont::Bold));

    btnP = new QPushButton;
    btnP->setParent(this);
    btnP->setText("一對");
    btnP->move(BTN_X5, BTN_Y);
    btnP->resize(BTN_WIDTH, BTN_HEIGHT);
    btnP->setFont(QFont("Courier", 18, QFont::Bold));
}

void Game::shuffleAndDealCard()
{
    // generate card
    cards.clear();
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            Card *new_card = new Card((Number)i, (Suit)j);
            cards.push_back(new_card);
        }
    }
    /*
    for (int i = 0; i < cards.size(); i++)
    {
        cout << cards.at(i)->num << " " << cards.at(i)->suit << "jjj\n";
    }
    */
    // deliver card
    for (int i = 0; i < 13; i++)
        for (int j = 0; j < players.size(); j++)
        {
            int r = rand() % cards.size();
            players.at(j)->addCard(cards.at(r));
            cards.erase(cards.begin() + r);
        }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < players.at(i)->ownCards.size(); j++)
        {
            cout << players.at(i)->ownCards.at(j)->num << " "
                 << players.at(i)->ownCards.at(j)->suit << "\n";
        }
        cout << "\n";
    }
    // sort card
    for (int i = 0; i < players.size(); i++)
        players.at(i)->sortCards();
}
void Game::del()
{
    cout << "kk" << endl;
}

void Game::cardButtonEvent(int i)
{
    cout << i << endl;
    Card *click_card = now_player->ownCards.at(i);
    QPushButton *click_button = nowcardsBTNs.at(i);
    cout << click_card->num << " " << click_card->suit << endl;
    // move button
    if (click_button->y() == CARD_BTN_Y)
        click_button->move(click_button->x(), CARD_BTN_Y_clicked);
    else
        click_button->move(click_button->x(), CARD_BTN_Y);

    // if(click_button->x())
}

void Game::player_turn(int nowP)
{
    now_player = players.at(nowP);
    other_players.clear();
    switch (nowP)
    {
    case 0:
        other_players.push_back(players.at(1));
        other_players.push_back(players.at(2));
        other_players.push_back(players.at(3));
        break;
    case 1:
        other_players.push_back(players.at(2));
        other_players.push_back(players.at(3));
        other_players.push_back(players.at(0));
        break;
    case 2:
        other_players.push_back(players.at(3));
        other_players.push_back(players.at(0));
        other_players.push_back(players.at(1));
        break;
    case 3:
        other_players.push_back(players.at(0));
        other_players.push_back(players.at(1));
        other_players.push_back(players.at(2));

        break;
    default:
        break;
    }
}

void Game::gameFlow()
{
    // set button
    player_turn(0);

    showNowPlayerOwnCards();
    showOtherPlayersOwnCard();
}

void Game::showNowPlayerOwnCards()
{
    QSignalMapper *signalMapper = new QSignalMapper(this);

    while (!nowcardsBTNs.empty())
    {
        delete nowcardsBTNs.back();
        nowcardsBTNs.pop_back();
    }

    int own_card_num = now_player->ownCards.size();
    for (int i = 0; i < own_card_num; i++)
    {
        QPushButton *newCardBTN = new QPushButton;
        newCardBTN->setParent(this);

        // button setting
        QPixmap cardIcon;
        cardIcon.load(now_player->ownCards.at(i)->cardPath);
        cardIcon = cardIcon.scaled(CARD_BUTTON_WIDTH, CARD_BUTTON_HEIGHT);

        newCardBTN->setIcon(cardIcon);
        newCardBTN->setIconSize(cardIcon.size());

        newCardBTN->move(CARD_BTN_X_LEFT + ((CARD_BTN_X_LENGTH - CARD_BUTTON_WIDTH) / own_card_num * i), CARD_BTN_Y);
        QObject::connect(newCardBTN, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(newCardBTN, i);

        nowcardsBTNs.push_back(newCardBTN);
    }
    QObject::connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(cardButtonEvent(int)));
}

void Game::showOtherPlayersOwnCard()
{

    while (!cardBacks.empty())
    {
        scene->removeItem(cardBacks.back());
        delete cardBacks.back();
        cardBacks.pop_back();
    }

    // player left
    for (int i = 0; i < other_players.at(0)->ownCards.size(); i++)
    {
        QGraphicsPixmapItem *new_cardback = new (QGraphicsPixmapItem);
        new_cardback->setPos(CARDBACK_LEFT_X, CARDBACK_LEFT_Y + CARDBACK_LEFT_Y_LENGTH / other_players.at(0)->ownCards.size() * i);
        new_cardback->setPixmap(QPixmap("./Dataset/CardBack.jpg").scaled(CARDBACK_HEIGHT, CARDBACK_WIDTH));
        scene->addItem(new_cardback);
        cardBacks.push_back(new_cardback);
    }
    // player up
    for (int i = 0; i < other_players.at(1)->ownCards.size(); i++)
    {
        QGraphicsPixmapItem *new_cardback = new (QGraphicsPixmapItem);
        new_cardback->setPos(CARDBACK_UP_X_LEFT + CARDBACK_UP_X_LENGTH / other_players.at(1)->ownCards.size() * i, CARDBACK_UP_Y);
        new_cardback->setPixmap(QPixmap("./Dataset/CardBack.jpg").scaled(CARDBACK_WIDTH, CARDBACK_HEIGHT));
        scene->addItem(new_cardback);
        cardBacks.push_back(new_cardback);
    }
    // player right
    for (int i = 0; i < other_players.at(2)->ownCards.size(); i++)
    {
        QGraphicsPixmapItem *new_cardback = new (QGraphicsPixmapItem);
        new_cardback->setPos(CARDBACK_RIGHT_X, CARDBACK_RIGHT_Y - CARDBACK_RIGHT_Y_LENGTH / other_players.at(2)->ownCards.size() * i);
        new_cardback->setPixmap(QPixmap("./Dataset/CardBack.jpg").scaled(CARDBACK_HEIGHT, CARDBACK_WIDTH));
        scene->addItem(new_cardback);
        cardBacks.push_back(new_cardback);
    }
}