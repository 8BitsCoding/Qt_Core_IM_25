#include <QtCore/QCoreApplication>

#include <qdebug.h>
#include <qfile.h>
#include <qdir.h>
/*
ASCII is a 7-bit character set containing 128(2^7) charaters.
It contains the numbers from 0-9, the upper and lower case English letters from A to Z,
and some special characters.
The character sets used in modern computers, in HTML, and on the Internet, are all based on ASCII
*/

QByteArray makeData() {
	QByteArray data;

	for (int i = 0; i < 10; i++) {
		data.append(72);		// H
		data.append(101);		// e
		data.append(108);		// l
		data.append(108);		// l
		data.append(111);		// o
		data.append(33);		// w
		data.append(13);		// \r
		data.append(10);		// \n
	}

	return data;
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QByteArray data = makeData();

	QString path = QDir::currentPath() + QDir::separator() + "data.txt";
	QFile file(path);

	if (file.open(QIODevice::WriteOnly)) {
		file.write(data);
		file.close();
	}

	qInfo() << "Done";

	return a.exec();
}
