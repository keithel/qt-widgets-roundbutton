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

#include "roundpushbutton.h"
#include <QPainter>
#include <QBitmap>

RoundPushButton::RoundPushButton(QWidget *parent)
    : QPushButton(parent)
{
    setFlat(true);
    updateForRadiusChange();
}

RoundPushButton::RoundPushButton(const QString &text, QWidget *parent)
    : QPushButton(text, parent)
{
    setFlat(true);
    updateForRadiusChange();
}

RoundPushButton::RoundPushButton(const QIcon &icon, const QString &text, QWidget *parent)
    : QPushButton(icon, text, parent)
{
    setFlat(true);
    updateForRadiusChange();
}

RoundPushButton::~RoundPushButton() {}

void RoundPushButton::updateForRadiusChange()
{
    int radius = std::min(width(), height()) / 2;
    if(radius != m_radius) {
        m_radius = radius;
        setStyleSheet(QString(
            "RoundPushButton {"
            "   background-color: #00f;"
            "   border: 1px solid gray;"
            "   border-radius: %1px;"
            "   color: white;"
            "   padding: 10px;"
            "}"
            "RoundPushButton:hover {"
            "   background-color: #04f;"
            "   border: 1px solid lightgray;"
            "}"
            "RoundPushButton:pressed {"
            "   background-color: #04a;"
            "   border: 1px solid darkgray;"
            "}").arg(radius)
        );
    }
}

QBitmap RoundPushButton::generateMask()
{
    int w = width();
    int h = height();
    int offset = 2; // make mask bigger by this to make sure anti-aliasing of border displays properly.
    int radius = std::min(w, h) / 2 + offset;
    QBitmap bmp(size());
    bmp.clear();
    QPainter p(&bmp);
    p.setPen(QPen(Qt::color1));
    p.setBrush(QBrush(Qt::color1));
    int diameter = radius*2;
    p.drawEllipse(-1*offset, -1*offset, diameter, diameter);
    if (w > h) {
        p.drawRect(radius-offset, 0, w-diameter+offset, h);
        p.drawEllipse(w-diameter+offset, -1*offset, diameter, diameter);
    } else {
        p.drawRect(0, radius-offset, w, h-diameter+offset);
        p.drawEllipse(-1*offset, h-diameter+offset, diameter, diameter);
    }
    p.end();
    return bmp;
}


void RoundPushButton::resizeEvent(QResizeEvent *event)
{
    updateForRadiusChange();
    setMask(generateMask());
    QPushButton::resizeEvent(event);
}
