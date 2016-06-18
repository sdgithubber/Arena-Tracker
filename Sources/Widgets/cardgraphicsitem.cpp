#include "cardgraphicsitem.h"
#include "herographicsitem.h"
#include "../utility.h"
#include <QtWidgets>


CardGraphicsItem::CardGraphicsItem( int id, QString code, QString createdByCode)
{
    this->code = code;
    this->createdByCode = createdByCode;
    this->id = id;
    this->played = this->discard = this->draw = false;
    this->heightShow = HEIGHT;
}


CardGraphicsItem::CardGraphicsItem(CardGraphicsItem *copy)
{
    this->code = copy->code;
    this->id = copy->id;
    this->played = copy->played;
    this->discard = copy->discard;
    this->draw = copy->draw;
    this->heightShow = copy->heightShow;
    this->setPos(copy->pos());
}


int CardGraphicsItem::getId()
{
    return this->id;
}


void CardGraphicsItem::setCode(QString code)
{
    this->code = code;
    update();
}


void CardGraphicsItem::setPlayed()
{
    this->played = true;
    prepareGeometryChange();
    update();
}


void CardGraphicsItem::setDiscard()
{
    this->discard = true;
    prepareGeometryChange();
    update();
}


void CardGraphicsItem::setDraw()
{
    this->draw = true;
    update();
}


void CardGraphicsItem::checkDownloadedCode(QString code)
{
    if(this->code == code)  update();
}


QRectF CardGraphicsItem::boundingRect() const
{
    return QRectF( -WIDTH/2, -heightShow/2+(played||discard?-CARD_LIFT:0), WIDTH, heightShow+(played||discard?CARD_LIFT:0));
}


void CardGraphicsItem::setZonePos(bool friendly, int pos, int cardsZone, int viewWidth, int cardHeightShow)
{
    const int hMinion = MinionGraphicsItem::HEIGHT-5;
    const int hHero = HeroGraphicsItem::HEIGHT;
    this->heightShow = cardHeightShow;
    viewWidth -= WIDTH+8 - viewWidth/cardsZone;
    const int wCard = std::min(175, viewWidth/cardsZone);
    int x = wCard*(pos - (cardsZone-1)/2.0);
    int y = friendly?hMinion + hHero + heightShow/2:-hMinion - hHero - heightShow/2;
    this->setPos(x, y);
}


void CardGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    Q_UNUSED(option);

    if(played)          painter->drawPixmap(-WIDTH/2, -heightShow/2-CARD_LIFT, QPixmap(":/Images/bgCardGlow.png"), 0, 0, 190, heightShow+CARD_LIFT);
    else if(discard)    painter->drawPixmap(-WIDTH/2, -heightShow/2-CARD_LIFT, QPixmap(":/Images/bgCardDiscard.png"), 0, 0, 190, heightShow+CARD_LIFT);
    if(draw)            painter->drawPixmap(-WIDTH/2, -heightShow/2, QPixmap(":/Images/bgCardDraw.png"), 0, 0, 190, heightShow);
    painter->drawPixmap(-WIDTH/2, -heightShow/2+((played||discard)&&!draw?-CARD_LIFT:0),
                        QPixmap(Utility::hscardsPath() + "/" + code + ".png"), 5, 34, WIDTH,
                        heightShow+((played||discard)&&!draw?CARD_LIFT:0));
}
