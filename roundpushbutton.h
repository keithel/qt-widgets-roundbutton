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

#ifndef ROUNDPUSHBUTTON_H
#define ROUNDPUSHBUTTON_H

#include <QPushButton>

class RoundPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit RoundPushButton(QWidget *parent = nullptr);
    explicit RoundPushButton(const QString &text, QWidget *parent = nullptr);
    RoundPushButton(const QIcon& icon, const QString &text, QWidget *parent = nullptr);
    ~RoundPushButton();

private:
    void updateForRadiusChange();
    QBitmap generateMask();

    // QWidget interface
protected:
    void resizeEvent(QResizeEvent *event) override;
private:
    size_t m_radius = 0;
};

#endif // ROUNDPUSHBUTTON_H
