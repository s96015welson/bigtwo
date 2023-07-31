#include "Game.h"

#include <cstdlib>
#include <iostream>

#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QLabel>
#include <QDebug>
#include <QObject>
#include <QString>
#include <QMessageBox>
#include <QPushButton>
#include <QSignalMapper>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsProxyWidget>
#include <ctime>
#include <cstdlib>
#include "unistd.h"
#include <string>
#include "Parameter.h"
#include "straight.h"
#include "straight_flush.h"
#include "four_of_a_kind.h"
#include "full_house.h"
#include "pair2.h"

using namespace std;
Game::Game(QWidget *parent)

{

    setFixedSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    setMouseTracking(true);
    srand(time(NULL));
    createScene();

    initial();
    // reset
    reset();
    // game flow
    // gameStart();

    show();
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
}

void Game::ShowMsg()
{
    QMessageBox msgBox;
    // QString final_score = ;

    msgBox.setStyleSheet("QLabel{"
                         "min-width:300px;"
                         "min-height:300px;"
                         "font-size:25px;"
                         "}");

    QString qStr = "第" + QString::number(Gametimes) + "次遊戲結束!\n";
    qStr += "Player1 Score:" + QString::number(players.at(0)->score) + "\n";
    qStr += "Player2 Score:" + QString::number(players.at(1)->score) + "\n";
    qStr += "Player3 Score:" + QString::number(players.at(2)->score) + "\n";
    qStr += "Player4 Score:" + QString::number(players.at(3)->score) + "\n\n";

    if (topScore < 50)
        qStr += "繼續下一局遊戲";
    else
    {
        qStr += "遊戲結束!";
        if (players.at(0)->score == topScore)
            qStr += "Player1 獲勝";
        if (players.at(1)->score == topScore)
            qStr += "Player2 獲勝";
        if (players.at(2)->score == topScore)
            qStr += "Player3 獲勝";
        if (players.at(3)->score == topScore)
            qStr += "Player4 獲勝";
    }

    msgBox.setText(qStr);
    Gametimes++;
    msgBox.exec();
}

void Game::initial()
{
}

void Game::reset()
{
    first_one_deal = false;
    Gametimes = 1;
    topScore = 0;
    lastwin = 0;
    // clear vectors

    players.clear();
    cards.clear();
    // clear show on scene items
    while (!nowcardsBTNs.empty())
    {
        nowcardsBTNs.back()->deleteLater();
        nowcardsBTNs.pop_back();
    }
    while (!cardBacks.empty())
    {
        scene->removeItem(cardBacks.back());
        delete cardBacks.back();
        cardBacks.pop_back();
    }
    while (!hasDealCards.empty())
    {
        scene->removeItem(hasDealCards.back());
        delete hasDealCards.back();
        hasDealCards.pop_back();
    }
    while (!hasDealCards.empty())
    {
        scene->removeItem(hasDealCards.back());
        delete hasDealCards.back();
        hasDealCards.pop_back();
    }
    while (!playerLabel.empty())
    {
        playerLabel.back()->deleteLater();
        playerLabel.pop_back();
    }

    /*
    if (btnSF != nullptr)
    {
        QPushButton *dbtn;

        dbtn = btnSF;
        btnSF = nullptr;
        dbtn->deleteLater();

        dbtn = btnFK;
        btnFK = nullptr;
        dbtn->deleteLater();

        dbtn = btnFH;
        btnFH = nullptr;
        dbtn->deleteLater();

        dbtn = btnS;
        btnS = nullptr;
        dbtn->deleteLater();

        dbtn = btnP;
        btnP = nullptr;
        dbtn->deleteLater();

        dbtn = btnPass;
        btnPass = nullptr;
        dbtn->deleteLater();

        dbtn = btnDeal;
        btnDeal = nullptr;
        dbtn->deleteLater();
    }
    */

    // initial button
    if (afterstart == false)
    {
        setInitialScene();
    }

    else
    {
        setButton();
        // generate player
        for (int i = 0; i < PLAYER_NUM; i++)
        {
            Player *new_player = new Player(i + 1);
            players.push_back(new_player);
        }
        gameStart();
    }
}

