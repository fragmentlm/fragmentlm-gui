#pragma once

#include "ui_MainWindow.h"
#include <fragmentlm/widget/main_window.hpp>

namespace FragmentLM::Impl
{

class AppMainWindow : public AbstractMainWindow
{
    Q_OBJECT
  public:
    AppMainWindow() noexcept;

  public:
    void setModel(std::unique_ptr<MainWindowModel> model) noexcept override;

    void spawnClientSettingsWindow() noexcept override;

    void spawnNetworkSettingsWindow() noexcept override;

  private:
    std::unique_ptr<MainWindowModel> m_Model;
    Ui::MainWindow m_Ui;
};

} // namespace FragmentLM::Impl
