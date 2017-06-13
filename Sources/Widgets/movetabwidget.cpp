#include "movetabwidget.h"
#include "../themehandler.h"
#include <QtWidgets>

MoveTabWidget::MoveTabWidget(QWidget *parent) : QTabWidget(parent)
{
    this->setTabBar(new MoveTabBar(this));
    this->hide();
    this->tabSize = 32;
}


void MoveTabWidget::setTheme(QString tabBarAlignment, int maxWidth, bool resizing)
{
    QString borderColor = ThemeHandler::themeColor1();
    int tabSize = std::max(24, std::min(32, maxWidth/std::max(1, this->count()) - 14));

    if(resizing && (tabSize == this->tabSize)) return;

    this->setStyleSheet(
        "QTabBar::tab:selected {background: transparent; border-bottom-color: transparent;}"
        "QTabBar::tab:hover {background: transparent; border-bottom-color: transparent;}"
        "QTabWidget::tab-bar {alignment: " + tabBarAlignment + ";}"
        "QTabWidget::pane {border-color: transparent; " + ThemeHandler::bgApp() + ";}"
        "QTabWidget::pane {position: absolute;top: -38px;}"
        "QTabBar::tab {border: 2px solid " + borderColor + ";"
            "padding: 5px;background: " + borderColor +
            "; height: 24px; width: " + QString::number(tabSize) + "px}"
    );

    if(tabSize != this->tabSize)    tabBar()->setIconSize(QSize(tabSize, tabSize));
    this->tabSize = tabSize;
}



MoveTabBar::MoveTabBar(QWidget *parent) : QTabBar(parent)
{
    this->setIconSize(QSize(32,32));
}

void MoveTabBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    QTabBar::mouseDoubleClickEvent(event);
    event->ignore();
}
void MoveTabBar::mouseMoveEvent(QMouseEvent *event)
{
    QTabBar::mouseMoveEvent(event);
    event->ignore();
}
void MoveTabBar::mousePressEvent(QMouseEvent *event)
{
    QTabBar::mousePressEvent(event);
    event->ignore();

}
void MoveTabBar::mouseReleaseEvent(QMouseEvent *event)
{
    QTabBar::mouseReleaseEvent(event);
    event->ignore();
}

