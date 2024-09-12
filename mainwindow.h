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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "roundpushbutton.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
    QPushButton *m_button = nullptr;
    RoundPushButton *m_roundButton = nullptr;
};
#endif // MAINWINDOW_H