void Game::gameStart()
{
    // reset & clear
    last_type = None;
    last_combination.clear();
    selected_type = None;
    selected_cards.clear();
    Passtime = 0;
    for (Player *player : players)
    {
        player->ownCards.clear();
    }
    // clear show on scene items
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
    while (!hasDealCards.empty())
    {
        scene->removeItem(hasDealCards.back());
        delete hasDealCards.back();
        hasDealCards.pop_back();
    }

    // deliver card
    shuffleAndDealCard();

    int first_player;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            if (players.at(i)->ownCards.at(j)->num == C3 && players.at(i)->ownCards.at(j)->suit == Clubs)
            {
                first_player = (i) % 4;
                break;
            }
        }
    }

    if (lastwin != 0)
        nextPlayer(lastwin - 1);
    else
        nextPlayer(first_player);
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

    QSignalMapper *signalMapperL = new QSignalMapper(this);

    btnPass = new QPushButton;
    btnPass->setParent(this);
    btnPass->setText("Pass");
    btnPass->move(900, 760);
    btnPass->resize(BTN_WIDTH * 0.5, BTN_HEIGHT);
    btnPass->setFont(QFont("Courier", 18, QFont::Bold));
    QObject::connect(btnPass, SIGNAL(clicked()), this, SLOT(Pass()));
    btnPass->show();

    btnDeal = new QPushButton;
    btnDeal->setParent(this);
    btnDeal->setText("出牌");
    btnDeal->move(900, 700);
    btnDeal->resize(BTN_WIDTH * 0.5, BTN_HEIGHT);
    btnDeal->setFont(QFont("Courier", 18, QFont::Bold));
    QObject::connect(btnDeal, SIGNAL(clicked()), this, SLOT(Deal()));
    btnDeal->show();

    btnSF = new QPushButton;
    btnSF->setParent(this);
    btnSF->setText("同花順");
    btnSF->move(BTN_X1, BTN_Y);
    btnSF->resize(BTN_WIDTH, BTN_HEIGHT);
    btnSF->setFont(QFont("Courier", 18, QFont::Bold));
    QObject::connect(btnSF, SIGNAL(clicked()), signalMapperL, SLOT(map()));
    signalMapperL->setMapping(btnSF, (int)Straight_Flush);
    btnSF->show();

    btnFK = new QPushButton;
    btnFK->setParent(this);
    btnFK->setText("鐵支");
    btnFK->move(BTN_X2, BTN_Y);
    btnFK->resize(BTN_WIDTH, BTN_HEIGHT);
    btnFK->setFont(QFont("Courier", 18, QFont::Bold));
    QObject::connect(btnFK, SIGNAL(clicked()), signalMapperL, SLOT(map()));
    signalMapperL->setMapping(btnFK, (int)Four_of_a_Kind);
    btnFK->show();

    btnFH = new QPushButton;
    btnFH->setParent(this);
    btnFH->setText("葫蘆");
    btnFH->move(BTN_X3, BTN_Y);
    btnFH->resize(BTN_WIDTH, BTN_HEIGHT);
    btnFH->setFont(QFont("Courier", 18, QFont::Bold));
    QObject::connect(btnFH, SIGNAL(clicked()), signalMapperL, SLOT(map()));
    signalMapperL->setMapping(btnFH, (int)Full_House);
    btnFH->show();

    btnS = new QPushButton;
    btnS->setParent(this);
    btnS->setText("順子");
    btnS->move(BTN_X4, BTN_Y);
    btnS->resize(BTN_WIDTH, BTN_HEIGHT);
    btnS->setFont(QFont("Courier", 18, QFont::Bold));
    QObject::connect(btnS, SIGNAL(clicked()), signalMapperL, SLOT(map()));
    signalMapperL->setMapping(btnS, (int)Straight);
    btnS->show();

    btnP = new QPushButton;
    btnP->setParent(this);
    btnP->setText("一對");
    btnP->move(BTN_X5, BTN_Y);
    btnP->resize(BTN_WIDTH, BTN_HEIGHT);
    btnP->setFont(QFont("Courier", 18, QFont::Bold));
    QObject::connect(btnP, SIGNAL(clicked()), signalMapperL, SLOT(map()));
    signalMapperL->setMapping(btnP, (int)Pair);
    btnP->show();

    QObject::connect(signalMapperL, SIGNAL(mapped(int)), this, SLOT(switchCombinationalType(int)));
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
    // deliver card
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j < players.size(); j++)
        {
            int r = rand() % cards.size();
            players.at(j)->addCard(cards.at(r));
            cards.erase(cards.begin() + r);
        }
    }

    // sort card
    for (int i = 0; i < players.size(); i++)
        players.at(i)->sortCards();
}

