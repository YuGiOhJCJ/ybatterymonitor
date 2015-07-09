/*
   Copyright 2012, 2015 YuGiOhJCJ.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
   */
#include "BatteryMonitor.h"
#include <QString>
#include <SDL2/SDL_power.h> /* for SDL_GetPowerInfo */
BatteryMonitor::BatteryMonitor()
{
	this->update();
	this->qlabel.setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
	this->qvboxlayout.addWidget(&(this->qlabel));
	this->setLayout(&(this->qvboxlayout));
	this->qtimer.start(1000);
	connect(&qtimer, SIGNAL(timeout()), this, SLOT(update()));
}
int BatteryMonitor::update()
{
	int percentage;
	SDL_GetPowerInfo(NULL, &percentage);
	QString qstr_percentage = QString::number(percentage);
	this->qlabel.setText("Battery: "+qstr_percentage+"% remaining");
	return 0;
}
