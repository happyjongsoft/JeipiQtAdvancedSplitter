#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->splitter->setChildrenCollapsible(false);

    ui->widget_1->setContentPixmap(QPixmap("1.jpg"));
    ui->widget_2->setContentPixmap(QPixmap("2.jpg"));

    ui->btnSplit->setChecked(true);
    onSplitView();

    connect(ui->btnSplit, &QPushButton::released,
            this, &MainWindow::onSplitView);
    connect(ui->btnMergeHorizontal, &QPushButton::released,
            this, &MainWindow::onMergeHorizontalView);
    connect(ui->btnMergeVertical, &QPushButton::released,
            this, &MainWindow::onMergeVerticalView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSplitView()
{
    ui->splitter->handle(1)->setEnabled(false);
    ui->splitter->setMaximumSize(QSize(1300, 480));
    ui->splitter->setMinimumSize(QSize(1300, 480));

    ui->splitter->setOrientation(Qt::Horizontal);
    ui->splitter->setSizes(QList<int>({1, 1}));

    ui->widget_1->setContentSnap(CONTENT_HLEFT);
    ui->widget_2->setContentSnap(CONTENT_HRIGHT);
}

void MainWindow::onMergeHorizontalView()
{
    ui->splitter->handle(1)->setEnabled(true);
    ui->splitter->setMaximumSize(QSize(640, 480));
    ui->splitter->setMinimumSize(QSize(640, 480));

    ui->splitter->setOrientation(Qt::Horizontal);
    ui->splitter->setSizes(QList<int>({1, 1}));

    ui->widget_1->setContentSnap(CONTENT_HLEFT);
    ui->widget_2->setContentSnap(CONTENT_HRIGHT);
}

void MainWindow::onMergeVerticalView()
{
    ui->splitter->handle(1)->setEnabled(true);
    ui->splitter->setMaximumSize(QSize(640, 480));
    ui->splitter->setMinimumSize(QSize(640, 480));

    ui->splitter->setOrientation(Qt::Vertical);
    ui->splitter->setSizes(QList<int>({1, 1}));

    ui->widget_1->setContentSnap(CONTENT_VTOP);
    ui->widget_2->setContentSnap(CONTENT_VBOTTOM);
}