void Game::cardButtonEvent(int i)
{
    Card *click_card = now_player->ownCards.at(i);
    QPushButton *click_button = nowcardsBTNs.at(i);
    // cout << click_card->num << " " << click_card->suit << endl;

    // none/single 時 btn歸位
    if ((selected_type == None || selected_type == Single) && (click_button->y() == CARD_BTN_Y))
        for (QPushButton *btn : nowcardsBTNs)
            btn->move(btn->x(), CARD_BTN_Y);
    // move button
    if (click_button->y() == CARD_BTN_Y)
        click_button->move(click_button->x(), CARD_BTN_Y_clicked);
    else
        click_button->move(click_button->x(), CARD_BTN_Y);

    // renew selected_Cards
    selected_cards.clear();
    for (int i = 0; i < nowcardsBTNs.size(); i++)
    {
        if (nowcardsBTNs.at(i)->y() == CARD_BTN_Y_clicked)
        {
            selected_cards.push_back(now_player->ownCards.at(i));
        }
    }
    // Can Deal?
    std::cout << selected_type << "S/L" << last_type << "\n";
    btnDeal->setDisabled(true);
    Combination *now_select_combination;
    if (selected_type == Straight_Flush) // 桐花順
    {
        now_select_combination = combination_types.at(0);
        if (selected_type != last_type && last_type != Four_of_a_Kind)
        {
            if (now_select_combination->is_this_combination(selected_cards))
                btnDeal->setDisabled(false);
        }
        else if (selected_type == last_type)
        {
            if (now_select_combination->is_this_combination(selected_cards) && now_select_combination->compare_combination(selected_cards, last_combination))
                btnDeal->setDisabled(false);
        }
    }
    else if (selected_type == Four_of_a_Kind) // 鐵支
    {
        now_select_combination = combination_types.at(1);
        if (selected_type != last_type && last_type != Straight_Flush)
        {
            if (now_select_combination->is_this_combination(selected_cards))
                btnDeal->setDisabled(false);
        }
        else if (selected_type == last_type)
        {
            if (now_select_combination->is_this_combination(selected_cards) && now_select_combination->compare_combination(selected_cards, last_combination))
                btnDeal->setDisabled(false);
        }
    }
    else if (selected_type == Straight || selected_type == Full_House || selected_type == Pair) // else
    {
        now_select_combination = combination_types.at((int)selected_type);

        if (last_type == None)
        {
            if (now_select_combination->is_this_combination(selected_cards))
                btnDeal->setDisabled(false);
        }
        else if (selected_type == last_type)
        {
            if (now_select_combination->is_this_combination(selected_cards) && now_select_combination->compare_combination(selected_cards, last_combination))
                btnDeal->setDisabled(false);
        }
    }

    else if ((last_type == Single || last_type == None) && selected_cards.size() == 1) // single &None
    {
        if (last_combination.empty())
            btnDeal->setDisabled(false);
        else if (((selected_cards.at(0)->num > last_combination.at(0)->num) || (selected_cards.at(0)->num == last_combination.at(0)->num && selected_cards.at(0)->suit > last_combination.at(0)->suit)))
            btnDeal->setDisabled(false);
    }

    if (first_one_deal == true)
    {
        bool has3 = false;
        for (Card *card : selected_cards)
        {
            if (card->num == C3 && card->suit == Clubs)
                has3 = true;
        }
        if (!has3)
            btnDeal->setDisabled(true);
    }
}

void Game::player_turn(int newP)
{
    now_player = players.at(newP);
    other_players.clear();
    switch (newP)
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

    // set label
    setPlayerText();
}

