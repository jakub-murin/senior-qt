#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "qt-hello_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

//    QFontDatabase *fdb = new QFontDatabase ;
    QStringList fam = QFontDatabase::families();

    qDebug() << "QFontDatabase::Any: available font families";
    for(int i=0 ; i< fam.count(); i++)
    {
        qDebug() << fam[i];
    }

    QFont font("Sans Serif");
//    font.setStyleHint(QFont::Monospace);
    QApplication::setFont(font);

    MainWindow w;
    w.show();
    return a.exec();
}
