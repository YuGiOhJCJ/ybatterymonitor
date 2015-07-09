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
#include "main.h"
#include "BatteryMonitor.h"
#include <QtWidgets/QApplication>
#include <QIcon>
#include <iostream> /* for cout */
using namespace std;
int main(int argc, char *argv[])
{
	QApplication qapplication(argc, argv);
	QIcon qicon(QCoreApplication::applicationDirPath()+"/ybatterymonitor.png");
	qapplication.setWindowIcon(qicon);
	BatteryMonitor batterymonitor;
	batterymonitor.show();
	for(int i = 1 ; i < argc; i++)
	{
		QString str(argv[i]);
		if(str.compare("--help") == 0 || str.compare("-h") == 0)
		{
			cout << "ybatterymonitor is a battery monitor written in C++ language using the Qt framework." << endl << endl;
			cout << "Usage: ybatterymonitor [OPTION]..." << endl << endl;
			cout << "Options:" << endl;
			cout << " -h, --help" << endl;
			cout << "\t\tdisplay this help and exit" << endl;
			cout << " -v, --version" << endl;
			cout << "\t\toutput version information and exit" << endl << endl;
			cout << "Examples:" << endl;
			cout << " ybatterymonitor -h\tdisplay this help and exit" << endl;
			cout << " ybatterymonitor -v\toutput version information and exit" << endl << endl;
			cout << "Report bugs to YuGiOhJCJ <yugiohjcj@1s.fr>." << endl;
			exit(EXIT_SUCCESS);
		}
		if(str.compare("--version") == 0 || str.compare("-v") == 0)
		{
			cout << "ybatterymonitor 20120829" << endl << endl;
			cout << "Copyright (C) 2012, 2015 YuGiOhJCJ <yugiohjcj@1s.fr>." << endl;
			cout << "This is free software; see the source for copying conditions. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE." << endl << endl;
			cout << "written by YuGiOhJCJ <yugiohjcj@1s.fr>." << endl;
			exit(EXIT_SUCCESS);
		}
		else
		{
			cerr << "Error: unknown argument ('" << argv[i] << "')" << endl;
			exit(EXIT_FAILURE);
		}
	}
	return qapplication.exec();
}
