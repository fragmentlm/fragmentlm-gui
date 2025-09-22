#pragma once

#include <QJsonObject>
#include <cstdint>

struct ClientRequest
{
    uint64_t startPos;
    QString fragment;
    QJsonObject tokensTable;
    QString tokensChecksum;
};
