#pragma once

#include "fragmentlm/tokenizer/tokenizer.hpp"
#include <QObject>
#include <memory>

namespace FragmentLM
{

class MainWindowModel : public QObject
{
    Q_OBJECT
  public:
    virtual ~MainWindowModel() = default;

    virtual void setTokenizer(std::unique_ptr<ITokenizer>) = 0;

    virtual void publishRequest(const QString &requestString) = 0;
};

} // namespace FragmentLM