void Game::showNowPlayerOwnCards()
{
    QSignalMapper *signalMapper = new QSignalMapper(this);

    // remove old btns
    while (!nowcardsBTNs.empty())
    {

        nowcardsBTNs.back()->deleteLater();
        nowcardsBTNs.pop_back();
    }

    // add new btns
    int own_card_num = now_player->ownCards.size();
    for (int i = 0; i < own_card_num; i++)
    {
        QPushButton *newCardBTN = new QPushButton;
        newCardBTN->setParent(this);

        // scene->addWidget(newCardBTN);

        // button setting
        QPixmap cardIcon;
        cardIcon.load(now_player->ownCards.at(i)->cardPath);
        cardIcon = cardIcon.scaled(CARD_BUTTON_WIDTH, CARD_BUTTON_HEIGHT);

        newCardBTN->setIcon(cardIcon);
        newCardBTN->setIconSize(cardIcon.size());

        newCardBTN->move(CARD_BTN_X_LEFT + ((CARD_BTN_X_LENGTH - CARD_BUTTON_WIDTH) / own_card_num * i), CARD_BTN_Y);
        QObject::connect(newCardBTN, SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(newCardBTN, i);
        newCardBTN->show();

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
        new_cardback->setPos(CARDBACK_RIGHT_X, CARDBACK_RIGHT_Y - CARDBACK_Y_UNIT * i);
        new_cardback->setPixmap(QPixmap("./Dataset/CardBackL.jpg").scaled(CARDBACK_HEIGHT, CARDBACK_WIDTH));
        scene->addItem(new_cardback);
        cardBacks.push_back(new_cardback);
    }
    // player up
    for (int i = 0; i < other_players.at(1)->ownCards.size(); i++)
    {
        QGraphicsPixmapItem *new_cardback = new (QGraphicsPixmapItem);
        new_cardback->setPos(CARDBACK_UP_X_RIGHT - CARDBACK_X_UNIT * i, CARDBACK_UP_Y);
        new_cardback->setPixmap(QPixmap("./Dataset/CardBack.jpg").scaled(CARDBACK_WIDTH, CARDBACK_HEIGHT));
        scene->addItem(new_cardback);
        cardBacks.push_back(new_cardback);
    }
    // player right
    for (int i = 0; i < other_players.at(2)->ownCards.size(); i++)
    {
        QGraphicsPixmapItem *new_cardback = new (QGraphicsPixmapItem);
        new_cardback->setPos(CARDBACK_LEFT_X, CARDBACK_LEFT_Y + CARDBACK_Y_UNIT * i);
        new_cardback->setPixmap(QPixmap("./Dataset/CardBackL.jpg").scaled(CARDBACK_HEIGHT, CARDBACK_WIDTH));
        scene->addItem(new_cardback);
        cardBacks.push_back(new_cardback);
    }
}

void Game::showCombination()
{

    // clear combination types
    while (!combination_types.empty())
    {
        delete combination_types.back();
        combination_types.pop_back();
    }

    // create new combination types
    Combination *Straight_Flush;
    Combination *Four_of_a_Kind;
    Combination *Full_House;
    Combination *Straight;
    Combination *Pair;

    Straight_Flush = new straight_flush(now_player);
    combination_types.push_back(Straight_Flush);

    Four_of_a_Kind = new four_of_a_kind(now_player);
    combination_types.push_back(Four_of_a_Kind);

    Full_House = new full_house(now_player);
    combination_types.push_back(Full_House);

    Straight = new straight(now_player);
    combination_types.push_back(Straight);

    Pair = new pair2(now_player);
    combination_types.push_back(Pair);

    // Cout all Combinations
    for (int k = 0; k < 5; k++)
    {
        switch (k)
        {
        case (0):
            cout << "Straight_Flush:" << endl;
            break;
        case (1):
            cout << "Four_of_a_Kind:" << endl;
            break;
        case (2):
            cout << "Full_House:" << endl;
            break;
        case (3):
            cout << "Straight:" << endl;
            break;
        case (4):
            cout << "Pair:" << endl;
            break;

        default:
            break;
        }

        if (k != 4)
        {
            for (int i = 0; i < combination_types.at(k)->combinations.size(); i++)
            {
                cout << (int)combination_types.at(k)->combinations[i][0]->num + 3 << "/" << (int)combination_types.at(k)->combinations[i][0]->suit << " ";
                cout << (int)combination_types.at(k)->combinations[i][1]->num + 3 << "/" << (int)combination_types.at(k)->combinations[i][1]->suit << " ";
                cout << (int)combination_types.at(k)->combinations[i][2]->num + 3 << "/" << (int)combination_types.at(k)->combinations[i][2]->suit << " ";
                cout << (int)combination_types.at(k)->combinations[i][3]->num + 3 << "/" << (int)combination_types.at(k)->combinations[i][3]->suit << " ";
                cout << (int)combination_types.at(k)->combinations[i][4]->num + 3 << "/" << (int)combination_types.at(k)->combinations[i][4]->suit << " ";
                cout << "\n";
            }
        }
        else
        {
            for (int i = 0; i < combination_types.at(k)->combinations.size(); i++)
            {
                cout << (int)combination_types.at(k)->combinations[i][0]->num + 3 << "/" << (int)combination_types.at(k)->combinations[i][0]->suit << " ";
                cout << (int)combination_types.at(k)->combinations[i][1]->num + 3 << "/" << (int)combination_types.at(k)->combinations[i][1]->suit << " ";
                cout << "\n";
            }
        }
        cout << "\n";
    }
}

void Game::showDealCards(bool show)
{
    while (!hasDealCards.empty())
    {
        scene->removeItem(hasDealCards.back());
        delete hasDealCards.back();
        hasDealCards.pop_back();
    }

    if (show)
    {
        for (int i = 0; i < selected_cards.size(); i++)
        {
            QGraphicsPixmapItem *new_card = new (QGraphicsPixmapItem);
            new_card->setPos(400 + 25 * i, 400);
            new_card->setPixmap(QPixmap(selected_cards.at(i)->cardPath).scaled(CARDBACK_WIDTH, CARDBACK_HEIGHT));
            scene->addItem(new_card);
            hasDealCards.push_back(new_card);
        }
    }
}

void Game::Pass()
{

    std::cout << "Pass\n";
    // now player Pass
    now_player->Pass = true;
    Passtime++;
    std::cout << "Pass:" << Passtime << "\n";
    selected_cards.clear();
    if (Passtime == 3) // pass 3 次，下一個人任意出牌
    {
        Passtime = 0;
        showDealCards(false); // clear show_card

        last_type = None;
        last_combination.clear();
        selected_type = None;
        selected_cards.clear();
    }
    nextPlayer();
}

void Game::Deal()
{
    last_combination = selected_cards;
    Passtime = 0; // pass次數歸零
    if (last_type == None)
    {
        for (Player *player : players)
            player->Pass = false;
    }
    now_player->Pass = false;

    std::cout << "Pass:" << Passtime << "\n";
    if (selected_cards.size() == 1)
    {
        last_type = Single;
        selected_type = Single;
    }

    else
        last_type = selected_type;

    // clean now_player's card
    for (int i = 0; i < now_player->ownCards.size(); i++)
    {
        for (int j = 0; j < selected_cards.size(); j++)
        {
            if (now_player->ownCards.at(i) == selected_cards.at(j))
            {
                now_player->ownCards.erase(now_player->ownCards.begin() + i);
            }
        }
    }
    showDealCards();
    selected_cards.clear();
    first_one_deal = false;

    if (now_player->ownCards.size() == 0)
        Finish();
    else
        nextPlayer();
}

void Game::nextPlayer(int next)
{
    if (next != -1)
        player_turn(next);
    else if (now_player == players.at(0))
        player_turn(1);
    else if (now_player == players.at(1))
        player_turn(2);
    else if (now_player == players.at(2))
        player_turn(3);
    else if (now_player == players.at(3))
        player_turn(0);

    // pass reset
    now_player->Pass = false;
    showNowPlayerOwnCards();
    showOtherPlayersOwnCard();
    showCombination();

    // set BTN enable/disable
    selected_type = None;

    btnSF->setDisabled(true);   // 同花順
    btnFK->setDisabled(true);   // 鐵支
    btnFH->setDisabled(true);   // 葫蘆
    btnS->setDisabled(true);    // 順子
    btnP->setDisabled(true);    // 一對
    btnDeal->setDisabled(true); // 出牌

    switch (last_type)
    {
    case (None):
        if (combination_types.at(0)->has_this_kind())
            btnSF->setDisabled(false); // 同花順
        if (combination_types.at(1)->has_this_kind())
            btnFK->setDisabled(false); // 鐵支
        if (combination_types.at(2)->has_this_kind())
            btnFH->setDisabled(false); // 葫蘆
        if (combination_types.at(3)->has_this_kind())
            btnS->setDisabled(false); // 順子
        if (combination_types.at(4)->has_this_kind())
            btnP->setDisabled(false); // 一對
        break;
    case (Straight_Flush):
        if (combination_types.at(0)->has_this_kind())
            btnSF->setDisabled(false); // 同花順
        break;
    case (Four_of_a_Kind):
        if (combination_types.at(1)->has_this_kind())
            btnFK->setDisabled(false); // 鐵支
        break;
    case (Full_House):
        if (combination_types.at(0)->has_this_kind())
            btnSF->setDisabled(false); // 同花順
        if (combination_types.at(1)->has_this_kind())
            btnFK->setDisabled(false); // 鐵支
        if (combination_types.at(2)->has_this_kind())
            btnFH->setDisabled(false); // 葫蘆
        break;
    case (Straight):
        if (combination_types.at(0)->has_this_kind())
            btnSF->setDisabled(false); // 同花順
        if (combination_types.at(1)->has_this_kind())
            btnFK->setDisabled(false); // 鐵支

        if (combination_types.at(3)->has_this_kind())
            btnS->setDisabled(false); // 順子
        break;
    case (Pair):
        if (combination_types.at(0)->has_this_kind())
            btnSF->setDisabled(false); // 同花順
        if (combination_types.at(1)->has_this_kind())
            btnFK->setDisabled(false); // 鐵支
        if (combination_types.at(4)->has_this_kind())
            btnP->setDisabled(false); // 一對
        break;
    case (Single):
        if (combination_types.at(0)->has_this_kind())
            btnSF->setDisabled(false); // 同花順
        if (combination_types.at(1)->has_this_kind())
            btnFK->setDisabled(false); // 鐵支

    default:
        break;
    }

    // lasttype=none or single
    if (last_type != None && last_type != Single)
    {
        // disable cards
    }
    // new player can't Pass
    if (last_type == None)
        btnPass->setDisabled(true);
    else
        btnPass->setDisabled(false);

    // btn rst
    btnSF->setStyleSheet("background:white");
    btnFK->setStyleSheet("background:white");
    btnFH->setStyleSheet("background:white");
    btnS->setStyleSheet("background:white");
    btnP->setStyleSheet("background:white");
}
void Game::switchCombinationalType(int new_selected_type)
{

    // card btn reset
    for (QPushButton *btn : nowcardsBTNs)
        btn->move(btn->x(), CARD_BTN_Y);
    // disable all cards
    for (QPushButton *btn : nowcardsBTNs)
        btn->setDisabled(true);
    // btn reset
    btnSF->setStyleSheet("background:white");
    btnFK->setStyleSheet("background:white");
    btnFH->setStyleSheet("background:white");
    btnS->setStyleSheet("background:white");
    btnP->setStyleSheet("background:white");

    // combinational type btn

    if (selected_type == (CombinationType)new_selected_type)
    {
        selected_type = Single;
    }

    else
        selected_type = (CombinationType)new_selected_type;

    switch (selected_type)
    {
    case (None):
        /*btnSF->setStyleSheet("border:1px;");//设置按钮背景颜色
        btnFK->setStyleSheet("border:1px;");//设置按钮背景颜色
        btnFH->setStyleSheet("border:1px;");//设置按钮背景颜色
        btnS->setStyleSheet("border:1px;");//设置按钮背景颜色
        btnP->setStyleSheet("border:1px;");//设置按钮背景颜色*/
        break;
    case (Straight_Flush):
        combination_types.at(0)->find_enable();
        btnSF->setStyleSheet("background:red");

        // btnSF->setStyleSheet("border:5px;");//设置按钮背景颜色
        break;
    case (Four_of_a_Kind):
        combination_types.at(1)->find_enable();
        // btnFK->setStyleSheet("border:5px;");//设置按钮背景颜色
        btnFK->setStyleSheet("background:red");
        break;
    case (Full_House):
        combination_types.at(2)->find_enable();
        // btnFH->setStyleSheet("border:5px;");//设置按钮背景颜色
        btnFH->setStyleSheet("background:red");
        break;
    case (Straight):
        combination_types.at(3)->find_enable();
        // btnS->setStyleSheet("border:5px;");//设置按钮背景颜色
        btnS->setStyleSheet("background:red");
        break;
    case (Pair):
        combination_types.at(4)->find_enable();
        // btnP->setStyleSheet("border:5px;");//设置按钮背景颜色
        btnP->setStyleSheet("background:red");

        break;
    case (Single):
        btnSF->setStyleSheet("background:white");
        btnFK->setStyleSheet("background:white");
        btnFH->setStyleSheet("background:white");
        btnS->setStyleSheet("background:white");
        btnP->setStyleSheet("background:white");
        break;

    default:
        break;
    }
    for (int i = 0; i < now_player->ownCards.size(); i++)
    {
        if (now_player->ownCards.at(i)->enable == true || selected_type == None || selected_type == Single)
            nowcardsBTNs.at(i)->setDisabled(false);
    }
}
void Game::setPlayerText()
{

    while (!playerLabel.empty())
    {
        playerLabel.back()->deleteLater();
        playerLabel.pop_back();
    }

    // set Player Name
    QLabel *label1 = new QLabel("Player1", this);
    QLabel *label2 = new QLabel("Player2", this);
    QLabel *label3 = new QLabel("Player3", this);
    QLabel *label4 = new QLabel("Player4", this);

    if (now_player->player_num == 1)
        label1->setGeometry(PLAYER1_X, PLAYER1_Y, LABEL_X, LABEL_Y);
    else if (now_player->player_num == 2)
        label2->setGeometry(PLAYER1_X, PLAYER1_Y, LABEL_X, LABEL_Y);
    else if (now_player->player_num == 3)
        label3->setGeometry(PLAYER1_X, PLAYER1_Y, LABEL_X, LABEL_Y);
    else if (now_player->player_num == 4)
        label4->setGeometry(PLAYER1_X, PLAYER1_Y, LABEL_X, LABEL_Y);

    for (int i = 0; i < 3; i++)
    {
        int playerX;
        int playerY;
        if (i == 0)
        {
            playerX = PLAYER2_X;
            playerY = PLAYER2_Y;
        }
        if (i == 1)
        {
            playerX = PLAYER3_X;
            playerY = PLAYER3_Y;
        }
        if (i == 2)
        {
            playerX = PLAYER4_X;
            playerY = PLAYER4_Y;
        }

        if (other_players.at(i)->player_num == 1)
            label1->setGeometry(playerX, playerY, LABEL_X, LABEL_Y);
        else if (other_players.at(i)->player_num == 2)
            label2->setGeometry(playerX, playerY, LABEL_X, LABEL_Y);
        else if (other_players.at(i)->player_num == 3)
            label3->setGeometry(playerX, playerY, LABEL_X, LABEL_Y);
        else if (other_players.at(i)->player_num == 4)
            label4->setGeometry(playerX, playerY, LABEL_X, LABEL_Y);
    }

    label1->setFont(QFont("Courier", 15, QFont::Bold, true));
    label2->setFont(QFont("Courier", 15, QFont::Bold, true));
    label3->setFont(QFont("Courier", 15, QFont::Bold, true));
    label4->setFont(QFont("Courier", 15, QFont::Bold, true));

    label1->show();
    label2->show();
    label3->show();
    label4->show();
    playerLabel.push_back(label1);
    playerLabel.push_back(label2);
    playerLabel.push_back(label3);
    playerLabel.push_back(label4);

    // Set Player Rest Card
    QLabel *labelN1 = new QLabel(QString::number(now_player->ownCards.size()), this);
    QLabel *labelN2 = new QLabel(QString::number(other_players.at(0)->ownCards.size()), this);
    QLabel *labelN3 = new QLabel(QString::number(other_players.at(1)->ownCards.size()), this);
    QLabel *labelN4 = new QLabel(QString::number(other_players.at(2)->ownCards.size()), this);

    labelN1->setGeometry(PLAYER1_X + 15, PLAYER1_Y + 40, LABEL_X, LABEL_Y);
    labelN2->setGeometry(PLAYER2_X + 80, PLAYER2_Y, LABEL_X, LABEL_Y);
    labelN3->setGeometry(PLAYER3_X + 80, PLAYER3_Y, LABEL_X, LABEL_Y);
    labelN4->setGeometry(PLAYER4_X + 80, PLAYER4_Y, LABEL_X, LABEL_Y);

    labelN1->setFont(QFont("Courier", 30));
    labelN2->setFont(QFont("Courier", 30));
    labelN3->setFont(QFont("Courier", 30));
    labelN4->setFont(QFont("Courier", 30));

    labelN1->show();
    labelN2->show();
    labelN3->show();
    labelN4->show();
    playerLabel.push_back(labelN1);
    playerLabel.push_back(labelN2);
    playerLabel.push_back(labelN3);
    playerLabel.push_back(labelN4);

    // show pass
    for (int i = 0; i < 3; i++)
    {
        if (other_players.at(i)->Pass == true)
        {
            QLabel *labelPass = new QLabel("Pass!", this);
            switch (i)
            {
            case 0:
                labelPass->setGeometry(PLAYER2_X, PLAYER2_Y + 40, LABEL_X, LABEL_Y);
                break;
            case 1:
                labelPass->setGeometry(PLAYER3_X, PLAYER3_Y + 40, LABEL_X, LABEL_Y);
                break;
            case 2:
                labelPass->setGeometry(PLAYER4_X, PLAYER4_Y + 40, LABEL_X, LABEL_Y);
                break;

            default:
                break;
            }
            labelPass->setFont(QFont("Courier", 20));
            labelPass->show();
            playerLabel.push_back(labelPass);
        }
    }
}
void Game::Finish()
{
    std::cout << "Finish\n";
    int score = 0;
    for (int i = 0; i < 4; i++)
    {
        if (!players.at(i)->ownCards.empty())
        {
            if (players.at(i)->ownCards.back()->num == C2)
                score += players.at(i)->ownCards.size() * 2;
            else
                score += players.at(i)->ownCards.size();
        }
    }
    now_player->score = score;
    std::cout << "score:" << score << "\n";
    if (score > topScore)
        topScore = score;
    lastwin = now_player->player_num;
    ShowMsg();
    if (topScore < 50)
        gameStart();
    else
    {
        afterstart = false;
        reset();
    }
}

void Game::setInitialScene()
{
    QPushButton *P1 = new QPushButton();
    P1->setParent(this);
    P1->setText("1人");
    P1->move(100, 100);
    P1->resize(100, 100);
    P1->setFont(QFont("Courier", 18, QFont::Bold));
    P1->setDisabled(true);
    initialBTNs.push_back(P1);

    QPushButton *P2 = new QPushButton();
    P2->setParent(this);
    P2->setText("2人");
    P2->move(220, 100);
    P2->resize(100, 100);
    P2->setFont(QFont("Courier", 18, QFont::Bold));
    P2->setDisabled(true);
    initialBTNs.push_back(P2);

    QPushButton *P3 = new QPushButton();
    P3->setParent(this);
    P3->setText("3人");
    P3->move(340, 100);
    P3->resize(100, 100);
    P3->setFont(QFont("Courier", 18, QFont::Bold));
    P3->setDisabled(true);
    initialBTNs.push_back(P3);

    QPushButton *P4 = new QPushButton();
    P4->setParent(this);
    P4->setText("4人");
    P4->move(460, 100);
    P4->resize(100, 100);
    P4->setFont(QFont("Courier", 18, QFont::Bold));
    P4->setDisabled(false);
    initialBTNs.push_back(P4);

    QPushButton *PVC = new QPushButton();
    PVC->setParent(this);
    PVC->setText("電腦對戰");
    PVC->move(100, 300);
    PVC->resize(200, 100);
    PVC->setFont(QFont("Courier", 18, QFont::Bold));
    PVC->setDisabled(true);
    initialBTNs.push_back(PVC);

    QPushButton *PVP = new QPushButton();
    PVP->setParent(this);
    PVP->setText("玩家對戰");
    PVP->move(340, 300);
    PVP->resize(200, 100);
    PVP->setFont(QFont("Courier", 18, QFont::Bold));
    PVP->setDisabled(false);
    initialBTNs.push_back(PVP);

    QPushButton *Start = new QPushButton();
    Start->setParent(this);
    Start->setText("Start");
    Start->move(100, 500);
    Start->resize(200, 100);
    Start->setFont(QFont("Courier", 18, QFont::Bold));
    Start->setDisabled(false);
    initialBTNs.push_back(Start);
    QObject::connect(Start, SIGNAL(clicked()), this, SLOT(startbtn()));

    QPushButton *Exit = new QPushButton();
    Exit->setParent(this);
    Exit->setText("Exit");
    Exit->move(340, 500);
    Exit->resize(200, 100);
    Exit->setFont(QFont("Courier", 18, QFont::Bold));
    Exit->setDisabled(false);
    initialBTNs.push_back(Exit);
    for (QPushButton *btn : initialBTNs)
        btn->show();
}
void Game::startbtn()
{
    afterstart = true;
    while (!initialBTNs.empty())
    {
        initialBTNs.back()->deleteLater();
        initialBTNs.pop_back();
    }

    reset();
}