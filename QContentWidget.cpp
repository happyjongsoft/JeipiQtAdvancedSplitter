#include "QContentWidget.h"
#include "ui_QContentWidget.h"

QContentWidget::QContentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QContentWidget),
    m_snapType(CONTENT_HLEFT),
    m_contentSize(QSize(640, 480))
{
    ui->setupUi(this);

    // setMinimumSize(QSize(4, 4));

    ui->label->setScaledContents(true);
    setContentSize(m_contentSize);
}

QContentWidget::~QContentWidget()
{
    delete ui;
}

void QContentWidget::setContentSize(QSize size)
{
    m_contentSize = size;
    ui->label->setMinimumSize(m_contentSize);
    ui->label->setMaximumSize(m_contentSize);

    updateContent();
}

void QContentWidget::setContentPixmap(QPixmap pix)
{
    ui->label->setPixmap(pix);
}

void QContentWidget::setContentSnap(ContentSnapType snap)
{
    m_snapType = snap;
    updateContent();
}

void QContentWidget::resizeEvent(QResizeEvent* event)
{
    updateContent();
    QWidget::resizeEvent(event);
}

void QContentWidget::updateContent()
{
    if(m_snapType == CONTENT_HLEFT){
        ui->label->move(0, (this->height() - m_contentSize.height()) / 2);
    }else if(m_snapType == CONTENT_HRIGHT){
        ui->label->move(this->width() - m_contentSize.width(), (this->height() - m_contentSize.height()) / 2);
    }else if(m_snapType == CONTENT_VTOP){
        ui->label->move((this->width() - m_contentSize.width()) / 2, 0);
    }else if(m_snapType == CONTENT_VBOTTOM){
        ui->label->move((this->width() - m_contentSize.width()) / 2, this->height() - m_contentSize.height());
    }
}
