#pragma once

#include "fragmentlm/model/main_window.hpp"
#include <QWidget>
#include <memory>

namespace FragmentLM
{

struct AbstractMainWindow : public QWidget
{
    Q_OBJECT
  public:
    virtual ~AbstractMainWindow() noexcept = default;

    virtual void setModel(std::unique_ptr<MainWindowModel> model) noexcept = 0;

    virtual void spawnClientSettingsWindow() noexcept = 0;

    virtual void spawnNetworkSettingsWindow() noexcept = 0;
};

} // namespace FragmentLM
