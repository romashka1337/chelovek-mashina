#include "sdiprogram_maslov.h"
#include <QApplication>
#include <QSplashScreen>

void loadModules(QSplashScreen* psplash)
{
    QTime time;
    time.start();
    for (int it = 0; it < 100; )
    {
        if (time.elapsed() > 40)
        {
            time.start();
            ++it;
        }
        psplash->showMessage("Loading modules: "
                             + QString::number(it) + "%",
                             Qt::AlignCenter,
                             Qt::white);
        qApp->processEvents();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen splash(QPixmap("../lab3/13.png"));
    splash.show();
    SDIProgram_Maslov w;
    loadModules(&splash);
    splash.finish(&w);
    w.show();

    return a.exec();
}
