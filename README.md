# RoundButton - Qt Widgets RoundButton example

An example app that shows how to make a rounded button using Qt Widgets.
This is trivially easy to do with QML, but non-trivial if you're using Qt
Widgets.

# What this does

It styles a QPushButton using Qt Widgets stylesheets to make the border and
background rounded, then re-creates that same geometry in a QBitmap that is then
set as a mask on the button widget. What the mask does is to both prevent
painting in the areas of the mask that are Qt::color0 (0), as well as allow
events to propagate to the widgets underneath it.

To illustrate that clicks will be delivered to widgets under the bounding box of
the round button, but outside (inside?) the masked area, a standard QPushButton
scaled to 1/4 of the size of the round button is placed underneath, to the
bottom right on the window.

## Running

Install Qt from online installer or elsewhere.
Open in Qt Creator, select Qt kit to use, build, and run.
Should run on both Qt 5.x and 6.x.
