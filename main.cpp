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

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
