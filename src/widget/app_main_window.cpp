#include "../internal/widget/app_main_window.hpp"
#include <utility>

using namespace FragmentLM::Impl;

AppMainWindow::AppMainWindow () noexcept
{
    m_Ui.setupUi(this);
}

void AppMainWindow::setModel (std::unique_ptr<MainWindowModel> model) noexcept
{
    m_Model = std::move(model);
}

void AppMainWindow::spawnClientSettingsWindow () noexcept
{
}

void AppMainWindow::spawnNetworkSettingsWindow () noexcept
{
}
