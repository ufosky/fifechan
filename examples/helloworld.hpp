/***************************************************************************
 *   Copyright (C) 2012 by the fifechan team                               *
 *   http://fifechan.github.com/fifechan                                   *
 *   This file is part of fifechan.                                        *
 *                                                                         *
 *   fifechan is free software; you can redistribute it and/or             *
 *   modify it under the terms of the GNU Lesser General Public            *
 *   License as published by the Free Software Foundation; either          *
 *   version 2.1 of the License, or (at your option) any later version.    *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA          *
 ***************************************************************************/

/**
 * Code to populate a global Gui object with a simple
 * Hello World example.
 */

namespace helloworld
{
    fcn::Container* top;
    fcn::ImageFont* font;
    fcn::Label* label;

    /**
     * Initialises the Hello World example by populating the global Gui
     * object.
     */
    void init()
    {
        // We first create a container to be used as the top widget.
        // The top widget in Guichan can be any kind of widget, but
        // in order to make the Gui contain more than one widget we
        // make the top widget a container.
        top = new fcn::Container();
        // We set the dimension of the top container to match the screen.
        top->setDimension(fcn::Rectangle(0, 0, 640, 480));
        // Finally we pass the top widget to the Gui object.
        globals::gui->setTop(top);

        // Now we load the font used in this example.
        font = new fcn::ImageFont("fixedfont.bmp", " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
        // Widgets may have a global font so we don't need to pass the
        // font object to every created widget. The global font is static.
        fcn::Widget::setGlobalFont(font);

        // Now we create a label with the text "Hello World".
        label = new fcn::Label("Hello World");
        // We give the label a position.
        label->setPosition(280, 220);
        // And finally we add the label to the top container.
        top->add(label);
    }
    
    /**
     * Halts the Hello World example.
     */
    void halt()
    {
        delete label;
        delete font;
        delete top;
    }
}
