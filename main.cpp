#include <QApplication>
#include "Game.h"

Game *game;

int main(int argc, char *argv[]){
    QApplication *app =new QApplication(argc, argv);

    game = new Game(app);
    game->show();

    return app->exec();
}
