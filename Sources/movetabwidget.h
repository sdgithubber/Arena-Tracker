#ifndef MOVETABWIDGET_H
#define MOVETABWIDGET_H


#include <QTabWidget>
#include <QTabBar>

class MoveTabWidget : public QTabWidget
{
public:
    MoveTabWidget(QWidget *parent = 0);
};


class MoveTabBar : public QTabBar
{
public:
    MoveTabBar(QWidget *parent = 0);

protected:
    void mouseDoubleClickEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
};

#endif // MOVETABWIDGET_H
