#include "internal/widget/app_main_window.hpp"
#include <memory>
#include <qapplication.h>
#include <qcoreapplication.h>
int main (int argc, char **argv)
{
    QApplication app(argc, argv);
    QCoreApplication::setApplicationName("fragmentlm-client");
    QCoreApplication::setOrganizationName("FragmentLM");
    auto mainWindow = std::make_unique<FragmentLM::Impl::AppMainWindow>();
    mainWindow->show();
    int retVal = app.exec();
    return 0;
}
