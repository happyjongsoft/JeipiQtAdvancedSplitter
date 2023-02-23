#ifndef QCONTENTWIDGET_H
#define QCONTENTWIDGET_H

#include <QWidget>
#include <QDebug>

enum ContentSnapType {
    CONTENT_HLEFT,
    CONTENT_HRIGHT,
    CONTENT_VTOP,
    CONTENT_VBOTTOM
};

namespace Ui {
class QContentWidget;
}

class QContentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QContentWidget(QWidget *parent = nullptr);
    ~QContentWidget();

    void setContentSize(QSize size);
    void setContentPixmap(QPixmap pix);
    void setContentSnap(ContentSnapType snap);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    void updateContent();

private:
    Ui::QContentWidget *ui;

    ContentSnapType     m_snapType;
    QSize               m_contentSize;
};

#endif // QCONTENTWIDGET_H
