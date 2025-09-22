#pragma once

#include <optional>
#include <variant>

template <typename T, typename E> class Result
{
  public:
    static Result<T, E> success (const T &value) noexcept
    {
        return Result<T, E>(value);
    }

    static Result<T, E> failure (const E &error) noexcept
    {
        return Result<T, E>(error);
    }

    Result<T, E>() noexcept
    {
    }

    Result (const T &value) noexcept : m_Value(value)
    {
    }
    Result (const E &error) noexcept : m_Value(error)
    {
    }

    operator T() noexcept
    {
        if (isSuccess())
        {
            return getValue();
        }
        return {};
    }

    operator E() noexcept
    {
        if (!isSuccess())
        {
            return getError();
        }
        return {};
    }

    bool isSuccess () const noexcept
    {
        return std::holds_alternative<T>(m_Value);
    }

    bool isError () const noexcept
    {
        return std::holds_alternative<E>(m_Value);
    }

    std::optional<T> getValue () const noexcept
    {
        if (auto val = std::get_if<T>(&m_Value))
        {
            return *val;
        }
        return std::nullopt;
    }

    std::optional<E> getError () const noexcept
    {
        if (auto val = std::get_if<E>(&m_Value))
        {
            return *val;
        }
        return std::nullopt;
    }

  private:
    std::variant<T, E> m_Value;
};
