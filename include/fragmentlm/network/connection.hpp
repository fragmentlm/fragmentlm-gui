#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

constexpr std::byte operator""_b(unsigned long long val) noexcept
{
    return static_cast<std::byte>(val);
}

namespace FragmentLM
{

struct INetworkConnection
{
    using Address                      = std::array<std::byte, 4>;
    static constexpr Address LocalHost = {0x7F_b, 0x00_b, 0x00_b, 0x01_b};

    virtual ~INetworkConnection() noexcept = default;

    virtual bool startListening(const Address &addr,
                                uint16_t port) noexcept = 0;
    virtual bool stopListening() noexcept               = 0;
};

} // namespace FragmentLM
