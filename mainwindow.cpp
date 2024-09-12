/****************************************************************************
 *  Copyright (C) 2024 Keith Kyzivat
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the MIT license.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  MIT License for more details.
 *
 *  You should have received a copy of the MIT License along with this
 *  program. If not, see <https://choosealicense.com/licenses/mit/>.
 */

#include "mainwindow.h"
#include <QEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget* butContainer = new QWidget(this);
    m_button = new QPushButton("Regular", butContainer);
    m_button->setStyleSheet("text-align:right;");
    m_roundButton = new RoundPushButton("Round Button", butContainer);
    setCentralWidget(butContainer);
    butContainer->installEventFilter(this);
}

MainWindow::~MainWindow() {}


bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    // Size the two buttons in the container to match the size of the container, since they don't have a layout manager.
    if (event->type() == QEvent::Resize) {
        QWidget *pbp = m_button->parentWidget();
        m_button->resize(pbp->size()/4);
        m_button->move(3*pbp->width()/4, 3*pbp->height()/4);
        m_roundButton->resize(m_roundButton->parentWidget()->size());
    }
    return false;
}
